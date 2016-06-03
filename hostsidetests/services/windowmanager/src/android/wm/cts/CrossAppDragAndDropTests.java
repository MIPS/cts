/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package android.wm.cts;

import com.android.tradefed.device.CollectingOutputReceiver;
import com.android.tradefed.device.DeviceNotAvailableException;
import com.android.tradefed.device.ITestDevice;
import com.android.tradefed.testtype.DeviceTestCase;

import java.util.HashMap;
import java.util.Map;

public class CrossAppDragAndDropTests extends DeviceTestCase {
    // Constants copied from ActivityManager.StackId. If they are changed there, these must be
    // updated.
    /** ID of stack where fullscreen activities are normally launched into. */
    private static final int FULLSCREEN_WORKSPACE_STACK_ID = 1;

    /** ID of stack where freeform/resized activities are normally launched into. */
    private static final int FREEFORM_WORKSPACE_STACK_ID = FULLSCREEN_WORKSPACE_STACK_ID + 1;

    /** ID of stack that occupies a dedicated region of the screen. */
    private static final int DOCKED_STACK_ID = FREEFORM_WORKSPACE_STACK_ID + 1;

    private static final String AM_FORCE_STOP = "am force-stop ";
    private static final String AM_MOVE_TASK = "am stack movetask ";
    private static final String AM_START_N = "am start -n ";
    private static final String AM_STACK_LIST = "am stack list";
    private static final String INPUT_MOUSE_SWIPE = "input mouse swipe ";

    private static final String TASK_ID_PREFIX = "taskId";

    private static final int SWIPE_DURATION_MS = 500;

    private static final String SOURCE_PACKAGE_NAME = "android.wm.cts.dndsourceapp";
    private static final String TARGET_PACKAGE_NAME = "android.wm.cts.dndtargetapp";

    private static final String SOURCE_ACTIVITY_NAME = "DragSource";
    private static final String TARGET_ACTIVITY_NAME = "DropTarget";

    private static final String DISALLOW_GLOBAL = "disallow_global";
    private static final String CANCEL_SOON = "cancel_soon";
    private static final String GRANT_NONE = "grant_none";
    private static final String GRANT_READ = "grant_read";
    private static final String GRANT_WRITE = "grant_write";
    private static final String GRANT_READ_PREFIX = "grant_read_prefix";
    private static final String GRANT_READ_NOPREFIX = "grant_read_noprefix";
    private static final String GRANT_READ_PERSISTABLE = "grant_read_persistable";

    private static final String REQUEST_NONE = "request_none";
    private static final String REQUEST_READ = "request_read";
    private static final String REQUEST_READ_NESTED = "request_read_nested";
    private static final String REQUEST_TAKE_PERSISTABLE = "request_take_persistable";
    private static final String REQUEST_WRITE = "request_write";

    private static final String TARGET_LOG_TAG = "DropTarget";

    private static final String RESULT_KEY_DRAG_STARTED = "DRAG_STARTED";
    private static final String RESULT_KEY_EXTRAS = "EXTRAS";
    private static final String RESULT_KEY_DROP_RESULT = "DROP";

    private static final String RESULT_OK = "OK";
    private static final String RESULT_EXCEPTION = "Exception";
    private static final String RESULT_NULL_DROP_PERMISSIONS = "Null DragAndDropPermissions";

    private ITestDevice mDevice;

