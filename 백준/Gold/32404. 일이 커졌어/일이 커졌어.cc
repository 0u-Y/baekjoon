#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<long long> res(n+1);

    int cur = n;

    for(int i=n; i>=1; i--) {
        if(i%2 == 1) {
            res[i] = cur--;
        }
    }

    for(int i=1; i<=n; i++) {
        if(i%2 == 0) {
            res[i] = cur--;
        }
    }

    for(int i=1; i<=n; i++) {
        if(i == n) cout<<res[i];
        else {
            cout<<res[i]<<" ";
        }
    }
}