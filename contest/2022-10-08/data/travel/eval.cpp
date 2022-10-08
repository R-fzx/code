#include <cstdlib>
#include <cstdio>

const int MAXN = 222;

FILE *fin, *fout, *fscore, *freport, *fstd;
int S, n, m, a[MAXN][MAXN];

inline void Input(void) {
	fscanf(fin, "%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		fscanf(fin, "%d%d", &x, &y);
		a[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) a[i][i] = 1;
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= n; j++) 
				a[i][j] |= a[i][k] && a[k][j];
}

int stack[MAXN];

inline int Check(void) {
	Input();
	int Ans, c_Ans;
	fscanf(fstd, "%d", &Ans);
	fscanf(fout, "%d", &c_Ans);
	if (Ans != c_Ans) { fprintf(freport, "����Ĵ𰸡�\n"); return 0; }
	for (int i = 1; i <= c_Ans; i++) { 
		if (fscanf(fout, "%d", stack + i) != 1) { fprintf(freport, "������㡣\n"); return 0; }
		if (stack[i] < 1 || stack[i] > n) { fprintf(freport, "�Ƿ������\n"); return 0; }
		for (int j = 1; j <= i - 1; j++) if (a[stack[i]][stack[j]] || a[stack[j]][stack[i]]) { fprintf(freport, "��\n"); return 0; }
	}
	if (fscanf(fout, "%d", stack) == 1) { fprintf(freport, "�����ʣ��\n"); return 0; }
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
	return 0;
}

