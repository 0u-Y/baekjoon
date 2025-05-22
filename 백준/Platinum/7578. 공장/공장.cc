#include <iostream>
#define ll long long

using namespace std;

int A[500001] = {0};
int B[1000001] = {0};
ll tree[2000004] = {0};


ll calculate(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end)/2;
    return calculate(node*2, start, mid, left, right) + calculate(node*2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int index) {
    if (index < start || end < index) {
        return;
    }

    if(start == end) {
        tree[node] = 1;
        return;
    }

    int mid = (start + end)/2;

    update(node*2, start, mid, index);
    update(node*2 + 1, mid + 1, end, index);
    
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll res = 0;
    cin>>n;

    for (int i=1; i<=n; i++) {
        cin>>A[i];
    }
    for (int i=1; i<=n; i++) {
        int num;
        cin>>num;
        B[num]= i;
    }

    for (int i=1; i<=n; i++) {
        res += calculate(1, 1, n, B[A[i]] + 1, n);
        update(1, 1, n, B[A[i]]);


    }

    cout<<res;




}
