#include <stdio.h>
#include <stdlib.h>

void printVetor(int* vetor, int n);
char* polarizar(int bits[], int bases[], int lenght, char base1, char base2);
char* basesBinToChar(int* basesBinarias,int n, char base1,char base2);
int* comparaBases(char* basesAlice, char* basesBob);

int main(int argc, char** argv) {

    //valor ASCII do bit 0 -> 48
    //valor ASCII do bit 1 -> 49

    /* Leitura da semente e da quantidade de bits utilizados */
    int s, n;
    scanf("%d %d", &s, &n);

    /* srand recebe como semente o valor s */
    srand(s);

    /* Leitura das duas bases utilizadas nesse processo */
    char base1, base2;
    scanf(" %c %c", &base1, &base2);
    printf("%c %c\n", base1, base2);

    /* vetor que guardará até 100 bits */
    int* bits = (int*) malloc(n * sizeof (int));

    /* vetor que guardará as bases dos até 100 bits */
    int* basesBinarias = (int*) malloc(n * sizeof (int));

    /*  Alice escolhe n bits com valores aleatórios entre 0 e 1 */
    int i = 0;
    for (i = 0; i < n; i++) {
        /* gerando valores aleatórios entre zero e um */
        bits[i] = rand() %2;
    }

    /*  Alice escolhe n bases aleatoriamente entre 0 e 1 */
    for (i = 0; i < n; i++) {
        /* gerando valores aleatórios entre zero e um */
        basesBinarias[i] = rand() %2;
    }

    printf("Os bits aleatórios escolhidos foram\n");
    printVetor(bits, n);
    printf("A bases aleatórias escolhidas foram\n");
    printVetor(basesBinarias, n);


    /*  Conversão dos valores das bases de binário para char conforme
    a tabela */
    char* bases = polarizar(bits, basesBinarias, n, base1, base2);


    printf("Polarização\n");
    for (i = 0; i < n; i++) {
        printf("%c ", bases[i]);
    }
    printf("\n");

    /* vetor que guardará as bases escolhidas por bob */
    char* basesBob = (char*) malloc(n* sizeof(char));

    /* leitura das bases dos n bits do bob */
    for (i = 0; i < n; i++) {
        scanf(" %c",&basesBob[i]);
    }

    /* impressão para verificar se foi lida corretamente a base do Bob  */
    for (i = 0; i < n; i++) {
        printf("%c ", basesBob[i]);
    }
    printf("\n");

    /* vetor que guardará as bases convertidas para caracter da Alice */
    char* basesChar = basesBinToChar(basesBinarias,n,base1,base2);

    /* impressão para verificar se as bases foram convertidas corretamente  */
    for (i = 0; i < n; i++) {
        printf("%c ", basesChar[i]);
    }
    printf("\n");

    return 0;
}










void printPolarizacao(char base1, char base2, int bits[],
        int basesBinarias[], int lenght) {

    int i;
    for (i = 0; i < lenght; ++i) {
        if (bits[i] == 0) {
            if (basesBinarias[i] == 0) {

            }
        }
    }
}

char* polarizar(int bits[], int bases[], int lenght, char base1,
        char base2) {

    char *basesChar = (char*) malloc(sizeof (char)*lenght);

    int i;
    for (i = 0; i < lenght; ++i) {
        /* Se a base é 0 então a base escolhida é a base1*/
        if (bases[i] == 0) {
            /* Se a base for '+' então verifica o valor do bit correspondente e faz a polarização */
            if (base1 == '+')
                if (bits[i] == 0)
                    basesChar[i] = '^';
                else
                    basesChar[i] = '>';
            /* Se a base for 'x' então verifica o valor do bit correspondente e faz a polarização */
            if (base1 == 'x')
                if (bits[i] == 0)
                    basesChar[i] = '/';
                else
                    basesChar[i] = '\\';
            /* Se a base for 'o' então verifica o valor do bit correspondente e faz a polarização */
            if (base1 == 'o')
                if (bits[i] == 0)
                    basesChar[i] = '@';
                else
                    basesChar[i] = 'G';
        }


        /* Se a base é 1 então a base escolhida é a base2 */
        if (bases[i] == 1) {
            /* Se a base for '+' então verifica o valor do bit correspondente e faz a polarização */
            if (base2 == '+')
                if (bits[i] == 0)
                    basesChar[i] = '^';
                else
                    basesChar[i] = '>';
            /* Se a base for 'x' então verifica o valor do bit correspondente e faz a polarização */
            if (base2 == 'x')
                if (bits[i] == 0)
                    basesChar[i] = '/';
                else
                    basesChar[i] = '\\';
            /* Se a base for 'o' então verifica o valor do bit correspondente e faz a polarização */
            if (base2 == 'o')
                if (bits[i] == 0)
                    basesChar[i] = '@';
                else
                    basesChar[i] = 'G';
        }
    }
    return basesChar;
}

void printVetor(int* vetor, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" %d", vetor[i]);
    }
    printf("\n");
}

char* basesBinToChar(int* basesBinarias,int n, char base1,char base2){
    char* basesChar = (char*)malloc(n * sizeof(char));
    int i;
    for (i = 0; i < n; i++) {
        if (basesBinarias[i]==0)
            basesChar[i]=base1;
        else
            basesChar[i]=base2;
    }
    return basesChar;
}


int* comparaBases(char* basesAlice, char* basesBob){

}
