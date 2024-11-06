#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int psum[1000001] = {0};


    for(int i=0; i<n; i++) {
        int s,e;
        cin>>s>>e;
        psum[s] += 1;
        psum[e+1] -= 1;
    }

    psum[0] = 0;

    for(int i=1; i<=1000000; i++) {
        psum[i] += psum[i-1];
    }

    int q;
    cin>>q;

    for(int i=0; i<q; i++) {
        int t;
        cin>>t;

        cout<<psum[t]<<'\n';
    }

}