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
 * limitations under the License
 */

package android.widget.cts;

import static org.mockito.Mockito.*;

import android.app.Activity;
import android.app.Instrumentation;
import android.test.ActivityInstrumentationTestCase2;
import android.view.Gravity;
import android.widget.PopupMenu;

import android.widget.cts.R;

public class PopupMenuTest extends
        ActivityInstrumentationTestCase2<MockPopupWindowCtsActivity> {
    private Instrumentation mInstrumentation;
    private Activity mActivity;

    public PopupMenuTest() {
        super("android.widget.cts", MockPopupWindowCtsActivity.class);
    }

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        mInstrumentation = getInstrumentation();
        mActivity = getActivity();
    }

    public void testAccessGravity() {
        PopupMenu popupMenu = new PopupMenu(mActivity,
                mActivity.findViewById(R.id.anchor_middle_left));
        assertEquals(Gravity.NO_GRAVITY, popupMenu.getGravity());

        popupMenu.setGravity(Gravity.TOP);
        assertEquals(Gravity.TOP, popupMenu.getGravity());
    }

    public void testOnDismissListener() {
        final PopupMenu popupMenu = new PopupMenu(mActivity,
                mActivity.findViewById(R.id.anchor_middle_left));
        PopupMenu.OnDismissListener listener = mock(PopupMenu.OnDismissListener.class);
        popupMenu.setOnDismissListener(listener);

        mInstrumentation.runOnMainSync(new Runnable() {
            public void run() {
                popupMenu.show();
            }
        });
        mInstrumentation.waitForIdleSync();
        verify(listener, never()).onDismiss(popupMenu);

        mInstrumentation.runOnMainSync(new Runnable() {
            public void run() {
                popupMenu.dismiss();
            }
        });
        mInstrumentation.waitForIdleSync();
        verify(listener, times(1)).onDismiss(popupMenu);

        mInstrumentation.runOnMainSync(new Runnable() {
            public void run() {
                popupMenu.dismiss();
            }
        });
        mInstrumentation.waitForIdleSync();
        verify(listener, times(1)).onDismiss(popupMenu);
    }
}
