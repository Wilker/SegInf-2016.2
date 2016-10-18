/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rsa.c
 * Author: wilker
 *
 * Created on 8 de Outubro de 2016, 16:55
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int findPrimes(int n, int *p1, int *p2, unsigned int* primes);
int decrypt(int p1, int p2, int c, int e);
int mod(int a, int b);
unsigned int modinv(unsigned int u, unsigned int v);
int load(int* primes);

int main(int argc, char** argv) {
    //Chave pública
    int n = 0;
    //expoente de encriptação
    int e = 0;
    //mensagem cifrada
    int c = 0;

    scanf("%d %d %d", &n, &e, &c);
    //primo 1
    int p1 = 0;
    //primo 2
    int p2 = 0;
    unsigned int* primes = (unsigned int *) malloc(78742 * sizeof (unsigned int)); // aloca a quantidade exata para todos os primos entre 1 e 1M

    if (findPrimes(n, &p1, &p2, primes)) {
        int m = decrypt(p1, p2, c, e);
        printf(m);
    }

    return (EXIT_SUCCESS);
}

/**
 * Retorna 1 caso encontre p1*p1=n  e 0 caso contrário
 * @param n
 * @return 
 */
int findPrimes(int n, int *p1, int *p2, unsigned int * primes) {
    load(primes);
    return 1;
}

int decrypt(int p1, int p2, int c, int e) {


    return 1;
}

unsigned int modinv(unsigned int u, unsigned int v) {
    unsigned int inv, u1, u3, v1, v3, t1, t3, q;
    int iter;
    /* Step X1. Initialise */
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    /* Remember odd/even iterations */
    iter = 1;
    /* Step X2. Loop while v3 != 0 */
    while (v3 != 0) {
        /* Step X3. Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1;
        v1 = t1;
        u3 = v3;
        v3 = t3;
        iter = -iter;
    }
    /* Make sure u3 = gcd(u,v) == 1 */
    if (u3 != 1)
        return 0; /* Error: No inverse exists */
    /* Ensure a positive result */
    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;

    return inv;
}

int mod(int a, int b) {
    if (b < 0)
        return mod(a, -b);
    int ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

int load(int* primes) {
    char* caminho = "/home/wilker/Documentos/Git/Primos/primos.txt";
    FILE *arq;
    arq = fopen(caminho, "r");
    if (!arq) {
        printf("Erro na abertura do arquivo, tente novamente:");
        system("pause");
        exit(1);
    }
    int tmp = 0;
    fscanf(arq, "%d", &tmp);
    primes[0] = tmp;
    int counter = 1;

    while (!feof(arq)) {
        printf("Lido %d\n", tmp);
        fscanf(arq, "%d", &tmp);
        primes[counter] = tmp;
        counter++;
        printf("Posição do array de int %d valor %d\n", counter, primes[counter]);
    }
    fclose(arq);
    return 0;
}