//https://www.acmicpc.net/problem/2747
//http://1ilsang.blog.me/221338025460

#include <cstdio>

int n;
int memo[46];

int go(int now) {
	if (now == 0) return 0;
	if (now <= 2) return 1;
	if (memo[now] != 0) return memo[now];
	return memo[now] = go(now - 1) + go(now - 2);
}

int main(void) {
	scanf("%d", &n);
	printf("%d\n", go(n));
	return 0;
}
