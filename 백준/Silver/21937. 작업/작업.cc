#include <iostream>
#include <vector>


using namespace std;

int n,m,start;


vector<int> adj[100001];


bool vis[100001] = {false};


int deg(int start){
    int sum = 0;
    
    for(int i=0; i<adj[start].size(); ++i){
        int to = adj[start][i];
        if(vis[to]) continue;
        vis[to] = 1;
        sum += deg(to) + 1;
    }

    return sum;

}





int main(){
    cin>>n>>m;


    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[b].push_back(a);
    }


    int k;
    cin>>k;

    cout<<deg(k);










}