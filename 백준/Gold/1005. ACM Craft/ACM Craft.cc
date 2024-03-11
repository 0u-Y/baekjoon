#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int t;
    int n,k;
    int x,y;
    int w;
    cin>>t;
    while(t--){
        int sum = 0;
        vector<int> adj[1001];
        int deg[1001];
        cin>>n>>k;
        int time[1001];
        for(int i=1; i<=n; i++){
            cin>>time[i];
        }
        for(int i=0; i<k; i++){
            cin>>x>>y;
            adj[x].push_back(y);
            deg[y]++;
        }
        queue<int> Q;
        int tot[1001] = {0};

        for(int i=1; i<= n; i++){
            if(deg[i] == 0){
                Q.push(i);
            }
        }
        cin>>w;
        while(!Q.empty()){
            int cur = Q.front(); Q.pop();
            for(int i=0; i<adj[cur].size(); i++){
                int nxt = adj[cur][i];
                tot[nxt] = max(tot[cur] + time[cur] , tot[nxt]);
                deg[nxt] --;
                if(deg[nxt] == 0){
                    Q.push(nxt);
                }
            }
        }
        cout<<tot[w] + time[w]<<"\n";

    


    }

}