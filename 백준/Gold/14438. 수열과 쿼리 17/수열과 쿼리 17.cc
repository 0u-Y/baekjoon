#include <iostream>
#include <vector>
#include <climits>


using namespace std;

typedef long long ll;


vector<ll> v(100001);
vector<ll> tree_min(400004);



ll init(int node, int start, int end){
    if(start == end) return tree_min[node] = v[start];
    else{
        int mid = (start + end)/2;

        return tree_min[node] = min(init(node*2, start, mid), init(node*2+1, mid + 1, end));  
    }
}


void update(int node, int start, int end, int index, ll value){
    if(index < start || index > end) return;
    
    if(start == end){
        tree_min[node] = value;
        v[index] = value;
    }
    else{
        int mid = (start + end)/2;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid + 1, end, index, value);

        tree_min[node] = min(tree_min[node*2], tree_min[node*2+1]);
    }
}



ll min_num(int node, int start, int end, int left, int right){
    if(left > end || right < start) return LLONG_MAX;
    if(left <= start && end <= right) return tree_min[node];
    else{
        int mid = (start + end)/2;
        ll left_min = min_num(node*2, start, mid, left, right);
        ll right_min = min_num(node*2+1, mid + 1, end, left, right);
        return min(left_min,right_min);

    }
}








int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>v[i];
    }

    init(1,1,n);

    int m;

    cin>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a;
        if(a == 1){
            cin>>b>>c;
            update(1,1,n,b,c);
        }
        else if(a == 2){
            cin>>b>>c;
            cout<<min_num(1,1,n,b,c)<<'\n';
        }
    }


}