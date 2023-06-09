// Copyright 2023 Kevin Ohlin (@ohlin)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Layers
#define QWERTY   DF(_QWERTY)
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
// Home row mods
#define CTL_A    LCTL_T(KC_A)
#define OPT_S    LOPT_T(KC_S)
#define CMD_D    LCMD_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define SFT_J    RSFT_T(KC_J)
#define CMD_K    RCMD_T(KC_K)
#define OPT_L    LOPT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)
// Other
#define CTL_ESC  MT(MOD_LCTL, KC_ESC)
#define CTL_QUOT MT(MOD_RCTL, KC_QUOTE)
#define CTL_MINS MT(MOD_RCTL, KC_MINUS)
#define RSE_ENT  LT(_RAISE, KC_ENT)
#define LWR_SPC  LT(_LOWER, KC_SPC)
#define SFT_SPC  MT(MOD_LSFT, KC_SPC)
#define YTC      LOPT(KC_X)
#define YTSD     LSA(KC_LT)
#define YTSU     LSA(KC_GT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                                               ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                                               |   Y  |   U  |   I  |   O  |   P  |   F3   |
 * |--------+------+------+------+------+------|                                               |------+------+------+------+------+--------|
 * |Ctrl/Esc| CTL/A| OPT/S| CMD/D| SFT/F|   G  |                                               |   H  | SFT/J| CMD/K| OPT/L| CTL/;| RClick |
 * |--------+------+------+------+------+------+-------------.                   ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  ' " | Hyper|                   | Hyper|  ` ~ |   N  |   M  | ,  < | . >  |  / ? | LClick |
 * `----------------------+------+------+------+------+------|                   |------+------+------+------+------+----------------------'
 *                        |Scroll| LCMD |Raise/|Shift/| Lower|                   | Raise|Lower/|Delete| RCMD |Scroll|
 *                        |      |      | Enter| Space|      |                   |      | Space|      |      |      |
 *                        `----------------------------------'                   `----------------------------------'
 */
[_QWERTY] = LAYOUT(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,     KC_F3,
    CTL_ESC,  CTL_A,   OPT_S,   CMD_D,   SFT_F,   KC_G,                                            KC_H,    SFT_J,   CMD_K,   OPT_L,  CTL_SCLN, KC_BTN2,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_QUOTE, KC_HYPR,    KC_HYPR, KC_GRV,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,  KC_BTN1,
                                KC_BTN5, KC_LCMD, RSE_ENT, SFT_SPC,  LOWER,      RAISE,   SFT_SPC, KC_BSPC, KC_RCMD, KC_BTN5
),

/*
 * Lower Layer
 *
 * ,-----------------------------------------.                                               ,-------------------------------------------.
 * |      |      |  7   |  8   |  9   |  0   |                                               | ScrUp| ScrLt|MouseU| ScrRt|      |        |
 * |------|------+------+------+------+------+                                               |------+------+------+------+------+--------|
 * |      |      |  4   |  5   |  6   |  +   |                                               | ScrDn|MouseL|MouseD|MouseR|      |        |
 * |------+------+------+------+------+------+-------------.                   ,-------------+------+------+------+------+------+--------|
 * |      |  0   |  1   |  2   |  3   |  -   |      |Shift |                   |      |      |      |LftClk| RtClk|      |      |        |
 * `--------------------+------+------+------+------+------|                   |------+------+------+------+------+----------------------'
 *                      |  (   |  {   |  }   |  )   |xxxxxx|                   |      |LftClk| RtClk|      |      |
 *                      |      |  [   |  ]   |      |xxxxxx|                   |      |      |      |      |      |
 *                      `----------------------------------'                   `----------------------------------'
 */
[_LOWER] = LAYOUT(
    _______, _______, KC_7,   KC_8,    KC_9,    KC_0,                                            KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, _______, _______,
    _______, _______, KC_4,   KC_5,    KC_6,    KC_EQL,                                          KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, KC_0,    KC_1,   KC_2,    KC_3,    KC_MINUS, _______, KC_LSFT,    _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, _______,
                              KC_LPRN, KC_LBRC, KC_RBRC,  KC_RPRN, _______,    _______, KC_BTN1, KC_BTN2, _______, _______
),

