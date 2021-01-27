/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney <drashna@live.com> (@drashna)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    DVORAK,
    COLEMAK,
    QWERTY,
    GAME,
    NUMPAD_DVORAK,
    NUMPAD_COLEMAK,
    _NAV,
    _MED,
    _CMD,
    SWITCH,
};

enum custom_keycodes {
    VRSN = ML_SAFE_RANGE,
};

#define CTL_ESC LCTL_T(KC_ESC)
#define OSM_SFT KC_LSFT

#define MO_SWIT MO(SWITCH)

#define TO_DVRK TO(DVORAK)
#define TO_CLMK TO(COLEMAK)
#define TO_QWRT TO(QWERTY)
#define TO_GAME TO(GAME)

#define MO_QWRT MO(QWERTY)

#define SP_NU_C LT(NUMPAD_COLEMAK, KC_SPC)
#define SP_NU_D LT(NUMPAD_DVORAK, KC_SPC)
#define ESC_CMD LT(_CMD, KC_ESC)
#define BSP_NAV LT(_NAV, KC_BSPC)
#define ENT_MED LT(_MED, KC_ENT)

#define CMD(X) LGUI(X)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX,           XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        CTL_ESC, HOME_A,  HOME_O,  HOME_E,  HOME_U,  KC_I,    KC_HYPR,           KC_MEH,  KC_D,    HOME_H,  HOME_T,  HOME_N,  HOME_S,  KC_MINS,
        OSM_SFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_CAPS,
        MO_SWIT, KC_LGUI, KC_LALT, KC_LALT, ESC_CMD,          XXXXXXX,           XXXXXXX,          ENT_MED ,MO_QWRT, XXXXXXX, XXXXXXX, MO_SWIT,
                                            SP_NU_D, KC_TAB,  KC_ENT,            XXXXXXX, ENT_MED ,BSP_NAV
    ),

    [COLEMAK] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B,    XXXXXXX,           XXXXXXX, KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_SLSH,
        CTL_ESC, COLE_A,  COLE_R,  COLE_S,  COLE_T,  KC_G,    KC_HYPR,           KC_MEH,  KC_M,    COLE_N,  COLE_E,  COLE_I,  COLE_O,  KC_MINS,
        OSM_SFT, KC_Z    ,KC_X,    KC_C,    KC_D,    KC_V,                                KC_K,    KC_H,    KC_COMM ,KC_DOT  ,KC_SLSH ,KC_CAPS,
        MO_SWIT, KC_LGUI, KC_LALT, KC_LALT, ESC_CMD,          XXXXXXX,           XXXXXXX,          KC_ENT,  MO_QWRT, XXXXXXX, XXXXXXX, MO_SWIT,
                                            SP_NU_C, KC_TAB,  KC_ENT,            XXXXXXX, KC_ENT,  BSP_NAV
    ),

    [QWERTY] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T,    XXXXXXX,           XXXXXXX, KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_SLSH,
        CTL_ESC, QWRT_A,  QWRT_S,  QWRT_D,  QWRT_F,  KC_G,    KC_HYPR,           KC_MEH,  KC_H,    QWRT_J,  QWRT_K,  QWRT_L,  QWRT_SC ,KC_MINS,
        OSM_SFT, KC_Z    ,KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM ,KC_DOT  ,KC_SLSH ,KC_CAPS,
        MO_SWIT, KC_LGUI, KC_LALT, KC_LALT, ESC_CMD,          XXXXXXX,           XXXXXXX,          KC_ENT,  MO_QWRT ,XXXXXXX, XXXXXXX, MO_SWIT,
                                            SP_NU_C, KC_TAB,  KC_ENT,            XXXXXXX, KC_ENT,  BSP_NAV
    ),

     [GAME] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,              _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            KC_SPC,  KC_TAB,  KC_ENT,            _______, _______, _______
    ),

    [NUMPAD_DVORAK] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______,                             KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_0,    _______, _______, _______, _______,
                                            _______, _______, _______,           _______, KC_LBRC, KC_RBRC
    ),

    [NUMPAD_COLEMAK] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_COLN, _______, _______, _______,           _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______,                             KC_BSLS, KC_1,    KC_2,    KC_3,    KC_QUOT, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_0,    _______, _______, _______, _______,
                                            _______, _______, _______,           _______, KC_LBRC, KC_RBRC
    ),

    [_NAV] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PGUP, KC_HOME, KC_UP,   _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            KC_CAPS, _______, _______,           _______, _______, _______
    ),

    [_MED] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_VOLU, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_MUTE,          _______,           _______,          _______, _______, _______, _______, _______,
                                            KC_MPLY, KC_MSTP, KC_MUTE,           _______, _______, _______
    ),

    [_CMD] = LAYOUT_moonlander(
        CMD(KC_GRV), CMD(KC_1), CMD(KC_2), CMD(KC_3), CMD(KC_4), CMD(KC_5), _______,     _______, CMD(KC_6), CMD(KC_7), CMD(KC_8),    CMD(KC_9),   CMD(KC_0),    _______,
        _______,     CMD(KC_Q), CMD(KC_W), CMD(KC_E), CMD(KC_R), CMD(KC_T), _______,     _______, CMD(KC_Y), CMD(KC_U), CMD(KC_I),    CMD(KC_O),   CMD(KC_P),    _______,
        _______,     CMD(KC_A), CMD(KC_S), CMD(KC_D), CMD(KC_F), CMD(KC_G), _______,     _______, CMD(KC_H), CMD(KC_J), CMD(KC_K),    CMD(KC_L),   CMD(KC_SCLN), _______,
        _______,     CMD(KC_Z), CMD(KC_X), CMD(KC_C), CMD(KC_V), CMD(KC_B),                       CMD(KC_N), CMD(KC_M), CMD(KC_COMM), CMD(KC_DOT), CMD(KC_SLSH), _______,
        _______,     _______,   _______,   _______,   _______,              _______,     _______,            _______,   _______,      _______,     _______,      _______,
                                                      _______,   _______,   _______,     _______, _______,   _______
    ),

    [SWITCH] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, TO_DVRK, TO_CLMK, TO_QWRT ,TO_GAME ,_______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

