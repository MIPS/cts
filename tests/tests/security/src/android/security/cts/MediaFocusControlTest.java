/*
 * Copyright (C) 2015 The Android Open Source Project
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

package android.security.cts;

import junit.framework.TestCase;

public class MediaFocusControlTest extends TestCase {
    public void testRestoreMediaButtonReceiverMethod() throws ClassNotFoundException {
        try {
            Class.forName("android.media.MediaFocusControl").getDeclaredMethod(
                    "restoreMediaButtonReceiver");
            fail("RestoreMediaButtonReceiver API method should not be available in patched " +
                    "devices: Device is vulnerable to the bug: 15428797");
        } catch (ClassNotFoundException e) {
            // MediaFocusControl class has been moved to com.android.server.audio package
            // in 6.0 + versions. However, this bug is raised for 4.4.1 - 4.4.4 versions
        } catch (NoSuchMethodException e) {
            // restoreMediaButtonReceiver API method should not be available in patched devices
        }
    }
}
