#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printVetor(int* vetor, int n);
int* hamming(int* bits, int n, int k);
int* read(int n);
int equals(int* v1, int* v2, int k);
float colisao(int** hashes, int linhas, int colunas);


int main(int argc, char** argv)

 {
    /* */
    /* Leitura do número de bits (k) de paridade e do número de valores de hash a serem calculados (d) */
    int k, d;
    scanf("%d %d", &k, &d);


    /* Cálculo de n, que determinará a quantidade de bits das linhas*/
    int n = (int) pow(2, k) - 1 - k;

    /* Matriz que guarda todos os hashes calulados*/
    int** hashes = (int**) malloc(d * sizeof (int*));

    /* Matriz para guardar todas as entradas lidas*/
    int** entradas = (int**) malloc(d * sizeof (int*));


    /* Loop para realizar as leituras e codificação */
    int i;
    for (i = 0; i < d; i++) {
        /* Lê para uma linha da matriz uma entrada do teclado */
        entradas[i] = read(n);
        /* Em seguida, calcula o hashe daquela linha recém lida*/
        hashes[i] = hamming(entradas[i], n, k);
        /* Depois, imprime a linha lida e o hash calculado */
        printVetor(entradas[i], n);
        printf("-");
        printVetor(hashes[i], k);
        printf("\n");
    }


	// float collided = colisao(hashes,d, k);
	// printf("O número de colisoes foi %.2f  \n",collided);

	return 0;
}

/* Lê a k vezes a quantidade de n bits e retona um vetor com os bits lidos
 1 0 0 1 1 0 1 0 0 0 0 */
int* read(int n) {
    int i;
    int* bits = (int*) malloc(n * sizeof (int));
    for (i = 0; i < n; i++) {
        scanf("%d", &bits[i]);
    }
    return bits;
}

int* hamming(int* bits, int n, int k) {

    /* Vetor para guardar o hash calculado */
    int* hash = (int*) malloc(k * sizeof (int));

    int* codificado = (int*) malloc((k + n) * sizeof (int));

    int i = 0;
    //marco todos os bits como inválidos
    for (i = 0; i < k; i++) {
        int marcar = (int) pow(2, i) - 1;
        codificado[marcar] = -1;
    }
    //copio os bits do vetor origianl para o vetor codificado
    int cont = 0;
    for (i = 0; i < k + n; i++) {
        if (codificado[i] != -1) {
            codificado[i] = bits[cont];
            cont++;
        }
    }

    //tenho que calcular k bits de paridade, assim passo k vezes no for
    for (i = 0; i < k; i++) {
        int soma = 0;
        int salto = (int) pow(2, i); //os saltos dos bits de paridades são sempre 2^i
        int j = salto - 1;
        int cont = 0;
        while (j < k + n) {
            if (cont == salto) {
                j = j + salto;
                cont = 0;
            } else {
                if (codificado[j] != -1) {
                    soma = soma + codificado[j];
                }
                cont++;
                j++;
            }
        }
        codificado[salto - 1] = soma % 2;
        hash[i] = soma % 2;
    }
    return hash;
}


int equals(int* v1, int* v2, int k) {
	int i;
	for(i = 0; i < k; i++) {
		if(v1[i] != v2[i]) return 0;
	}
	return 1;
}

float colisao(int** hashes, int linhas, int colunas) {

int colisao =0;
int i =0;
int j =0;
float percent=0;
for(i = 0; i < linhas-1 ; i++) {
      for(j = i+1; i < linhas ; j++) {
            if(equals(hashes[i],hashes[j],colunas))
                  colisao++;
      }
}
percent = (float)linhas/(float)colisao;
printf("%.2f\n",percent);
return percent;
}


void printVetor(int* vetor, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", vetor[i]);
    }
}
