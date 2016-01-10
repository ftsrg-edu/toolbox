#include <stdio.h>
#include <math.h>

int number_of_primes(int n) {
	int p = 0;

	// for the sake of readability, we align the indexing with the actual numbers
	int is_prime[n+1];
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		is_prime[i] = 1;
	}

	// use the sieve of Erathosthenes
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			p++;
			int j = i + i;
			while (j <= n) {
				is_prime[j] = 0;
				j += i;
			}
		}
	}

	return p;
}

int main() {
	const int n = 1000000;

	printf("Calculating...\n");
	int p = number_of_primes(n);
	printf("Done.\n");
	printf("There are %d primes from 1 to %d.\n", p, n);

	return 0;
}
