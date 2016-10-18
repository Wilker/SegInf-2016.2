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
int findPrimes(int n, int *p1, int *p2);
int decrypt(int p1, int p2, int c, int e);
int mod(int a, int b);
int extendedEuclidean(int a, int b, int *u, int *v);

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
    if (findPrimes(n, &p1, &p2)) {
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
int findPrimes(int n, int *p1, int *p2) {
    return 1;
}

int decrypt(int p1, int p2, int c, int e) {


    return 1;
}

int extendedEuclidean(int a, int b, int *u, int *v) {
    int u1, u2, v1, v2;
    u = v2 = 1;
    v = u2 = 0;
    while (mod(a, b) != 0) {
        int q = a / b;
        int r = mod(a, b);
        a = b;
        b = r;
        u1 = u;
        u = u2;
        u2 = u1 - q*u;
        v1 = v;
        v = v2;
        v2 = v1 - q*v;
    }
    return a;
}

int mod(int a, int b) {
    if (b < 0)
        return mod(a, -b);
    int ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}