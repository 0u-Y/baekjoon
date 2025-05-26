#include <iostream>
using namespace std;

#define MAX_K 20
#define MAX_M 200000

int num[MAX_M + 1];
int table[MAX_K + 1][MAX_M + 1];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;

    cin>>m;

    for(int i=1; i<=m; i++) {
        cin>>num[i];
        table[0][i] = num[i];
    }



    for(int i=1; i<=MAX_K; i++) {
        for(int j=1; j<=m; j++) {
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }

    int Q;
    cin>>Q;

    while(Q--) {
        int n,x;
        cin>>n>>x;

        for(int k=MAX_K; k>=0; k--) {
            if(n & (1<<k)) {
                x = table[k][x];
            }
        }
        cout<<x<<'\n';
    }
}