    private Map<String, String> mResults;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        mDevice = getDevice();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
        mDevice.executeShellCommand(AM_FORCE_STOP + SOURCE_PACKAGE_NAME);
        mDevice.executeShellCommand(AM_FORCE_STOP + TARGET_PACKAGE_NAME);
    }

    private String adbShell(String command) throws DeviceNotAvailableException {
        return mDevice.executeShellCommand(command);
    }

    private void clearLogs() throws DeviceNotAvailableException {
        adbShell("logcat -c");
    }

    private String getStartCommand(String componentName, String modeExtra) {
        return AM_START_N + componentName + " -e mode " + modeExtra;
    }

    private String getMoveTaskCommand(int taskId, int stackId) throws Exception {
        return AM_MOVE_TASK + taskId + " " + stackId + " true";
    }

    private String getComponentName(String packageName, String activityName) {
        return packageName + "/" + packageName + "." + activityName;
    }

    private void launchDockedActivity(String packageName, String activityName, String mode)
            throws Exception {
        clearLogs();
        final String componentName = getComponentName(packageName, activityName);
        adbShell(getStartCommand(componentName, mode));
        final int taskId = getActivityTaskId(componentName);
        adbShell(getMoveTaskCommand(taskId, DOCKED_STACK_ID));
        waitForResume(packageName, activityName);
    }

    private void launchFreeformActivity(String packageName, String activityName, String mode)
            throws Exception {
        clearLogs();
        final String componentName = getComponentName(packageName, activityName);
        adbShell(getStartCommand(componentName, mode) + " --stack " + FREEFORM_WORKSPACE_STACK_ID);
        waitForResume(packageName, activityName);
    }

    private void waitForResume(String packageName, String activityName) throws Exception {
        final String fullActivityName = packageName + "." + activityName;
        int retryCount = 3;
        do {
            String logs = adbShell("logcat -d -b events");
            for (String line : logs.split("\\n")) {
                if(line.contains("am_on_resume_called") && line.contains(fullActivityName)) {
                    return;
                }
            }
        } while (retryCount-- > 0);

        throw new Exception(fullActivityName + " has failed to start");
    }

    private void injectInput(Point from, Point to, int durationMs) throws Exception {
        adbShell(INPUT_MOUSE_SWIPE + from.x + " " + from.y + " " + to.x + " " + to.y + " " +
                durationMs);
    }

    static class Point {
        public int x, y;

        public Point(int _x, int _y) {
            x=_x;
            y=_y;
        }

        public Point() {}
    }

    private String findTaskInfo(String name) throws Exception {
        CollectingOutputReceiver outputReceiver = new CollectingOutputReceiver();
        mDevice.executeShellCommand(AM_STACK_LIST, outputReceiver);
        final String output = outputReceiver.getOutput();
        for (String line : output.split("\\n")) {
            if (line.contains(name)) {
                return line;
            }
        }
        return "";
    }

    private boolean getWindowBounds(String name, Point from, Point to) throws Exception {
        final String taskInfo = findTaskInfo(name);
        final String[] sections = taskInfo.split("\\[");
        if (sections.length > 2) {
            try {
                parsePoint(sections[1], from);
                parsePoint(sections[2], to);
                return true;
            } catch (Exception e) {
                return false;
            }
        }
        return false;
    }

    private int getActivityTaskId(String name) throws Exception {
        final String taskInfo = findTaskInfo(name);
        for (String word : taskInfo.split("\\s+")) {
            if (word.startsWith(TASK_ID_PREFIX)) {
                final String withColon = word.split("=")[1];
                return Integer.parseInt(withColon.substring(0, withColon.length() - 1));
            }
        }
        return -1;
    }

    private Point getWindowCenter(String name) throws Exception {
        Point p1 = new Point();
        Point p2 = new Point();
        if (getWindowBounds(name, p1, p2)) {
            return new Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
        }
        return null;
    }

    private void parsePoint(String string, Point point) {
        final String[] parts = string.split("[,|\\]]");
        point.x = Integer.parseInt(parts[0]);
        point.y = Integer.parseInt(parts[1]);
    }

    private Map<String, String> getLogResults(String className) throws Exception {
        int retryCount = 3;
        Map<String, String> output = new HashMap<String, String>();
        do {

            String logs = adbShell("logcat -v brief -d " + className + ":I" + " *:S");
            for (String line : logs.split("\\n")) {
                if (line.startsWith("I/" + className)) {
                    String payload = line.split(":")[1].trim();
                    final String[] split = payload.split("=");
                    if (split.length > 1) {
                        output.put(split[0], split[1]);
                    }
                }
            }
            if (output.containsKey(RESULT_KEY_DROP_RESULT)) {
                return output;
            }
        } while (retryCount-- > 0);
        return output;
    }

    private void doTestDragAndDrop(String sourceMode, String targetMode, String expectedDropResult)
            throws Exception {

        launchDockedActivity(SOURCE_PACKAGE_NAME, SOURCE_ACTIVITY_NAME, sourceMode);
        launchFreeformActivity(TARGET_PACKAGE_NAME, TARGET_ACTIVITY_NAME, targetMode);

        clearLogs();

        injectInput(
                getWindowCenter(getComponentName(SOURCE_PACKAGE_NAME, SOURCE_ACTIVITY_NAME)),
                getWindowCenter(getComponentName(TARGET_PACKAGE_NAME, TARGET_ACTIVITY_NAME)),
                SWIPE_DURATION_MS);

        mResults = getLogResults(TARGET_LOG_TAG);
        assertResult(RESULT_KEY_DROP_RESULT, expectedDropResult);
    }


    private void assertResult(String resultKey, String expectedResult) {
        if (expectedResult == null) {
            if (mResults.containsKey(resultKey)) {
                fail("Unexpected " + resultKey + "=" + mResults.get(resultKey));
            }
        } else {
            assertTrue("Missing " + resultKey, mResults.containsKey(resultKey));
            assertEquals(expectedResult, mResults.get(resultKey));
        }
    }

    public void testCancelSoon() throws Exception {
        doTestDragAndDrop(CANCEL_SOON, REQUEST_NONE, null);
        assertResult(RESULT_KEY_DRAG_STARTED, RESULT_OK);
        assertResult(RESULT_KEY_EXTRAS, RESULT_OK);
    }

    public void testDisallowGlobal() throws Exception {
        doTestDragAndDrop(DISALLOW_GLOBAL, REQUEST_NONE, null);
        assertResult(RESULT_KEY_DRAG_STARTED, null);
    }

    public void testGrantNoneRequestNone() throws Exception {
        doTestDragAndDrop(GRANT_NONE, REQUEST_NONE, RESULT_EXCEPTION);
        assertResult(RESULT_KEY_DRAG_STARTED, RESULT_OK);
        assertResult(RESULT_KEY_EXTRAS, RESULT_OK);
    }

    public void testGrantNoneRequestRead() throws Exception {
        doTestDragAndDrop(GRANT_NONE, REQUEST_READ, RESULT_NULL_DROP_PERMISSIONS);
    }

    public void testGrantNoneRequestWrite() throws Exception {
        doTestDragAndDrop(GRANT_NONE, REQUEST_WRITE, RESULT_NULL_DROP_PERMISSIONS);
    }

    public void testGrantReadRequestNone() throws Exception {
        doTestDragAndDrop(GRANT_READ, REQUEST_NONE, RESULT_EXCEPTION);
    }

    public void testGrantReadRequestRead() throws Exception {
        doTestDragAndDrop(GRANT_READ, REQUEST_READ, RESULT_OK);
    }

    public void testGrantReadRequestWrite() throws Exception {
        doTestDragAndDrop(GRANT_READ, REQUEST_WRITE, RESULT_EXCEPTION);
    }

    public void testGrantReadNoPrefixRequestReadNested() throws Exception {
        doTestDragAndDrop(GRANT_READ_NOPREFIX, REQUEST_READ_NESTED, RESULT_EXCEPTION);
    }

    public void testGrantReadPrefixRequestReadNested() throws Exception {
        doTestDragAndDrop(GRANT_READ_PREFIX, REQUEST_READ_NESTED, RESULT_OK);
    }

    public void testGrantPersistableRequestTakePersistable() throws Exception {
        doTestDragAndDrop(GRANT_READ_PERSISTABLE, REQUEST_TAKE_PERSISTABLE, RESULT_OK);
    }

    public void testGrantReadRequestTakePersistable() throws Exception {
        doTestDragAndDrop(GRANT_READ, REQUEST_TAKE_PERSISTABLE, RESULT_EXCEPTION);
    }

    public void testGrantWriteRequestNone() throws Exception {
        doTestDragAndDrop(GRANT_WRITE, REQUEST_NONE, RESULT_EXCEPTION);
    }

    public void testGrantWriteRequestRead() throws Exception {
        doTestDragAndDrop(GRANT_WRITE, REQUEST_READ, RESULT_EXCEPTION);
    }

    public void testGrantWriteRequestWrite() throws Exception {
        doTestDragAndDrop(GRANT_WRITE, REQUEST_WRITE, RESULT_OK);
    }
}