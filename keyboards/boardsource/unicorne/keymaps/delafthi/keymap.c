#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// clang-format off

/*
 * LAYOUT_split_3x6_3 physical layout reference:
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * | R1-1 | R1-2 | R1-3 | R1-4 | R1-5 | R1-6 |             | R1-1 | R1-2 | R1-3 | R1-4 | R1-5 | R1-6 |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | R2-1 | R2-2 | R2-3 | R2-4 | R2-5 | R2-6 |             | R2-1 | R2-2 | R2-3 | R2-4 | R2-5 | R2-6 |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | R3-1 | R3-2 | R3-3 | R3-4 | R3-5 | R3-6 |             | R3-1 | R3-2 | R3-3 | R3-4 | R3-5 | R3-6 |
 * '------+------+------+------+------+------'             '------+------+------+------+------+------'
 *                      | Th1  | Th2  | Th3  |             | Th1  | Th2  | Th3  |
 *                      '--------------------'             '--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Dvorak base
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_QUOT,         KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,        KC_G,    KC_C,    KC_R,    KC_L,           KC_BSPC,
        LT(1, KC_ESC),  KC_A,            KC_O,    KC_E,    KC_U,    KC_I,         KC_D,        KC_H,    KC_T,    KC_N,    KC_S,           LT(1, KC_MINS),
        KC_LSFT,        LCTL_T(KC_SCLN), KC_Q,    KC_J,    KC_K,    LT(2, KC_X), LT(3, KC_B), KC_M,    KC_W,    KC_V,    RCTL_T(KC_Z),  KC_RSFT,
                                                   KC_LALT, KC_LGUI, KC_SPC,      KC_ENT,      KC_RGUI, KC_RALT
    ),

    // Layer 1: Symbols + Navigation
    [1] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,      KC_BSLS, KC_CIRC, KC_ASTR, KC_QUES, KC_SLSH, KC_DEL,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL,  KC_TRNS,
        KC_TRNS, KC_PERC, KC_AMPR, KC_LBRC, KC_RBRC, KC_TILD,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PLUS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 2: Numpad
    [2] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_CIRC, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_ASTR, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 3: Function keys + Media
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F6,   KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 4: QWERTY gaming (left hand)
    [4] = LAYOUT_split_3x6_3(
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        LT(5, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                          KC_LALT, KC_LGUI, KC_SPC,       KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // Layer 5: QWERTY gaming (extra left keys)
    [5] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_M,    KC_L,    KC_K,    KC_J,    KC_H,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_RALT, KC_RGUI, KC_ENT,       KC_TRNS, KC_TRNS, KC_TRNS
    ),

};

// clang-format on

const uint16_t PROGMEM switch_to_qwerty_gaming_combo[] = {KC_F, KC_D, LT(3, KC_B), COMBO_END};
combo_t                key_combos[]                    = {
    COMBO(switch_to_qwerty_gaming_combo, TG(4)),
};

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C
