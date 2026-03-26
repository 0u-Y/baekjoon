#include <iostream>
#include <vector>
using namespace std;

int table[30][100005];
int starts[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, M;

    cin>>N>>K>>M;

    for (int i=0; i<N; i++) {
        cin>>starts[i];
    }

    for (int i=1; i<=K; i++) {
        cin>>table[0][i];
    }

    for (int i=1; i<30; i++) {
        for (int j=1; j<=K; j++) {
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }

    int move = M-1;

    for (int i=0; i<N; i++) {
        int curr = starts[i];

        for (int j = 0; j<30; j++) {
            if (move & ( 1<<j )) {
                curr = table[j][curr];
            }
        }

        cout <<curr<<" ";
    }

}