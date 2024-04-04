#include <iostream>

using namespace std;

int main() {
    int n;

    int max_num_idx;

    int arr[100001];

    cin>>n;

    if(n == 1){
        int num;
        cin>>num;
        cout<<num;
        return 0;
        
    }

    int max_num = 0;
    long sum = 0;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        sum += num; // 8
        max_num = max(num,max_num); //4
    }

    if((sum - max_num) > max_num){
        cout<<(sum&1);
    }
    else{
        cout<<max_num - (sum - max_num);

    }





    
    


}
