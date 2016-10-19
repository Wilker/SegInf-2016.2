#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000 /*size of integers array*/

int findPrimes(int *primes, int n, int *p1, int *p2);
int decrypt(int p1, int p2, int c, int e);
int mod(int a, int b);
unsigned int modinv(unsigned int u, unsigned int v);

int main(int argc, char** argv) {
	int i, j;
	int *primes;

	primes = malloc(sizeof(int)*LIMIT);
	printf("Calculando primos...\n");
	for (i = 2; i<LIMIT; i++)
		primes[i] = 1;

	for (i = 2; i<LIMIT; i++)
	if (primes[i])
	for (j = i; i*j<LIMIT; j++)
		primes[i*j] = 0;

	printf("Imprimindo primos...\n");
	for (i = 2; i<LIMIT; i++)
	if (primes[i])
	printf("%d\t", i);
	
	printf("\nInsira a chave publica, o expoente e a mensagem cifrada: ");

	//Chave pública
	int n = 0;
	//expoente de encriptação
	int e = 0;
	//mensagem cifrada
	int c = 0;

	scanf("%d %d %d", &n, &e, &c);
	//primo 1
	int* p1 = 0;
	//primo 2
	int* p2 = 0;

	if (findPrimes(primes, n, &p1, &p2)) {
		//int m = decrypt(p1, p2, c, e);
		printf("Primos %d \t %d", p1, p2);
	}
	else{
		printf("Primos nao encontrados!");
	}

	getch();
}

/**
* Retorna 1 caso encontre p1*p1=n  e 0 caso contrário
* @param n
* @return
*/

int findPrimes(int *primes, int n, int *p1, int *p2) {
	int i, j;
	for (i = 2; i < LIMIT; i++){
		if (primes[i]){
			for (j = 2; j < LIMIT; j++){
				if (primes[j]){
					if (n == i*j){
						*p1 = i;
						*p2 = j;
						return 1;
					}
				}

			}
		}

	}
	return 0;
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
