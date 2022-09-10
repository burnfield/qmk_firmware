#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "keymap_swedish.hh"
enum layers {
  _QWE = 0,
  _NAV,
  _SYM,
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
  IO_CHAT,
  PERDAS_ODIA,
  PERDAS_ADIA,
  PERDAS_ARNG,
  COMPER_CRBR,
  MCOM_RBRC,
};
const uint16_t PROGMEM we_combo[] = {SE_W, SE_E, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {SE_S, SE_D, COMBO_END};

const uint16_t PROGMEM xc_combo[] = {LALT_T(SE_X), LSFT_T(SE_C), COMBO_END};
const uint16_t PROGMEM cv_combo[] = {LSFT_T(SE_C), LCTL_T(SE_V), COMBO_END};

const uint16_t PROGMEM io_combo[] = {SE_I, SE_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {SE_K, SE_L, COMBO_END};

const uint16_t PROGMEM perdas_combo[] = {SE_SLSH, LALT_T(SE_DOT), COMBO_END};
const uint16_t PROGMEM perdas0_combo[] = {SE_L, HM_SCLN, COMBO_END};
const uint16_t PROGMEM perdas1_combo[] = {SE_O, SE_P, COMBO_END};

const uint16_t PROGMEM comper_combo[] = {LALT_T(SE_DOT), RSFT_T(SE_COMM),
                                         COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {RSFT_T(SE_COMM), RCTL_T(SE_M),
                                       COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [WE_ESC] = COMBO(we_combo, KC_ESC),
    [SD_TAB] = COMBO(sd_combo, KC_TAB),

    [XC_CLBR] = COMBO(xc_combo, SE_LBRC),
    [CV_LPRN] = COMBO(cv_combo, SE_LCBR),

    [KL_ENT] = COMBO(kl_combo, KC_ENT),
    [IO_CHAT] = COMBO(io_combo, KC_F20),

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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWE] = LAYOUT(
    SE_Q,    SE_W,    SE_E,    SE_R,    SE_T,    /**/ SE_Y,    SE_U,    SE_I,    SE_O,    SE_P,
    SE_GUIA, SE_S,    SE_D,    SE_F,    SE_G,    /**/ SE_H,    SE_J,    SE_K,    SE_L,    HM_SCLN,
    SE_Z,    SE_ALTX, SE_SFTC, SE_CTLV, SE_B,    /**/ SE_N,    SE_CTLM, SE_SFTM, SE_ALTD, SE_SLSH,
  						       KC_SPC,  NAV,     /**/ SYM,     KC_BSPC),

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
};
// clang-format on
