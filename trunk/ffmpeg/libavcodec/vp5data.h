/**
 * @file vp5data.h
 * VP5 compatible video decoder
 *
 * Copyright (C) 2006  Aurelien Jacobs <aurel@gnuage.org>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef AVCODEC_VP5DATA_H
#define AVCODEC_VP5DATA_H

#include <stdint.h>

static const uint8_t vp5_coeff_groups[] = {
    -1, 0, 1, 1, 2, 1, 1, 2,
     2, 1, 1, 2, 2, 2, 1, 2,
     2, 2, 2, 2, 1, 1, 2, 2,
     3, 3, 4, 3, 4, 4, 4, 3,
     3, 3, 3, 3, 4, 3, 3, 3,
     4, 4, 4, 4, 4, 3, 3, 4,
     4, 4, 3, 4, 4, 4, 4, 4,
     4, 4, 5, 5, 5, 5, 5, 5,
};

static const uint8_t vp5_vmc_pct[2][11] = {
    { 243, 220, 251, 253, 237, 232, 241, 245, 247, 251, 253 },
    { 235, 211, 246, 249, 234, 231, 248, 249, 252, 252, 254 },
};

static const uint8_t vp5_dccv_pct[2][11] = {
    { 146, 197, 181, 207, 232, 243, 238, 251, 244, 250, 249 },
    { 179, 219, 214, 240, 250, 254, 244, 254, 254, 254, 254 },
};

static const uint8_t vp5_ract_pct[3][2][6][11] = {
    { { { 227, 246, 230, 247, 244, 254, 254, 254, 254, 254, 254 },
        { 202, 254, 209, 231, 231, 249, 249, 253, 254, 254, 254 },
        { 206, 254, 225, 242, 241, 251, 253, 254, 254, 254, 254 },
        { 235, 254, 241, 253, 252, 254, 254, 254, 254, 254, 254 },
        { 234, 254, 248, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } },
      { { 240, 254, 248, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 238, 254, 240, 253, 254, 254, 254, 254, 254, 254, 254 },
        { 244, 254, 251, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } } },
    { { { 206, 203, 227, 239, 247, 254, 253, 254, 254, 254, 254 },
        { 207, 199, 220, 236, 243, 252, 252, 254, 254, 254, 254 },
        { 212, 219, 230, 243, 244, 253, 252, 254, 254, 254, 254 },
        { 236, 237, 247, 252, 253, 254, 254, 254, 254, 254, 254 },
        { 240, 240, 248, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } },
      { { 230, 233, 249, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 238, 238, 250, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 248, 251, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } } },
    { { { 225, 239, 227, 231, 244, 253, 243, 254, 254, 253, 254 },
        { 232, 234, 224, 228, 242, 249, 242, 252, 251, 251, 254 },
        { 235, 249, 238, 240, 251, 254, 249, 254, 253, 253, 254 },
        { 249, 253, 251, 250, 254, 254, 254, 254, 254, 254, 254 },
        { 251, 250, 249, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } },
      { { 243, 244, 250, 250, 254, 254, 254, 254, 254, 254, 254 },
        { 249, 248, 250, 253, 254, 254, 254, 254, 254, 254, 254 },
        { 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 },
        { 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254 } } },
};

static const int16_t vp5_dccv_lc[5][36][2] = {
    { {154,  61}, {141,  54}, { 90,  45}, { 54,  34}, { 54,  13}, {128, 109},
      {136,  54}, {148,  45}, { 92,  41}, { 54,  33}, { 51,  15}, { 87, 113},
      { 87,  44}, { 97,  40}, { 67,  36}, { 46,  29}, { 41,  15}, { 64,  80},
      { 59,  33}, { 61,  31}, { 51,  28}, { 44,  22}, { 33,  12}, { 49,  63},
      { 69,  12}, { 59,  16}, { 46,  14}, { 31,  13}, { 26,   6}, { 92,  26},
      {128, 108}, { 77, 119}, { 54,  84}, { 26,  71}, { 87,  19}, { 95, 155} },
    { {154,   4}, {182,   0}, {159,  -8}, {128,  -5}, {143,  -5}, {187,  55},
      {182,   0}, {228,  -3}, {187,  -7}, {174,  -9}, {189, -11}, {169,  79},
      {161,  -9}, {192,  -8}, {187,  -9}, {169, -10}, {136,  -9}, {184,  40},
      {164, -11}, {179, -10}, {174, -10}, {161, -10}, {115,  -7}, {197,  20},
      {195, -11}, {195, -11}, {146, -10}, {110,  -6}, { 95,  -4}, {195,  39},
      {182,  55}, {172,  77}, {177,  37}, {169,  29}, {172,  52}, { 92, 162} },
    { {174,  80}, {164,  80}, { 95,  80}, { 46,  66}, { 56,  24}, { 36, 193},
      {164,  80}, {166,  77}, {105,  76}, { 49,  68}, { 46,  31}, { 49, 186},
      { 97,  78}, {110,  74}, { 72,  72}, { 44,  60}, { 33,  30}, { 69, 131},
      { 61,  61}, { 69,  63}, { 51,  57}, { 31,  48}, { 26,  27}, { 64,  89},
      { 67,  23}, { 51,  32}, { 36,  33}, { 26,  28}, { 20,  12}, { 44,  68},
      { 26, 197}, { 41, 189}, { 61, 129}, { 28, 103}, { 49,  52}, {-12, 245} },
    { {102, 141}, { 79, 166}, { 72, 162}, { 97, 125}, {179,   4}, {307,   0},
      { 72, 168}, { 69, 175}, { 84, 160}, {105, 127}, {148,  34}, {310,   0},
      { 84, 151}, { 82, 161}, { 87, 153}, { 87, 135}, {115,  51}, {317,   0},
      { 97, 125}, {102, 131}, {105, 125}, { 87, 122}, { 84,  64}, { 54, 184},
      {166,  18}, {146,  43}, {125,  51}, { 90,  64}, { 95,   7}, { 38, 154},
      {294,   0}, { 13, 225}, { 10, 225}, { 67, 168}, {  0, 167}, {161,  94} },
    { {172,  76}, {172,  75}, {136,  80}, { 64,  98}, { 74,  67}, {315,   0},
      {169,  76}, {207,  56}, {164,  66}, { 97,  80}, { 67,  72}, {328,   0},
      {136,  80}, {187,  53}, {154,  62}, { 72,  85}, { -2, 105}, {305,   0},
      { 74,  91}, {128,  64}, {113,  64}, { 61,  77}, { 41,  75}, {259,   0},
      { 46,  84}, { 51,  81}, { 28,  89}, { 31,  78}, { 23,  77}, {202,   0},
      {323,   0}, {323,   0}, {300,   0}, {236,   0}, {195,   0}, {328,   0} },
};

static const int16_t vp5_ract_lc[3][3][5][6][2] = {
    { { { {276,  0}, {238,  0}, {195,  0}, {156,  0}, {113,  0}, {274,  0} },
        { {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1} },
        { {192, 59}, {182, 50}, {141, 48}, {110, 40}, { 92, 19}, {125,128} },
        { {169, 87}, {169, 83}, {184, 62}, {220, 16}, {184,  0}, {264,  0} },
        { {212, 40}, {212, 36}, {169, 49}, {174, 27}, {  8,120}, {182, 71} } },
      { { {259, 10}, {197, 19}, {143, 22}, {123, 16}, {110,  8}, {133, 88} },
        { {  0,  1}, {256,  0}, {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1} },
        { {207, 46}, {187, 50}, { 97, 83}, { 23,100}, { 41, 56}, { 56,188} },
        { {166, 90}, {146,108}, {161, 88}, {136, 95}, {174,  0}, {266,  0} },
        { {264,  7}, {243, 18}, {184, 43}, {-14,154}, { 20,112}, { 20,199} } },
      { { {230, 26}, {197, 22}, {159, 20}, {146, 12}, {136,  4}, { 54,162} },
        { {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1}, {  0,  1} },
        { {192, 59}, {156, 72}, { 84,101}, { 49,101}, { 79, 47}, { 79,167} },
        { {138,115}, {136,116}, {166, 80}, {238,  0}, {195,  0}, {261,  0} },
        { {225, 33}, {205, 42}, {159, 61}, { 79, 96}, { 92, 66}, { 28,195} } },
    }, {
      { { {200, 37}, {197, 18}, {159, 13}, {143,  7}, {102,  5}, {123,126} },
        { {197,  3}, {220, -9}, {210,-12}, {187, -6}, {151, -2}, {174, 80} },
        { {200, 53}, {187, 47}, {159, 40}, {118, 38}, {100, 18}, {141,111} },
        { {179, 78}, {166, 86}, {197, 50}, {207, 27}, {187,  0}, {115,139} },
        { {218, 34}, {220, 29}, {174, 46}, {128, 61}, { 54, 89}, {187, 65} } },
      { { {238, 14}, {197, 18}, {125, 26}, { 90, 25}, { 82, 13}, {161, 86} },
        { {189,  1}, {205, -2}, {156, -4}, {143, -4}, {146, -4}, {172, 72} },
        { {230, 31}, {192, 45}, {102, 76}, { 38, 85}, { 56, 41}, { 64,173} },
        { {166, 91}, {141,111}, {128,116}, {118,109}, {177,  0}, { 23,222} },
        { {253, 14}, {236, 21}, {174, 49}, { 33,118}, { 44, 93}, { 23,187} } },
      { { {218, 28}, {179, 28}, {118, 35}, { 95, 30}, { 72, 24}, {128,108} },
        { {187,  1}, {174, -1}, {125, -1}, {110, -1}, {108, -1}, {202, 52} },
        { {197, 53}, {146, 75}, { 46,118}, { 33,103}, { 64, 50}, {118,126} },
        { {138,114}, {128,122}, {161, 86}, {243, -6}, {195,  0}, { 38,210} },
        { {215, 39}, {179, 58}, { 97,101}, { 95, 85}, { 87, 70}, { 69,152} } },
    }, {
      { { {236, 24}, {205, 18}, {172, 12}, {154,  6}, {125,  1}, {169, 75} },
        { {187,  4}, {230, -2}, {228, -4}, {236, -4}, {241, -2}, {192, 66} },
        { {200, 46}, {187, 42}, {159, 34}, {136, 25}, {105, 10}, {179, 62} },
        { {207, 55}, {192, 63}, {192, 54}, {195, 36}, {177,  1}, {143, 98} },
        { {225, 27}, {207, 34}, {200, 30}, {131, 57}, { 97, 60}, {197, 45} } },
      { { {271,  8}, {218, 13}, {133, 19}, { 90, 19}, { 72,  7}, {182, 51} },
        { {179,  1}, {225, -1}, {154, -2}, {110, -1}, { 92,  0}, {195, 41} },
        { {241, 26}, {189, 40}, { 82, 64}, { 33, 60}, { 67, 17}, {120, 94} },
        { {192, 68}, {151, 94}, {146, 90}, {143, 72}, {161,  0}, {113,128} },
        { {256, 12}, {218, 29}, {166, 48}, { 44, 99}, { 31, 87}, {148, 78} } },
      { { {238, 20}, {184, 22}, {113, 27}, { 90, 22}, { 74,  9}, {192, 37} },
        { {184,  0}, {215, -1}, {141, -1}, { 97,  0}, { 49,  0}, {264, 13} },
        { {182, 51}, {138, 61}, { 95, 63}, { 54, 59}, { 64, 25}, {200, 45} },
        { {179, 75}, {156, 87}, {174, 65}, {177, 44}, {174,  0}, {164, 85} },
        { {195, 45}, {148, 65}, {105, 79}, { 95, 72}, { 87, 60}, {169, 63} } },
    }
};

static const uint8_t vp5_coord_div[] = { 2, 2, 2, 2, 4, 4 };

#endif /* AVCODEC_VP5DATA_H */
