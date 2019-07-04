ifndef integration_hpp
#define integration_hpp
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
void status_semaforo();
void write_semaforo();
void read_semaforo();


#endif
