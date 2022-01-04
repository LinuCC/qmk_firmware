/*
Copyright 2021 CapsUnlocked

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             KC_BTN3,
    KC_BTN2,  OSL(1),    OSL(2),
    KC_BTN1,  OSL(3),    OSL(4)
  ),
  [1] = LAYOUT(
             _______,
    _______, KC_F1  , KC_F2,
    KC_F3  , KC_F4  , KC_F5
  ),
  [2] = LAYOUT(
              _______   ,
    _______ , KC_F6     , KC_F7    ,
    KC_F8   , KC_F9     , KC_F10
  ),
  [3] = LAYOUT(
               _______  ,
    _______  , LCA(KC_1), LCA(KC_2),
    LCA(KC_3), LCA(KC_4), LCA(KC_5)
  ),
  [4] = LAYOUT(
             _______,
    OSL(5) , _______,   _______,
    _______, _______,   _______
  ),
  [5] = LAYOUT(
             _______,
    RGB_MOD, KC_UP  ,   RESET,
    KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

// Volume up/down on the encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (clockwise) {
    tap_code_delay(KC_WH_U, 5);
  } else {
    tap_code_delay(KC_WH_D, 5);
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
    case 0:
      rgblight_mode(0);
      rgblight_sethsv_noeeprom(HSV_AZURE);
      break;
    case 1:
      rgblight_mode(23);
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case 2:
      rgblight_mode(23);
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case 3:
      rgblight_mode(23);
      rgblight_sethsv_noeeprom(HSV_TEAL);
      break;
    case 4:
      rgblight_mode(23);
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      break;
    case 5:
      rgblight_mode(23);
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
  }
  return state;
}
