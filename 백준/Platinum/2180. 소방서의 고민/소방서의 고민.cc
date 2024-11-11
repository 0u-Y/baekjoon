#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
const int mod = 40000;


bool compare(pair<int,int> m, pair<int,int> n) {
    if(m.first == 0) return false;
    else if(n.first == 0) return true;
    else if(m.second == 0 && n.second == 0) return m.first < n.first;
    ull result_m = m.second * n.first;
    ull result_n = m.first * n.second;
    return result_m < result_n;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int,int> > v;

    for(int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end(), compare);

    ull result = 0;

    for(int i=0; i<v.size(); i++) {
        pair<int,int> cur = v[i];
        result = result + (result * cur.first % mod + cur.second % mod) % mod;
    }



    cout<<result % mod;



	
    



}

