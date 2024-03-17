#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,d;


vector<pair<int,int> > v[100001];

vector<int> map(10000, 1e9);


int main(){

  cin>>n>>d;

  for(int i=0; i<n; i++){
    int a,b,c;
    cin>>a>>b>>c;
    if(a > d || b-a < c) continue;
    v[b].push_back(make_pair(a,c)); //(출발지, 비용)
  }


  map[0] = 0;

  for(int i=1; i<=d; i++){
    map[i] = map[i-1] + 1;
    for(int j=0; j< v[i].size(); j++){
      map[i] = min(map[i], map[v[i][j].first] + v[i][j].second);
    
    }

  }

  cout<<map[d];


  


}