#define CC1 {169,255,255} // Blue
#define CC2 {85,255,255}  // Green
#define CC3 {0,255,255}   // Red
#define CC4 {43,255,255}  // Yellow
#define CC5 {180,255,255} // Violet
#define CC6 {148,255,255} // Azure




const uint8_t PROGMEM layer_color[][3] = {
    [DVORAK]  = CC1,
    [COLEMAK] = CC6,
    [QWERTY]  = CC2,
    [GAME]    = CC3,
};

/* const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = { */
/*     [DVORAK] = { CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1 }, */
/*  */
/*     [COLEMAK] = { CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1 }, */
/*  */
/*     [QWERTY] = { CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2, CC2 }, */
/*  */
/*     [GAME] = { CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3, CC3 }, */
/*  */
/*     [SWITCH] = { CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1, CC1 }, */
/*  */
/* }; */

void set_layer_color(int layer) {
  HSV hsv = {
    .h = pgm_read_byte(&layer_color[layer][0]),
    .s = pgm_read_byte(&layer_color[layer][1]),
    .v = pgm_read_byte(&layer_color[layer][2]),
  };
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    /* HSV hsv = { */
    /*   .h = pgm_read_byte(&ledmap[layer][i][0]), */
    /*   .s = pgm_read_byte(&ledmap[layer][i][1]), */
    /*   .v = pgm_read_byte(&ledmap[layer][i][2]), */
    /* }; */
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case DVORAK:
      set_layer_color(DVORAK);
      break;
    case COLEMAK:
      set_layer_color(COLEMAK);
      break;
    case QWERTY:
      set_layer_color(QWERTY);
      break;
    case GAME:
      set_layer_color(GAME);
      break;
    case SWITCH:
      set_layer_color(SWITCH);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        }
    }
    return true;
}
