#include QMK_KEYBOARD_H
enum layers {
  _QWE = 0,
  _NAV,
  _FN,
  _SYM,
  _OSL,
  _I3SW,
  _I3MV,
};

enum custom_keycodes {
  MT_TMUX = SAFE_RANGE,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MT_TMUX:
    if (record->event.pressed) {
      tap_code16(RCTL(KC_Q));
      set_oneshot_layer(_OSL, ONESHOT_START);
    }
    return false;
  case KC_1 ... KC_0:
    if (record->event.pressed) {
      tap_code16(keycode);
      clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
    return false;
  }
  return true;
};

// Left side
#define KC_GUIA LGUI_T(KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_SFTD LSFT_T(KC_D)
#define KC_CTLF RCTL_T(KC_F)

#define HM_EXLM KC_EXLM
#define HM_AT KC_AT
#define HM_HASH KC_HASH
#define HM_DLR KC_DLR

// Right side qwerty
#define KC_ALTL LALT_T(KC_L)
#define KC_SFTK RSFT_T(KC_K)
#define KC_CTLJ RCTL_T(KC_J)
#define KC_GUISCLN LGUI_T(KC_SCLN)

#define HM_LPRN KC_LPRN
#define HM_ASTR KC_ASTR
#define HM_AMPR KC_AMPR
#define HM_RPRN KC_RPRN

enum combos {
  Q_W_ESC,
  S_D_TAB,
  X_C_LBRC,
  C_V_LCBR,
  K_L_ENT,
  I_O_TMUX,
  U_I_I3SW,
  Y_U_I3MV,
  COMM_DOT_RBRC,
  M_COMM_RCBR,
};

const uint16_t PROGMEM w_e_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM s_d_combo[] = {KC_ALTS, KC_SFTD, COMBO_END};

const uint16_t PROGMEM x_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM c_v_combo[] = {KC_C, KC_V, COMBO_END};

const uint16_t PROGMEM i_o_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM u_i_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM y_u_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM k_l_combo[] = {KC_SFTK, KC_ALTL, COMBO_END};

const uint16_t PROGMEM comm_dot_combo[] = {KC_DOT, KC_COMM, COMBO_END};
const uint16_t PROGMEM m_comm_combo[] = {KC_COMM, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [Q_W_ESC] = COMBO(w_e_combo, KC_ESC),
    [S_D_TAB] = COMBO(s_d_combo, KC_TAB),

    [X_C_LBRC] = COMBO(x_c_combo, KC_LBRC),
    [C_V_LCBR] = COMBO(c_v_combo, KC_LCBR),

    [K_L_ENT] = COMBO(k_l_combo, KC_ENT),
    [I_O_TMUX] = COMBO(i_o_combo, MT_TMUX),
    [U_I_I3SW] = COMBO(u_i_combo, OSL(_I3SW)),
    [Y_U_I3MV] = COMBO(y_u_combo, OSL(_I3MV)),

    [COMM_DOT_RBRC] = COMBO(comm_dot_combo, KC_RBRC),
    [M_COMM_RCBR] = COMBO(m_comm_combo, KC_RCBR),
};

// Aliases for readability
#define QWE DF(_QWE)
#define SYM MO(_SYM)
#define NAV MO(_NAV)
#define BSPC_FN LT(_FN, KC_BSPC)

// define i3 swap
#define SW_1 LGUI(KC_1)
#define SW_2 LGUI(KC_2)
#define SW_3 LGUI(KC_3)
#define SW_4 LGUI(KC_4)
#define SW_5 LGUI(KC_5)
#define SW_6 LGUI(KC_6)
#define SW_7 LGUI(KC_7)
#define SW_8 LGUI(KC_8)
#define SW_9 LGUI(KC_9)
#define SW_0 LGUI(KC_0)

// define i3 swap
#define MV_1 RSG(KC_1)
#define MV_2 RSG(KC_2)
#define MV_3 RSG(KC_3)
#define MV_4 RSG(KC_4)
#define MV_5 RSG(KC_5)
#define MV_6 RSG(KC_6)
#define MV_7 RSG(KC_7)
#define MV_8 RSG(KC_8)
#define MV_9 RSG(KC_9)
#define MV_0 RSG(KC_0)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWE] = LAYOUT(
    _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      /**/                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,       _______,
    _______, KC_GUIA, KC_ALTS, KC_SFTD, KC_CTLF, KC_G,                      /**/                   KC_H,    KC_CTLJ, KC_SFTK, KC_ALTL, KC_GUISCLN, _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, /**/ _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    _______,
  		                       _______, _______, KC_SPC,  NAV,     _______, /**/ _______, SYM,     KC_BSPC, _______, _______),

  [_SYM] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,                      /**/                   KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    _______,
    _______, HM_EXLM, HM_AT,   HM_HASH, HM_DLR,     KC_PERC,                   /**/                   KC_CIRC, HM_AMPR, HM_ASTR, HM_LPRN,  HM_RPRN, _______,
    _______, KC_MINS, KC_UNDS, KC_QUOT, S(KC_QUOT), KC_BSLS, _______, _______, /**/ _______, _______, KC_PIPE, KC_PLUS,  KC_EQL, KC_GRV,  KC_TILD,  _______,
                                  _______, _______, _______, KC_TRNS, _______, /**/ _______, KC_TRNS, _______, _______, _______),

  [_NAV] = LAYOUT(
    _______, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS, _______,
  	_______, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, _______,
  	_______, KC_TRNS, KC_TRNS ,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  							   KC_TRNS, KC_TRNS, MO(_FN), KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS, KC_TRNS),
  [_FN] = LAYOUT(
    _______, KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,                     /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, _______,
  	_______, KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,                    /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, _______,
  	_______, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, _______,
                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_OSL] = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      /**/                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  							   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_I3SW] = LAYOUT(
    _______, SW_1,    SW_2,    SW_3,    SW_4,    SW_5,                      /**/                   SW_6,    SW_7,    SW_8,    SW_9,    SW_0,    _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  							   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

  [_I3MV] = LAYOUT(
    _______, MV_1,    MV_2,    MV_3,    MV_4,    MV_5,                      /**/                   MV_6,    MV_7,    MV_8,    MV_9,    MV_0,    _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   /**/                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  	_______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______,
  							   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, /**/ KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
// clang-format on
