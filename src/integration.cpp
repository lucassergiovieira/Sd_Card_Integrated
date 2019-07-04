#include <iostream>
#include "integration.hpp"
#include "SDHCFileSystem.h"
#include "mbed.h"

DigitalOut my_leds[]={(PD_12),(PD_13),(PD_14)};
int s=0;
Timeout timeout;
InterruptIn event(PA_0);
Timer cont;
void begin();
void end();
Ticker ticker;
Serial pc(USBTX, USBRX);
SDFileSystem sd(PA_7, PA_6, PA_5, PC_1, "sd"); // MOSI, MISO, SCK, CS
FILE *fp
unsigned float c; 

//############################
//variaveis para escrever no semaforo
Ticker tsem;
Timer endsem;
char status_sem;
float time_sem=0.0;


//############################
//funcoes para gravar no SD
void status_semaforo(){
        time_sem++;
	switch(s){          // switch case para semáforo normal 
                case 0:  
                    status_sem = 'verde';
		    write_semaforo();
		
                break;
                case 1:

                    status_sem = 'amarelo';
		    write_semaforo();
                break;
                case 2:
                    status_sem = 'vermelho';
		    write_semaforo();
                break;
                }
	
}
void write_semaforo(){

    wait(2);
    pc.printf("Start\r\n"); // inicializando o sd card 
    while(true){
      FILE *fp = fopen("/sd/myfile.txt", "w");  // open the file in 'write' mode
    while (!feof(fp)){                        // while not end of file
           c=fgetc(fp);                         // get a character/byte from the file
           printf(" Status %02x\n\r",status_sem); 
           printf(" Time %02x\n\r",time_sem);// and show it in hex format
      }
      fclose(fp);                               // close the file


}

void read_semaforo(){ wait(2);
    pc.printf("Start\r\n"); // inicializando o sd card 
    while(true){
      FILE *fp = fopen("/sd/myfile.txt", "r");  // open the file in 'read' mode
    while (!feof(fp)){                        // while not end of file
           c=fgetc(fp);                         // get a character/byte from the file 
      }
      fclose(fp);                               // close the file
time_sem=0;

}

//############################


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
