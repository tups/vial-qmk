#include QMK_KEYBOARD_H
#include "arsenik.h"

enum arsenik_layers {
    _base,
    //_lafayette,
    //_num_row,
    _vim_nav,
    _num_nav,
    //_num_pad,
    _fun_pad,
};

enum custom_keycodes {
    ODK_1 = SAFE_RANGE,  // „
    ODK_2,  // “
    ODK_3,  // ”
    ODK_4,  // ¢
    ODK_5,  // ‰
};

// Custom keycodes exposed to Vial. Must match the order of the
// "customKeycodes" array in vial.json (index 0 -> QK_KB_0, etc.).
enum vial_custom_keycodes {
    VRGB_TOG = QK_KB_0,  // "RGB Toggle"
    OS_UNDO,             // Ctrl+Z / Cmd+Z  (selon AG_TOGG)
    OS_CUT,              // Ctrl+X / Cmd+X
    OS_COPY,             // Ctrl+C / Cmd+C
    OS_PASTE,            // Ctrl+V / Cmd+V
    OS_ALL,              // Ctrl+A / Cmd+A
    OS_SAVE,             // Ctrl+S / Cmd+S
    OS_NTAB,             // Ctrl+T / Cmd+T
    MAC_TOGG,            // Toggle Win/Mac : swap LAlt<->LGui uniquement.
                         // (AG_TOGG swappe aussi RAlt<->RGui, ce qui casse
                         // AltGr utilisé par QwertyLafayette sur RALT_T)
};

// Sends Ctrl+kc on Windows mode, Cmd+kc on Mac mode (toggled with AG_TOGG).
// tap_code16 bypasses the magic Alt<->GUI remapping, so the modifier we
// send here is exactly what the OS receives.
static inline void tap_os_shortcut(uint16_t kc) {
    tap_code16(keymap_config.swap_lalt_lgui ? G(kc) : C(kc));
}

