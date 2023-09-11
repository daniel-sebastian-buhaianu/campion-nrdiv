#include <stdio.h>

#define NMAX 50
#define VMAX 10000000000000

unsigned nrdiv(unsigned long long x)
{
	if (x == 1) return 1;

	unsigned d = 2, nrd = 2;

	while (d*d < x) {
		if (x % d == 0) nrd += 2; // doi divizori: d, x/d

		d++;
	}

	if (d*d == x) nrd++; // caz x patrat perfect

	return nrd;
}

int main()
{
	FILE *fin = fopen("nrdiv.in", "r");

	if (!fin) { printf("Eroare citire nrdiv.in\n"); return 1; }
	
	unsigned short n;

	fscanf(fin, "%hu", &n);

	if (n < 1 || n > NMAX) { printf("Eroare valoare n\n"); return 2; }

	unsigned short i;
	unsigned long long x;
	
	FILE *fout = fopen("nrdiv.out", "w");

	for (i = 0; i < n; i++) {
		fscanf(fin, "%llu", &x);

		if (x < 1 || x > VMAX) { printf("Eroare valoare x\n"); return 3; }

		fprintf(fout, "%u\n", nrdiv(x));
	}
	
	fclose(fin);
	fclose(fout);

	return 0;
}

// scor 30
