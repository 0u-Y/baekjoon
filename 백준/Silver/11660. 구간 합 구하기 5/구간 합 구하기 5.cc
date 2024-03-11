#include <iostream>
using namespace std;



int n, m;
int psum[1025][1025];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            cin >> num;
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + num;
        }
    }

    for (int k = 0; k < m; k++) {
        int x, y, x2, y2;
        cin >> x >> y >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y - 1] - psum[x - 1][y2] + psum[x - 1][y - 1] << '\n';
    }
    return 0;
}
