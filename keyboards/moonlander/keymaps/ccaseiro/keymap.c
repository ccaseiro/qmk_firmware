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
    GAME,
    NUMPAD,
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
#define TO_GAME TO(GAME)

#define SPC_NUM LT(NUMPAD, KC_SPC)
#define ESC_CMD LT(_CMD, KC_ESC)

#define CMD(X) LGUI(X)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DVORAK] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    XXXXXXX,           XXXXXXX, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        CTL_ESC, HOME_A,  HOME_O,  HOME_E,  HOME_U,  KC_I,    KC_HYPR,           KC_MEH,  KC_D,    HOME_H,  HOME_T,  HOME_N,  HOME_S,  KC_MINS,
        OSM_SFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_CAPS,
        MO_SWIT, KC_LGUI, KC_LALT, KC_LALT, ESC_CMD,          XXXXXXX,           XXXXXXX,          KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, MO_SWIT,
                                            SPC_NUM, KC_TAB,  KC_ENT,            XXXXXXX, KC_ENT,  KC_BSPC
    ),

     [GAME] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,              _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,              _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,              _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            KC_SPC,  KC_TAB,  KC_ENT,            _______, _______, _______
    ),

    [NUMPAD] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_GRV,  KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______, _______,           _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______,                             KC_BSLS, KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          KC_0,    _______, _______, _______, _______,
                                            _______, _______, _______,           _______, KC_LBRC, KC_RBRC
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
        _______, TO_DVRK, _______, TO_GAME, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,          _______,           _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),
};

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
