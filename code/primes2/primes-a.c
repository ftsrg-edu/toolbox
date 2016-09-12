#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_prime(int k) {
	int prime = 1;
	int root = (int) sqrt(k);
	for (int i = 2; i <= root; i++) {
		if (k % i == 0) {
			prime = 0;
		}
	}
	return prime;
}

int number_of_primes(int n) {
	int p = 0;
	for (int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			p++;
		}
	}
	return p;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage: primes <n>\n");
		return -1;
	}
	const int n = strtol(argv[1], NULL, 10);

	printf("Calculating... ");
	int p = number_of_primes(n);
	printf("// Done.\n");
	printf("There are %d primes from 1 to %d.\n", p, n);

	return 0;
}
