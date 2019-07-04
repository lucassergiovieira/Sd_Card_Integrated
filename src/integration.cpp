#include <iostream>
#include "integration.hpp"
#include "mbed.h"

DigitalOut my_leds[]={(PD_12),(PD_13),(PD_14)};
int s=0;
Timeout timeout;
InterruptIn event(PA_0);
Timer cont;
void begin();
void end();
Ticker ticker ;

void semaforo(){        // chama a função loop 
            event.rise(&button); // chamar push na borda de subida da interrupção
            switch(s){          // switch case para semáforo normal 
                case 0:  
                    my_leds[0]=1;// aciona led verde 
                    my_leds[2]=0;
                    timeout.attach(&semaforo,20);// conta 20s aceso 
                break;
                case 1:

                    my_leds[1]=1;//aciona led amarelo 
                    my_leds[0]=0;//mantem verde apagado
                    timeout.attach(&semaforo,4);// conta 4s aceso
                break;
                case 2:
                    my_leds[2]=1;// aciona led vermelho
                    my_leds[1]=0;// mantem led amarelo apagado
                    timeout.attach(&semaforo,10);// conta 10s aceso 
                break;
                }
    if(s>=2) {// loop do switch 
        s=0;
        }
    else {
        s++;// loop do switch 
        }
}
    
void button(){ // função de interrupção  retorna led amarelo
    if(s==1){   
        semaforo();  
    }
}

void semaforo_off(){
    my_leds[0]=0;
    my_leds[1]=0;
    my_leds[2]=0;
}
void pisca_led(){
    if(my_leds[1]==1){
        my_leds[1]=0;
    }
    else{
        my_leds[1]=1;
    }
    
void begin();{
    cont.start();
}

void end();{
    cont.stop();
    temp = cont.read();
    if(temp<=3){
        ticker.detach();
        button();
        }
    else if(temp>3&&temp<=10){
        semaforo_off();
        timeout.detach();
        ticker.attach(&pisca_led, 0.5);
        }
    else if(temp>10){
        ticker.detach();
        timeout.detach();
        semaforo_off();
        }
    void semaforo();
}  
