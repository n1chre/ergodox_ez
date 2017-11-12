#include QMK_KEYBOARD_H
#include "action_layer.h"

// layers
#define L_BASE 0 // base
#define L_SYMB 1 // symbols
#define L_NAVI 2 // navigation
#define L_SHOR 3 // shortcuts (spectacle, ...)
#define L_FUNC 4 // function keys and macros (TODO add macros)

#define ____________  KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// KC__ only works on macOS

/* Layer 0: Base layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   L2   |   1  |   2  |   3  |   4  |   5  |Cmd+X |           |Cmd+W |   6  |   7  |   8  |   9  |   0  |  TODO  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |Cmd+C |           |Shift+|   Y  |   U  |   I  |   O  |   P  |  TODO  |
 * |--------+------+------+------+------+------|      |           | Tab  |------+------+------+------+------+--------|
 * |Esc/Ctrl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  ~L3   |
 * |--------+------+------+------+------+------|Cmd+V |           | Tab  |------+------+------+------+------+--------|
 * | LShft  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |  RShft |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  ~L2 |  '   | `/Alt|  [   |]/Cmd |                                       | Cmd  |  ~L2 | Prev |Ply/Ps| Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | Del  | Mute |       | ~L4  |  ~L3   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Vol+ |       | Home |        |      |
 *                                 | Shift| Bspc/|------|       |------| Enter/ |Space/|
 *                                 |      |  Cmd | Vol- |       | End  |  Cmd   | ~L1  |
 *                                 `--------------------'       `----------------------'
 */
[L_BASE] = LAYOUT_ergodox(
      // left hand
      TG(L_NAVI),   KC_1,         KC_2,         KC_3,         KC_4,         KC_5,         LGUI(KC_X),
      KC_TAB,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         LGUI(KC_C),
      CTL_T(KC_ESC),KC_A,         KC_S,         KC_D,         KC_F,         KC_G,
      KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         LGUI(KC_V),
      MO(L_NAVI),   KC_QUOT,      ALT_T(KC_GRV),KC_LBRC,      GUI_T(KC_RBRC),

                                                KC_DEL,       KC__MUTE,
                                                              KC__VOLUP,
                                  OSM(MOD_LSFT),GUI_T(KC_BSPC),KC__VOLDOWN,

      // right hand
      LGUI(KC_W),   KC_6,         KC_7,         KC_8,         KC_9,         KC_0,         KC_NO,
      LSFT(KC_TAB), KC_Y,         KC_U,         KC_I,         KC_O,         KC_P,         KC_NO,
                    KC_H,         KC_J,         KC_K,         KC_L,         KC_SCOLON,    MO(L_SHOR),
      KC_TAB,       KC_N,         KC_M,         KC_COMMA,     KC_DOT,       KC_SLASH,     KC_RSFT,
                                  KC_RGUI,      MO(L_NAVI),   KC_MRWD,      KC_MPLY,      KC_MFFD,

                                  MO(L_FUNC),   MO(L_SHOR),
                                  KC_HOME,
                                  KC_END,       GUI_T(KC_ENT),LT(L_SYMB,KC_SPC)
),

