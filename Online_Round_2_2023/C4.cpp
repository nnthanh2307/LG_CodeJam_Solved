#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define WMAX 100000

#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FLT(i, a, b) for(int i = (a); i <= (b); i++)
#define FGT(i, a, b) for(int i = (a); i >= (b); i--)
#define FG(i, a, b) for(int i = (a); i > (b); i--)
#define end "\n"

struct Node {
    long long score;
    vector<vector<ull>> graph;
};

vector<Node> st;

static int x = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void print(vector<vector<ull>> &graph, int m) {
    FLT (i, 1, m) {
        FLT (j, 1, m) cout << graph[i][j] << " ";
        cout << endl;
    }
}

void floy(vector<vector<ull>> &graph, int m) {
    for (int k = 1; k <= m; k++) {
        for (int u = 1; u <= m; u++) {
            for (int v = 1; v <= m; v++) {
                if (graph[u][k] != INT_MAX && graph[k][v] != INT_MAX) {
                    graph[u][v] = min(graph[u][v], graph[u][k] + graph[k][v]);
                }
            }
        }
    }
}

ull score(vector<vector<ull>> &graph, int m) {
    ull score = 0;
    FLT (i, 1, m) {
        FLT (j, i + 1, m) 
            if (graph[i][j] < INT_MAX) score += graph[i][j];
    }
    return score;
}

bool updateGraph(vector<vector<ull>> &graph, int u, int v, int w, int m) {
    if (graph[u][v] <= w) return false;
    graph[u][v] = w; graph[v][u] = w;
    
    FLT (i, 1, m) {
        FLT (j, 1, m) {
            graph[i][j] = min(graph[i][j], 
                min(graph[i][v] + graph[u][j], graph[i][u] + graph[v][j]) + w);
        }
    }
    return true;
}
 
void solve() {
    int m, n, q; cin >> m >> n >> q;
    int a, b, c;
    vector<vector<ull>> graph(201, vector<ull>(201));
    ull current = 0;

    FLT (i, 1, m) {
        FLT (j, 1, m) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = INT_MAX;
        }
    }

    FOR (i, 0, n) {
        cin >> a >> b >> c;
        graph[a][b] = c; graph[b][a] = c;
    }

    floy(graph, m);
    current = score(graph, m);
    
    FOR (i, 0, q) {
        int a; cin >> a;
        if (a == 1) {
            cout << current << " ";
        } else if (a == 2) {
            int u, v , w; cin >> u >> v >> w;
            struct Node node;
            node.graph = graph; node.score = current;
            if (updateGraph(graph, u, v, w, m)) {
                current = score(graph, m);
                node.graph = graph;
                st.push_back(node);
            } else {
                graph = node.graph;
            }
        } else if (a == 3) {
            if (st.size() > 0) {
                auto temp = st.back();
                graph = temp.graph; current = temp.score;
                st.pop_back();
            }
        }
    }
    cout << endl;
}
 
    int TC = 0; cin >> TC;
    while (TC--) 
        solve();
 
    return 0;
}