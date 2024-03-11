#include <iostream>
#include <algorithm>


using namespace std;


int n;

int main(){
    cin>>n;

    int arr[10] = {0};

    while(true){
        arr[n%10] ++;
        if(n/10 == 0){
            break;
        }
        n/=10;
    }

    int num = 0;

    for(int i=0; i<10; i++){
        if(i != 6 && i != 9){
            num = max(num, arr[i]);
        }
    }

    num = max(num, (arr[6] + arr[9] + 1)/2);

    cout<<num;





}


