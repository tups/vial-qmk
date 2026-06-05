/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* VIAL UID for Lily58 Pro V2*/
#define VIAL_KEYBOARD_UID {0x7E, 0xFD, 0xFC, 0x5B, 0x7D, 0x39, 0x48, 0x07}

/* VIAL secure unlock keystroke - currently both big keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS {4, 9}
#define VIAL_UNLOCK_COMBO_COLS {4, 4}

/* Space reduction */
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define VIAL_TAP_DANCE_ENTRIES 2
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

/* Select hand configuration */
#define MASTER_LEFT

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_DRIVER SIOD0
#define SERIAL_USART_TIMEOUT 100

/* Split debugging options */
#define SPLIT_MAX_CONNECTION_ERRORS 10
#define SPLIT_CONNECTION_CHECK_TIMEOUT 500
#define FORCED_SYNC_THROTTLE_MS 100

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100


/* RGB Matrix Configuration */
#ifdef RGB_MATRIX_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_MULTISPLASH
#define RGB_MATRIX_DEFAULT_HUE 226
#define RGB_MATRIX_DEFAULT_SAT 58
#define RGB_MATRIX_DEFAULT_VAL 80
#define RGB_MATRIX_DEFAULT_SPD 127
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_SPLIT { 29, 29 }
#undef RGBLIGHT_ENABLE
#endif

/* OLED Configuration */
#ifdef OLED_ENABLE
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 30000
#define OLED_BRIGHTNESS 120
#define OLED_DISPLAY_ADDRESS 0x3C
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN GP19
#define I2C1_SDA_PIN GP18
#endif

/* WPM calculation */
#define WPM_ALLOW_COUNT_REGRESSION
//  ───────────────────< Basic QMK options for Arsenik >───────────────────

#undef PERMISSIVE_HOLD
/* QMK’s `PERMISSIVE_HOLD` can be some extra comfort for experienced users, but
 * can also be an absolute pain for beginners, especially if you are trying to
 * learn home-row-mods, which is why we chose to deactivate this option by
 * default.
 */


#ifndef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#endif
/* QMK considers tap-hold actions as "tap by default" when another key is
 * pressed during the "quantum period", but some tap-holds should ideally be
 * "hold by default" to avoid this delay or accidentally pressing keys like
 * Enter or Escape.
 *
 * This option allows us to have a fine-grain controll over this behaviour.
 *
 * Arsenik provides a good default implementation of the required function
 * `get_hold_on_other_key_press` in the `keymap.c` file.
 */


#ifndef TAPPING_TERM_PER_KEY
#define TAPPING_TERM_PER_KEY
#endif
/* Tap-hold actions (especially home-row-mods) may be hard to use as a
 * beginner, as it is common to hold those keys for too long and accidentally
 * use the `hold-action`.
 *
 * This option allows us to have a fine-grain controll over the `TAPPING_TERM`
 * for each tap-hold key, allowing for a longer delay on those sensitive keys
 * without slowing down the safer ones.
 *
 * Arsenik provides a good default implementation of the required function
 * `get_tapping_term` in the `keymap.c` file.
 */


#define ARSENIK_LAYOUT_lily58_pro_v2
/* NOTE: This line gets automatically filled in by the install script, but the
 * underlying layout may not yet exist, and keyboard specific layout may have
 * other variants you might want to check out.
 */


#define ARSENIK_HRM_TAPPING_TERM 300
/* This is the delay used by Arsenik for sensitive tap-holds, which include
 * home-row-mods and mod-taps using the spacebar
 */


//  ────────────────────< Main Arsenik configuration >─────────────────

// Below are a bunch of options to quickly customize the Arsenik keymap. You
// can pick and choose them by (un)commenting the different `#define`
// declarations.

