#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pair<int, int> loc_ani[100001];

    int m, n, l;
    cin >> m >> n >> l;

    int cnt = 0;

    int loc[100001];

    for (int i = 1; i <= m; i++) {
        cin >> loc[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> loc_ani[i].first >> loc_ani[i].second;
    }

    sort(loc + 1, loc + m + 1);
    sort(loc_ani + 1, loc_ani + n + 1);

    int j = 1;

    for (int i = 1; i <= m; i++) {
        while (j <= n && (i == m || abs(loc[i] - loc_ani[j].first) <= abs(loc[i + 1] - loc_ani[j].first))) {
            if (abs(loc[i] - loc_ani[j].first) + loc_ani[j].second <= l) {
                cnt++;
            }
            j++;
        }
    }

    cout << cnt;
    
}
