#include <iostream>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,m;

    cin>>n>>m;


    long long count[m+1] = {0};


    long long prefix = 0;
    long long ans = 0;



    for(int i=0; i<n; i++) {
        int num;
        cin>>num;
        prefix += num;
        count[prefix % m]++;

        if(prefix % m == 0) ans++;

    }



    for(int i=0; i<m; i++) {
        ans += count[i] * (count[i] - 1) / 2;
    }

    cout<<ans;





}