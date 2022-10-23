#include <bits/stdc++.h>
#include <fstream>

//#include <windows.h>

#pragma GCC optimize("Ofast")

using namespace std;

ifstream fin("cube.in");
ofstream fout("cube.out");

struct Point {
	int x, y, z;
};
bool operator<(Point x, Point y) {
	if (x.x == y.x) {
		if (x.y == y.y) {
			return x.z < y.z;
		}
		return x.y < y.y;
	}
	return x.x < y.x;
}

int n;

int ans;
map<Point, int> mp;

signed main() {
	//int _runtime_stt = GetTickCount();
	fin >> n;
	for (int i = 1, x0, y0, z0, x1, y1, z1; i <= n; i++) {
		fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
		for (int x = x0; x <= x1; x++) {
			for (int y = y0; y <= y1; y++) {
				for (int z = z0; z <= z1; z++) {
					mp[(Point) {x, y, z}]++;
				}
			}
		}
	}
	for (auto it : mp) {
		if (it.second >= n - 1) {
			ans++;
		}
	}
	fout << ans;
	/*int _runtime_end = GetTickCount();
	double _runtime = double(_runtime_end - _runtime_stt) / 1000.0;
	cout << "Runtime: " << _runtime << '\n';
	system("pause");*/
	return 0;
}
