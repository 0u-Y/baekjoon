#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>





using namespace std;


vector<int> p(100001,-1);



int find(int x){
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}


bool is_diff_group(int u, int v){
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;

    cin>>n>>m;

    tuple<int,int,int> edge[1000001];

    for(int i=0; i<m; i++){
        int a,b,cost;
        cin>>a>>b>>cost;
        edge[i] = {cost,a,b};
    }

    sort(edge, edge + m);


    int cnt = 0;
    int total_cost = 0;

    int max_road = 0;
    

    for(int i=0; i<m; i++){
        int a,b,cost;
        tie(cost,a,b) = edge[i];
        if(!is_diff_group(a,b)) continue;
        total_cost += cost;
        max_road = max(max_road, cost);
        cnt++;
        if(cnt == n-1) break;
    }


    cout<<total_cost - max_road;


    











}