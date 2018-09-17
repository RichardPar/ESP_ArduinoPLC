#include <EEPROM.h>

#include "Program.h"
#include "DeviceConfig.h"
#include "Memory.h"
#include "IO.h"
#include "Engine.h"
#include "SerialPort.h"
#include "StatusLED.h"

#ifdef NODEMCU
extern "C" {
#include "user_interface.h"
}
#else
#include "TimerOne.h"
#endif


DeviceConfig deviceConfig = DeviceConfig(0); // uses first bytes of EEPROM
Program program = Program(DEVICE_CONFIG_EEPROM_BYTES + ENGINE_EEPROM_BYTES);
Memory memory = Memory(); // these are the current values of coils and analog values, etc.
IO io = IO(&deviceConfig, &memory);
Engine engine = Engine(DEVICE_CONFIG_EEPROM_BYTES, &program, &memory);
SerialPort serialPort = SerialPort(&io, &memory, &deviceConfig, &program, &engine);
StatusLED statusLED = StatusLED(STATUS_LED_PIN, &engine);



#ifdef NODEMCU
os_timer_t myTimer;

void timerISR(void *pArg) {
      statusLED.timerISR();
} // End of timerCallback


#else
// There is a bug in the Arduino compiler (as of 1.6.9) where it doesn't auto-create a prototype for timerISR
// That means timerISR has to appear *before* we call Timer1.attachInterrupt in setup().
void timerISR() {
  statusLED.timerISR(); // called 490 times per second by Timer1 (default PWM frequency)  
}
#endif
void setup() {        

#ifdef NODEMCU
  os_timer_setfn(&myTimer, timerISR, NULL);
  os_timer_arm(&myTimer, 2, true); // 2 Miliseconds,, hopefully
  EEPROM.begin(2048); // Set to 4K EEPROM - this MUST be done before any EEPROM activity
  int z;

#if 0
  for (z=0;z<2048;z++)
      EEPROM.write(z,0xFF);
  EEPROM.commit();    
#endif
  
#else  
  Timer1.attachInterrupt(timerISR);
#endif
  statusLED.init();
  serialPort.setupSerialPort(); 
  deviceConfig.readFromEeprom(); 
  if(program.readFromEeprom()) {
    engine.readFromEeprom(); // reads engine running status
  }
  engine.preScan();
  io.configureIO();
}

void loop() {  
  io.scanInputs();
  engine.solveLogic();
  if(engine.getStatus() && engine.getErrorCode() == ERROR_NONE) {
    io.scanOutputs();
  }
  else {
    io.turnOutputsOff();
  }
  serialPort.readAndWrite();
  //delay(10);
}
