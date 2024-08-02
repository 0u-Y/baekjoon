#include <iostream>
#include <climits>
#include <algorithm>



using namespace std;


int main(){
    int n,m;
    cin>>n>>m;


    int d[201][201];
    int num[201][201];

    const int INF = INT_MAX;

    for(int i=1; i<=n; i++){
        fill(d[i], d[i] + n + 1, INF);
        fill(num[i], num[i] + n + 1, 0);
        d[i][i] = 0;
    }





    for(int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(d[a][b] > c){
            d[a][b] = c;
            d[b][a] = c;
            num[a][b] = b;
            num[b][a] = a;

        }

    }




    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    num[i][j] = num[i][k];
                    num[j][i] = num[j][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j){
                cout<<"- ";
            }
            else{
                cout<<num[i][j]<<" ";
            }
        }
        cout<<'\n';
        
    }








}