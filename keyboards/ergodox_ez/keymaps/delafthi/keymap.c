#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// clang-format off

/*
 * Mapping from LAYOUT_split_3x6_3 to LAYOUT_ergodox_pretty:
 *
 * - Split rows 1-3 map to ergodox rows 2-4
 * - Ergodox row 1 (number row) and row 5 (bottom row) are new
 * - Extra inner column keys on rows 2 and 4 are KC_NO
 * - Thumb key 2 (left) -> left bottom row position 4
 * - Thumb key 1 (left) -> left bottom row position 5
 * - Thumb key 3 (left) -> left thumb cluster bottom-left
 * - Thumb key 1 (right) -> right bottom row position 1
 * - Thumb key 2 (right) -> right bottom row position 2
 * - Thumb key 3 (right) -> right thumb cluster bottom-right
 * - All other extra keys are KC_NO
 *
 * Ergodox physical layout reference:
 *
 * ,---------------------------------------------.           ,---------------------------------------------.
 * | Row1-1 | 1-2 | 1-3 | 1-4 | 1-5 | 1-6 | 1-7  |           | 1-1  | 1-2 | 1-3 | 1-4 | 1-5 | 1-6 | Row1-7 |
 * |--------+-----+-----+-----+-----+-----+------|           |------+-----+-----+-----+-----+-----+--------|
 * | Row2-1 | 2-2 | 2-3 | 2-4 | 2-5 | 2-6 | 2-7  |           | 2-1  | 2-2 | 2-3 | 2-4 | 2-5 | 2-6 | Row2-7 |
 * |--------+-----+-----+-----+-----+-----|      |           |      |-----+-----+-----+-----+-----+--------|
 * | Row3-1 | 3-2 | 3-3 | 3-4 | 3-5 | 3-6 |------|           |------| 3-1 | 3-2 | 3-3 | 3-4 | 3-5 | Row3-6 |
 * |--------+-----+-----+-----+-----+-----| 4-7  |           | 4-1  |-----+-----+-----+-----+-----+--------|
 * | Row4-1 | 4-2 | 4-3 | 4-4 | 4-5 | 4-6 |      |           |      | 4-2 | 4-3 | 4-4 | 4-5 | 4-6 | Row4-7 |
 * '--------+-----+-----+-----+-----+------------'           '------------+-----+-----+-----+-----+--------'
 *    | 5-1 | 5-2 | 5-3 | 5-4 | 5-5 |                                     | 5-1 | 5-2 | 5-3 | 5-4 | 5-5 |
 *    '-----------------------------'                                     '-----------------------------'
 *                                 ,-------------.           ,-------------.
 *                                 | ThTL | ThTR |           | ThTL | ThTR |
 *                          ,------+------+------|           |------+------+------.
 *                          |      |      | ThM  |           | ThM  |      |      |
 *                          | ThBL | ThBC |------|           |------| ThBC | ThBR |
 *                          |      |      | ThBR |           | ThBL |      |      |
 *                          '--------------------'           '--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: Dvorak base
    [0] = LAYOUT_ergodox_pretty(
        KC_NO,          KC_NO,           KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,
        KC_TAB,         KC_QUOT,         KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_NO,       MO(6),   KC_F,        KC_G,    KC_C,    KC_R,    KC_L,           KC_BSPC,
        LT(1, KC_ESC),  KC_A,            KC_O,    KC_E,    KC_U,    KC_I,                               KC_D,        KC_H,    KC_T,    KC_N,    KC_S,           LT(1, KC_MINS),
        KC_LSFT,        LCTL_T(KC_SCLN), KC_Q,    KC_J,    KC_K,    LT(2, KC_X),  KC_NO,       KC_NO,   LT(3, KC_B), KC_M,    KC_W,    KC_V,    RCTL_T(KC_Z),  KC_RSFT,
        KC_NO,          KC_NO,           KC_NO,   KC_LALT, KC_LGUI,                                                  KC_RGUI, KC_RALT, KC_NO,   KC_NO,          KC_NO,
                                                                          KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                                                  KC_NO,       KC_NO,
                                                                 KC_SPC,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_ENT
    ),

    // Layer 1: Symbols + Navigation
    [1] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,       KC_NO,   KC_BSLS, KC_CIRC, KC_ASTR, KC_QUES, KC_SLSH, KC_DEL,
        KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_EQL,  KC_TRNS,
        KC_TRNS, KC_PERC, KC_AMPR, KC_LBRC, KC_RBRC, KC_TILD, KC_NO,       KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_PLUS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                              KC_NO,       KC_NO,
                                            KC_TRNS,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_TRNS
    ),

    // Layer 2: Numpad
    [2] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,       KC_NO,   KC_CIRC, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_ASTR, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,       KC_NO,   KC_0,    KC_1,    KC_2,    KC_3,    KC_PLUS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                              KC_NO,       KC_NO,
                                            KC_TRNS,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_TRNS
    ),

    // Layer 3: Function keys + Media
    [3] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F6,   KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                              KC_NO,       KC_NO,
                                            KC_TRNS,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_TRNS
    ),

    // Layer 4: QWERTY gaming (left hand)
    [4] = LAYOUT_ergodox_pretty(
        KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        LT(5, KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,          KC_NO,   KC_NO,   KC_LALT, KC_LGUI,                                         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                             KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                                     KC_NO,       KC_NO,
                                                     KC_SPC, KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_TRNS
    ),

    // Layer 5: QWERTY gaming (extra left keys)
    [5] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,    KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_M,    KC_L,    KC_K,    KC_J,    KC_H,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,    KC_NO,       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_RGUI,                                         KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                              KC_NO,       KC_NO,
                                             KC_ENT,  KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_TRNS
    ),

    // Layer 6: Reset
    [6] = LAYOUT_ergodox_pretty(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                           KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                      KC_NO,  KC_NO,       KC_NO,  KC_NO,
                                                              KC_NO,       KC_NO,
                                             KC_NO,   KC_NO,  KC_NO,       KC_NO,  KC_NO,  KC_NO
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
