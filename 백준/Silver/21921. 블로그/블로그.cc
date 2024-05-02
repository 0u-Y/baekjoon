#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n);

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    if (m > n) {
        cout << "SAD";
        return 0;
    }

    int current_sum = 0, max_sum = 0, count = 0;

    for (int i = 0; i < m; i++) {
        current_sum += num[i];
    }
    max_sum = current_sum;
    count = 1; 

    for (int i = m; i < n; i++) {
        current_sum += num[i] - num[i - m];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            count = 1;
        } else if (current_sum == max_sum) {
            count++;
        }
    }

    if (max_sum == 0) {
        cout << "SAD";
    } else {
        cout << max_sum << "\n" << count;
    }

}
