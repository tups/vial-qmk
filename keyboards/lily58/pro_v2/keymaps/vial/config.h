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
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
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
