#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int cnt = 2000000001;
    int num;
    cin>>n>>m;
    int nums[n];

    for(int i=0; i<n; i++){
        cin>>num;
        nums[i] = num;
    }
    sort(nums,nums+n);

    int ed = 0;

    for(int st = 0; st<n; st++){
        while(ed<n && nums[ed] - nums[st] < m) ed++;
        if(ed == n) break;
        cnt = min(nums[ed] - nums[st], cnt);
    }
    cout<<cnt;
}