/* Layer 1: Symbols layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |   @  |   #  |  $   |  %   |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  |   |   [  |   ]  |  ~   |      |           |      |      |  "   |   _  |  +   |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  \   |   (  |   )  |  `   |------|           |------|      |  '   |   -  |  =   |  :   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   {  |   }  |      |      |           |      |      |      |   <  |  >   |  ?   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_SYMB] = LAYOUT_ergodox(
  // left hand
  ____________, KC_EXLM,      KC_AT,        KC_HASH,      KC_DLR,       KC_PERC,      ____________,
  ____________, ____________, KC_PIPE,      KC_LBRC,      KC_RBRC,      KC_TILDE,     ____________,
  ____________, ____________, KC_BSLASH,    KC_LPRN,      KC_RPRN,      KC_GRAVE,
  ____________, ____________, ____________, KC_LCBR,      KC_RCBR,      ____________, ____________,
  ____________, ____________, ____________, ____________, ____________,

                                            ____________, ____________,
                                                          ____________,
                              ____________, ____________, ____________,

  // right hand
  ____________, KC_CIRC,      KC_AMPR,      KC_ASTR,      KC_LPRN,      KC_RPRN,      ____________,
  ____________, ____________, KC_DQUO,      KC_UNDERSCORE,KC_PLUS,      ____________, ____________,
                ____________, KC_QUOTE,     KC_MINUS,     KC_EQUAL,     KC_COLN,      ____________,
  ____________, ____________, ____________, KC_LABK,      KC_RABK,      KC_QUES,      ____________,
                              ____________, ____________, ____________, ____________, ____________,

                              ____________, ____________,
                              ____________,
                              ____________, ____________, ____________
),

/* Layer 2: Navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      | Home | PgUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  End |PgDwn |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |Accel0|                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |MdlClk|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Left | Right|MsWhDw|       |      |      |      |
 *                                 | Click| Click|------|       |------| Esc  | Enter|
 *                                 |      |      |MsWhUp|       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_NAVI] = LAYOUT_ergodox(
  // left hand
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, KC_MS_UP,     ____________, ____________, ____________,
  ____________, ____________, KC_MS_LEFT,   KC_MS_DOWN,   KC_MS_RIGHT,  ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, KC_MS_ACCEL0,

                                            KC_MS_BTN3,   ____________,
                                                          KC_WH_D,
                              KC_MS_BTN1,   KC_MS_BTN2,   KC_WH_U,

  // right hand
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, KC_HOME,      KC_PGUP,      ____________, ____________, ____________,
                KC_LEFT,      KC_DOWN,      KC_UP,        KC_RIGHT,     ____________, ____________,
  ____________, ____________, KC_END,       KC_PGDOWN,    ____________, ____________, ____________,
                              ____________, ____________, ____________, ____________, ____________,

                              ____________, ____________,
                              ____________,
                              ____________, KC_ESCAPE,    KC_ENTER
),

/* Layer 3: Shortcuts
 *
 * Left hand is used for Spectacle window manager (https://www.spectacleapp.com)
 * mapping  ==>  ~/Library/Application\ Support/Spectacle/Shortcuts.json
 * F - full screen
 * U,D,L,R - up, down, left, right (UL = upper left)
 * N - next display
 * P - previsous display
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |MacLock |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  UL  |  U   |  UR  |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  L   |  F   |   R  |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  DL  |  D   |  DR  |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  N   |  P   |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_SHOR] = LAYOUT_ergodox(
  // left hand
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, MEH(KC_W),    MEH(KC_E),    MEH(KC_R),    ____________, ____________,
  ____________, ____________, MEH(KC_S),    MEH(KC_D),    MEH(KC_F),    ____________,
  ____________, ____________, MEH(KC_X),    MEH(KC_C),    MEH(KC_V),    ____________, ____________,
  ____________, ____________, ____________, ____________, ____________,

                                            ____________, ____________,
                                                          ____________,
                              MEH(KC_G),    MEH(KC_A),    ____________,

  // right hand
  ____________, ____________, ____________, ____________, ____________, ____________, LCTL(LSFT(KC_POWER)),
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
                ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
                              ____________, ____________, ____________, ____________, ____________,

                              ____________, ____________,
                              ____________,
                              ____________, ____________, ____________
),

/* Layer 4: Function keys and macros
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[L_FUNC] = LAYOUT_ergodox(
  // left hand
  ____________, KC_F1,        KC_F2,        KC_F3,        KC_F4,        KC_F5,        ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, ____________,

                                            ____________, ____________,
                                                          ____________,
                              ____________, ____________, ____________,

  // right hand
  ____________, KC_F6,        KC_F7,        KC_F8,        KC_F9,        KC_F10,       ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
                ____________, ____________, ____________, ____________, ____________, ____________,
  ____________, ____________, ____________, ____________, ____________, ____________, ____________,
                              ____________, ____________, ____________, ____________, ____________,

                              ____________, ____________,
                              ____________,
                              ____________, ____________, ____________
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case L_BASE:
      break;
    case L_SYMB:
      ergodox_right_led_1_on();
      break;
    case L_NAVI:
      ergodox_right_led_2_on();
      break;
    case L_SHOR:
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }

};
