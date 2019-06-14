
// checks whether left shift is being held
bool is_lsft_pressed(void) {
	if ((keyboard_report->mods & (MOD_BIT(KC_LSFT))) != 0) {
		return true;
	}
	return false;
}

// acts like LT normally, or TG when used with left shift
bool custom_layer_toggle(int layer, keyrecord_t *record) {
	if (record->event.pressed) {
		if (is_lsft_pressed()) {
			layer_invert(layer);
		} else {
			layer_on(layer);
		}
	} else {
		if (!is_lsft_pressed()) {
			layer_off(layer);
		}
	}
	return false;
};
