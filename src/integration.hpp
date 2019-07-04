#ifndef integration
#define integration
#include "mbed.h"


extern DigitalOut my_leds[];
extern InterruptIn event;
void semaforo();
void pisca_led();
void semaforo_off();
void button();
void begin();
void end();
float temp;

#endif