// The ARSENIK_LAYOUT macro allows us to declare a config for a 4x6+3 keyboard, then truncate it
// (or fill it with noops) depending on the size of your keyboard. Your keyboard may have extra
// definitions for this macro or none at all (preventing you from compiling the keymap). Check
// the `README.md` file for more information.
//
// A comprehensive list of QMK keycodes is available here: https://docs.qmk.fm/keycodes
// However, we used a many aliases to automatically adapt the keymap depending on the options you
// enabled in the `config.h` file (or just to have some syntaxic sugar). You can find all of them
// in the `arsenik.h` file. Feel free to remove those aliases and replace them with their actual
// value if you need something Arsenik doesn’t provide.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_base] = ARSENIK_LAYOUT(
        KC_CAPS, KC_1, KC_2,  KC_3,  KC_4,  KC_5,      KC_6, KC_7,  KC_8,    KC_9,   KC_0,    KC_DEL,
        KC_TAB,  KC_Q, KC_W,  KC_E,  KC_R,  KC_T,      KC_Y, KC_U,  KC_I,    KC_O,   KC_P,    KC_INS,
        KC_ESC,  KC_A, KC_SS, KC_DD, KC_FF, KC_G,      KC_H, KC_JJ, KC_KK,   KC_LL,  KC_SCLN, KC_ENTER,
        KC_LSFT, KC_Z, KC_X,  KC_C,  KC_V,  KC_B, MAC_TOGG, XX, KC_N, KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        MO(_fun_pad), _vim_nav, KC_BSPC, LT(_num_nav, KC_SPC),    LT(_num_nav, KC_SPC), RALT_T(KC_ENT), MO(_vim_nav), MO(_fun_pad)
    ),

    /*[_lafayette] = ARSENIK_LAYOUT(
        __, AG(KC_1), AG(KC_2), AG(KC_3), AG(KC_4), AG(KC_5),      AG(KC_6), AG(KC_7), AG(KC_8), AG(KC_9), AG(KC_0), __,
        __, AS(CIRC), AS(LABK), AS(RABK), AS(DLR),  AS(PERC),      AS(AT),   AS(AMPR), AS(ASTR), AS(QUOT), AS(GRV),  __,
        __, AS(LCBR), AS(LPRN), AS(RPRN), AS(RCBR), AS(EQL),       AS(BSLS), AS(PLUS), AS(MINS), AS(SLSH), AS(DQUO), __,
        __, AS(TILD), AS(LBRC), AS(RBRC), AS(UNDS), AS(HASH),      AS(PIPE), AS(EXLM), AS(SCLN), AS(COLN), AS(QUES), __,
                          __, MO(_num_row),   KC_SPC,   XX,      XX,   KC_SPC,   MO(_num_row), __
    ),

    // Not fully implemented yet
    [_num_row] = ARSENIK_LAYOUT(
        __, __,    __,    __,    __,    __,         __,    __,       __,       __,      __,       __,
        __, AS_S1, AS_S2, AS_S3, AS_S4, AS_S5,      AS_S6, AS_S7,    AS_S8,    AS_S9,   AS_S0,    __,
        __, AS(1), AS(2), AS(3), AS(4), AS(5),      AS(6), AS(7),    AS(8),    AS(9),   AS(0),    __,
        __, ODK_1, ODK_2, ODK_3, ODK_4, ODK_5,      XX,    AS(MINS), AS(COMM), AS(DOT), AS(SLSH), __,
                    __, LAFAYETTE,   KC_SPC,   XX,      XX,   KC_SPC,   LAFAYETTE, __
    ),*/

    [_vim_nav] = ARSENIK_LAYOUT(
        __, G(KC_1),      G(KC_2),  G(KC_3),   G(KC_4),  G(KC_5), G(KC_6),  G(KC_7),  G(KC_8), G(KC_9), G(KC_0),      __,
        __, MO(_num_nav), OS_NTAB,  KC_WBAK,   KC_WFWD,  XX,      KC_HOME,  KC_PGDN,  KC_PGUP, KC_END,  G(AS(P)),     __,
        __, OS_ALL,       OS_SAVE,  S(KC_TAB), KC_TAB,   XX,      KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT, MO(_fun_pad), __,
        __, OS_UNDO,      OS_CUT,   OS_COPY,   OS_PASTE, XX, XX, XX, KC_WH_L,  KC_WH_D,  KC_WH_U, KC_WH_R, XX,           __,
                                    __, KC_DEL,   __,   XX,      XX,   __,   KC_ESC, __
    ),

    [_num_nav] = ARSENIK_LAYOUT(
        __, G(KC_1),  G(KC_2),  G(KC_3),  G(KC_4),  G(KC_5),        G(KC_6),  G(KC_7),  G(KC_8), G(KC_9), G(KC_0),  __,
        __, KC_TAB,   KC_HOME,  KC_UP,    KC_END,   KC_PGUP,        AS(SLSH), AS(7),    AS(8),   AS(9),   G(AS(P)), __,
        __, OS_ALL,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,        AS(MINS), AS(4),    AS(5),   AS(6),   AS(0),    __,
        __, OS_UNDO,  OS_CUT,   OS_COPY,  OS_PASTE, S(KC_TAB), XX, XX, AS(COMM), AS(1),    AS(2),   AS(3),   AS(DOT),  __,
                                    __, KC_DEL,   __,   XX,      XX,   __,   KC_ESC, __
    ),

    [_fun_pad] = ARSENIK_LAYOUT(
        __, __,    __,     __,     __,     __,      __, __,      __,      __,      __, __,
        __, KC_F1, KC_F2,  KC_F3,  KC_F4,  XX,      XX, XX,      XX,      XX,      XX, __,
        __, KC_F5, KC_F6,  KC_F7,  KC_F8,  XX,      XX, KC_LCTL, KC_LALT, KC_LGUI, __, __,
        __, KC_F9, KC_F10, KC_F11, KC_F12, XX, XX, XX, XX, XX,      XX,      XX,      XX, __,
                    __, __,   KC_SPC,   XX,      XX,   KC_SPC,   __, __
    ),

};


// This is where you’ll write most of your custom code for your keyborad.
// This callback is called right before the keycode is sent to the OS.
//
// returning false cancels any furnther processing.
// for instance, calling `tap_code(KC_B)` if KC_A is pressed but true is
// returned, "ba" is sent, but if `false` is returned, it’s just "b"
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#   ifdef SELENIUM_RESTORE_SPACE
    static bool thumb_mod_same_hand_as_space_held = false;
    if ((keycode & 0xff) == KC_SPC && record->tap.count == 0)
        thumb_mod_same_hand_as_space_held = record->event.pressed;
#   endif

    // Let QMK do its thing on key releases.
    if (!record->event.pressed) return true;

#   ifdef SELENIUM_RESTORE_SPACE
    if ((keycode & 0xff) == KC_BSPC &&
        !thumb_mod_same_hand_as_space_held &&
        record->tap.count > 0
    ) {
        tap_code(KC_SPC);
        return false;
    }
