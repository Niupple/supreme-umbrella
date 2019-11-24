/* copyright dyj
 * template for Algorithm Coding Assignments
 */
#include <bits/stdc++.h>
#define NAME "dzzxl"
#ifdef DEBUG
#define DP(...) fprintf(stderr, ##__VA_ARGS__)
#else
#define DP(...) 
#endif

using namespace std;

typedef long long LL;

int N, K;
int av[102];
LL dp[102][102];

bool readin() {
	scanf("%d%d", &N, &K);
	if(N == 0 && K == 0) {
		return false;
	}
	DP("N = %d, K = %d\n", N, K);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", av+i);
	}
	return true;
}

void process() {
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; ++i) {
		dp[i][1] = 1;
	}
	for(int j = 2; j <= K; ++j) {
		for(int i = 1; i <= N; ++i) {
			for(int k = 1; k < i; ++k) {
				if(av[k] < av[i]) {
					dp[i][j] += dp[k][j-1];
				}
			}
		}
	}
	LL ans = 0;
	for(int i = 1; i <= N; ++i) {
		ans += dp[i][K];
	}
	printf("%lld\n", ans);
}

int main() {
#ifdef DEBUG
	freopen(NAME ".in", "r", stdin);
#endif
	
	while(readin()) {
		process();
	}

	return 0;
}

