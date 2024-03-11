#include <iostream>
#include <queue>
#include <vector>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<int> adj[32001];

    int deg[32001];

    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> Q;

    for(int i  = 1; i<=n; i++){
        if(deg[i] == 0){
            Q.push(i);
        }
    }
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout<<cur<<" ";
        for(int i=0; i<adj[cur].size(); i++){
            int nxt = adj[cur][i];
            deg[nxt]--;
            if(deg[nxt] == 0){
                Q.push(nxt);
            }
        }


    }
   
}
