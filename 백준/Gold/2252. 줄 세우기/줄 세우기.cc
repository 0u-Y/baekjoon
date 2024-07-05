#include <iostream>
#include <vector>
#include <queue>



using namespace std;

int deg[32001];

vector<int> adj[32001];







int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }

    queue<int> Q;

    for(int i=1; i<=n; i++){
        if(deg[i] == 0){
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        cout<<cur<<" ";
        for(int nxt : adj[cur]){
            deg[nxt]--;
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }

    











}