#   endif

    switch (keycode) {
        // ----------------------------------------
        // Code for your custom keycodes goes here.
        // ----------------------------------------

        case ODK_1: ODK1_SEQUENCE; return false;
        case ODK_2: ODK2_SEQUENCE; return false;
        case ODK_3: ODK3_SEQUENCE; return false;
        case ODK_4: ODK4_SEQUENCE; return false;
        case ODK_5: ODK5_SEQUENCE; return false;

        case VRGB_TOG:
#           ifdef RGB_MATRIX_ENABLE
            rgb_matrix_toggle();
#           endif
            return false;

        // OS-aware shortcuts: follow the AG_TOGG (Win/Mac) state.
        case OS_UNDO:  tap_os_shortcut(AS(Z)); return false;
        case OS_CUT:   tap_os_shortcut(AS(X)); return false;
        case OS_COPY:  tap_os_shortcut(AS(C)); return false;
        case OS_PASTE: tap_os_shortcut(AS(V)); return false;
        case OS_ALL:   tap_os_shortcut(AS(A)); return false;
        case OS_SAVE:  tap_os_shortcut(AS(S)); return false;
        case OS_NTAB:  tap_os_shortcut(AS(T)); return false;

        case MAC_TOGG:
            // Swap LAlt<->LGui only. RAlt stays untouched so AltGr
            // (QwertyLafayette on RALT_T) keeps working on both OSes.
            keymap_config.swap_lalt_lgui = !keymap_config.swap_lalt_lgui;
            keymap_config.swap_ralt_rgui = false;
            eeconfig_update_keymap(&keymap_config);
            return false;
    }

    return true;
}

static inline bool tap_keycode_used_in_text(uint16_t keycode) {
    // We can’t make assumptions on curstom keycodes
    if (keycode >= SAFE_RANGE) return false;

    // Remove "quantum" part of the keycode to get the action on tap.
    const uint16_t tap_keycode = keycode & 0xff;
    // `tap_keycode <= KC_0` includes all letters and numbers, but also
    // `KC_NO` which is safer to include, since it is commonly used in the
    // keymap as a placeholder for complex actions on tap.
    return (tap_keycode <= KC_0) || (tap_keycode == KC_SPACE);
}

uint16_t get_tapping_term_user(uint16_t keycode, keyrecord_t *record) {
    return tap_keycode_used_in_text(keycode) ? ARSENIK_HRM_TAPPING_TERM : TAPPING_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return !tap_keycode_used_in_text(keycode);
}


#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}
#endif

#ifdef OLED_ENABLE

#include "glcdfont.c"  // 6x8 font data (same as the oled driver's) for pixel rendering

// The stock oled_write() is locked to 8px-aligned rows (SSD1306 pages), which
// makes lines look cramped. This draws a string pixel by pixel at any (x, y),
// allowing real line spacing. Blank pixels are written too, erasing leftovers.
static void oled_write_at(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        const unsigned char *glyph = &font[(unsigned char)*str * 6];
        for (uint8_t col = 0; col < 6; col++) {
            uint8_t bits = pgm_read_byte(glyph + col);
            for (uint8_t row = 0; row < 8; row++) {
                oled_write_pixel(x + col, y + row, bits & (1 << row));
            }
        }
        x += 6;
        str++;
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180; // flip display on offhand
    }
    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(logo, false);
}

static void render_status(void) {
    // 3 lines of 8px text with a 4px gap between them (y = 0, 12, 24).
    // Lines are padded to 21 chars so stale pixels get erased.
    char line[22];

    oled_write_at(0, 0, "Lily58 Pro V2        ");

    const char *layer_name;
    switch (get_highest_layer(layer_state)) {
        case _base:    layer_name = "Base";   break;
        // case _lafayette: layer_name = "Lafayette"; break;
        // case _num_row:   layer_name = "NumRow";    break;
        case _vim_nav: layer_name = "VimNav"; break;
        case _num_nav: layer_name = "NumNav"; break;
        // case _num_pad:   layer_name = "NumPad";    break;
        case _fun_pad: layer_name = "FunPad"; break;
        default:       layer_name = NULL;     break;
    }
    if (layer_name) {
        snprintf(line, sizeof(line), "Layer: %-14s", layer_name);
    } else {
        snprintf(line, sizeof(line), "Layer: L%02d%-11s", get_highest_layer(layer_state), "");
    }
    oled_write_at(0, 12, line);

    snprintf(line, sizeof(line), "OS: %-3s  RGB: %-6s",
             keymap_config.swap_lalt_lgui ? "Mac" : "Win",
#ifdef RGB_MATRIX_ENABLE
             rgb_matrix_is_enabled() ? "ON" : "OFF"
#else
             "--"
#endif
    );
    oled_write_at(0, 24, line);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
