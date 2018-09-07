//https://www.acmicpc.net/problem/14889

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int area[21][21];
int chk[21];
int n, maxValue;
int ans = 987654321;

void go(int lo, int cnt) {
	if (lo == n) return;
	if (cnt == n / 2) {
		vector<int> v, v2;
		int tmp = 0, tmp2 = 0;
		for (int i = 0; i < n; i++) {
			if (chk[i] == 1) {
				v.push_back(i);
			}
			else {
				v2.push_back(i);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				tmp += area[v[i]][v[j]];
				tmp += area[v[j]][v[i]];
			}
		}
		for (int i = 0; i < v2.size(); i++) {
			for (int j = i + 1; j < v2.size(); j++) {
				tmp2 += area[v2[i]][v2[j]];
				tmp2 += area[v2[j]][v2[i]];
			}
		}
		tmp = abs(tmp - tmp2);
		if (tmp < ans) ans = tmp;
		return;
	}
	chk[lo] = 1;
	go(lo + 1, cnt + 1);
	chk[lo] = 0;
	go(lo + 1, cnt);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &area[i][j]);
		}
	}
	go(0, 0);
	printf("%d\n", ans);
	return 0;
}
