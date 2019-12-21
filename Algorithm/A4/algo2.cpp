#include <cstdio>
#include <queue>

using namespace std;

const int MAX_N = 100, MAX_M = 200;
int N, M;   // N = #V, M = #E
int cne;
int color[MAX_N];

struct edge {
    int to;
    edge *nxt;
} E[MAX_M * 2], *node[MAX_N];

void add_edge(int f, int t) {
    E[cne].to = t;
    E[cne].nxt = node[f];
    node[f] = E+cne++;
}

void readin() {
    int a, b;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; ++i) {
        scanf("%d%d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    fill_n(color, N, -1);
}

bool bfs(int x) {
    queue<int> que;
    que.push(x);
    color[x] = 0;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(edge *i = node[now]; i; i = i->nxt) {
            int to = i->to;
            if (color[to] == -1) {
                color[to] = color[now] ^ 1;
                que.push(to);
            } else if (color[to] == color[now]) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool check() {
    for (int i = 1; i <= N; ++i) {
        if (color[i] == -1) {
            if (!bfs(i)) {
                return false;
            }
        }
    }
    return true;
}

void process() {
    if (check()) {
        printf("YES!\n");
    } else {
        printf("NO!\n");
    }
}

int main() {

    readin();
    process();

    return 0;
}