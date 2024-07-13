#include <iostream>
#include <algorithm>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;

    long long arr[2001];

    if(n == 2){
        cout<<0;
        return 0;
    }

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    sort(arr + 1, arr + n + 1);
    
    int cnt = 0;





    for(int i=1; i<=n; i++){
        int st = 1;
        int en = n;
        

        while(st < en){
            if(st == i){
                st++;
                continue;
            }
            if(en == i){
                en--;
                continue;
            }
            long long tmp = arr[st] + arr[en];

            if(tmp == arr[i]){
                cnt++;
                break;
            }

            if(tmp < arr[i]) st++;
            else en--;
        }


    }



    cout<<cnt;


}