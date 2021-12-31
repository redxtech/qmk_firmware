//encoder
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

