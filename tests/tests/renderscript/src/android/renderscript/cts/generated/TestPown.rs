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

#pragma version(1)
#pragma rs java_package_name(android.renderscript.cts)

rs_allocation gAllocInExponent;

float __attribute__((kernel)) testPownFloatIntFloat(float inBase, unsigned int x) {
    int inExponent = rsGetElementAt_int(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

float2 __attribute__((kernel)) testPownFloat2Int2Float2(float2 inBase, unsigned int x) {
    int2 inExponent = rsGetElementAt_int2(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

float3 __attribute__((kernel)) testPownFloat3Int3Float3(float3 inBase, unsigned int x) {
    int3 inExponent = rsGetElementAt_int3(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

float4 __attribute__((kernel)) testPownFloat4Int4Float4(float4 inBase, unsigned int x) {
    int4 inExponent = rsGetElementAt_int4(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

half __attribute__((kernel)) testPownHalfIntHalf(half inBase, unsigned int x) {
    int inExponent = rsGetElementAt_int(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

half2 __attribute__((kernel)) testPownHalf2Int2Half2(half2 inBase, unsigned int x) {
    int2 inExponent = rsGetElementAt_int2(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

half3 __attribute__((kernel)) testPownHalf3Int3Half3(half3 inBase, unsigned int x) {
    int3 inExponent = rsGetElementAt_int3(gAllocInExponent, x);
    return pown(inBase, inExponent);
}

half4 __attribute__((kernel)) testPownHalf4Int4Half4(half4 inBase, unsigned int x) {
    int4 inExponent = rsGetElementAt_int4(gAllocInExponent, x);
    return pown(inBase, inExponent);
}
