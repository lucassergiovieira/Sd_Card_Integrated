#include "mbed.h"
#include "SDHCFileSystem.h"
#include "integration.cpp"

Serial pc(USBTX, USBRX);
SDFileSystem sd(PA_7, PA_6, PA_5, PC_1, "sd"); // MOSI, MISO, SCK, CS
FILE *temp
unsigned float c; 
int main() {
    wait(2);
    pc.printf("Start\r\n"); // inicializando o sd card 
    while(true){
      FILE *fp = fopen("/sd/myfile.txt", "r");  // open the file in 'read' mode
    while (!feof(fp)){                        // while not end of file
           c=fgetc(fp);                         // get a character/byte from the file
           printf("Read from file %02x\n\r",c); // and show it in hex format
      }
      fclose(fp);                               // close the file


    }
