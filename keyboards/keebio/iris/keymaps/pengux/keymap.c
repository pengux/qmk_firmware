#include "iris.h"
#include "keymap_swedish.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _EMPTY 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET

#define KC_AA NO_AA
#define KC_AE NO_AE
#define KC_OE NO_OSLH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
    //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
    // §      , 1     , 2     , 3     , 4     , 5     ,                      6     , 7     , 8     , 9     , 0     , BSPC  ,
       KC_GRV ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                     KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
    //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    // TAB    , q     , w     , e     , r     , t     ,                      v     , u     , i     , o     , p     , å     ,
       KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                     KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_AA  ,
    //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    // LSFT   , a     , s     , d     , f     , g     ,                      h     , j     , k     , l     , ö     , ä     ,
       KC_LSFT,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                     KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_OE  ,KC_AE  ,
    //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
    // LCTL   , z     , x     , c     , v     , b     , DEL    ,    ENTER  , n     , m     , ,     , .     , -     , '     ,
       KC_LCTL,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,KC_DEL  , KC_ENT, KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,NO_APOS,
    //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
    //                               LALT   , OS    ,_LOWER/ESC,       ENTER  , SPACE , _RAISE
                                     KC_LALT,KC_LGUI,LT(_LOWER,KC_ESC),LT(_LOWER,KC_ENT), KC_SPC,OSL(_RAISE)
    //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_LOWER] = LAYOUT(
    //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
    // BRGHT+ , BRGHT-, MPrev , MPlay , MNXT  , MSTOP ,                     Mute   , 7     , 8     , 9     , /     ,       ,
       KC_SLCK,KC_PAUSE,KC_MPRV,KC_MPLY,KC_MNXT,KC_MSTP,                     KC_MUTE,KC_P7  ,KC_P8  ,KC_P9,  KC_PSLS,KC_TRNS,
    //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    //        ,       ,       , Up    ,       ,       ,                     Vol+   , 4     , 5     , 6     , *     ,       ,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_UP  ,KC_TRNS,KC_TRNS,                     KC_VOLU,KC_P4  ,KC_P5  ,KC_P6  ,KC_PAST,KC_TRNS,
    //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
    //        ,       , Left  , Down  , Right ,       ,                     Vol-   , 1     , 2     , 3     , -     ,       ,
       KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,                     KC_VOLD,KC_P1  ,KC_P2  ,KC_P3  ,KC_PMNS,KC_TRNS,
    //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
    //        ,       ,       ,       ,       ,       ,        ,            ,      , 0     , ','   ,       , +     ,       ,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS ,KC_TRNS,KC_P0 ,KC_COMM,KC_TRNS,KC_PPLS,KC_TRNS,
    //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
    //                                      ,       ,       ,                ,       ,
                                     KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS
    //                              `-------+-------+-------'        `-------+-------+-------'
  ),

  [_RAISE] = LAYOUT(
  //,-------+-------+-------+-------+-------+-------.                    ,-------+-------+-------+-------+-------+-------.
  //        ,       , @     , $     ,       ,       ,                      |     , \     , (     , )     , ?     , `     ,
     KC_TRNS,KC_TRNS,NO_AT  ,NO_DLR ,KC_TRNS,KC_TRNS,             NO_PIPE_MAC,NO_BSLS_MAC,NO_LBRC,NO_RBRC,NO_QUES,NO_GRV ,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  // CAPS   ,       ,       ,       ,       ,       ,                            ,       , {     , }     , +     , ´     ,
     KC_CAPS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,             KC_TRNS,KC_TRNS,NO_LCBR_MAC,NO_RCBR_MAC,NO_PLUS,NO_ACUT,
  //|-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  //        , <     , >     ,       ,       ,       ,       ,            ,       ,       ,       ,       , ~     , ^     ,
     KC_TRNS,NO_LESS,NO_GRTR,KC_TRNS,KC_TRNS,KC_TRNS,                     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,NO_TILD,NO_CIRC ,
  //|-------+-------+-------+-------+-------+-------+-------.    ,-------|-------+-------+-------+-------+-------+-------|
  // F1     , F2    , F3    , F4    , F5    , F6    ,                      F7    , F8    , F9    , F10   , F11   , F12   ,
     KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_TRNS,     KC_TRNS,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
  //`-------+-------+-------+--+----+-------+-------+-------/    \-------+-------+-------+-------+-------+-------+-------'
  //                                      ,       ,       ,                ,       ,
                                   KC_TRNS,KC_TRNS,KC_TRNS,         KC_TRNS,KC_TRNS,KC_TRNS
  //                              `-------+-------+-------'        `-------+-------+-------'
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _EMPTY);
      }
      return false;
      break;
  }
  return true;
}
