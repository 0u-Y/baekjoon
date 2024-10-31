#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm> 

using namespace std;



vector<int> p(1002, -1);

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
  u = find(u);
  v = find(v);
  if(u == v) return 0;
  if(p[u] == p[v]) p[u]--;
  if(p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;

  vector<tuple<int, int, int> >edge;

  int edge_cnt = 0;

  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      int cost;
      cin>>cost;
      if(i == j) continue;
      edge.push_back(make_tuple(cost, i, j));
      edge_cnt++;
    }
  }

  sort(edge.begin(), edge.end());

  int cnt = 0;
  long long ans = 0;

  for(int i=0; i<edge_cnt; i++) {
    int a, b, cost;
    tie(cost, a, b) = edge[i];
    if(!is_diff_group(a,b)) continue;
    ans += cost;
    cnt++;
    if(cnt == n-1) break;
  }

  cout<<ans;
  
}