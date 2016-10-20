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

//#define max_primes 21474 /*size of integers array*/


int findPrimes(int n, int *p1, int *p2, int primes[]);
int decrypt(int *p1, int *p2, int c, int e, int n);
int mod(int a, int b);
long long modular_pow(long long base, long long exponent, int modulus);
int modinv(int u, int v);
int* load_primes(void);
int max_primes = 100000;

int main(int argc, char** argv) {
    //Chave pública
    int n = 0;
    //expoente de encriptação
    int e = 0;
    //mensagem cifrada
    int c = 0;
    //primo 1
    int *p1 = 0;
    //primo 2
    int *p2 = 0;



    scanf("%d %d %d", &n, &e, &c);


    int find;
    do {
        int* primes = load_primes();
        find = findPrimes(n, &p1, &p2, primes);
        if (find) {
            int m = decrypt(&p1, &p2, c, e, n);
            printf("%d", m);
        }
        free(primes);
        max_primes = max_primes * 2;
    } while (!find);


    return (0);
}

/**
 * Retorna 1 caso encontre p1*p1=n  e 0 caso contrário
 * @param n
 * @return 
 */
int findPrimes(int n, int *p1, int *p2, int primes[]) {
    int i;
    for (i = 0; i <= max_primes; i++) {
        int j;
        for (j = 0; j <= max_primes; j++) {
            if (primes[i] * primes[j] == n) {
                *p1 = primes[i];
                *p2 = primes[j];
                printf("Primos encontrados %d e %d\n", *p1, *p2);
                return 1;
            }
        }
    }
    return 0;
}

int decrypt(int *p1, int *p2, int c, int e, int n) {
    int d = modinv(e, (*p1 - 1)*(*p2 - 1));
    unsigned int m = modular_pow(c, d, n);
    return m;
}

int modinv(int u, int v) {
    int inv, u1, u3, v1, v3, t1, t3, q;
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

long long modular_pow(long long base, long long exponent, int modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int* load_primes(void) {
    int i, j;
    int *primes;
    primes = (int*) malloc(max_primes * sizeof (int));
    int *numbers;
    numbers = (int*) malloc(max_primes * sizeof (int));


    for (i = 0; i < max_primes; i++) {
        numbers[i] = i + 2;
    }

    /*sieve the non-primes*/
    for (i = 0; i < max_primes; i++) {
        if (numbers[i] != -1) {
            for (j = 2 * numbers[i] - 2; j < max_primes; j += numbers[i])
                numbers[j] = -1;
        }
    }

    /*transfer the primes to their own array*/
    j = 0;
    for (i = 0; i < max_primes && j < primes; i++)
        if (numbers[i] != -1)
            primes[j++] = numbers[i];
    free(numbers);
    return primes;
}