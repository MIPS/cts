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

// Don't edit this file!  It is auto-generated by frameworks/rs/api/generate.sh.

package android.renderscript.cts;

import android.renderscript.Allocation;
import android.renderscript.RSRuntimeException;
import android.renderscript.Element;
import android.renderscript.cts.Target;

import java.util.Arrays;

public class TestLength extends RSBaseCompute {

    private ScriptC_TestLength script;
    private ScriptC_TestLengthRelaxed scriptRelaxed;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        script = new ScriptC_TestLength(mRS);
        scriptRelaxed = new ScriptC_TestLengthRelaxed(mRS);
    }

    @Override
    protected void tearDown() throws Exception {
        script.destroy();
        scriptRelaxed.destroy();
        super.tearDown();
    }

    public class ArgumentsFloatFloat {
        public float inV;
        public Target.Floaty out;
    }

    private void checkLengthFloatFloat() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_32, 1, 0x8119352509f7cc9fl, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            script.forEach_testLengthFloatFloat(inV, out);
            verifyResultsLengthFloatFloat(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloatFloat: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthFloatFloat(inV, out);
            verifyResultsLengthFloatFloat(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloatFloat: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthFloatFloat(Allocation inV, Allocation out, boolean relaxed) {
        float[] arrayInV = new float[INPUTSIZE * 1];
        Arrays.fill(arrayInV, (float) 42);
        inV.copyTo(arrayInV);
        float[] arrayOut = new float[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (float) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsFloatFloat args = new ArgumentsFloatFloat();
            // Create the appropriate sized arrays in args
            // Fill args with the input values
            args.inV = arrayInV[i];
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.FLOAT, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(arrayOut[i])) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    message.append("Input inV: ");
                    appendVariableToMessage(message, arrayInV[i]);
                    message.append("\n");
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    if (!args.out.couldBe(arrayOut[i])) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthFloatFloat" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    public class ArgumentsFloatNFloat {
        public float[] inV;
        public Target.Floaty out;
    }

    private void checkLengthFloat2Float() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_32, 2, 0xaf3b0f345dd9595dl, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            script.forEach_testLengthFloat2Float(inV, out);
            verifyResultsLengthFloat2Float(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat2Float: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthFloat2Float(inV, out);
            verifyResultsLengthFloat2Float(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat2Float: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthFloat2Float(Allocation inV, Allocation out, boolean relaxed) {
        float[] arrayInV = new float[INPUTSIZE * 2];
        Arrays.fill(arrayInV, (float) 42);
        inV.copyTo(arrayInV);
        float[] arrayOut = new float[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (float) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsFloatNFloat args = new ArgumentsFloatNFloat();
            // Create the appropriate sized arrays in args
            args.inV = new float[2];
            // Fill args with the input values
            for (int j = 0; j < 2 ; j++) {
                args.inV[j] = arrayInV[i * 2 + j];
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.FLOAT, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(arrayOut[i])) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 2 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 2 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    if (!args.out.couldBe(arrayOut[i])) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthFloat2Float" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    private void checkLengthFloat3Float() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_32, 3, 0xaf3b19d5bcdfe7bel, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            script.forEach_testLengthFloat3Float(inV, out);
            verifyResultsLengthFloat3Float(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat3Float: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthFloat3Float(inV, out);
            verifyResultsLengthFloat3Float(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat3Float: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthFloat3Float(Allocation inV, Allocation out, boolean relaxed) {
        float[] arrayInV = new float[INPUTSIZE * 4];
        Arrays.fill(arrayInV, (float) 42);
        inV.copyTo(arrayInV);
        float[] arrayOut = new float[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (float) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsFloatNFloat args = new ArgumentsFloatNFloat();
            // Create the appropriate sized arrays in args
            args.inV = new float[3];
            // Fill args with the input values
            for (int j = 0; j < 3 ; j++) {
                args.inV[j] = arrayInV[i * 4 + j];
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.FLOAT, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(arrayOut[i])) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 3 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 4 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    if (!args.out.couldBe(arrayOut[i])) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthFloat3Float" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    private void checkLengthFloat4Float() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_32, 4, 0xaf3b24771be6761fl, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            script.forEach_testLengthFloat4Float(inV, out);
            verifyResultsLengthFloat4Float(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat4Float: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_32, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthFloat4Float(inV, out);
            verifyResultsLengthFloat4Float(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthFloat4Float: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthFloat4Float(Allocation inV, Allocation out, boolean relaxed) {
        float[] arrayInV = new float[INPUTSIZE * 4];
        Arrays.fill(arrayInV, (float) 42);
        inV.copyTo(arrayInV);
        float[] arrayOut = new float[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (float) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsFloatNFloat args = new ArgumentsFloatNFloat();
            // Create the appropriate sized arrays in args
            args.inV = new float[4];
            // Fill args with the input values
            for (int j = 0; j < 4 ; j++) {
                args.inV[j] = arrayInV[i * 4 + j];
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.FLOAT, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(arrayOut[i])) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 4 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 4 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    if (!args.out.couldBe(arrayOut[i])) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthFloat4Float" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    public class ArgumentsHalfHalf {
        public short inV;
        public double inVDouble;
        public Target.Floaty out;
    }

    private void checkLengthHalfHalf() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_16, 1, 0xd70e76bc6dc47281l, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            script.forEach_testLengthHalfHalf(inV, out);
            verifyResultsLengthHalfHalf(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalfHalf: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthHalfHalf(inV, out);
            verifyResultsLengthHalfHalf(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalfHalf: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthHalfHalf(Allocation inV, Allocation out, boolean relaxed) {
        short[] arrayInV = new short[INPUTSIZE * 1];
        Arrays.fill(arrayInV, (short) 42);
        inV.copyTo(arrayInV);
        short[] arrayOut = new short[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (short) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsHalfHalf args = new ArgumentsHalfHalf();
            // Create the appropriate sized arrays in args
            // Fill args with the input values
            args.inV = arrayInV[i];
            args.inVDouble = Float16Utils.convertFloat16ToDouble(args.inV);
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.HALF, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    message.append("Input inV: ");
                    appendVariableToMessage(message, arrayInV[i]);
                    message.append("\n");
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    message.append("\n");
                    message.append("Actual   output out (in double): ");
                    appendVariableToMessage(message, Float16Utils.convertFloat16ToDouble(arrayOut[i]));
                    if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthHalfHalf" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    public class ArgumentsHalfNHalf {
        public short[] inV;
        public double[] inVDouble;
        public Target.Floaty out;
    }

    private void checkLengthHalf2Half() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_16, 2, 0x1f6dec10f0ea410dl, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            script.forEach_testLengthHalf2Half(inV, out);
            verifyResultsLengthHalf2Half(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf2Half: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthHalf2Half(inV, out);
            verifyResultsLengthHalf2Half(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf2Half: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthHalf2Half(Allocation inV, Allocation out, boolean relaxed) {
        short[] arrayInV = new short[INPUTSIZE * 2];
        Arrays.fill(arrayInV, (short) 42);
        inV.copyTo(arrayInV);
        short[] arrayOut = new short[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (short) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsHalfNHalf args = new ArgumentsHalfNHalf();
            // Create the appropriate sized arrays in args
            args.inV = new short[2];
            args.inVDouble = new double[2];
            // Fill args with the input values
            for (int j = 0; j < 2 ; j++) {
                args.inV[j] = arrayInV[i * 2 + j];
                args.inVDouble[j] = Float16Utils.convertFloat16ToDouble(args.inV[j]);
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.HALF, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 2 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 2 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    message.append("\n");
                    message.append("Actual   output out (in double): ");
                    appendVariableToMessage(message, Float16Utils.convertFloat16ToDouble(arrayOut[i]));
                    if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthHalf2Half" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    private void checkLengthHalf3Half() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_16, 3, 0x1f6dec503a911ab0l, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            script.forEach_testLengthHalf3Half(inV, out);
            verifyResultsLengthHalf3Half(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf3Half: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthHalf3Half(inV, out);
            verifyResultsLengthHalf3Half(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf3Half: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthHalf3Half(Allocation inV, Allocation out, boolean relaxed) {
        short[] arrayInV = new short[INPUTSIZE * 4];
        Arrays.fill(arrayInV, (short) 42);
        inV.copyTo(arrayInV);
        short[] arrayOut = new short[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (short) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsHalfNHalf args = new ArgumentsHalfNHalf();
            // Create the appropriate sized arrays in args
            args.inV = new short[3];
            args.inVDouble = new double[3];
            // Fill args with the input values
            for (int j = 0; j < 3 ; j++) {
                args.inV[j] = arrayInV[i * 4 + j];
                args.inVDouble[j] = Float16Utils.convertFloat16ToDouble(args.inV[j]);
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.HALF, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 3 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 4 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    message.append("\n");
                    message.append("Actual   output out (in double): ");
                    appendVariableToMessage(message, Float16Utils.convertFloat16ToDouble(arrayOut[i]));
                    if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthHalf3Half" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    private void checkLengthHalf4Half() {
        Allocation inV = createRandomAllocation(mRS, Element.DataType.FLOAT_16, 4, 0x1f6dec8f8437f453l, false);
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            script.forEach_testLengthHalf4Half(inV, out);
            verifyResultsLengthHalf4Half(inV, out, false);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf4Half: " + e.toString());
        }
        try {
            Allocation out = Allocation.createSized(mRS, getElement(mRS, Element.DataType.FLOAT_16, 1), INPUTSIZE);
            scriptRelaxed.forEach_testLengthHalf4Half(inV, out);
            verifyResultsLengthHalf4Half(inV, out, true);
            out.destroy();
        } catch (Exception e) {
            throw new RSRuntimeException("RenderScript. Can't invoke forEach_testLengthHalf4Half: " + e.toString());
        }
        inV.destroy();
    }

    private void verifyResultsLengthHalf4Half(Allocation inV, Allocation out, boolean relaxed) {
        short[] arrayInV = new short[INPUTSIZE * 4];
        Arrays.fill(arrayInV, (short) 42);
        inV.copyTo(arrayInV);
        short[] arrayOut = new short[INPUTSIZE * 1];
        Arrays.fill(arrayOut, (short) 42);
        out.copyTo(arrayOut);
        StringBuilder message = new StringBuilder();
        boolean errorFound = false;
        for (int i = 0; i < INPUTSIZE; i++) {
            ArgumentsHalfNHalf args = new ArgumentsHalfNHalf();
            // Create the appropriate sized arrays in args
            args.inV = new short[4];
            args.inVDouble = new double[4];
            // Fill args with the input values
            for (int j = 0; j < 4 ; j++) {
                args.inV[j] = arrayInV[i * 4 + j];
                args.inVDouble[j] = Float16Utils.convertFloat16ToDouble(args.inV[j]);
            }
            Target target = new Target(Target.FunctionType.NORMAL, Target.ReturnType.HALF, relaxed);
            CoreMathVerifier.computeLength(args, target);

            // Compare the expected outputs to the actual values returned by RS.
            boolean valid = true;
            if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                valid = false;
            }
            if (!valid) {
                if (!errorFound) {
                    errorFound = true;
                    for (int j = 0; j < 4 ; j++) {
                        message.append("Input inV: ");
                        appendVariableToMessage(message, arrayInV[i * 4 + j]);
                        message.append("\n");
                    }
                    message.append("Expected output out: ");
                    appendVariableToMessage(message, args.out);
                    message.append("\n");
                    message.append("Actual   output out: ");
                    appendVariableToMessage(message, arrayOut[i]);
                    message.append("\n");
                    message.append("Actual   output out (in double): ");
                    appendVariableToMessage(message, Float16Utils.convertFloat16ToDouble(arrayOut[i]));
                    if (!args.out.couldBe(Float16Utils.convertFloat16ToDouble(arrayOut[i]))) {
                        message.append(" FAIL");
                    }
                    message.append("\n");
                    message.append("Errors at");
                }
                message.append(" [");
                message.append(Integer.toString(i));
                message.append("]");
            }
        }
        assertFalse("Incorrect output for checkLengthHalf4Half" +
                (relaxed ? "_relaxed" : "") + ":\n" + message.toString(), errorFound);
    }

    public void testLength() {
        checkLengthFloatFloat();
        checkLengthFloat2Float();
        checkLengthFloat3Float();
        checkLengthFloat4Float();
        checkLengthHalfHalf();
        checkLengthHalf2Half();
        checkLengthHalf3Half();
        checkLengthHalf4Half();
    }
}
