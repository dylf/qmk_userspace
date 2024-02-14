#include QMK_KEYBOARD_H
#include "layers.h"
#include "oled.h"

#ifdef RGB_MATRIX_ENABLE

// LED Layout
// Columns
// 0    1   2   3   4   5     6   7   8   9   10  11
// Physical (Center: 59)
// 18  20  24  28  32  37  | 44  56  74  112 224 224
//                                                    Rows  Physical (Center: 14)
// 37  36  35  34  33  32  | 00  01  02  03  04  05         8
// 38  39  40  41  42  43  | 11  10  09  08  07  06         9
// 49  48  47  46  45  44  | 12  13  14  15  16  17         10
// 50  51  52  53  54  55  | 23  22  21  20  19  18         12
//         59  58          |         26  27                 16
//                 57  56  | 24  25                         21
//                 60  63  | 31  28                         32
//                 61  62  | 30  29                         64

led_config_t g_led_config = { {
    // Key matrix to LED index
    // Right Side
    {0, 1, 2, 3, 4, 5 },
    {11, 10, 9, 8, 7, 6 },
    {12, 13, 14, 15, 16, 17 },
    {23, 22, 21, 20, 19, 18 },
    {24, 25, 26, 27, NO_LED, NO_LED},
    {31, 30, 29, 28, NO_LED, NO_LED },
    // Left Side
    {37, 36, 35, 34, 33, 32 },
    {38, 39, 40, 41, 42, 43 },
    {49, 48, 47, 46, 45, 44 },
    {50, 51, 52, 53, 54, 55 },
    {NO_LED, NO_LED, 59, 58, NO_LED, NO_LED },
    {NO_LED, NO_LED, NO_LED, NO_LED, 57, 56 },
}, {
    // LED index to physical position
    // Use the map above
    // Right 1-32
    {44, 8}, {56, 8}, {74, 8}, {112, 8}, {224, 8}, {224, 8},
    {224, 9}, {224, 9}, {112, 9}, {74, 9}, {56, 9}, {44, 9},
    {44, 10}, {56, 10}, {74, 10}, {112, 10}, {224, 10}, {224, 10},
    {224, 12}, {224, 12}, {112, 12}, {74, 12}, {56, 12}, {44, 12},
    {44, 21}, {56, 21}, {74, 16}, {112, 16}, {56, 32}, {56, 64},
    {44, 64}, {44, 32},
    // Left 1-32
    {37, 8}, {32, 8}, {28, 8}, {24, 8}, {20, 8}, {18, 8},
    {18, 9}, {20, 9}, {24, 9}, {28, 9}, {32, 9}, {37, 9},
    {37, 10}, {32, 10}, {28, 10}, {24, 10}, {20, 10}, {18, 10},
    {18, 12}, {20, 12}, {24, 12}, {28, 12}, {32, 12}, {37, 12},
    {37, 21}, {32, 21}, {28, 16}, {24, 16}, {32, 32}, {32, 64},
    {37, 64}, {37, 32},

}, {
    // LED index to flag
    // Right 1-32
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
    // Left 1-32
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
    4,4,4,4,4,4,4,4,
} };

#endif
