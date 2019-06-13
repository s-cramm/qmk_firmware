#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define NUMP 1 // Numpad
#define NAVI 2 // navigation keys
#define FCTN 3 // function keys
#define GAME 4 // game mode

// custom key combos
#define KC_WSL LCTL(LGUI(KC_LEFT))
#define KC_WSR LCTL(LGUI(KC_RIGHT))
#define KC_MML LGUI(LSFT(KC_LEFT))
#define KC_MMR LGUI(LSFT(KC_RIGHT))
#define KC_SLW LCTL(LSFT(KC_LEFT))

enum custom_keycodes {
	EPRM = SAFE_RANGE,
	KSC,
	T_NAVI,
	T_NUMP,
	T_FCTN,
	VRSN,
	RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_ergodox(
		// left hand main
		KC_GRAVE,	KC_HASH,	KC_LCBR,	KC_LPRN,	KC_LBRACKET,	KC_AMPR,	KC_CIRC,
		KC_AT,		KC_QUOTE,	KC_COMMA,	KC_DOT,		KC_P,			KC_Y,		T_NAVI,
		KC_PERC,	KC_A,		KC_O,		KC_E,		KC_U,			KC_I,
		KC_DLR,		KC_SCOLON,	KC_Q,		KC_J,		KC_K,			KC_X,		T_NUMP,
		KC_LCTRL,	KC_LALT,	LCTL(KC_X),	LCTL(KC_C),	LCTL(KC_V),	
		// left hand thumb cluster
					KC_DELETE,	KC_ESCAPE,
								_______,
		KC_ENTER,	KC_LSHIFT,	KC_LGUI,
		// right hand main
		_______,	KC_ASTR,	KC_RBRACKET,	KC_RPRN,	KC_RCBR,	KC_EQUAL,	KC_EXLM,
		_______,	KC_F,		KC_G,			KC_C,		KC_R,		KC_L,		KC_SLASH,
					KC_D,		KC_H,			KC_T,		KC_N,		KC_S,		KC_MINUS,
		T_FCTN,		KC_B,		KC_M,			KC_W,		KC_V,		KC_Z,		KC_BSLASH,
								KC_SLW,			_______,	LCTL(KC_S),	KSC,		OSL(NAVI),
		// right hand thumb cluster
		KC_F13,		KC_PSCREEN,
		KC_F14,
		KC_TAB,		KC_BSPACE,	KC_SPACE
	),

	[NUMP] = LAYOUT_ergodox(
		// left hand main
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,
		// left hand thumb cluster
					_______,	_______,
								_______,
		_______,	_______,	_______,
		// right hand main
		_______,	_______,	KC_NUMLOCK,	KC_KP_SLASH,	KC_KP_ASTERISK,	KC_KP_MINUS,	_______,
		_______,	_______,	KC_7,		KC_8,			KC_9,			KC_KP_PLUS,		_______,
					_______,	KC_4,		KC_5,			KC_6,			KC_KP_ENTER,	_______,
		_______,	_______,	KC_1,		KC_2,			KC_3,			_______,		_______,
								KC_0,		_______,		KC_DOT,			_______,		_______,
		// right hand thumb cluster
		_______,	_______,
		_______,
		_______,	_______,	_______
	),

	[NAVI] = LAYOUT_ergodox(
		// left hand main
		KC_ESCAPE,	_______,	_______,		_______,		_______,		_______,	_______,
		_______,	_______,	_______,		KC_MS_WH_UP,	_______,		_______,	_______,
		_______,	_______,	KC_MS_WH_LEFT,	KC_MS_WH_DOWN,	KC_MS_WH_RIGHT,	_______,
		_______,	_______,	_______,		_______,		_______,		_______,	_______,
		_______,	_______,	_______,		_______,		_______,
		// left hand thumb cluster
					_______,	_______,
								_______,
		_______,	_______,	_______,
		// right hand main
		_______,	_______,	_______,	_______,	_______,	_______,	TO(GAME),
		_______,	KC_PGUP,	KC_MML,		KC_UP,		KC_MMR,		_______,	_______,
					KC_PGDOWN,	KC_LEFT,	KC_DOWN,	KC_RIGHT,	_______,	_______,
		_______,	_______,	KC_WSL,		_______,	KC_WSR,		_______,	_______,
								_______,	_______,	_______,	_______,	_______,
		// right hand thumb cluster
		_______,	_______,
		_______,
		_______,	_______,	_______
	),

