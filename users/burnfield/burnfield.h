#pragma once
#include QMK_KEYBOARD_H
#include "oneshot.h"
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

enum layers {
    _COLE = 0,
    _QWE,
    _SYM,
    _NAV,
    _FN,
};

// Aliases for readability
#define QWE DF(_QWE)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define FN MO(_FN)

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

#define _______________COLEMAK_L1_______________ KC_Q, KC_W, KC_F, KC_P, KC_B
#define _______________COLEMAK_L2_______________ KC_A, KC_R, KC_S, KC_T, KC_G
#define _______________COLEMAK_L3_______________ KC_Z, KC_X, KC_C, KC_D, KC_V

#define _______________COLEMAK_R1_______________ KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define _______________COLEMAK_R2_______________ KC_M, KC_N, KC_E, KC_I, KC_O
#define _______________COLEMAK_R3_______________ KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH

#define _______________QWERTY_L1________________ KC_Q, KC_W, KC_E, KC_R, KC_T
#define _______________QWERTY_L2________________ KC_A, KC_S, KC_D, KC_F, KC_G
#define _______________QWERTY_L3________________ KC_Z, KC_X, KC_C, KC_V, KC_D

#define _______________QWERTY_R1________________ KC_Y, KC_U, KC_I, KC_O, KC_P
#define _______________QWERTY_R2________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define _______________QWERTY_R3________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define _______________SYM_L1___________________ KC_ESC, KC_LBRC, KC_LCBR, KC_LPRN, KC_CIRC
#define _______________SYM_L2___________________ KC_TAB, KC_QUOT, KC_EQL, KC_MINS, KC_BSLS
#define _______________SYM_L3___________________ KC_ASTR, S(KC_QUOT), KC_PLUS, KC_UNDS, KC_PIPE

#define _______________SYM_R1___________________ KC_DLR, KC_RPRN, KC_RCBR, KC_RBRC, KC_AT
#define _______________SYM_R2___________________ KC_GRV, OS_CTRL, OS_SHFT, OS_ALT, OS_GUI
#define _______________SYM_R3___________________ KC_TILD, KC_EXLM, KC_AMPR, KC_PERC, KC_HASH

#define _______________NAV_L1___________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define _______________NAV_L2___________________ OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, _______
#define _______________NAV_L3___________________ KC_DEL, _______, RCTL(KC_W), RCTL(KC_Q), CW_TOGG

#define _______________NAV_R1___________________ KC_6, KC_7, KC_8, KC_9, KC_0
#define _______________NAV_R2___________________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT
#define _______________NAV_R3___________________ KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSPC

#define _______________NUM_L1___________________ KC_1, KC_2, KC_3, KC_4, KC_5
#define _______________NUM_L2___________________ OS_GUI, OS_ALT, OS_SHFT, OS_CTRL, KC_F11
#define _______________NUM_L3___________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5

#define _______________NUM_R1___________________ KC_6, KC_7, KC_8, KC_9, KC_0
#define _______________NUM_R2___________________ KC_F12, OS_CTRL, OS_SHFT, OS_ALT, OS_GUI
#define _______________NUM_R3___________________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define ___LTHUMBKEYS___ KC_SPC, NAV
#define ___RTHUMBKEYS___ SYM, KC_RSFT

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case SYM:
        case NAV:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case SYM:
        case NAV:
        case KC_LSFT:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_RCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _FN);
}
