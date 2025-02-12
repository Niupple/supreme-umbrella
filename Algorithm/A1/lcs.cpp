#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
	return x&(-x);
}

int highbit(int x) {
	for(int i = 30; i >= 0; --i) {
		if(x&(1<<i)) {
			return i;
		}
	}
	return -1;
}

const char *sigma = "abcdefghijklmnopqrstuvwxyz0123456789";

int maxc(int l, int r) {
	return highbit((l-1)^r);
}

int cross(int l1, int r1, int l2, int r2) {
	return max(0, min(r1, r2)-max(l1, l2));
}

int calc(int l1, int r1, int l2, int r2) {
	int k1 = maxc(l1, r1);
	int k2 = maxc(l2, r2);
	if(k1 > k2) {
		swap(l1, l2);
		swap(r1, r2);
		swap(k1, k2);
	}
	l1 %= (1<<(k1+1));
	r1 %= (1<<(k1+1));
	l2 %= (1<<(k2+1));
	r2 %= (1<<(k2+1));
	if(k1 == k2) {
		ret = max(ret, cross(l1, r1, l2, r2));
	} else {
		ret = max(ret, max(cross(l1+k2-k1, r1+k2-k1, l2, r2), cross(l1+k2, r1+k2, l2, r2)));
	}
	int ll, lr, rl, rr;
	ll = k1 - (k1 >> 1);
	lr = k1 + (k1 >> 1);
	rl = k2 - (k1 >> 1);
	rr = k2 + (k1 >> 1);
	ret = max(ret, chain(l1, r1, l2, r2, ll, lr, rl, rr, k1 >> 1));
}

int main() {


	return 0;
}
