#include "integration.hpp"

int main() {
    //############################
    //ticker e timer pra gravar e ler semaforo
    Ticker tsem(&status_semaforo,.5);
    Timer  ndsem(&read_semaforo,20);



    event.rise(&begin);
    event.fall(&end);
    button();
}

