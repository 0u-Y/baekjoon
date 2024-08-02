#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


int main(){

    int d[101][101];
    int val[101];

    const int INF = INT_MAX;




    int n,m,r;

    cin>>n>>m>>r;

    for(int i=1; i<=n; i++){
        cin>>val[i];
    }


    for(int i=1; i<=n; i++){
        fill(d[i], d[i] + n + 1, INF);
    }


    for(int i=0; i<r; i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b] = min(d[a][b], c);
        d[b][a] = min(d[b][a], c);
    }

    for(int i=1; i<=n; i++){
        d[i][i] = 0;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][k] < INF && d[k][j] < INF){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    int ans = 0;

    for(int i=1; i<=n; i++){
        int cnt = val[i];
        for(int j=1; j<=n; j++){
            if(i != j && d[i][j] <= m){
                cnt += val[j];
            }
        }

        ans = max(cnt, ans);

    }

    cout<<ans;

}