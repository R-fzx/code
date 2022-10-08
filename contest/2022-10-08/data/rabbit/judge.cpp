#include <cstdio>
#include <cstdlib>
FILE *fscore, *freport, *fstd, *fin, *fout;
const int MAXN = 1010;
int a[MAXN][MAXN], S;
int Check(void) {
	int n;
	fscanf(fin, "%d", &n);
	int Ans;
	fscanf(fout, "%d", &Ans);
	if (Ans != n * (n - 1) / 2) return 0;
	for (int i = 1; i <= Ans; i++) {
		int l1, l2, l3;
		if (fscanf(fout, "%d%d%d", &l1, &l2, &l3) != 3) {
			return (int)S * 0.2;
		}
		if (++a[l1][l2] > 3 || ++a[l2][l1] > 3) return (int)S * 0.2;
		if (++a[l3][l2] > 3 || ++a[l2][l3] > 3) return (int)S * 0.2;
		if (++a[l1][l3] > 3 || ++a[l3][l1] > 3) return (int)S * 0.2;
	}
	return S;
}

int main(int argc, char *argv[]) {
	fscore = fopen(argv[5], "w");
	freport = fopen(argv[6], "w");
	fstd = fopen(argv[3], "r");

	S = atoi(argv[4]);

	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "r");

	int ans = Check();
	fprintf(fscore, "%d", ans);
	fprintf(freport, "^_^");
	return 0;
}

