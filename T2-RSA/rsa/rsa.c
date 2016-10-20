#include <stdio.h>
#include <stdlib.h>

int findPrimes(int n, int *p1, int *p2, int primes[]);
int decrypt(int *p1, int *p2, int c, int e, int n);
int mod(int a, int b);
long long modular_pow(long long base, long long exponent, int modulus);
int modinv(int u, int v);
int* load_primes(void);
int max_primes = 131072; //Um valor inicial igual a 2^17

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

    //lendo a entrada
    scanf("%d %d %d", &n, &e, &c);

    int find;

    // inicialmente é utilizado um tamanho pequeno de números primos.
    // a cada loop, caso não encontre, a quantidade de números primos dobra. 
    // enqt houver memória, ou atingir o valor máximo de um int de 4 bytes.
    do {
        //carrega os números primos em um vetor
        int* primes = load_primes();
        //busca para ver se encontra dois primos multiplicados que de o valor de N
        find = findPrimes(n, &p1, &p2, primes);
        //se encontrou decripta a mensagem
        if (find) {
            int m = decrypt(&p1, &p2, c, e, n);
            printf("%d", m);
        }
        free(primes);
        //proteção para não estourar o tamanho do int
        if (max_primes > 1073741823) {
            max_primes = 2147483647;
        } else {
            max_primes = max_primes * 2;
        }

    } while (!find);

    return (0);
}

int findPrimes(int n, int *p1, int *p2, int primes[]) {
    int i;
    for (i = 0; i <= max_primes; i++) {
        int j;
        for (j = 0; j <= max_primes; j++) {
            if (primes[i] * primes[j] == n) {
                //Primos encontrados!
                *p1 = primes[i];
                *p2 = primes[j];
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
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    iter = 1;
    while (v3 != 0) {
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;

        u1 = v1;
        v1 = t1;
        u3 = v3;
        v3 = t3;
        iter = -iter;
    }
    if (u3 != 1)
        return 0; //Não há inverso!
    //Garantir que o resultado é positido
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
    if (!primes) {
        printf("Memória Insuficiente, encerrando o programa");
        exit(1);
    }
    int *numbers;
    numbers = (int*) malloc(max_primes * sizeof (int));


    for (i = 0; i < max_primes; i++) {
        numbers[i] = i + 2;
    }

    //Preenche números compostos com -1
    for (i = 0; i < max_primes; i++) {
        if (numbers[i] != -1) {
            for (j = 2 * numbers[i] - 2; j < max_primes; j += numbers[i])
                numbers[j] = -1;
        }
    }

    //Os que não são primos passam para o vetor de primos
    j = 0;
    for (i = 0; i < max_primes && j < primes; i++)
        if (numbers[i] != -1)
            primes[j++] = numbers[i];
    free(numbers);
    return primes;
}