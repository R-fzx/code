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
		fscanf(fout, "%d%d%d", &l1, &l2, &l3);
		if (++a[l1][l2] > 3 || ++a[l2][l1] > 3) return (int)S * 0.2;
		if (++a[l3][l2] > 3 || ++a[l2][l3] > 3) return (int)S * 0.2;
		if (++a[l1][l3] > 3 || ++a[l3][l1] > 3) return (int)S * 0.2;
	}
	return S;
}

int main(int argc, char *argv[]) {
	fscore = fopen("score.log", "w");
	freport = fopen("report.log", "w");
	fstd = fopen(argv[2], "r");

	S = atoi(argv[1]);

	fin = fopen("rabbit.in", "r");
	fout = fopen("rabbit.out", "r");

	int ans = Check();
	fprintf(fscore, "%d", ans);
	fprintf(freport, "^_^");
	return 0;
}

