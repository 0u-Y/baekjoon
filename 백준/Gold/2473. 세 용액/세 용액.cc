#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;



ll arr[5001];

int result_st, result_mid, result_en;


int main(){

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }


    sort(arr + 1, arr + n + 1);

    ll result = LLONG_MAX;

    



    for(int i=1; i<=n-2; i++){
        int mid = i + 1;
        int en = n;
        while(mid < en){
            ll tmp = arr[i] + arr[mid] + arr[en];
            if(abs(tmp) < result){
                result = abs(tmp);
                result_st = i;
                result_mid = mid;
                result_en = en;
            }
            if(tmp > 0) en--;
            else mid++;
        }
    }

    cout<<arr[result_st]<<" "<<arr[result_mid]<<" "<<arr[result_en];


}