/*
 * Raise Layer
 *
 * ,-------------------------------------------.                                              ,-------------------------------------------.
 * |    `   |      |  &   |  *   |  (   |  |   |                                              | VolUp|      |   ↑  |      |      |        |
 * |--------+------+------+------+------+------|                                              |------+------+------+------+------+--------|
 * |    ~   |      |  $   |  %   |  ^   |  \   |                                              | VolDn|  ←   |   ↓  |   →  |      |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.                  ,-------------+------+------+------+------+------+--------|
 * |    |   |      |  !   |  @   |  #   |  /   |      |      |                  |      |      |VolMut| Opt+C|  <   |   >  |      |        |
 * `----------------------+------+------+------+------+------|                  |------+------+------+------+------+----------------------'
 *                        |  (   |  {   |  }   |  )   |      |                  |xxxxxx|      |      |      |      |
 *                        |      |  [   |  ]   |      |      |                  |xxxxxx|      |      |      |      |
 *                        `----------------------------------'                  `----------------------------------'
 */
[_RAISE] = LAYOUT(
    KC_GRV,  _______, S(KC_7), S(KC_8), S(KC_9), KC_PIPE,                                        KC_VOLU, _______, KC_UP,   _______, _______, _______,
    KC_TILD, _______, S(KC_4), S(KC_5), S(KC_6), KC_BSLS,                                        KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, _______, CTL_QUOT,
    KC_PIPE, _______, S(KC_1), S(KC_2), S(KC_3), KC_SLSH, _______, _______,    _______, _______, KC_MUTE, YTC,     YTSD,    YTSU,    _______, _______,
                               KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,    _______, _______, _______, _______, _______
),

/*
 * Adjust Layer: RGB
 *
 * ,-------------------------------------------.                                            ,-------------------------------------------.
 * |        |      |      |      |      |      |                                            |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                                            |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                                            | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.                ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |                |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|                |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |xxxxxx|                |xxxxxx|      |      |      |      |
 *                        |      |      |      |      |xxxxxx|                |xxxxxx|      |      |      |      |
 *                        `----------------------------------'                `----------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______,  _______,
    _______, _______, _______, _______, _______, _______,                                       RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_M_P,  _______,
    _______, _______, _______, _______, _______, _______,_______, _______,    _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_M_SW, _______,
                               _______, _______, _______,_______, _______,    _______, _______, _______, _______, _______
),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                                               ,-------------------------------------------.
//  * |        |      |      |      |      |      |                                               |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                                               |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                                               |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.                   ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |                   |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|                   |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |                   |      |      |      |      |      |
//  *                        |      |      |      |      |      |                   |      |      |      |      |      |
//  *                        `----------------------------------'                   `----------------------------------'
//  */
//  [_LAYERINDEX] = LAYOUT(
//      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
//                                 _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//      ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("\nKyria rev2.1\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM ko_logo[] = {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
            0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0x70, 0x18, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
            0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfe, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0x7f, 0x1f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 
            0x30, 0x18, 0x8c, 0xe6, 0x73, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 
            0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
            0x3f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 0x80, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
            0x00, 0x00, 0x80, 0xc0, 0xf0, 0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x0f, 
            0x07, 0x01, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0xc0, 0xf0, 
            0x78, 0x1e, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 
            0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x07, 0x01, 0x00, 0x80, 0xc0, 0x60, 
            0x30, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0e, 0x0f, 0x0f, 0x0d, 
            0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x8d, 0xcd, 0xed, 0x7d, 
            0x3d, 0xbd, 0xdd, 0xed, 0xf5, 0xf1, 0xf9, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x07, 
            0x07, 0x0f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf1, 0xc7, 0x86, 0x06, 
            0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x86, 0xe6, 0xfe, 0x7e, 
            0x1e, 0x0e, 0x02, 0x80, 0xc0, 0xc0, 0x60, 0x70, 0x38, 0x1c, 0x0e, 0x07, 0xf3, 0xf9, 0xfc, 0xfe, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
            0xfc, 0xf0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x78, 0xbc, 0xcf, 0xc7, 0xe3, 0x70, 0x38, 
            0x1c, 0x0e, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
            0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
            0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 
            0x7f, 0x9f, 0xcf, 0xf3, 0xf8, 0x7e, 0xbf, 0xdf, 0x8f, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0f, 
            0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 
            0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x01, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x11, 0x0d, 
            0x06, 0x03, 0x03, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
            0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
        // clang-format on
        oled_write_raw_P(ko_logo, sizeof(ko_logo));
    }
    return false;
}
#endif
