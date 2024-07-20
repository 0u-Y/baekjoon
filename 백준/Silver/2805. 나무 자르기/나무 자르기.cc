#include <iostream>

using namespace std;

int main(){
    int n,m;

    cin>>n>>m;


    int tree[1000001];




    int start = 1;
    int end = 0;

    int result = 0;

    for(int i=1; i<=n; i++){
        cin>>tree[i];
        end = max(end, tree[i]);
    }


    while(start <= end){
        int mid = (start + end)/2;

        long long cnt = 0;

        for(int i=1; i<=n; i++){
            if(tree[i] > mid) cnt += (tree[i] - mid);
        }

        if(cnt >= m){
            result = mid;
            start = mid + 1;           
        }
        else{
            end = mid - 1;
        }
    }

    cout<<result;


}