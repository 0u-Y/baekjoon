#include <iostream>
#include <algorithm>


using namespace std;


const int INF = 1e9;

int d[102][102];


int n,m;

int a,b,c;





int main(){
    cin>>n;
    cin>>m;


    for(int i=1; i<=n; i++){
        fill(d[i], d[i] + n + 1, INF);
    }
    while(m--){
        cin>>a>>b>>c;
        d[a][b] = min(d[a][b], c);
    }

    for(int i=1; i<=n; i++){
        d[i][i] = 0;
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] == INF){
                cout<<"0 ";
            }
            else{
                cout<<d[i][j]<<" ";
            }
        }
        cout<<'\n';
    }








}