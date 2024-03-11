#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second



using namespace std;


int n,e;

int a,b,c;


int st,en;

const int INF = 1e9;



priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair< int,int> > > pq;


vector<pair<int,int> > adj[801];

int d[801];









long dijkstra(int a, int b){ // 정점 a -> 정점 b
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    fill(d, d + n + 1, INF);

    d[a] = 0;

    pq.push(make_pair(d[a], a));

    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        for(int i=0; i<adj[cur.Y].size(); i++){
            pair<int,int> nxt = adj[cur.Y][i];
            if(d[nxt.Y] > d[cur.Y] + nxt.X){
                d[nxt.Y] = d[cur.Y] + nxt.X;
                pq.push(make_pair(d[nxt.Y], nxt.Y));
            }
        }
    }


    return d[b];
    

    
    


    

}





int main(){
    cin>>n>>e;

    for(int i=0; i<e; i++){
        cin>>a>>b>>c; // a -> b 비용 = c
        
        adj[a].push_back(make_pair(c,b)); // (비용, 정점)
        adj[b].push_back(make_pair(c,a));

    }



    cin>>st>>en;
    

    long way1 = dijkstra(1,st) + dijkstra(st,en) + dijkstra(en,n);
    long way2 = dijkstra(1,en) + dijkstra(en,st) + dijkstra(st,n);


    long ans = min(way1, way2);


    if(ans >= INF){
        cout<<-1;
    }
    else{
        cout<<ans;
    }

}