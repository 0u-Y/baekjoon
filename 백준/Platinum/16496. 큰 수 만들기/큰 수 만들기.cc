#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(string a, string b) {
    string m = a + b;
    string n = b + a;
    return m > n;
}

int main() {

    int n;
    cin>>n;

    vector<string> v;


    int cnt = 0;

    for(int i=0; i<n; i++) {
        string num;
        cin>>num;
        if(num == "0") cnt++;
        v.push_back(num);
    }

    if(cnt == n) {
        cout<<0;
        return 0;
    }

    sort(v.begin(), v.end(), compare);
    

    string res = "";

    for(int i=0; i<n; i++) {
        res += v[i];
    }

    cout<<res;




}