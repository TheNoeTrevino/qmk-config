// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // default
    [0] = LAYOUT(
       // LT(4, KC_PSCR),        KC_1,         KC_2,           KC_3,           KC_4,     KC_5,                               KC_6,          KC_7,        KC_8,           KC_9,            KC_0,     LT(4, KC_DEL),
                TO(5),        KC_1,         KC_2,           KC_3,           KC_4,     KC_5,                               KC_6,          KC_7,        KC_8,           KC_9,            KC_0,     LT(4, KC_DEL),
               KC_TAB,        KC_Q,         KC_W,           KC_E,           KC_R,     KC_T,                               KC_Y,          KC_U,        KC_I,           KC_O,            KC_P,           KC_BSLS,
               KC_ESC,        KC_A,   LT(3, KC_S),    LT(2, KC_D),    LT(1, KC_F),    KC_G,                               KC_H,          KC_J,        KC_K,           KC_L,            KC_SCLN,        KC_QUOT,
              KC_LSFT,        KC_Z,   GUI_T(KC_X),    ALT_T(KC_C),    CTL_T(KC_V),    KC_B,                               KC_N,    CTL_T(KC_M), ALT_T(KC_COMM), GUI_T(KC_DOT),         KC_SLSH,        KC_RSFT,
                                                                  KC_LSFT,  KC_RCTL, KC_BSPC,                   KC_SPC,  KC_ENT,  KC_RSFT
    ),
    // keypad
    [1] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PPLS, KC_7,   KC_8,   KC_9,   KC_RBRC, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_EQL,  KC_4,   KC_5,   KC_6,   KC_RGHT, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PMNS, KC_1,   KC_2,   KC_3,   KC_RCBR, KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,          KC_P0,   KC_TRNS, KC_PDOT
    ),
    // pairs
    [2] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PPLS, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_EQL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PMNS, KC_LCBR, KC_LT,   KC_GT,   KC_RCBR, KC_TRNS,
                                             KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    // symbols
    [3] = LAYOUT(
        KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PPLS, KC_AMPR, KC_ASTR, KC_UNDS, KC_UNDS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_EQL,  KC_DLR,  KC_PERC, KC_CIRC, KC_GRV,  KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_PMNS, KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_TRNS,// TODO: add tilde here
                                             KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_PDOT
    ),
    // misc
    [4] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,       KC_F5,          KC_F6,                                    KC_F6,   KC_F7,      KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_F7,    KC_F8,   KC_F9,   KC_F10,      KC_F11,         KC_F12,                                   KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,     KC_WWW_SEARCH,  KC_VOLU,                                  KC_TRNS, MS_LEFT,    MS_DOWN, MS_UP,   MS_RGHT, KC_TRNS,
        KC_TRNS,  KC_TRNS, KC_TRNS, KC_KB_MUTE,  KC_MAIL,        KC_VOLD,                                  KC_TRNS, KC_KB_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_MPRV,        KC_MNXT, KC_MEDIA_PLAY_PAUSE,   MS_BTN1,  MS_BTN2, KC_PDOT
    ),
    [5] = LAYOUT(
                TO(0),        KC_1,         KC_2,           KC_3,           KC_4,     KC_5,                               KC_6,          KC_7,        KC_8,           KC_9,            KC_0,     LT(4, KC_DEL),
               KC_TAB,        KC_Q,         KC_W,           KC_E,           KC_R,     KC_T,                               KC_Y,          KC_U,        KC_I,           KC_O,            KC_P,           KC_BSLS,
               KC_ESC,        KC_A,   KC_S,    KC_D, KC_F,   KC_G,                               KC_H,          KC_J,        KC_K,           KC_L,            KC_SCLN,        KC_QUOT,
              KC_LSFT,        KC_Z,    KC_X ,    KC_C,    KC_V,    KC_B,                               KC_N,    CTL_T(KC_M), ALT_T(KC_COMM), GUI_T(KC_DOT),         KC_SLSH,        KC_RSFT,
                                                                   KC_SPC,  KC_SPC,  KC_SPC,                   KC_SPC,  KC_ENT,  KC_RALT
    ),
};


