#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

std::vector<int> primes;

int number_of_primes(int n) {
	// for the sake of readability, we align the indexing with the actual number
	int is_prime[n+1];
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		is_prime[i] = 1;
	}

	// use the sieve of Erathosthenes
	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			int j = i + i;
			while (j <= n) {
				is_prime[j] = 0;
				j += i;
			}
		}
	}

	return primes.size();
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


/*
#include<iostream>

using namespace std;

long factorial(int n);

int main() {
	for (int i = 1; i < 1000000; i++) {
		string* s = new string("hello");
	}
}

int main()
{
    int n(0);
    cin>>n;
    long val=factorial(n);
    cout<<val;
    cin.get();
    return 0;
}

long factorial(int n)
{
    long result(1);
    while(n--)
    {
        result*=n;
    }
    return result;
}
*/
