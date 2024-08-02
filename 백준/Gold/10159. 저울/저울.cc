#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;


    bool d[101][101];

    for(int i=1; i<=n; i++){
        fill(d[i], d[i] + n + 1, false);
    }



    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a][b] = true; 
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] && d[k][j]) {
                    d[i][j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && !d[i][j] && !d[j][i]) {
                count++;
            }
        }
        cout << count << '\n';
    }


}
