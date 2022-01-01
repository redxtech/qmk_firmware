#include QMK_KEYBOARD_H

enum custom_keycodes {
  KC_DEL_SPAM = SAFE_RANGE,
  MACRO_SEC_BOOT,
  MACRO_BOOT_WIN
};

// layer shrotcut defines
#define _BL 0 // base layer
#define _FL 1 // function layer
#define _ML 2 // macro layer
#define _RL 3 // RGB layer
#define _MS 4 // mouse layer


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //      ESC         F1      F2      F3      F4      F5      F6      F7      F8      F9      F10         F11         F12         Prt                 Rotary(Play/Pause)
    //      ~           1       2       3       4       5       6       7       8       9       0           -           (=)         BackSpc             Del (PGUP)
    //      Tab         Q       W       E       R       T       Y       U       I       O       P           [           ]           \                   PgUp (PGDN)
    //      Caps        A       S       D       F       G       H       J       K       L       ;           "                       Enter               PgDn (End)
    //      Sh_L        Z       X       C       V       B       N       M       ,       .       ?                                   Sh_R        Up      End (DEL)
    //      Ct_L        Win_L   Alt_L                           SPACE                           Alt_R       FN          Ct_R        Left        Down    Right
	[_BL] = LAYOUT(
            KC_ESC,     KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,     KC_F11,     KC_F12,     KC_PSCR,            KC_MPLY,
            KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,            KC_PGUP,
            KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,            KC_PGDN,
            HYPR(KC_NO),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,    KC_QUOT,                KC_ENT,             KC_END,
            KC_LSFT,    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,                            KC_RSFT,    KC_UP,  KC_DEL,
            KC_LCTL,    KC_LGUI,KC_LALT,                        KC_SPC,                         KC_RALT,    MO(_FL),    KC_RCTL,    KC_LEFT,    KC_DOWN, KC_RGHT
    ),
	[_FL] = LAYOUT(
            EEP_RST,    _______,_______,_______,_______,KC_SLEP,KC_PWR, KC_VOLD,KC_VOLU,KC_MSTP,KC_MPLY,    KC_MPRV,    KC_MNXT,    KC_SLCK,            KC_MUTE,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,    _______,    _______,            _______,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,    _______,    RESET,              _______,
            KC_CAPS,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,                _______,            KC_HOME,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                            _______,    _______,KC_INS,
            _______,    _______,_______,                        _______,                        MO(2),      _______,    MO(3),      _______,    _______, _______
    ),
	[_ML] = LAYOUT(
            KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,
            TG(4),      TG(0),  TG(5),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,
            KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,              MACRO_BOOT_WIN,
            KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,                  KC_NO,              MACRO_SEC_BOOT,
            KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,      KC_NO,  KC_DEL_SPAM,
            KC_NO,      KC_NO,  KC_NO,                          KC_NO,                          _______,    _______,    KC_NO,      KC_NO,      KC_NO,  KC_NO
    ),
	[_RL] = LAYOUT(
            EEP_RST,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,
            KC_NO,      RGB_TOG,RGB_M_P,RGB_M_B,RGB_M_R,RGB_M_SW,RGB_M_SN,RGB_M_K,RGB_M_X,RGB_M_G,RGB_M_T,  KC_NO,      KC_NO,      KC_NO,              KC_NO,
            KC_NO,      BL_ON,  BL_INC, RGB_VAI,RGB_HUI,RGB_SAI,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,              KC_NO,
            KC_NO,      BL_DEC, BL_DEC, RGB_VAD,RGB_HUD,RGB_SAD,KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      KC_NO,                  KC_NO,              KC_NO,
            KC_NO,      BL_TOGG,BL_BRTG,BL_STEP,KC_NO,  KC_NO,  NK_TOGG,KC_NO,  KC_NO,  KC_NO,  KC_NO,                              KC_NO,      RGB_MOD,KC_NO,
            KC_NO,      KC_NO,  KC_NO,                          KC_NO,                          KC_NO,      _______,    _______,    RGB_SPD,    RGB_RMOD,RGB_SPI
    ),
	[_MS] = LAYOUT(
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,    _______,    _______,            _______,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,    _______,    _______,            _______,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,    _______,    _______,            _______,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,    _______,                _______,            _______,
            _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,                            KC_BTN1,    KC_MS_U,KC_BTN2,
            _______,    _______,_______,                        _______,                        _______,    _______,    _______,    KC_MS_L,    KC_MS_D,KC_MS_R
    ),
};

// code for macro to spam del until toggled
bool spam_del;
uint16_t spam_timer = false;
uint16_t spam_interval = 100; // (1000ms == 1s)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_0:
                SEND_STRING(SS_DOWN(X_LSFT)"hello world1"SS_UP(X_LSFT));
                return false;
            case MACRO_SEC_BOOT:
                SEND_STRING(SS_TAP(X_ENTER)SS_DELAY(1000)SS_TAP(X_DOWN)SS_DELAY(50)SS_TAP(X_ENTER)SS_DELAY(1000)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_DELAY(50)SS_TAP(X_ENTER)SS_DELAY(1000)SS_TAP(X_DOWN)SS_TAP(X_DOWN)SS_DELAY(50)SS_TAP(X_ENTER)SS_DELAY(1000)SS_TAP(X_ENTER)SS_TAP(X_DOWN)SS_TAP(X_ENTER));
                return false;
            case MACRO_BOOT_WIN:
                SEND_STRING(SS_TAP(X_ENTER)SS_DELAY(250)SS_TAP(X_UP)SS_DELAY(50)SS_TAP(X_ENTER)SS_DELAY(250)SS_TAP(X_UP)SS_DELAY(50)SS_TAP(X_UP)SS_DELAY(50)SS_TAP(X_UP)SS_DELAY(50)SS_TAP(X_ENTER));
                return false;
            case KC_DEL_SPAM: // Toggle's if we hit "ENTER" or "BACKSPACE" to input macros
              if (record->event.pressed) {
                spam_del ^= 1;
                spam_timer = timer_read();
              }
              return false;
        }
    }

    return true;
};

void matrix_scan_user(void) {
  if (spam_del && timer_elapsed(spam_timer) >= spam_interval) {
     spam_timer = timer_read();
     SEND_STRING(SS_TAP(X_DEL));
  }
}

// add functionality to the rotary encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // first encoder
        switch(biton32(layer_state)){
            case 1:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case 2:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
            case 3:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_AUDIO_VOL_UP);
                } else {
                    tap_code(KC_AUDIO_VOL_DOWN);
                }
                break;
        }
    }
    return true;
}