#define ARSENIK_ENABLE_LAFAYETTE_LAYER
/* When active, gives access to the programming symbols layer used by layouts
 * like Ergo‑L and all of the "Lafayette" familly of layouts (it’s their AltGr
 * layer). The definition of this layer depends on the keyboard layout you are
 * using, so make sure to select the correct one in the list bellow.
 *
 * When inactive, this layer is discarded and replaced by AltGr.
 */

// #define ARSENIK_ENABLE_HRM
/* When active, adds a Meta, Ctrl and Alt home-row-mod on respectively s/l,
 * d/k or f/j on a Qwerty keyboard. Those home-row-mods stay on those exact
 * keys regardless of the layout being used, meaning they would be on r/i, s/e
 * and t/n on a Colemak keyboard.
 */

// #define ARSENIK_MAC_MODIFIERS
/* Swaps around home-row-mods from Meta, Ctrl, Alt to Alt, Meta, Ctrl, as it
 * may make more sense on a Mac, like to keep common shortcuts accessible with
 * the Ergo‑L layout, for instance
 *
 * (Requires `ARSENIK_ENABLE_HRM`)
 */

// #define ARSENIK_ENABLE_SIMPLE_THUMBS
/* When active, uses an extra simple config without any tap-holds on the thumb
 * keys. It may be a *lot* simpler to use, but requieres a keyboard with at
 * least 6 thumb keys (so 3 per thumb) instead of 3 thumb keys total and is
 * overall a lot less efficient (especially when combining modifiers).
 *
 * Base thumb config: LSFT_T(KC_ESC)  LT(_num_nav, KC_SPC)  RALT_T(KC_ENT)
 * When it’s active: KC_ALT  KC_CTL  KC_GUI     MO(_num_nav)  KC_SPC  KC_RALT
 * (KC_RALT becomes the `_lafayette` layer if `ARSENIK_ENABLE_LAFAYETTE_LAYER`
 * is active)
 *
 * (Prevents using `ARSENIK_ENABLE_SELENIUM_VARIANT`)
 */

// #define ARSENIK_ENABLE_SELENIUM_VARIANT
/* Most ergonomic keyboards have at least 4 comfortable thumb keys keys (so 2
 * per thumb). Selenium is a variant of Arsenik made to fit on 34 keys keyboard
 * to take advantage of the extra thumb key. It does it by splitting the numbers
 * and navigation layers to 2 distict layers, and adds an escape key.
 *
 * Base thumb config: LSFT_T(KC_ËSC)  LT(_num_nav, KC_SPC)  RALT_T(KC_ENT)
 * Selenium: LSFT_T(KC_ESC) LT(_num_row, KC_BSPC) LT(_vim_nav, KC_SPC) RALT_T(KC_ENT)
 */

// #define SELENIUM_LEFT_HAND_SPACE
/* Swaps around the backspace and space keycodes, for people who prefer using
 * their left thunb for the space bar.
 *
 * (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)
 */

#define SELENIUM_RESTORE_SPACE
/* Having Space accessible to only one thumb may create some problems, especially
 * when trying to type Shift + Space or Lafayette / AltGr + Space (depending if
 * your space key is on your left or right hand). When active, backspace gets
 * temporarily replaced by space when the original space key is held.
 *
 * (Requires `ARSENIK_ENABLE_SELENIUM_VARIANT`)
 */


// Lists of layouts supported by Arsenik. Some parts of the config are dependent
// on keyboard layout used on your computer. If they don’t match up some
// characters may not be correctly placed or missing entirely. If multiple
// options are toggled at the same time, the first one is chosen.
#define ARSENIK_HOST_LAYOUT_QWERTY
// #define ARSENIK_HOST_LAYOUT_AZERTY
// #define ARSENIK_HOST_LAYOUT_ERGOL
// #define ARSENIK_HOST_LAYOUT_BEPO
// #define ARSENIK_HOST_LAYOUT_DVORAK
// #define ARSENIK_HOST_LAYOUT_COLEMAK
// #define ARSENIK_HOST_LAYOUT_WORKMAN
