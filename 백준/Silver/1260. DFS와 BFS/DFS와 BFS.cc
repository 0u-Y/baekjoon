#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;



int n,m;


int map[1001][1001];
queue<int> Q;

bool vis[1001] = {0};


void BFS(int a){
    cout<<a<<" ";
    Q.push(a);
    vis[a] = 1;
    while(!Q.empty()){
        a = Q.front(); Q.pop();
        for(int i=1; i<=n; i++){
            if(map[a][i] == 1 && vis[i] == 0){
                Q.push(i);
                vis[i] = 1;
                cout<<i<<" ";
            }
        }
    }

}

void DFS(int a){
    vis[a] = 1;
    cout<<a<<" ";
    for(int i=1; i<=n; i++){
        if(map[a][i] == 1 && vis[i] == 0){
            DFS(i);
        }
    }
}

int main(){
    int v;
    cin>>n>>m>>v;

    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for(int i=1; i<=n; i++){
        vis[i] = 0;
    }

    DFS(v);
    for(int i=1; i<=n; i++){
        vis[i] = 0;
    }
    cout<<'\n';
    BFS(v);

    

    




}