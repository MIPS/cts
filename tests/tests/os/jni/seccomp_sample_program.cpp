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

#include <linux/filter.h>

// This file defines a sample seccomp-bpf policy. It is taken from the
// Chromium renderer process policy applied to isolatedProcess services.
//
// In the future, this policy should be further restricted to just the set
// of system calls that an isolatedProcess should be allowed to make.

#if defined(__arm__)
struct sock_filter kTestSeccompFilter[] = {
  {0x20, 0, 0, 0x4},
  {0x15, 1, 0, 0x40000028},
  {0x6, 0, 0, 0x30006},
  {0x20, 0, 0, 0x0},
  {0x35, 0, 90, 0xab},
  {0x35, 0, 43, 0x108},
  {0x35, 0, 21, 0x14f},
  {0x35, 0, 10, 0x168},
  {0x35, 0, 5, 0x181},
  {0x35, 0, 2, 0xf0006},
  {0x35, 0, 58, 0xffff0},
  {0x35, 57, 55, 0xffff1},
  {0x35, 0, 43, 0x182},
  {0x35, 53, 55, 0xf0001},
  {0x35, 0, 2, 0x16f},
  {0x35, 0, 53, 0x17e},
  {0x35, 52, 39, 0x180},
  {0x35, 38, 51, 0x16e},
  {0x35, 0, 5, 0x15b},
  {0x35, 0, 2, 0x160},
  {0x35, 0, 35, 0x161},
  {0x35, 45, 47, 0x165},
  {0x35, 0, 46, 0x15c},
  {0x35, 45, 32, 0x15d},
  {0x35, 0, 2, 0x152},
  {0x35, 0, 30, 0x153},
  {0x35, 40, 42, 0x15a},
  {0x35, 41, 39, 0x151},
  {0x35, 0, 10, 0x121},
  {0x35, 0, 5, 0x138},
  {0x35, 0, 2, 0x143},
  {0x35, 0, 24, 0x147},
  {0x35, 23, 34, 0x148},
  {0x35, 0, 22, 0x139},
  {0x35, 32, 34, 0x142},
  {0x35, 0, 2, 0x127},
  {0x35, 0, 30, 0x12a},
  {0x35, 31, 18, 0x135},
  {0x35, 30, 28, 0x126},
  {0x35, 0, 4, 0x10e},
  {0x35, 0, 2, 0x119},
  {0x35, 0, 14, 0x11e},
  {0x35, 137, 26, 0x120},
  {0x35, 23, 25, 0x118},
  {0x35, 0, 3, 0x10b},
  {0x35, 0, 23, 0x10c},
  {0x35, 9, 0, 0x10d},
  {0x5, 0, 0, 0x110},
  {0x35, 7, 20, 0x10a},
  {0x35, 0, 25, 0xce},
  {0x35, 0, 12, 0xee},
  {0x35, 0, 6, 0xf9},
  {0x35, 0, 2, 0x100},
  {0x35, 0, 13, 0x101},
  {0x35, 129, 14, 0x107},
  {0x35, 1, 0, 0xfa},
  {0x5, 0, 0, 0x10d},
  {0x35, 11, 9, 0xfd},
  {0x35, 0, 2, 0xf0},
  {0x35, 0, 148, 0xf1},
  {0x35, 6, 8, 0xf8},
  {0x35, 7, 0, 0xef},
  {0x5, 0, 0, 0x106},
  {0x35, 0, 7, 0xda},
  {0x35, 0, 3, 0xde},
  {0x35, 0, 3, 0xe0},
  {0x35, 2, 0, 0xe1},
  {0x5, 0, 0, 0x103},
  {0x35, 1, 0, 0xdc},
  {0x5, 0, 0, 0x102},
  {0x35, 209, 172, 0xdd},
  {0x35, 0, 2, 0xd2},
  {0x35, 0, 253, 0xd3},
  {0x35, 252, 253, 0xd4},
  {0x35, 252, 251, 0xd1},
  {0x35, 0, 10, 0xb9},
  {0x35, 0, 5, 0xc1},
  {0x35, 0, 2, 0xc7},
  {0x35, 0, 248, 0xcb},
  {0x35, 247, 246, 0xcd},
  {0x35, 0, 245, 0xc5},
  {0x35, 244, 245, 0xc6},
  {0x35, 0, 2, 0xbb},
  {0x35, 0, 244, 0xbf},
  {0x35, 162, 242, 0xc0},
  {0x35, 241, 240, 0xba},
  {0x35, 0, 4, 0xb2},
  {0x35, 0, 2, 0xb5},
  {0x35, 0, 239, 0xb6},
  {0x35, 237, 236, 0xb8},
  {0x35, 236, 237, 0xb4},
  {0x35, 0, 2, 0xad},
  {0x35, 0, 234, 0xb0},
  {0x35, 233, 234, 0xb1},
  {0x35, 156, 232, 0xac},
  {0x35, 0, 42, 0x52},
  {0x35, 0, 21, 0x7e},
  {0x35, 0, 10, 0x96},
  {0x35, 0, 5, 0xa4},
  {0x35, 0, 2, 0xa8},
  {0x35, 0, 226, 0xa9},
  {0x35, 224, 226, 0xaa},
  {0x35, 0, 223, 0xa5},
  {0x35, 224, 223, 0xa6},
  {0x35, 0, 2, 0x9e},
  {0x35, 0, 221, 0x9f},
  {0x35, 220, 221, 0xa2},
  {0x35, 220, 219, 0x98},
  {0x35, 0, 5, 0x8c},
  {0x35, 0, 2, 0x90},
  {0x35, 0, 217, 0x91},
  {0x35, 216, 215, 0x94},
  {0x35, 0, 214, 0x8d},
  {0x35, 213, 212, 0x8e},
  {0x35, 0, 2, 0x85},
  {0x35, 0, 210, 0x86},
  {0x35, 209, 211, 0x8a},
  {0x35, 210, 209, 0x7f},
  {0x35, 0, 10, 0x64},
  {0x35, 0, 5, 0x73},
  {0x35, 0, 2, 0x7a},
  {0x35, 0, 205, 0x7b},
  {0x35, 153, 205, 0x7d},
  {0x35, 0, 204, 0x77},
  {0x35, 203, 202, 0x79},
  {0x35, 0, 2, 0x6c},
  {0x35, 0, 200, 0x6d},
  {0x35, 199, 200, 0x72},
  {0x35, 197, 199, 0x6a},
  {0x35, 0, 4, 0x5b},
  {0x35, 0, 2, 0x60},
  {0x35, 0, 195, 0x62},
  {0x35, 193, 195, 0x63},
  {0x35, 192, 193, 0x5c},
  {0x35, 0, 2, 0x54},
  {0x35, 0, 192, 0x55},
  {0x35, 191, 189, 0x57},
  {0x35, 188, 190, 0x53},
  {0x35, 0, 21, 0x2d},
  {0x35, 0, 10, 0x3e},
  {0x35, 0, 5, 0x46},
  {0x35, 0, 2, 0x4f},
  {0x35, 0, 185, 0x50},
  {0x35, 182, 183, 0x51},
  {0x35, 0, 181, 0x48},
  {0x35, 181, 182, 0x4e},
  {0x35, 0, 2, 0x41},
  {0x35, 0, 180, 0x43},
  {0x35, 179, 178, 0x44},
  {0x35, 177, 176, 0x3f},
  {0x35, 0, 5, 0x33},
  {0x35, 0, 2, 0x38},
  {0x35, 0, 175, 0x3c},
  {0x35, 174, 172, 0x3d},
  {0x35, 0, 173, 0x36},
  {0x35, 124, 171, 0x37},
  {0x35, 0, 2, 0x2f},
  {0x35, 0, 169, 0x30},
  {0x35, 168, 169, 0x31},
  {0x35, 166, 167, 0x2e},
  {0x35, 0, 10, 0x17},
  {0x35, 0, 5, 0x21},
  {0x35, 0, 2, 0x26},
  {0x35, 0, 162, 0x29},
  {0x35, 163, 162, 0x2b},
  {0x35, 0, 160, 0x22},
  {0x35, 153, 161, 0x25},
  {0x35, 0, 2, 0x19},
  {0x35, 0, 159, 0x1d},
  {0x35, 158, 157, 0x1e},
  {0x35, 156, 155, 0x18},
  {0x35, 0, 4, 0xd},
  {0x35, 0, 2, 0x11},
  {0x35, 0, 154, 0x13},
  {0x35, 153, 152, 0x15},
  {0x35, 150, 152, 0xe},
  {0x35, 0, 2, 0x3},
  {0x35, 0, 149, 0x7},
  {0x35, 147, 149, 0x8},
  {0x35, 146, 147, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 140, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 143, 144, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 136, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 139, 0, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 132, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 135, 0, 0x6},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 128, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 131, 0, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 124, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 127, 0, 0x0},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 120, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 123, 0, 0x5},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 116, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 119, 120, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 112, 0x0},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 115, 0xfffffe7f},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 108, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 110, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 103, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 105, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 98, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 100, 0, 0x4},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 93, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 95, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 88, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 90, 0, 0x9},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 83, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 85, 0, 0xa},
  {0x6, 0, 0, 0x30005},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 77, 0x0},
  {0x20, 0, 0, 0x20},
  {0x15, 80, 79, 0x4},
  {0x20, 0, 0, 0x2c},
  {0x15, 0, 73, 0x0},
  {0x20, 0, 0, 0x28},
  {0x45, 77, 76, 0xfffdb7cc},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 69, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 72, 0, 0x10},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 65, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 68, 0, 0xf},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 61, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 64, 0, 0x3},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 57, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 60, 0, 0x4},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 53, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 56, 0, 0x53564d41},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 49, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 52, 0, 0x29},
  {0x6, 0, 0, 0x30004},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 44, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 48, 47, 0xfffffff8},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 40, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 43, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 36, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 39, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 32, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 35, 0, 0x2},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 28, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 31, 0, 0x6},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 24, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 27, 0, 0x7},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 20, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 23, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 16, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 19, 0, 0x0},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 12, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 15, 0, 0x406},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 8, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 0, 12, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 4, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 8, 7, 0xfff1e3fc},
  {0x20, 0, 0, 0x14},
  {0x15, 1, 0, 0x0},
  {0x6, 0, 0, 0x30003},
  {0x20, 0, 0, 0x10},
  {0x15, 2, 0, 0x2da4},
  {0x6, 0, 0, 0x30002},
  {0x6, 0, 0, 0x50001},
  {0x6, 0, 0, 0x7fff0000},
  {0x6, 0, 0, 0x30001},
};
#elif defined(__aarch64__)
struct sock_filter kTestSeccompFilter[] = {
  {0x20, 0, 0, 0x4},
  {0x15, 1, 0, 0xc00000b7},
  {0x6, 0, 0, 0x30006},
  {0x20, 0, 0, 0x0},
  {0x35, 0, 51, 0x88},
  {0x35, 0, 25, 0xba},
  {0x35, 0, 12, 0xdf},
  {0x35, 0, 6, 0xea},
  {0x35, 0, 3, 0x104},
  {0x35, 0, 1, 0x114},
  {0x35, 86, 85, 0x116},
  {0x35, 85, 81, 0x105},
  {0x35, 0, 84, 0xf2},
  {0x35, 83, 82, 0xf3},
  {0x35, 0, 2, 0xe4},
  {0x35, 0, 77, 0xe6},
  {0x35, 92, 80, 0xe9},
  {0x35, 0, 79, 0xe2},
  {0x35, 78, 97, 0xe3},
  {0x35, 0, 6, 0xd1},
  {0x35, 0, 3, 0xd9},
  {0x35, 0, 1, 0xdd},
  {0x35, 100, 73, 0xde},
  {0x35, 69, 73, 0xdc},
  {0x35, 0, 68, 0xd5},
  {0x35, 67, 71, 0xd6},
  {0x35, 0, 2, 0xcc},
  {0x35, 0, 69, 0xce},
  {0x35, 68, 64, 0xd0},
  {0x35, 0, 66, 0xc7},
  {0x35, 65, 99, 0xc8},
  {0x35, 0, 12, 0x9e},
  {0x35, 0, 6, 0xa6},
  {0x35, 0, 3, 0xa9},
  {0x35, 0, 1, 0xac},
  {0x35, 61, 57, 0xb3},
  {0x35, 60, 56, 0xaa},
  {0x35, 0, 58, 0xa7},
  {0x35, 58, 98, 0xa8},
  {0x35, 0, 2, 0xa1},
  {0x35, 0, 56, 0xa3},
  {0x35, 55, 51, 0xa4},
  {0x35, 0, 50, 0x9f},
  {0x35, 49, 52, 0xa0},
  {0x35, 0, 6, 0x94},
  {0x35, 0, 3, 0x97},
  {0x35, 0, 1, 0x9c},
  {0x35, 49, 45, 0x9d},
  {0x35, 48, 47, 0x99},
  {0x35, 0, 43, 0x95},
  {0x35, 42, 45, 0x96},
  {0x35, 0, 2, 0x8b},
  {0x35, 0, 40, 0x8e},
  {0x35, 42, 43, 0x8f},
  {0x35, 0, 42, 0x89},
  {0x35, 41, 37, 0x8a},
  {0x35, 0, 25, 0x4e},
  {0x35, 0, 12, 0x65},
  {0x35, 0, 6, 0x80},
  {0x35, 0, 3, 0x83},
  {0x35, 0, 1, 0x85},
  {0x35, 31, 35, 0x86},
  {0x35, 30, 117, 0x84},
  {0x35, 0, 29, 0x81},
  {0x35, 122, 115, 0x82},
  {0x35, 0, 2, 0x72},
  {0x35, 0, 30, 0x7c},
  {0x35, 29, 25, 0x7d},
  {0x35, 0, 24, 0x66},
  {0x35, 118, 27, 0x71},
  {0x35, 0, 6, 0x5b},
  {0x35, 0, 3, 0x61},
  {0x35, 0, 1, 0x63},
  {0x35, 23, 22, 0x64},
  {0x35, 155, 22, 0x62},
  {0x35, 0, 20, 0x5c},
  {0x35, 16, 20, 0x5d},
  {0x35, 0, 2, 0x58},
  {0x35, 0, 17, 0x59},
  {0x35, 13, 17, 0x5a},
  {0x35, 0, 15, 0x4f},
  {0x35, 15, 11, 0x51},
  {0x35, 0, 15, 0x2c},
  {0x35, 0, 6, 0x3b},
  {0x35, 0, 3, 0x3e},
  {0x35, 0, 1, 0x48},
  {0x35, 10, 6, 0x4a},
  {0x35, 9, 5, 0x44},
  {0x35, 0, 4, 0x3c},
  {0x35, 6, 7, 0x3d},
  {0x35, 0, 3, 0x34},
  {0x35, 0, 4, 0x38},
  {0x35, 4, 0, 0x3a},
  {0x5, 0, 0, 0x104},
  {0x35, 0, 2, 0x2d},
  {0x35, 1, 0, 0x33},
  {0x5, 0, 0, 0x102},
  {0x5, 0, 0, 0x102},
  {0x35, 0, 5, 0x1d},
  {0x35, 0, 2, 0x21},
  {0x35, 0, 254, 0x27},
  {0x35, 253, 254, 0x2b},
  {0x35, 0, 251, 0x1e},
  {0x35, 250, 252, 0x20},
  {0x35, 0, 2, 0x14},
  {0x35, 0, 248, 0x19},
  {0x35, 249, 179, 0x1a},
  {0x35, 0, 248, 0x11},
  {0x35, 247, 246, 0x13},
  {0x20, 0, 0, 0x24},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 235, 0xffffffff},
  {0x20, 0, 0, 0x20},
  {0x45, 0, 233, 0x80000000},
  {0x20, 0, 0, 0x20},
  {0x15, 238, 239, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 228, 0xffffffff},
  {0x20, 0, 0, 0x20},
  {0x45, 0, 226, 0x80000000},
  {0x20, 0, 0, 0x20},
  {0x45, 233, 231, 0xfffffff8},
  {0x20, 0, 0, 0x2c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 221, 0xffffffff},
  {0x20, 0, 0, 0x28},
  {0x45, 0, 219, 0x80000000},
  {0x20, 0, 0, 0x28},
  {0x45, 226, 224, 0xfffdb7cc},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 214, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 212, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 217, 219, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 207, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 205, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 210, 0, 0x10},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 200, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 198, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 203, 0, 0xf},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 193, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 191, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 196, 0, 0x3},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 186, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 184, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 189, 0, 0x4},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 179, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 177, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 182, 0, 0x53564d41},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 172, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 170, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 175, 0, 0x29},
  {0x6, 0, 0, 0x30005},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 164, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 162, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 167, 0, 0x1393},
  {0x6, 0, 0, 0x30004},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 156, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 154, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 159, 0, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 149, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 147, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 152, 0, 0x6},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 142, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 140, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 145, 0, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 135, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 133, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 138, 0, 0x0},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 128, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 126, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 131, 0, 0x5},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 121, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 119, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 124, 126, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 114, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 112, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 117, 0xfffffe7f},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 107, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 105, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 109, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 99, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 97, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 101, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 91, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 89, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 93, 0, 0x4},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 83, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 81, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 85, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 75, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 73, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 77, 0, 0x9},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 67, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 65, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 69, 0, 0xa},
  {0x6, 0, 0, 0x30003},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 58, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 56, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 61, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 51, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 49, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 54, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 44, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 42, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 47, 0, 0x2},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 37, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 35, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 40, 0, 0x6},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 30, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 28, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 33, 0, 0x7},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 23, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 21, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 26, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 16, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 14, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 19, 0, 0x0},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 9, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 7, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 12, 0, 0x406},
  {0x20, 0, 0, 0x1c},
  {0x15, 4, 0, 0x0},
  {0x15, 0, 2, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 1, 0, 0x80000000},
  {0x6, 0, 0, 0x30002},
  {0x20, 0, 0, 0x18},
  {0x15, 0, 6, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 4, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 2, 0, 0xffe1e3fc},
  {0x6, 0, 0, 0x7fff0000},
  {0x6, 0, 0, 0x50001},
  {0x6, 0, 0, 0x30001},
};
#elif defined(__i386__)
struct sock_filter kTestSeccompFilter[] = {
  {0x20, 0, 0, 0x4},
  {0x15, 1, 0, 0x40000003},
  {0x6, 0, 0, 0x30007},
  {0x20, 0, 0, 0x0},
  {0x45, 0, 1, 0x40000000},
  {0x6, 0, 0, 0x30006},
  {0x35, 0, 87, 0x94},
  {0x35, 0, 43, 0xdd},
  {0x35, 0, 20, 0x11c},
  {0x35, 0, 10, 0x13f},
  {0x35, 0, 5, 0x149},
  {0x35, 0, 2, 0x163},
  {0x35, 0, 79, 0x164},
  {0x35, 78, 73, 0x165},
  {0x35, 0, 78, 0x14c},
  {0x35, 71, 76, 0x161},
  {0x35, 0, 2, 0x141},
  {0x35, 0, 74, 0x144},
  {0x35, 73, 68, 0x145},
  {0x35, 67, 73, 0x140},
  {0x35, 0, 4, 0x12d},
  {0x35, 0, 2, 0x136},
  {0x35, 0, 69, 0x137},
  {0x35, 68, 63, 0x138},
  {0x35, 68, 62, 0x134},
  {0x35, 0, 2, 0x127},
  {0x35, 0, 66, 0x128},
  {0x35, 65, 59, 0x12c},
  {0x35, 63, 64, 0x11d},
  {0x35, 0, 11, 0xfe},
  {0x35, 0, 6, 0x10a},
  {0x35, 0, 3, 0x10e},
  {0x35, 1, 0, 0x10f},
  {0x5, 0, 0, 0x135},
  {0x35, 57, 52, 0x110},
  {0x35, 0, 56, 0x10c},
  {0x35, 55, 50, 0x10d},
  {0x35, 0, 2, 0x102},
  {0x35, 0, 54, 0x103},
  {0x35, 135, 52, 0x109},
  {0x35, 51, 52, 0x101},
  {0x35, 0, 4, 0xef},
  {0x35, 0, 2, 0xf1},
  {0x35, 0, 48, 0xfc},
  {0x35, 42, 48, 0xfd},
  {0x35, 153, 46, 0xf0},
  {0x35, 0, 3, 0xe0},
  {0x35, 0, 45, 0xe1},
  {0x35, 0, 43, 0xee},
  {0x5, 0, 0, 0x12a},
  {0x35, 41, 252, 0xde},
  {0x35, 0, 20, 0xb6},
  {0x35, 0, 10, 0xc7},
  {0x35, 0, 5, 0xd2},
  {0x35, 0, 2, 0xd9},
  {0x35, 0, 36, 0xdb},
  {0x35, 30, 177, 0xdc},
  {0x35, 0, 29, 0xd3},
  {0x35, 28, 34, 0xd4},
  {0x35, 0, 2, 0xcd},
  {0x35, 0, 32, 0xce},
  {0x35, 31, 25, 0xd1},
  {0x35, 24, 30, 0xcb},
  {0x35, 0, 4, 0xbf},
  {0x35, 0, 2, 0xc1},
  {0x35, 0, 21, 0xc5},
  {0x35, 20, 26, 0xc6},
  {0x35, 231, 25, 0xc0},
  {0x35, 0, 2, 0xb9},
  {0x35, 0, 17, 0xba},
  {0x35, 21, 22, 0xbb},
  {0x35, 21, 15, 0xb8},
  {0x35, 0, 9, 0xa9},
  {0x35, 0, 4, 0xb0},
  {0x35, 0, 2, 0xb2},
  {0x35, 0, 16, 0xb4},
  {0x35, 15, 16, 0xb5},
  {0x35, 15, 14, 0xb1},
  {0x35, 0, 2, 0xab},
  {0x35, 0, 13, 0xac},
  {0x35, 12, 157, 0xad},
  {0x35, 5, 10, 0xaa},
  {0x35, 0, 5, 0xa2},
  {0x35, 0, 2, 0xa5},
  {0x35, 0, 8, 0xa6},
  {0x35, 7, 6, 0xa8},
  {0x35, 0, 6, 0xa4},
  {0x5, 0, 0, 0x105},
  {0x35, 0, 2, 0x98},
  {0x35, 0, 2, 0x9e},
  {0x35, 1, 2, 0x9f},
  {0x35, 1, 0, 0x96},
  {0x5, 0, 0, 0x102},
  {0x5, 0, 0, 0x100},
  {0x35, 0, 40, 0x4f},
  {0x35, 0, 20, 0x6e},
  {0x35, 0, 10, 0x7d},
  {0x35, 0, 5, 0x8a},
  {0x35, 0, 2, 0x8e},
  {0x35, 0, 250, 0x90},
  {0x35, 249, 250, 0x91},
  {0x35, 0, 247, 0x8c},
  {0x35, 246, 247, 0x8d},
  {0x35, 0, 2, 0x7f},
  {0x35, 0, 246, 0x85},
  {0x35, 245, 243, 0x86},
  {0x35, 243, 156, 0x7e},
  {0x35, 0, 4, 0x76},
  {0x35, 0, 2, 0x79},
  {0x35, 0, 241, 0x7a},
  {0x35, 240, 239, 0x7b},
  {0x35, 238, 239, 0x77},
  {0x35, 0, 2, 0x72},
  {0x35, 0, 236, 0x73},
  {0x35, 234, 236, 0x75},
  {0x35, 235, 233, 0x6f},
  {0x35, 0, 9, 0x60},
  {0x35, 0, 4, 0x66},
  {0x35, 0, 2, 0x6a},
  {0x35, 0, 229, 0x6c},
  {0x35, 230, 229, 0x6d},
  {0x35, 229, 145, 0x67},
  {0x35, 0, 2, 0x63},
  {0x35, 0, 225, 0x64},
  {0x35, 224, 226, 0x65},
  {0x35, 225, 224, 0x62},
  {0x35, 0, 4, 0x57},
  {0x35, 0, 2, 0x5a},
  {0x35, 0, 170, 0x5b},
  {0x35, 219, 220, 0x5c},
  {0x35, 218, 220, 0x59},
  {0x35, 0, 2, 0x51},
  {0x35, 0, 216, 0x52},
  {0x35, 215, 216, 0x53},
  {0x35, 215, 216, 0x50},
  {0x35, 0, 20, 0x29},
  {0x35, 0, 10, 0x38},
  {0x35, 0, 5, 0x41},
  {0x35, 0, 2, 0x46},
  {0x35, 0, 209, 0x48},
  {0x35, 209, 210, 0x4e},
  {0x35, 0, 209, 0x43},
  {0x35, 208, 207, 0x44},
  {0x35, 0, 2, 0x3d},
  {0x35, 0, 206, 0x3e},
  {0x35, 204, 203, 0x3f},
  {0x35, 202, 204, 0x3c},
  {0x35, 0, 4, 0x30},
  {0x35, 0, 2, 0x33},
  {0x35, 0, 201, 0x36},
  {0x35, 152, 199, 0x37},
  {0x35, 198, 199, 0x31},
  {0x35, 0, 2, 0x2d},
  {0x35, 0, 196, 0x2e},
  {0x35, 195, 194, 0x2f},
  {0x35, 195, 194, 0x2b},
  {0x35, 0, 9, 0x17},
  {0x35, 0, 4, 0x1f},
  {0x35, 0, 2, 0x22},
  {0x35, 0, 191, 0x25},
  {0x35, 188, 182, 0x26},
  {0x35, 187, 189, 0x21},
  {0x35, 0, 2, 0x19},
  {0x35, 0, 187, 0x1d},
  {0x35, 184, 185, 0x1e},
  {0x35, 184, 183, 0x18},
  {0x35, 0, 4, 0xe},
  {0x35, 0, 2, 0x12},
  {0x35, 0, 180, 0x13},
  {0x35, 181, 180, 0x15},
  {0x35, 180, 178, 0x11},
  {0x35, 0, 2, 0x3},
  {0x35, 0, 177, 0x8},
  {0x35, 176, 175, 0xd},
  {0x35, 174, 175, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 168, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 171, 0, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 164, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 167, 0, 0x6},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 160, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 163, 0, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 156, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 159, 0, 0x0},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 152, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 155, 0, 0x5},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 148, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 151, 152, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 144, 0x0},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 147, 0xfffffe7f},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 140, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 142, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 135, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 137, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 130, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 132, 0, 0x4},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 125, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 127, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 120, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 122, 0, 0x9},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 115, 0x0},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 117, 0, 0xa},
  {0x6, 0, 0, 0x30005},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 109, 0x0},
  {0x20, 0, 0, 0x20},
  {0x15, 112, 111, 0x4},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 105, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 108, 0, 0x10},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 101, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 104, 0, 0xf},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 97, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 100, 0, 0x3},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 93, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 96, 0, 0x4},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 89, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 92, 0, 0x53564d41},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 85, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 88, 0, 0x29},
  {0x6, 0, 0, 0x30004},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 80, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 84, 83, 0xfffffff8},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 76, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 79, 0, 0x8},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 72, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 75, 0, 0xd},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 68, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 71, 0, 0xa},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 64, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 67, 0, 0x9},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 60, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 63, 0, 0xc},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 56, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 59, 0, 0xb},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 52, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 55, 0, 0x11},
  {0x20, 0, 0, 0x14},
  {0x15, 0, 48, 0x0},
  {0x20, 0, 0, 0x10},
  {0x15, 51, 50, 0x10},
  {0x20, 0, 0, 0x2c},
  {0x15, 0, 44, 0x0},
  {0x20, 0, 0, 0x28},
  {0x45, 48, 47, 0xfffdb7cc},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 40, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 43, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 36, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 39, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 32, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 35, 0, 0x2},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 28, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 31, 0, 0x6},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 24, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 27, 0, 0x7},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 20, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 23, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 16, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 19, 0, 0x0},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 12, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 15, 0, 0x406},
  {0x20, 0, 0, 0x1c},
  {0x15, 0, 8, 0x0},
  {0x20, 0, 0, 0x18},
  {0x15, 0, 12, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 4, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 8, 7, 0xfff363fc},
  {0x20, 0, 0, 0x14},
  {0x15, 1, 0, 0x0},
  {0x6, 0, 0, 0x30003},
  {0x20, 0, 0, 0x10},
  {0x15, 2, 0, 0x9d0},
  {0x6, 0, 0, 0x30002},
  {0x6, 0, 0, 0x50001},
  {0x6, 0, 0, 0x7fff0000},
  {0x6, 0, 0, 0x30001},
};
#elif defined(__x86_64__)
struct sock_filter kTestSeccompFilter[] = {
  {0x20, 0, 0, 0x4},
  {0x15, 1, 0, 0xc000003e},
  {0x6, 0, 0, 0x30007},
  {0x20, 0, 0, 0x0},
  {0x45, 0, 1, 0x40000000},
  {0x6, 0, 0, 0x30006},
  {0x35, 0, 59, 0x7f},
  {0x35, 0, 29, 0xe4},
  {0x35, 0, 14, 0x111},
  {0x35, 0, 7, 0x120},
  {0x35, 0, 3, 0x13c},
  {0x35, 0, 1, 0x13f},
  {0x35, 102, 95, 0x140},
  {0x35, 101, 94, 0x13e},
  {0x35, 0, 1, 0x123},
  {0x35, 99, 94, 0x126},
  {0x35, 98, 91, 0x121},
  {0x35, 0, 3, 0x119},
  {0x35, 0, 1, 0x11d},
  {0x35, 95, 88, 0x11e},
  {0x35, 94, 89, 0x11a},
  {0x35, 0, 86, 0x112},
  {0x35, 85, 92, 0x118},
  {0x35, 0, 6, 0xf8},
  {0x35, 0, 3, 0x106},
  {0x35, 0, 1, 0x10e},
  {0x35, 88, 83, 0x110},
  {0x35, 80, 82, 0x107},
  {0x35, 0, 86, 0x101},
  {0x35, 78, 80, 0x102},
  {0x35, 0, 4, 0xea},
  {0x35, 0, 1, 0xec},
  {0x35, 77, 82, 0xf7},
  {0x35, 74, 0, 0xeb},
  {0x5, 0, 0, 0x12a},
  {0x35, 0, 89, 0xe5},
  {0x35, 73, 78, 0xe7},
  {0x35, 0, 15, 0xac},
  {0x35, 0, 7, 0xcb},
  {0x35, 0, 3, 0xd9},
  {0x35, 0, 1, 0xdc},
  {0x35, 73, 66, 0xdd},
  {0x35, 67, 65, 0xda},
  {0x35, 0, 1, 0xd5},
  {0x35, 70, 65, 0xd6},
  {0x35, 62, 69, 0xd4},
  {0x35, 0, 4, 0xbb},
  {0x35, 0, 1, 0xc9},
  {0x35, 118, 61, 0xca},
  {0x35, 0, 65, 0xc8},
  {0x5, 0, 0, 0x121},
  {0x35, 0, 56, 0xae},
  {0x35, 57, 62, 0xba},
  {0x35, 0, 6, 0x8a},
  {0x35, 0, 3, 0x95},
  {0x35, 0, 1, 0x9d},
  {0x35, 58, 166, 0x9e},
  {0x35, 57, 52, 0x97},
  {0x35, 0, 56, 0x8c},
  {0x35, 55, 50, 0x8e},
  {0x35, 0, 3, 0x83},
  {0x35, 0, 1, 0x87},
  {0x35, 45, 52, 0x88},
  {0x35, 44, 46, 0x84},
  {0x35, 0, 50, 0x80},
  {0x35, 49, 44, 0x81},
  {0x35, 0, 28, 0x3b},
  {0x35, 0, 14, 0x69},
  {0x35, 0, 7, 0x74},
  {0x35, 0, 3, 0x79},
  {0x35, 0, 1, 0x7c},
  {0x35, 36, 38, 0x7e},
  {0x35, 35, 42, 0x7a},
  {0x35, 0, 1, 0x77},
  {0x35, 35, 33, 0x78},
  {0x35, 34, 32, 0x76},
  {0x35, 0, 3, 0x6e},
  {0x35, 0, 1, 0x71},
  {0x35, 31, 29, 0x73},
  {0x35, 35, 30, 0x6f},
  {0x35, 0, 27, 0x6b},
  {0x35, 33, 28, 0x6d},
  {0x35, 0, 6, 0x4a},
  {0x35, 0, 3, 0x62},
  {0x35, 0, 1, 0x67},
  {0x35, 24, 29, 0x68},
  {0x35, 23, 28, 0x66},
  {0x35, 0, 27, 0x4c},
  {0x35, 21, 19, 0x60},
  {0x35, 0, 3, 0x3f},
  {0x35, 0, 1, 0x48},
  {0x35, 18, 174, 0x49},
  {0x35, 15, 17, 0x40},
  {0x35, 0, 14, 0x3c},
  {0x35, 238, 15, 0x3e},
  {0x35, 0, 15, 0x1d},
  {0x35, 0, 6, 0x31},
  {0x35, 0, 3, 0x36},
  {0x35, 0, 1, 0x39},
  {0x35, 15, 8, 0x3a},
  {0x35, 9, 14, 0x37},
  {0x35, 0, 6, 0x33},
  {0x35, 238, 12, 0x35},
  {0x35, 0, 3, 0x27},
  {0x35, 0, 1, 0x29},
  {0x35, 4, 2, 0x2c},
  {0x35, 8, 3, 0x28},
  {0x35, 1, 0, 0x20},
  {0x5, 0, 0, 0x105},
  {0x35, 5, 0, 0x24},
  {0x5, 0, 0, 0x104},
  {0x35, 0, 7, 0xb},
  {0x35, 0, 4, 0x15},
  {0x35, 0, 2, 0x1a},
  {0x35, 233, 0, 0x1c},
  {0x5, 0, 0, 0x100},
  {0x35, 254, 253, 0x16},
  {0x35, 0, 253, 0x12},
  {0x35, 252, 253, 0x13},
  {0x35, 0, 3, 0x6},
  {0x35, 0, 1, 0x9},
  {0x35, 233, 240, 0xa},
  {0x35, 248, 247, 0x7},
  {0x35, 0, 247, 0x4},
  {0x35, 246, 245, 0x5},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 239, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 237, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 239, 0, 0x1},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 232, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 230, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 232, 0, 0x6},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 225, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 223, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 225, 0, 0x2},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 218, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 216, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 218, 0, 0x0},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 211, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 209, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 211, 0, 0x5},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 204, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 202, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 204, 205, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 197, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 195, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 197, 0xfffffe7f},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 190, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 188, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 189, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 182, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 180, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 181, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 174, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 172, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 173, 0, 0x4},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 166, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 164, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 165, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 158, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 156, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 157, 0, 0x9},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 150, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 148, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x54, 0, 0, 0xfffffe7f},
  {0x15, 149, 0, 0xa},
  {0x6, 0, 0, 0x30005},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 141, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 139, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 141, 0, 0x10},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 134, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 132, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 134, 0, 0xf},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 127, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 125, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 127, 0, 0x3},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 120, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 118, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 120, 0, 0x4},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 113, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 111, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 113, 0, 0x53564d41},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 106, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 104, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 106, 0, 0x29},
  {0x6, 0, 0, 0x30004},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 98, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 96, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 98, 0, 0x3},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 91, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 89, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 91, 0, 0x1},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 84, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 82, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 84, 0, 0x2},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 77, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 75, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 77, 0, 0x6},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 70, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 68, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 70, 0, 0x7},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 63, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 61, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 63, 0, 0x5},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 56, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 54, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 56, 0, 0x0},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 49, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 47, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 49, 0, 0x406},
  {0x20, 0, 0, 0x1c},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 42, 0xffffffff},
  {0x20, 0, 0, 0x18},
  {0x45, 0, 40, 0x80000000},
  {0x20, 0, 0, 0x18},
  {0x15, 0, 43, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 0, 41, 0x0},
  {0x20, 0, 0, 0x20},
  {0x45, 39, 38, 0xffe363fc},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 31, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 29, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 31, 0, 0xa57},
  {0x6, 0, 0, 0x30003},
  {0x20, 0, 0, 0x14},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 23, 0xffffffff},
  {0x20, 0, 0, 0x10},
  {0x45, 0, 21, 0x80000000},
  {0x20, 0, 0, 0x10},
  {0x15, 23, 24, 0x1},
  {0x20, 0, 0, 0x24},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 16, 0xffffffff},
  {0x20, 0, 0, 0x20},
  {0x45, 0, 14, 0x80000000},
  {0x20, 0, 0, 0x20},
  {0x15, 16, 15, 0x4},
  {0x20, 0, 0, 0x24},
  {0x15, 3, 0, 0x0},
  {0x15, 0, 9, 0xffffffff},
  {0x20, 0, 0, 0x20},
  {0x45, 0, 7, 0x80000000},
  {0x20, 0, 0, 0x20},
  {0x45, 10, 9, 0xfffffff8},
  {0x20, 0, 0, 0x2c},
  {0x15, 4, 0, 0x0},
  {0x15, 0, 2, 0xffffffff},
  {0x20, 0, 0, 0x28},
  {0x45, 1, 0, 0x80000000},
  {0x6, 0, 0, 0x30002},
  {0x20, 0, 0, 0x28},
  {0x45, 2, 1, 0xfffdb7cc},
  {0x6, 0, 0, 0x50001},
  {0x6, 0, 0, 0x7fff0000},
  {0x6, 0, 0, 0x30001},
};
#endif

struct sock_fprog GetTestSeccompFilterProgram() {
  struct sock_fprog prog = {
    .len = sizeof(kTestSeccompFilter) / sizeof(struct sock_filter),
    .filter = kTestSeccompFilter
  };
  return prog;
}
