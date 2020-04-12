#include QMK_KEYBOARD_H


#define _BASE 0
#define _NUMBERS 1
#define _I3WM 2
#define _MOUSE 3

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,----------------------------------,                             ,----------------------------------,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         |   -  |   =  |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      | ESC  |  BS  |                             | SPACE|ENTER |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
 *                      '------+------'                             '------+------'
 */

[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_QUOT, \
       KC_LBRC, KC_RBRC,                                                   MT(MOD_LCTL, KC_MINS), KC_EQL,                   \
                        LT(_I3WM, KC_BSPC), SFT_ESC,   SFT_ENT, LT(_NUMBERS, KC_SPC),                \
                                             ____, ____,  ____, ____,                                                 \
                                             ____, ____,  ____, ____                                                  \
),

/* NUMBERS
 * ,----------------------------------,                             ,----------------------------------,
 * |  !   |  @   |  #   |  $   |  %   |                             |  ^   |  &   |  *   |  (   |  )   |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |                             |  6   |  7   |  8   |  9   |  0   |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |  ~   | TAB  |      |      |      |                             |      |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      | F12  |                                                         |  [   |  ]   |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 */

[_NUMBERS] = LAYOUT( \
  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, \
  KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
  KC_TILDE, KC_TAB,  ____,  ____,  ____,                            KC_F6,  KC_SLSH,   KC_BSLS,   KC_QUES, KC_PIPE,  \
           ____, KC_F12,                                                               KC_LBRC, KC_RBRC,             \
                                         ____, KC_LALT,  ____, ____,                                               \
                                           ____, ____,  ____, ____,                                               \
                                           ____, ____,  ____, ____                                                \
),

/* i3wm
 * ,----------------------------------,                             ,----------------------------------,
 * | MUTE | VOL- | VOL+ |      |      |                             |      |      | HOME | END  | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * | gui+1| gui+2| gui+3| gui+4| gui+5|                             | gui+h| gui+j| gui+k| gui+l| PgUp |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * | RESET| mleft| mdup |mright|      |                             |      | left |  up  |right |      |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        | mbtn | mdow |                                                         | down |      |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      | '------+------'                             '------+------'
 */

[_I3WM] = LAYOUT( \
  KC_MUTE, KC_VOLD, KC_VOLU, ____,  ____,                            ____,  ____,    KC_HOME,   KC_END,   KC_PGUP,  \
  LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),         LGUI(KC_H), LGUI(KC_J), LGUI(KC_K), LGUI(KC_L), KC_PGDOWN,  \
  RESET, KC_ML,  KC_MU, KC_MR, KC_PERC,                          KC_CIRC, KC_LEFT, KC_UP, KC_RIGHT, KC_RPRN, \
           KC_MB1, KC_MD,                                                               KC_DOWN,    ____,             \
                                           ____, ____, ____, ____,                                   \
                                           ____, ____,  ____, ____,                                               \
                                           ____, ____,  ____, ____                                                \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}


