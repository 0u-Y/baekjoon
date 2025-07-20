#include <iostream>
#include <vector>

using namespace std;

const int MAX = 500001;
const int LOG = 17;
// dp[v][t] = v의 2^t번째 조상 -> dp[v][t] = dp[dp[v][t-1]][t-1] 자명
int dp[MAX][LOG];
vector<int> tree[MAX];
int depth[MAX];
int visited[MAX];
int n,m;

void make_table() {
    for(int j=1; j<LOG; j++) {
        for(int i=1; i<=n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u,v);
    }
    int diff = depth[u] - depth[v];

    for(int i=0; diff; i++) {
        if(diff & 1) u = dp[u][i];
        diff >>= 1;
    }

    if(u == v) return u;

    for(int i=LOG-1; i>=0; i--) {
        if(dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return dp[u][0];
}

void dfs(int cur, int d) {
    visited[cur] = 1;
    depth[cur] = d;

    for(int next : tree[cur]) {
        if(!visited[next]) {
            dp[next][0] = cur;
            dfs(next, d + 1);
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    for (int i=0; i<n-1; i++) {
        int a, b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1,0);
    make_table();

    cin>>m;

    while(m--) {
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }
}