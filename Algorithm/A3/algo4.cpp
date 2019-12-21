#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to;
    edge *nxt;
} E[MAXM<<1], *node[MAXN];

int N, M;
bool usd[MAXN];

void add_edge(int f, int t) {
    E[cne].to = f;
    E[cne].nxt = node[f];
    node[f] = E+cne++;
}

void readin() {
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
}

stack<int> stk;

int dfs(int x, int f) {
    usd[x] = true;
    stk.push(x);
    for (edge *i = node[x]; i; i = i->nxt) {
        int now = i->to;
        if (now != f) {
            if (usd[now]) {
                int y;
                do {
                    y = stk.top();
                    stk.pop();
                    printf("%d\n", y);
                } while(y != now);
                exit(0);
            } else {
                dfs(now);
            }
        }
    }
    stk.pop();
}

void process() {
    dfs(1, 1);
}

int main() {

    readin();
    process();

    return 0;
}