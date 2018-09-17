#ifndef BoardSelect_h
#define BoardSelect_h

// make sure exactly one of these lines is uncommented:
//#define UNO
//#define NANO
//#define MEGA
#define NODEMCU

const byte NUM_STRINGS = 0; // not implemented yet

#ifdef UNO
  const int STATUS_LED_PIN = 13;
  const int MAX_ANALOG_INPUT = 5;
  const int MAX_PROGRAM_SIZE = 750; // in bytes (includes the 34(?) header bytes)
  const int MAX_PIN_NUMBER = 11; 
  const int PIN_MAP[] = {2,3,4,5,6,7,8,9,10,11,12};
  const int DEVICE_CONFIG_EEPROM_BYTES = 16;
  const int PWM_PINS[] = {3, 5, 6, 9, 10, 11};
  const int PWM_PIN_COUNT = 6; // must be length of the PWM_PINS array
  const int NUM_BOOLEANS = 512; // has to be a multiple of 8
  const byte NUM_NUMERICS = 24; // has to be a multiple of 8
#endif
#ifdef NANO
  const int STATUS_LED_PIN = 13;
  const int MAX_ANALOG_INPUT = 7;
  const int MAX_PROGRAM_SIZE = 750; // in bytes (includes the 34(?) header bytes)
  const int MAX_PIN_NUMBER = 12; // pin 13 is a status LED
  const int PIN_MAP[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
  const int DEVICE_CONFIG_EEPROM_BYTES = 16;
  const int PWM_PINS[] = {3, 5, 6, 9, 10, 11};
  const int PWM_PIN_COUNT = 6; // must be length of the PWM_PINS array
  const int NUM_BOOLEANS = 512; // has to be a multiple of 8
  const byte NUM_NUMERICS = 24; // has to be a multiple of 8
#endif
#ifdef MEGA
  const int STATUS_LED_PIN = 13;
  const int MAX_ANALOG_INPUT = 15;
  const int MAX_PROGRAM_SIZE = 3750; // in bytes (includes the 34(?) header bytes)
  const int MAX_PIN_NUMBER = 53; // pin 13 is a status LED
  const int PIN_MAP[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57};
  const int DEVICE_CONFIG_EEPROM_BYTES = 56;
  const int PWM_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 44, 45, 46};
  const int PWM_PIN_COUNT = 14; // must be length of the PWM_PINS array
  const int NUM_BOOLEANS = 1024; // has to be a multiple of 8
  const byte NUM_NUMERICS = 96; // has to be a multiple of 8
#endif

#ifdef NODEMCU
  const int STATUS_LED_PIN = 16;
  const int MAX_ANALOG_INPUT = 1;
  const int MAX_PROGRAM_SIZE = 1800; // in bytes (includes the 34(?) header bytes)
  const int MAX_PIN_NUMBER = 8 ; // pin 16 is a status LED
  const int PIN_MAP[] = {15,4,0,2,14,12,13,15,3,1};
                        /* PIN13 maps to D7 - First two pins are Serial but its dedicated on NodeMCU*/
  const int DEVICE_CONFIG_EEPROM_BYTES = 56;
  const int PWM_PINS[] = {2,3,4,5,6,7,8};
  const int PWM_PIN_COUNT = 3; // must be length of the PWM_PINS array
  const int NUM_BOOLEANS = 1024; // has to be a multiple of 8
  const byte NUM_NUMERICS = 96; // has to be a multiple of 8
#endif



#endif
