#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[10001];
int glass[10001];

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> glass[i];
    }

    dp[0] = glass[0] = 0;
    dp[1] = glass[1];
    if (n >= 2) {
        dp[2] = glass[1] + glass[2];
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = max({dp[i - 3] + glass[i - 1] + glass[i], dp[i - 2] + glass[i], dp[i - 1]});
    }

    cout << dp[n];

    return 0;
}
