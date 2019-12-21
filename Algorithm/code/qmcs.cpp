/* copyright dyj
 * template for Algorithm Coding Assignments
 */
#include <bits/stdc++.h>
#define NAME "qmcs"
#ifdef DEBUG
#define DP(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define DP(...) 
#endif

using namespace std;

typedef long long LL;

int N, K, M;
int av[1003], dp[1003], sp[1003];
const int MOD = 998244353;

void readin() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", av+i);
	}
}

int unique(int *a, int n) {
	int cnt = 1, now = 1;
	a[n+1] = -1;
	for(int i = 2; i <= n+1; ++i) {
		DP("at %d:\n", i);
		if(a[i] == a[now]) {
			DP("++cnt\n");
			++cnt;
		} else {
			DP("a[%d] = %d\n", now, cnt);
			a[now++] = cnt;
			a[now] = av[i];
			cnt = 1;
		}
	}
	--now;
#ifdef DEBUG
	for(int i = 1; i <= now; ++i) {
		DP("a[%d] = %d\n", i, a[i]);
	}
#endif
	return now;
}

void process() {
	sort(av+1, av+1+N);
	M = unique(av, N);
	for(int i = 1; i <= M; ++i) {
		dp[i] = av[i];
	}
	for(int j = 2; j <= K; ++j) {
		DP("in round %d\n", j);
		sp[0] = 0;
		for(int i = 1; i <= M; ++i) {
			sp[i] = ((LL)sp[i-1] + dp[i])%MOD;
			dp[i] = 1LL*sp[i-1]*av[i]%MOD;
			DP("dp[%d] = %d\n", i, dp[i]);
			DP("sp[%d] = %d\n", i, dp[i]);
		}
	}
	int ans = 0;
	for(int i = 1; i <= M; ++i) {
		ans = ((LL)ans + dp[i])%MOD;
	}
	printf("%d\n", ans);
}

int main() {
#ifdef DEBUG
	freopen(NAME ".in", "r", stdin);
#endif
	
	readin();
	process();

	return 0;
}

