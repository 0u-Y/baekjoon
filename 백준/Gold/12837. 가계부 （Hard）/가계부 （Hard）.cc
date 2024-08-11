#include <iostream>
#include <vector>

using namespace std;



typedef long long ll;


int N,Q;




vector<ll> a;
vector<ll> tree;



void update(int node, int index, ll diff, int start, int end){
    if(index < start || index > end){
        return;
    }

    tree[node] += diff;
    
    if(start != end){
        int mid = (start + end)/2;

        update(node*2, index, diff, start, mid);
        update(node*2+1, index, diff, mid + 1, end);
    }

}



long long query(int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return 0;
    }
    if(start >= left && right >= end){
        return tree[node];
    }

    int mid = (start + end)/2;

    ll left_sum = query(node*2, start ,mid, left, right);
    ll right_sum = query(node*2+1, mid + 1, end, left, right);



    return left_sum + right_sum;
}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>Q;


    a.resize(N + 1, 0);
    tree.resize(4 * N, 0);

    

    while(Q--){
        int type;
        cin>>type;
        if(type == 1){
            int p;
            ll x;
            cin>>p>>x;
            ll diff = x;
            a[p] += diff;
            update(1, p, diff, 1, N);
        }
        else if(type == 2){
            int p,q;
            cin>>p>>q;
            cout<<query(1, 1, N, p, q)<<'\n';

        }
    }

}