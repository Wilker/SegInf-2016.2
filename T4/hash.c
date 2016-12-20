#include <stdio.h>
#include <stlib.h>
#include <math.h>

void printVetor(int* vetor, int n);

int main(int argc, char** argv) {
/* */
    /* Leitura do número de bits (k) de paridade e do número de valores de hash a serem calculados (d) */
    int k, d;
    scanf("%d %d", &k, &d);


    /* Cálculo de n, que determinará a quantidade de bits das linhas*/
    int n = pow(2,k) - 1 - k;



    return 0;
}

/* Lê a k vezes a quantidade de n bits e retona um vetor com os bits lidos */
int* read(int k, int n) {
    int i;

    int* bits = (int*) malloc(n * sizeof(int));
    for (i = 0; i < k; i++) {
        scanf("%d", bits[i]);
    }
}


void printVetor(int* vetor, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d", vetor[i]);
    }
    printf("\n");
}