	[GAME] = LAYOUT_ergodox(
		// left hand main
		KC_0,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,
		KC_F6,		_______,	_______,	_______,	_______,	_______,	KC_7,
		KC_F5,		_______,	_______,	_______,	_______,	_______,
		KC_F4,		_______,	_______,	_______,	_______,	_______,	KC_8,
		_______,	_______,	KC_F3,		KC_F2,		KC_F1,
		// left hand thumb cluster
					_______,	_______,
								_______,
		KC_9,		_______,	KC_ENTER,
		// right hand main
		LCTL(LSFT(KC_F1)),	LCTL(LSFT(KC_F2)),	LCTL(LSFT(KC_F3)),	LCTL(LSFT(KC_F4)),	LCTL(LSFT(KC_F5)),	LCTL(LSFT(KC_F6)),	KC_F7,
		LSFT(KC_GRAVE),		_______,			_______,			_______,			_______,			_______,			KC_F8,
							_______,			_______,			_______,			_______,			_______,			KC_F9,
		_______,			_______,			_______,			_______,			_______,			_______,			KC_F10,
												_______,			_______,			_______,			_______,			TO(BASE),
		// right hand thumb cluster
		_______,	_______,
		_______,
		_______,	_______,	_______
	),

	[FCTN] = LAYOUT_ergodox(
		// left hand main
		_______,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		_______,
		_______,	KC_F6,		KC_F7,		KC_F8,		KC_F9,		KC_F10,		_______,
		_______,	KC_F11,		KC_F12,		KC_F13,		KC_F14,		KC_F15,
		_______,	KC_F16,		KC_F17,		KC_F18,		KC_F19,		_______,	_______,
		_______,	_______,	_______,	_______,	_______,
		// left hand thumb cluster
					_______,	_______,
								_______,
		_______,	_______,	_______,
		// right hand main
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
					_______,	_______,	_______,	_______,	_______,	_______,
		_______,	_______,	_______,	_______,	_______,	_______,	_______,
								_______,	_______,	_______,	_______,	_______,
		// right hand thumb cluster
		_______,	_______,
		_______,
		_______,	_______,	_______
	),
};

bool shift_status(void) {
	if ((keyboard_report->mods & (MOD_BIT(KC_LSFT))) != 0) {
		return true;
	} else if ((keyboard_report->mods & (MOD_BIT(KC_RSFT))) != 0) {
		return true;
	}
	return false;
};

bool custom_layer_toggle(int layer, keyrecord_t *record) {
	if (record->event.pressed) {
		if (shift_status()) {
			layer_invert(layer);
		} else {
			layer_on(layer);
		}
	} else {
		if (!shift_status()) {
			layer_off(layer);
		}
	}
	return false;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// dynamically generate these.
		case EPRM:
			if (record->event.pressed) {
				eeconfig_init();
			}
			return false;
		case KSC:
			if (record->event.pressed) {
				SEND_STRING("Konichiwa KatamariSanChan-Otou-San");
			}
			return true;
		case T_NAVI:
			return custom_layer_toggle(NAVI, record);
		case T_NUMP:
			return custom_layer_toggle(NUMP, record);
		case T_FCTN:
			return custom_layer_toggle(FCTN, record);
	}
	return true;
};

uint32_t layer_state_set_user(uint32_t state) {

	uint8_t layer = biton32(state);
	
	ergodox_led_all_set(LED_BRIGHTNESS_LO);
	
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();
	switch (layer) {
		case 1:
			ergodox_right_led_3_on();
			break;
		case 2:
			ergodox_right_led_2_on();
			break;
		case 3:
			ergodox_right_led_1_on();
			break;
		case 4:
			ergodox_right_led_3_on();
			ergodox_right_led_2_on();
			break;
		case 5:
			ergodox_right_led_3_on();
			ergodox_right_led_1_on();
			break;
		case 6:
			ergodox_right_led_2_on();
			ergodox_right_led_1_on();
			break;
		case 7:
			ergodox_right_led_3_on();
			ergodox_right_led_2_on();
			ergodox_right_led_1_on();
			break;
		default:
			break;
	}
	return state;
};
