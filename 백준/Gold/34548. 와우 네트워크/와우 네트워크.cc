#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> parent, r;


bool compare(tuple<int,int,int> a, tuple<int,int,int> b) {
    return get<2>(a) < get<2>(b);
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if(r[u] < r[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
        if(r[u] == r[v]) r[u]++;
    }
    return true;

}

int main() {

    int n,m,t;
    cin>>n>>m>>t;

    vector<tuple<int,int,int> > edge(m);

    for(int i=0; i<m; i++) {
        int u,v,s;
        cin>>u>>v>>s;
        edge[i] = make_tuple(u,v,s);
    }

    // 경계 시간 순 정렬
    sort(edge.begin(), edge.end(), compare);

    parent.resize(n+1);
    r.assign(n+1, 0);

    for(int i=1; i<=n; i++) parent[i] = i;

    long long ans = 0;
    long long last_time = 0;

    // 분리된 컴포넌트 수
    long long cnt = n;

    for(int i=0; i<m;) {
        int s = get<2>(edge[i]);

        long long l = s - last_time - 1;

        if(l > 0) {
            ans += l * cnt;
        }


        // 시간, 컴포넌트 수 변화
        while(i < m && get<2>(edge[i]) == s) {
            int u = get<0>(edge[i]);
            int v = get<1>(edge[i]);
            if(merge(u,v)) cnt --;
            i++;
        }

        ans += cnt;

        last_time = s;
    }

    if(last_time < t) {
        ans += (t - last_time) * cnt;
    }

    cout<<ans;
}