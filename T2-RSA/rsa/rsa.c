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

void decrypt(int p1,int p2,int c);
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

        decrypt(p1, p2, c) {


        }
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


