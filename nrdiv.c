#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	char *ciur;
	unsigned short n;
	unsigned i, radmax, d, j, nrprime, *prim, p, nrd;
	unsigned long long *v, max;

	FILE *fin = fopen("nrdiv.in", "r");

	if (!fin) { printf("Eroare citire nrdiv.in\n"); return 1; }

	fscanf(fin, "%hu", &n);

	v = (unsigned long long*)calloc(n, sizeof(unsigned long long));

	if (!v) { printf("Eroare alocare memorie\n"); return 2; }	

	for (max = i = 0; i < n; i++) {
		fscanf(fin, "%llu", &v[i]);

		if (v[i] > max) max = v[i];
	}

	fclose(fin);
	
	radmax = sqrt(max);

	ciur = (char*)calloc(radmax, sizeof(char));

	for (d = 2; d*d < radmax; d++)
		if (!ciur[d])
			for (j = d*d; j <= radmax; j += d)
				ciur[j] = 1;

	prim = (unsigned*)calloc(1, sizeof(unsigned));

	if (!prim) { printf("Eroare alocare memorie\n"); return 2; }

	prim[0] = 2, nrprime = 1;

	for (d = 3; d <= radmax; d += 2)
		if (!ciur[d]) {
			prim = (unsigned*)realloc(prim, (nrprime + 1) * sizeof(unsigned));

			if (!prim) { printf("Eroare realocare memorie\n"); return 3; }

			prim[nrprime++] = d;
		}
	
	FILE *fout = fopen("nrdiv.out", "w");

	for (i = 0; i < n; i++) {
		nrd = 1;

		for (j = 0; j < nrprime && prim[j]*prim[j] <= v[i]; j++) {
			for (p = 0; v[i] % prim[j] == 0; v[i] /= prim[j], p++);

			nrd *= (p + 1);	
		}

		if (v[i] > 1) nrd *= 2;
		
		fprintf(fout, "%u\n", nrd);
	}

	fclose(fout);

	free(v); 
	free(ciur); 
	free(prim);

	return 0;
}
// scor 100
