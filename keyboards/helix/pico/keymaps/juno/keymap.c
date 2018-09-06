#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QVORAK = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  QVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};


// Fillers to make layering more clear
#define _____ KC_TRNS
#define XXXXX KC_NO
//Macros
#define M_SAMPLE M(KC_SAMPLEMACRO)
#define ALTAB ALT_T(KC_TAB)         // Tap to Tab, Hold to Alt
#define GUI   GUI_T(KC_ESC)         // Tap to ESC, Hold to GUI (Command)
#define LOWER LT(_LOWER, KC_LANG2)  // Tap to 英数, Hold to Lower
#define RAISE LT(_RAISE, KC_LANG1)  // Tap to かな, Hold to Raise
#define TABADJ LT(_ADJUST, KC_TAB)  // Tap to TAB, Hold to Adjust

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qvorak - Qwerty for macOS Dvorak Input Source
   * Hardware:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | TabAd|   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bspc |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | CTRL |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  ''  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|      |      |      |GUI/Es|Low/Ei| Space| Enter|Rai/Kn|Alt/Tb|      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   * Software:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | TabAd|   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bspc |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | CTRL |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  | Shift|
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |Adjust|      |      |      |GUI/Es|Low/Ei|Space |Enter |Rai/Kn|Alt/Tb|      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
   [_QVORAK] = LAYOUT( \
     TABADJ,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                  KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    KC_BSPC, \
     KC_LCTL, KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                  KC_H,  KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
     KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT , \
     ADJUST,  XXXXX, XXXXX, XXXXX, GUI,   LOWER, KC_SPC, KC_ENT, RAISE, ALTAB, XXXXX,   XXXXX,  XXXXX,   XXXXX \
   ),

  /* Lower for Qvorak
   * Hardware:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |   _  |   +  |   {  |   }  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
   * `-------------------------------------------------------------------------------------------------'
   * Software:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |   {  |   }  |   ?  |   +  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | Home | PgDn | PgUp |  End |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      | Vol- | Vol+ |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
    XXXXX,   XXXXX,   XXXXX, XXXXX,   XXXXX,  XXXXX,               XXXXX,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
    XXXXX,   XXXXX,   XXXXX, XXXXX,   XXXXX,  XXXXX,               XXXXX,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXX, \
    _____,   _____,   _____, _____,   _____,  _____, _____, _____, _____,   _____,   _____,   KC_VOLD, KC_VOLU, _____ \
  ),

  /* Raise for Qvorak
   * Hardware:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |   -  |   =  |   [  |   ]  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |             |      | Left | Down |  Up  | Right|      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Bspc |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   * Software:
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |   [  |   ]  |   /  |   =  |  \   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |             |      | Left | Down |  Up  | Right|      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      | Bspc |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
    KC_GRV, KC_1,  KC_2,  KC_3,   KC_4,   KC_5,                   KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
    KC_F1,  KC_F2, KC_F3, KC_F4,  KC_F5,  KC_F6,                  XXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_F7,  KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,                 XXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _____, \
    _____,  _____, _____, _____,  _____,  _____,  KC_BSPC, _____, _____, _____,   _____,   _____,   _____,   _____ \
  ),

  /* Adjust
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Aud on|Audoff|MU TOG|MU MOD|      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |CK TOG|CK RST| CK UP|CK DWN|      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
    _____, RESET,   _____,  _____,  _____,   _____,               _____, _____, _____,    _____,  _____,   _____, \
    _____, AU_ON,   AU_OFF, MU_TOG, MU_MOD,  _____,               _____, _____, _____,    _____,  _____,   _____, \
    _____, CK_TOGG, CK_RST, CK_UP,  CK_DOWN, _____,               _____, _____, _____,    _____,  _____,   _____, \
    _____, _____,   _____,  _____,  _____,   _____, _____, _____, _____, _____, _____,    _____,  _____,   _____ \
  )
};



#ifdef AUDIO_ENABLE

float tone_qvorak[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qvorak);
        #endif
        persistent_default_layer_set(1UL<<_QVORAK);
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
  }
  return true;
}

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(50); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif


//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
     iota_gfx_task();  // this is what updates the display continuously
}

void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

//assign the right code to your layers for OLED display
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

static void render_logo(struct CharacterMatrix *matrix) {

  static char logo[]={
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,
    0};
  matrix_write(matrix, logo);
  //matrix_write_P(&matrix, PSTR(" Split keyboard kit"));
}



void render_status(struct CharacterMatrix *matrix) {

  // Render to mode icon
  static char logo[][2][3]={{{0x95,0x96,0},{0xb5,0xb6,0}},{{0x97,0x98,0},{0xb7,0xb8,0}}};
  if(keymap_config.swap_lalt_lgui==false){
    matrix_write(matrix, logo[0][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[0][1]);
  }else{
    matrix_write(matrix, logo[1][0]);
    matrix_write_P(matrix, PSTR("\n"));
    matrix_write(matrix, logo[1][1]);
  }

  // Define layers here, Have not worked out how to have text displayed for each layer. Copy down the number you see and add a case for it below
  char buf[40];
  snprintf(buf,sizeof(buf), "Undef-%ld", layer_state);
  matrix_write_P(matrix, PSTR("\nLayer: "));
    switch (layer_state) {
        case L_BASE:
           matrix_write_P(matrix, PSTR("Default"));
           break;
        case L_RAISE:
           matrix_write_P(matrix, PSTR("Raise"));
           break;
        case L_LOWER:
           matrix_write_P(matrix, PSTR("Lower"));
           break;
        case L_ADJUST:
        case L_ADJUST_TRI:
           matrix_write_P(matrix, PSTR("Adjust"));
           break;
        default:
           matrix_write(matrix, buf);
    }

  // Host Keyboard LED Status
  char led[40];
    snprintf(led, sizeof(led), "\n%s  %s  %s",
            (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) ? "NUMLOCK" : "       ",
            (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) ? "CAPS" : "    ",
            (host_keyboard_leds() & (1<<USB_LED_SCROLL_LOCK)) ? "SCLK" : "    ");
  matrix_write(matrix, led);
}


void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

#if DEBUG_TO_SCREEN
  if (debug_enable) {
    return;
  }
#endif

  matrix_clear(&matrix);
  if(is_master){
    render_status(&matrix);
  }else{
    render_logo(&matrix);
  }
  matrix_update(&display, &matrix);
}

#endif
