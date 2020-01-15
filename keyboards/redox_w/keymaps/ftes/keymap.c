#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _CODE_FN_ARROW 2
#define _MEDIA_MOUSE_UMLAUT 3
#define _NUMPAD 4

// layer modifiers
// shift and capslock in one
#define SFT_CPL SFT_T(KC_CAPS)
// toggle
# define TG_QWER TG(_QWERTY)
# define TG_NUMP TG(_NUMPAD)
// code layer
#define COD_ESC LT(_CODE_FN_ARROW, KC_ESC) // left
#define COD_MIN LT(_CODE_FN_ARROW, KC_MINS) // right
// media layer
#define MED_TAB LT(_MEDIA_MOUSE_UMLAUT, KC_TAB) // left
#define MED_SLS LT(_MEDIA_MOUSE_UMLAUT, KC_SLSH) // right

// special keys
#define KC_CTPL LCTL_T(KC_BSLS)

enum unicode_names {
    ae,
    AE,
    oe,
    OE,
    ue,
    UE,
    SS,
    EUR
};

const uint32_t PROGMEM unicode_map[] = {
    [ae]  = 0xE4,   // ä
    [AE]  = 0xC4,   // Ä
    [oe]  = 0xF6,   // ö
    [OE]  = 0xD6,   // Ö
    [ue]  = 0xFC,   // ü
    [UE]  = 0xDC,   // Ü
    [SS]  = 0xDF,   // ß
    [EUR] = 0x20AC, // €
};

void eeconfig_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TG_QWER ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,TG_NUMP ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     MED_TAB ,KC_QUOT ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y    ,KC_GRV  ,                          XXXXXXX ,KC_F    ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,MED_SLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     COD_ESC ,KC_A    ,KC_O    ,KC_E    ,KC_U    ,KC_I    ,KC_LBRC ,                          KC_RBRC ,KC_D    ,KC_H    ,KC_T    ,KC_N    ,KC_S    ,COD_MIN ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SFT_CPL ,KC_SCLN ,KC_Q    ,KC_J    ,KC_K    ,KC_X    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_B    ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,SFT_CPL ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_EQL  ,KC_BSLS ,KC_COPY ,     KC_CTPL ,    KC_BSPC ,KC_DEL  ,        KC_ENT  ,KC_SPC  ,    KC_RALT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_______ ,                          _______ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,_______ ,                          _______ ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,_______ ,        _______ ,_______ ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_CODE_FN_ARROW] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LABK ,KC_LPRN ,KC_LBRC ,KC_LCBR ,KC_DQUO ,KC_BSLS ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_RABK ,KC_RPRN ,KC_LBRC ,KC_RCBR ,KC_QUOT ,KC_SLSH ,                          XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_PIPE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PSTE ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_MEDIA_MOUSE_UMLAUT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,X(SS)   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,XXXXXXX ,KC_MS_U ,X(EUR)  ,KC_WH_U ,XXXXXXX ,RESET   ,                          XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_MNXT ,XP(ue,UE),XXXXXXX,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤────────┼
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,KC_MPLY ,KC_VOLD ,KC_MPRV ,XP(oe,OE),XP(ae,AE),XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┼
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,KC_MSTP ,KC_MUTE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     KC_BTN1 ,    KC_BTN2 ,KC_BTN3 ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,KC_PSLS ,KC_PAST ,KC_PMNS ,TG_NUMP ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┤────────┼
     XXXXXXX ,XXXXXXX ,KC_PSCR ,XXXXXXX ,KC_PAUS ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┤────────┼
     XXXXXXX ,XXXXXXX ,KC_INS  ,KC_HOME ,KC_PGUP ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,KC_P4   ,KC_P5   ,KC_P6   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤────────┼
     XXXXXXX ,XXXXXXX ,KC_DEL  ,KC_END  ,KC_PGDN ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,KC_P0   ,    KC_COMM ,     KC_P0   ,KC_PDOT ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _DVORAK:
            set_led_off;
            break;
        case _QWERTY:
            set_led_green; // actually red
            break;
        case _CODE_FN_ARROW:
            set_led_blue; // actually orange
            break;
        case _MEDIA_MOUSE_UMLAUT:
            set_led_red; // actually green
            break;
        case _NUMPAD:
            set_led_white; // all on
            break;
        default:
            break;
    }
  return state;
}


