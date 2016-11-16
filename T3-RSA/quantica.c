#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {

    //valor ASCII do bit 0 -> 48
    //valor ASCII do bit 1 -> 49

    /* escolha da semente e da quantidade de bits utilizados */
    int s, n;
    scanf("%d %d",&s,&n);


    /* escolha das duas bases utilizadas nesse processo */
    char base1, base2;
    scanf("%d %d",&s,&n);

    /* vator que guardará até 100 bits */
    char bits[n];
    int i = 0;

    /* srand recebe como semente o valor s */
    srand(s);

    /* seleção aleatória da base utilizada */
    bits[n] = rand()%1;

    /* gerar valores aleatórios até o máximo de n bits */
    for(i = 0; i<n; i++){

        /* gerando valores aleatórios entre zero e um */
        bits[n] = rand()%2;

    }

    return 0;
}

