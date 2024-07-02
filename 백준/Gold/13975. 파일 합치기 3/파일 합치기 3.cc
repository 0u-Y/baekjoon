#include <iostream>
#include <queue>

using namespace std;


typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;


    while(t--){
        int k;
        cin>>k;
        ll cnt = 0;

        priority_queue<ll, vector<ll>, greater<ll> > pq;

        for(int i=0; i<k; i++){
            ll num;
            cin>>num;
            pq.push(num);
        }


        while(pq.size() > 1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            cnt += (a+b);
            pq.push(a+b);
        }


        cout<<cnt<<'\n';


    }

}