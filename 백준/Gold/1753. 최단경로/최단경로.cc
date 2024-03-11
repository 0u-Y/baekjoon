#include <iostream>
#include <functional>
#include <queue>

using namespace std;

#define X first
#define Y second

int v, e, st;

vector<pair<int,int> > adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005];

int main(){
    cin>>v>>e>>st;

    fill(d, d+v+1, INF);
    while(e--){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w,v});

    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    d[st] = 0;
    pq.push({d[st], st});

    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(int i=0; i< adj[cur.Y].size(); i++){
            pair<int,int> nxt = adj[cur.Y][i];
            if(d[nxt.Y] <= d[cur.Y] + nxt.X)continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push(make_pair(d[nxt.Y], nxt.Y));
        }

    }

    for(int i=1; i<=v; i++){
        if(d[i] == INF) cout<<"INF"<<'\n';
        else{
            cout<<d[i] << '\n';
        }
    }


}

