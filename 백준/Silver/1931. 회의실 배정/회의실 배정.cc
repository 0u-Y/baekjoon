#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int start;

int cnt = 1;


vector<pair<int, int> > v;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;


    for(int i=0; i<n; i++){

        int a,b;

        cin>>a>>b;
        v.push_back(make_pair(b,a));

        
    }
    

    sort(v.begin(), v.end());


    start = v[0].first;



    for(int i=1; i<n; i++){
        if(v[i].second >= start){
            start = v[i].first;
            cnt++;
        }
    }


    cout<<cnt;











}