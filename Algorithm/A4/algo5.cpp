#include <cstdio>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

const int MAX_N = 100, MAX_M = 200;
int N, M;   // N = #V, M = #E
int S, T;
int cne;
bool in[MAX_N];
typedef pair<int, int> pii;

struct edge {
    int to, v;
    edge *nxt;
} E[MAX_M * 2], *node[MAX_N];

void add_edge(int f, int t, int v) {
    E[cne].to = t;
    E[cne].v = v;
    E[cne].nxt = node[f];
    node[f] = E+cne++;
}

void readin() {
    int a, b, v;
    scanf("%d%d", &N, &M);
    scanf("%d%d", &S, &T);
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d%d", &a, &b, &v);
        add_edge(a, b, v);
        add_edge(b, a, v);
    }
}


int prim_like(int x) {
    priority_queue<pii> que;
    in[x] = true;
    int H = INT_MAX;
    for (edge *i = node[x]; i; i = i->nxt) {
        que.push({i->v, i - E});
    }
    while (!que.empty()) {
        auto p = que.top();
        que.pop();
        H = min(H, p.first);
        edge *e = E + p.second;
        if (!in[e->to]) {
            in[e->to] = true;
            if (e->to == T) {
                return H;
            }
            for (edge *i = node[e->to]; i; i = i->nxt) {
                que.push({i->v, i - E});
            }
        }
    }
    return -1;
}

void process() {
    int ans = prim_like(S);
    if (ans == -1) {
        printf("No Solution!\n");
    } else {
        printf("%d\n", ans);
    }
}

int main() {

    readin();
    process();

    return 0;
}