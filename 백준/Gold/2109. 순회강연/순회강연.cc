#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int p,d;

vector<pair<int, int> > v;

priority_queue<int, vector<int>, greater<int> > pq;

int cnt;


int main(){
    cin>>n;

    
    for(int i=0; i<n; i++){
        cin>>p>>d;
        v.push_back(make_pair(d,p));
    }

    sort(v.begin(), v.end());


    for(int i=0; i<n; i++){
        pq.push(v[i].second);
        cnt+= v[i].second;
        if(pq.size() > v[i].first){
            cnt-=pq.top();
            pq.pop();

        }

    }

    cout<<cnt;



}