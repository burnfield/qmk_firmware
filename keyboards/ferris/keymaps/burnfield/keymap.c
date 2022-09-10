#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "keymap_swedish.hh"
enum layers {
  _QWE = 0,
  _NAV,
  _SYM,
  _OSL,
  _I3SW,
  _I3MV,
};

enum custom_keycodes {
  MT_EXLM = SAFE_RANGE,
  MT_BSLS,
  MT_PIPE,
  MT_QUOT,
  MT_EQL,
  MT_UNDS,
  MT_MINS,
  MT_RPRN,
  MT_SCLN,
  SE_GRV,
  MT_CIRC,
  MT_TILD,
  MT_TMUX,
  SE_CPSW,
  SE_ENT,
  SE_ESC,
  SE_SPC,
};

#define HM_EXLM LGUI_T(MT_EXLM)
#define HM_BSLS LALT_T(MT_BSLS)
#define HM_PIPE LSFT_T(MT_PIPE)
#define HM_QUOT LCTL_T(MT_QUOT)
#define HM_EQL RCTL_T(MT_EQL)
#define HM_UNDS RSFT_T(MT_UNDS)
#define HM_MINS LALT_T(MT_MINS)
#define HM_RPRN RGUI_T(MT_RPRN)
#define HM_SCLN RGUI_T(MT_SCLN)

const custom_shift_key_t custom_shift_keys[] = {
    {RSFT_T(SE_COMM), SE_LABK}, // Shift , is !
    {LALT_T(SE_DOT), SE_RABK},  // Shift . is ?
    {HM_SCLN, SE_COLN},         // Shift : is ;
    {SE_SLSH, SE_QUES},         // Shift : is ;
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// Left side
#define SE_GUIA LGUI_T(SE_A)
#define SE_ALTX LALT_T(SE_X)
#define SE_SFTC LSFT_T(SE_C)
#define SE_CTLV LCTL_T(SE_V)

#define LGUI_F5 LGUI_T(KC_F5)
#define LALT_F2 LALT_T(KC_F2)
#define LSFT_F3 LSFT_T(KC_F3)
#define LCTL_F4 LCTL_T(KC_F4)

// Right side qwerty
#define SE_ALTD LALT_T(SE_DOT)
#define SE_SFTM RSFT_T(SE_COMM)
#define SE_CTLM RCTL_T(SE_M)
#define CTL_LFT RCTL(KC_LEFT)
#define CTL_RGT RCTL(KC_RGHT)

bool caps_word = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HM_EQL:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_EQL);
      }
      return false;
    }
  case HM_UNDS:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_UNDS);
      }
      return false;
    }
  case HM_MINS:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_MINS);
      }
      return false;
    }
  case HM_RPRN:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_RPRN);
      }
      return false;
    }
  case HM_EXLM:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_EXLM);
      }
      return false;
    }
  case HM_BSLS:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_BSLS);
      }
      return false;
    }
  case HM_PIPE:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_PIPE);
      }
      return false;
    }
  case HM_QUOT:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_QUOT);
      }
      return false;
    }
  case HM_SCLN:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        tap_code16(SE_SCLN);
      }
      return false;
    }
  case SE_GRV:
    if (record->event.pressed) {
      tap_code16(KC_PLUS);
      tap_code16(KC_PLUS);
      tap_code16(KC_BSPC);
    }
    return false;
  case MT_TILD:
    if (record->event.pressed) {
      tap_code16(SE_TILD);
      tap_code16(SE_TILD);
      tap_code16(KC_BSPC);
    }
    return false;
  case MT_CIRC:
    if (record->event.pressed) {
      tap_code16(SE_CIRC);
      tap_code16(SE_CIRC);
      tap_code16(KC_BSPC);
    }
    return false;
  case MT_TMUX:
    if (record->event.pressed) {
      tap_code16(LCTL(SE_Q));
      set_oneshot_layer(_OSL, ONESHOT_START);
    }
    return false;
  case KC_1 ... KC_0:
    if (record->event.pressed) {
      tap_code16(keycode);
      clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    return false;
  case SE_A ... SE_Z:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(LSFT(keycode));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  case SE_ENT:
    if (record->event.pressed) {
      if (caps_word) {
        caps_word = false;
      } else {
        tap_code16(KC_ENT);
      }
    }
    return false;
  case SE_SPC:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(SE_UNDS);
      } else {
        tap_code16(KC_SPC);
      }
    }
    return false;
  case SE_ESC:
    if (record->event.pressed) {
      if (caps_word) {
        caps_word = false;
      } else {
        tap_code16(KC_ESC);
      }
    }
    return false;
  case SE_CPSW:
    if (record->event.pressed) {
      caps_word = !caps_word;
    }
    return false;
  case SE_GUIA:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(RSFT(SE_A));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  case SE_ALTX:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(RSFT(SE_X));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  case SE_SFTC:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(RSFT(SE_C));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  case SE_CTLV:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(RSFT(SE_V));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  case SE_CTLM:
    if (record->event.pressed) {
      if (caps_word) {
        tap_code16(RSFT(SE_M));
      } else {
        tap_code16(keycode);
      }
    }
    return false;
  }
  if (!process_custom_shift_keys(keycode, record)) {
    return false;
  }
  return true;
};

