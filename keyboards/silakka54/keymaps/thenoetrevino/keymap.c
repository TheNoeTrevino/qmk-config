// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                       'L', 'L', 'L',  'R', 'R', 'R'
    );


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // default
    [0] = LAYOUT(
              KC_PSCR,        KC_1,         KC_2,           KC_3,           KC_4,     KC_5,                               KC_6,          KC_7,        KC_8,            KC_9,            KC_0,                  KC_DEL,
               KC_TAB,        KC_Q,         KC_W,           KC_E,           KC_R,     KC_T,                               KC_Y,          KC_U,        KC_I,            KC_O,            KC_P,                  KC_BSLS,
               KC_ESC,        KC_A,   LT(3, KC_S),    LT(2, KC_D),    LT(1, KC_F),    KC_G,                               KC_H,          KC_J,        KC_K,            KC_L,            KC_SCLN,               KC_QUOT,
                MO(4),  GUI_T(KC_Z), LSFT_T(KC_X),    ALT_T(KC_C),    CTL_T(KC_V),    KC_B,                               KC_N,    CTL_T(KC_M), ALT_T(KC_COMM), RSFT_T(KC_DOT),         GUI_T(KC_SLSH),        MO(5),
                                                                         CW_TOGG,  MO(4), KC_BSPC,                   KC_SPC,  KC_ENT,  MO(5)
    ),
    // keypad
    [1] = LAYOUT(
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            KC_PPLS, KC_7,   KC_8,   KC_9,   KC_RBRC, _______,
        _______,  _______, _______, _______, _______, _______,                            KC_EQL,  KC_4,   KC_5,   KC_6,   KC_RGHT, _______,
        _______,  _______, _______, _______, _______, _______,                            KC_PMNS, KC_1,   KC_2,   KC_3,   KC_RCBR, _______,
                                             _______, _______, _______,          KC_P0,   KC_COMM, KC_PDOT
    ),
    // pairs
    [2] = LAYOUT(
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______,  _______, _______, _______, _______, _______,                            _______, KC_LCBR, KC_LT,   KC_GT,   KC_RCBR, _______,
                                             _______, _______, _______,         _______,  _______,  _______
    ),
    // symbols
    [3] = LAYOUT(
        _______,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            KC_PPLS, KC_AMPR, KC_ASTR, KC_UNDS, _______, _______,
        _______,  _______, _______, _______, _______, _______,                            KC_EQL,  KC_DLR,  KC_PERC, KC_CIRC, KC_GRV,  _______,
        _______,  _______, _______, _______, _______, _______,                            KC_PMNS, KC_EXLM, KC_AT,   KC_HASH, KC_TILD, _______,
                                             _______, _______, _______,         _______,  _______, _______
    ),
    // mouse layer
    [4] = LAYOUT(
        _______,  _______, _______, _______,     _______,        _______,                        _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______, _______,     _______,        _______,                        _______,  _______,    _______, _______, _______, _______,
        _______,  _______, _______, _______,     _______,        _______,                        _______,  MS_LEFT,    MS_DOWN, MS_UP,   MS_RGHT, _______,
        _______,  _______, _______, _______,     _______,        _______,                        _______,  _______,    _______, _______, _______, _______,
                                                 _______,        _______, _______,      MS_BTN1,  MS_BTN2, KC_PDOT
    ),
    // function keys
    [5] = LAYOUT(
        _______,  KC_F1,   KC_F2,    KC_F3,     KC_F4,          KC_F5,                                    _______, _______,    _______, _______, _______, _______,
        _______,  KC_F6,   KC_F7,    KC_F8,     KC_F9,          KC_F10,                                   _______, _______,    _______, _______, _______, _______,
        _______,  KC_F11,  KC_F12,   KC_F13,    KC_F14,         KC_F15,                                   _______, MS_LEFT,    MS_DOWN, MS_UP,   MS_RGHT, _______,
        _______,  _______, _______,  _______,   KC_VOLU,        KC_VOLD,                                  _______, KC_KB_MUTE, _______, _______, _______, _______,
                                                KC_MPRV,        KC_MNXT, KC_MEDIA_PLAY_PAUSE,   MS_BTN1,  MS_BTN2, KC_PDOT
    ),
    // gaming layer
    [6] = LAYOUT(
                TO(0),    KC_1,     KC_2,    KC_3,  KC_4,     KC_5,                               KC_6,          KC_7,        KC_8,           KC_9,            KC_0,     LT(4, KC_DEL),
               KC_TAB,    KC_Q,     KC_W,    KC_E,  KC_R,     KC_T,                               KC_Y,          KC_U,        KC_I,           KC_O,            KC_P,           KC_BSLS,
               KC_ESC,    KC_A,     KC_S,    KC_D,  KC_F,     KC_G,                               KC_H,          KC_J,        KC_K,           KC_L,            KC_SCLN,        KC_QUOT,
              KC_LSFT,    KC_Z,     KC_X,    KC_C,  KC_V,     KC_B,                               KC_N,    CTL_T(KC_M), ALT_T(KC_COMM), GUI_T(KC_DOT),         KC_SLSH,        KC_RSFT,
                                                KC_SPC,  KC_SPC,  KC_SPC,                   KC_SPC,  KC_ENT,  KC_RALT
    ),
};


