#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n,h;
  cin>>n>>h;

  int cave[500001] = {0};

  for(int i=1; i<=n; i++) {
    int a;
    cin>>a;
    if(i % 2 == 1) {
      cave[1] ++;
      if(a + 1 <= h) cave[a + 1] --;
    }
    else {
        cave[h - a + 1] ++;
    }
  }

  for(int i=2; i<=h; i++) {
    cave[i] += cave[i-1];
  }


  int res = 1;

  int min_obstacle = cave[1];

  for(int j=2; j<=h; j++) {
    if(cave[j] < min_obstacle) {
      min_obstacle = cave[j];
      res = 1;
    }
    else if(cave[j] == min_obstacle) {
      res++;
    }
  }


  cout << min_obstacle << " " << res;
}


