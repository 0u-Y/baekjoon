#include <iostream>
#include <algorithm>


using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[1001];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int length[1001];

    for(int i=0; i<n; i++){
        length[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i]){
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }
    int max = *max_element(length, length + n);
    cout<<max<<'\n';



}