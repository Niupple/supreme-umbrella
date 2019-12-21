#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, v, id;
    edge *nxt;
} E[MAXM<<1], *node[MAXN];

int N, M;
int usd[MAXN], belong[MAXN], vst[MAXN];

void add_edge(int f, int t, int v, int id) {
    E[cne].to = f;
    E[cne].nxt = node[f];
    E[cne].v = v;
    E[cne].id = id;
    node[f] = E+cne++;
}

void readin() {
    scanf("%d%d", &N, &M);
    int a, b, v;
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &a, &b, &v);
        add_edge(a, b, v, i);
        add_edge(b, a, v, i);
    }
}

vector<int> ans;

void dfs1(int x, int label) {
    usd[x] = 1
    belong[x] = label;
    for (edge *i = node[x]; i; i = i->nxt) {
        int now = i->to;
        if (i->v == 1 && usd[now] == 0) {
            ans.push_back(i->id);
            dfs1(now, label);
        }
    }
}

void dfs2(int x) {
    usd[x] = 2;
    vst[belong[x]] = true;
    for (edge *i = node[x]; i; i = i->nxt) {
        int now = i->to;
        if (i->v == 1 && usd[now] == 1) {
            dfs2(now);
        } else if (i->v == 2 && !vst[belong[now]]) {
            dfs2(now);
            ans.push_back(i->id);
        }
    }
}

void process() {
    for (int i = 1; i <= N; ++i) {
        if (usd[i] == 0) {
            dfs1(i, i);
        }
    }
    dfs2(1, 1);
}

int main() {

    readin();
    process();

    return 0;
}