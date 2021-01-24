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

#pragma once

#define ORYX_CONFIGURATOR

// Default tapping term is 200
#define TAPPING_TERM 220

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// This prevents short hold periods to be interpreted as individual taps when typing quickly.
#define PERMISSIVE_HOLD

// This prevents accidental repeats of the tap-hold keys when typing quickly.
#define TAPPING_FORCE_HOLD


// Home row mods, using Dvorak ... AOEU <--> HTNS
#define HOME_A              LCTL_T(KC_A)
#define HOME_O              LALT_T(KC_O)
#define HOME_E              LSFT_T(KC_E)
#define HOME_U              LGUI_T(KC_U)
#define HOME_H              RGUI_T(KC_H)
#define HOME_T              RSFT_T(KC_T)
#define HOME_N              LALT_T(KC_N)
#define HOME_S              RCTL_T(KC_S)

#define COLE_A              LCTL_T(KC_A)
#define COLE_R              LALT_T(KC_R)
#define COLE_S              LSFT_T(KC_S)
#define COLE_T              LGUI_T(KC_T)
#define COLE_N              RGUI_T(KC_N)
#define COLE_E              RSFT_T(KC_E)
#define COLE_I              LALT_T(KC_I)
#define COLE_O              RCTL_T(KC_O)
