#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
//    _COLEMAK,
//    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
//  COLEMAK,
//  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  KANA,
  EISU,
  RGBRST,
  REFOCUS
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)

#define KC_TMB1 GUI_T(KC_LANG2)
#define KC_TMB2 LOWER
#define KC_TMB3 KC_SPC
#define KC_TMB4 LCTL_T(KC_ENT)
#define KC_TMB5 RAISE
#define KC_TMB6 ALT_T(KC_LANG1)
#define KC_LOCK LCTL(LSFT(KC_POWER))
#define KC_SLP LGUI(LALT(KC_POWER))
#define KC_RFC REFOCUS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | TAB  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ADJUST| Win  | Alt  |LOWER |Space |             | Enter| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
[_QWERTY] = LAYOUT_ortho_4x12(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
      KC_ESC,  ADJUST,  KC_LGUI, KC_TMB1, KC_TMB2, KC_TMB3,                   KC_TMB4, KC_TMB5, KC_TMB6, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ADJUST| Alt  | Win  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
  /*
  [_COLEMAK] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
      KC_ESC,  ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,                    KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),
  */

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |ADJUST| Alt  | Win  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
  /*
  [_DVORAK] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_DEL, \
      KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
      KC_ESC,  ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,                    KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),
  */

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             | Home | PgDn | PgUp | End  |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
      _______, _______, _______, _______, _______, _______,    _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
      _______, _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | `    |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |             | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |       |
   * `-----------------------------------------'             `-----------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12( \
      KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6  ,    _______, KC_MINS, KC_EQL, KC_LBRC,  KC_RBRC, KC_BSLS, \
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,    KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______, \
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset| BRMD | BRMU |      |      |             |      |      |      |      |Rfocus|      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | LOCK |             | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Sleep|             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      _______, RESET,   KC_BRMD, KC_BRMU, _______, _______,    _______, _______, _______, _______, KC_RFC,  _______, \
      _______, _______, _______, _______, _______, KC_LOCK,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
      _______, _______, _______, _______, _______, KC_SLP,     _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______ \
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // case COLEMAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_COLEMAK);
    //   }
    //   return false;
    //   break;
    // case DVORAK:
    //   if (record->event.pressed) {
    //     set_single_persistent_default_layer(_DVORAK);
    //   }
    //   return false;
    //   break;

    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
           rgblight_mode_noeeprom(16);
          #endif
        }

        lower_pressed = true;
        lower_pressed_time = record->event.time;

        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

        if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
          // Send ESC keycode if LOWER key released without other key
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
        lower_pressed = false;
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(15);
          #endif
        }

        raise_pressed = true;
        raise_pressed_time = record->event.time;

        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);

        if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
          // Send TAB keycode if RAISE key released without other key
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        }
        raise_pressed = false;
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        }
      #endif
      return false;
      break;

    case EISU:
      if (record->event.pressed) {
          SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
         SEND_STRING(SS_LALT("`"));
      }
      return false;
      break;

    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        }
      #endif
      break;

    case REFOCUS:
      // Refocus to document from omnibar in Chrome
      // This is useful when navigation with Vimium extension
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("p")); // Cmd+L
        SEND_STRING("ca.a;iogrkZ" SS_TAP(X_ENTER)); // "javascript:" + ENTER
      }
      return false;
      break;
  }
  return true;
}


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
}
