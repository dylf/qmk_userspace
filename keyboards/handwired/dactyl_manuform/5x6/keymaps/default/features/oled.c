#include QMK_KEYBOARD_H
#include "layers.h"
#include "oled.h"

#ifdef OLED_ENABLE

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
//
//     oled_write_P(qmk_logo, false);
// }
//
// bool oled_task_user(void) {
//     render_logo();
//     return false;
// }
//
// #endif

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);


 #ifdef RGB_MATRIX_ENABLE
 oled_write_P(PSTR("\nRGB: "), false);
//Display the name of the current animation
  switch (rgblight_get_mode()){
	case RGB_MATRIX_CYCLE_ALL:
		oled_write_P(PSTR("Cycle All"), true);
		break;
        case RGB_MATRIX_ALPHAS_MODS:
		oled_write_P(PSTR("Alphas Mods"), true);
		break;
	case RGB_MATRIX_GRADIENT_UP_DOWN:
		oled_write_P(PSTR("Gradient up down"), true);
		break;
	case RGB_MATRIX_GRADIENT_LEFT_RIGHT:
		oled_write_P(PSTR("Gradient l/r"), true);
		break;
    case RGB_MATRIX_BREATHING:
        oled_write_P(PSTR("Breathing"), true);
        break;
    case RGB_MATRIX_BAND_SAT:
        oled_write_P(PSTR("Band sat"), true);
        break;
    case RGB_MATRIX_BAND_VAL:
        oled_write_P(PSTR("Band val"), true);
        break;
    case RGB_MATRIX_BAND_PINWHEEL_SAT:
        oled_write_P(PSTR("Pinwheel sat"), true);
        break;
    case RGB_MATRIX_STARLIGHT_DUAL_HUE:
        oled_write_P(PSTR("Starlight dual h"), true);
        break;
    case RGB_MATRIX_STARLIGHT_DUAL_SAT:
        oled_write_P(PSTR("Starlight dual s"), true);
        break;
    // case RGB_MATRIX_STARLIGHT_DUAL:
    //     oled_write_P(PSTR("Starlight dual"), true);
    //     break;
    // case RGB_MATRIX_RIVERFLOW:
    //     oled_write_P(PSTR("Riverflow"), true);
    //     break;
    case RGB_MATRIX_BAND_SPIRAL_VAL:
        oled_write_P(PSTR("Spiral val"), true);
        break;
    case RGB_MATRIX_CYCLE_LEFT_RIGHT:
        oled_write_P(PSTR("cycle left/r"), true);
        break;
    case RGB_MATRIX_CYCLE_UP_DOWN:
        oled_write_P(PSTR("cycle u/d"), true);
        break;

	default:
		oled_write_P(PSTR("I didn't set this one"), true);
		break;
  }

  oled_write_P(PSTR("\nHue: "), false);
    oled_write_P(get_u8_str(rgb_matrix_get_hue(), '0'), false);
    oled_write_P(PSTR(" Sat: "), false);
    oled_write_P(get_u8_str(rgb_matrix_get_sat(), '0'), false);
    oled_write_P(PSTR(" Val: "), false);
    oled_write_P(get_u8_str(rgb_matrix_get_val(), '0'), false);




    return false;
}
#endif

#ifdef WPM_ENABLE
oled_write_P(PSTR("\nWPM: "), false);
oled_write_P(get_u8_str(get_current_wpm(), '0'), false);
#endif

#endif
//