enum combos {
  WE_ESC,
  SD_TAB,
  XC_CLBR,
  CV_LPRN,
  KL_ENT,
  IO_TMUX,
  UI_I3SW,
  YU_I3MV,
  PERDAS_ODIA,
  PERDAS_ADIA,
  PERDAS_ARNG,
  COMPER_CRBR,
  MCOM_RBRC,
  CAP_WORD,
};
const uint16_t PROGMEM we_combo[] = {SE_W, SE_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {SE_S, SE_D, COMBO_END};

const uint16_t PROGMEM xc_combo[] = {LALT_T(SE_X), LSFT_T(SE_C), COMBO_END};
const uint16_t PROGMEM cv_combo[] = {LSFT_T(SE_C), LCTL_T(SE_V), COMBO_END};

const uint16_t PROGMEM io_combo[] = {SE_I, SE_O, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {SE_U, SE_I, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {SE_Y, SE_U, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {SE_K, SE_L, COMBO_END};
const uint16_t PROGMEM capsword_combo[] = {SE_SPC, KC_BSPC, COMBO_END};

const uint16_t PROGMEM perdas_combo[] = {SE_SLSH, LALT_T(SE_DOT), COMBO_END};
const uint16_t PROGMEM perdas0_combo[] = {SE_L, HM_SCLN, COMBO_END};
const uint16_t PROGMEM perdas1_combo[] = {SE_O, SE_P, COMBO_END};

const uint16_t PROGMEM comper_combo[] = {LALT_T(SE_DOT), RSFT_T(SE_COMM),
                                         COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {RSFT_T(SE_COMM), RCTL_T(SE_M),
                                       COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [WE_ESC] = COMBO(we_combo, SE_ESC),
    [SD_TAB] = COMBO(sd_combo, KC_TAB),

    [XC_CLBR] = COMBO(xc_combo, SE_LBRC),
    [CV_LPRN] = COMBO(cv_combo, SE_LCBR),

    [KL_ENT] = COMBO(kl_combo, SE_ENT),
    [IO_TMUX] = COMBO(io_combo, MT_TMUX),
    [UI_I3SW] = COMBO(ui_combo, OSL(_I3SW)),
    [YU_I3MV] = COMBO(yu_combo, OSL(_I3MV)),

    [CAP_WORD] = COMBO(capsword_combo, SE_CPSW),

    [PERDAS_ODIA] = COMBO(perdas_combo, SE_ODIA),
    [PERDAS_ADIA] = COMBO(perdas0_combo, SE_ADIA),
    [PERDAS_ARNG] = COMBO(perdas1_combo, SE_ARNG),

    [COMPER_CRBR] = COMBO(comper_combo, SE_RBRC),
    [MCOM_RBRC] = COMBO(mcom_combo, SE_RCBR),
};

// Aliases for readability
#define QWE DF(_QWE)
#define SYM MO(_SYM)
#define NAV MO(_NAV)

// define i3 swap
#define SW_1 LALT_T(KC_1)
#define SW_2 LALT_T(KC_2)
#define SW_3 LALT_T(KC_3)
#define SW_4 LALT_T(KC_4)
#define SW_5 LALT_T(KC_5)
#define SW_6 LALT_T(KC_6)
#define SW_7 LALT_T(KC_7)
#define SW_8 LALT_T(KC_8)
#define SW_9 LALT_T(KC_9)
#define SW_0 LALT_T(KC_0)

// define i3 swap
#define MV_1 LSFT_T(LALT_T(KC_1))
#define MV_2 LSFT_T(LALT_T(KC_2))
#define MV_3 LSFT_T(LALT_T(KC_3))
#define MV_4 LSFT_T(LALT_T(KC_4))
#define MV_5 LSFT_T(LALT_T(KC_5))
#define MV_6 LSFT_T(LALT_T(KC_6))
#define MV_7 LSFT_T(LALT_T(KC_7))
#define MV_8 LSFT_T(LALT_T(KC_8))
#define MV_9 LSFT_T(LALT_T(KC_9))
#define MV_0 LSFT_T(LALT_T(KC_0))

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWE] = LAYOUT(
    SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    /**/ SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,
    SE_GUIA, SE_S,    SE_D,    SE_F,    SE_G,    /**/ SE_H,    SE_J,    SE_K,    SE_L,    HM_SCLN,
    SE_Z,    SE_ALTX, SE_SFTC, SE_CTLV, SE_B,    /**/ SE_N,    SE_CTLM, SE_SFTM, SE_ALTD, SE_SLSH,
  						       SE_SPC,  NAV,     /**/ SYM,     KC_BSPC),

  [_SYM] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    HM_EXLM, SE_AT,   SE_HASH, SE_DLR,  SE_PERC, /**/ MT_CIRC, SE_AMPR, SE_ASTR, SE_LPRN,  HM_RPRN,
    SE_GRV,  HM_BSLS, HM_PIPE, HM_QUOT, S(SE_2), /**/ SE_PLUS, HM_EQL,  HM_UNDS, HM_MINS,  MT_TILD,
                               _______, _______, /**/ _______, _______),

  [_NAV] = LAYOUT(
  	KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, /**/ KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
  	LGUI_F5, KC_F6,   KC_F7,   KC_F8,   _______, /**/ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LGUI,
  	KC_F1,   LALT_F2, LSFT_F3, LCTL_F4, _______, /**/ CTL_LFT, KC_RCTL, KC_RSFT, CTL_RGT, KC_LALT,
  							   _______, _______, /**/ _______, KC_DEL),

  [_OSL] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  							   KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS),

  [_I3SW] = LAYOUT(
    SW_1,    SW_2,    SW_3,    SW_4,    SW_5,    /**/ SW_6,    SW_7,    SW_8,    SW_9,     SW_0,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  							   KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS),

  [_I3MV] = LAYOUT(
    MV_1,    MV_2,    MV_3,    MV_4,    MV_5,    /**/ MV_6,    MV_7,    MV_8,    MV_9,     MV_0,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  	KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  							   KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS),
};
// clang-format on
