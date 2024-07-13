#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;


int main(){

    int n;
    cin>>n;

    long long arr[100001];

    

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    sort(arr, arr + n);

    int st = 0;
    int en = n - 1;

    int result = INT_MAX;

    int result_st, result_en;

    while(st < en){
        long long tmp = arr[st] + arr[en];

        if(abs(tmp) < result){
            result_st = st;
            result_en = en;
            result = abs(tmp);
        }

        if(tmp > 0) en--;
        else st++;
    }


    cout<<arr[result_st]<<" "<<arr[result_en];

}