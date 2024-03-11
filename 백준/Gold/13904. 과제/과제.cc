#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int n;

vector<pair<int,int> > v;

priority_queue<int, vector<int> , greater<int> > pq;

int main(){

    cin>>n;
    int cnt = 0;

    for(int i = 0; i<n; i++){
        int d,w;
        cin>>d>>w;

        v.push_back(make_pair(d,w));
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