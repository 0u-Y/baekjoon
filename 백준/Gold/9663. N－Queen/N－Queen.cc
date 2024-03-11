#include <iostream>
#include <algorithm>

using namespace std;



bool isput[30]; // column 확인
bool isput2[30]; // \ 모양 대각선 확인
bool isput3[30]; // / 모양 대각선 확인

int  cnt = 0;


int n;



void func(int a){
    if(a == n){
        cnt++;
        return;
    }


    for(int i=0; i<n; i++){
        if(isput[i] || isput2[i + a] || isput3[a + n - i - 1]) continue;
        
        isput[i] = 1;
        isput2[i + a] = 1;
        isput3[a + n - 1 - i] = 1;
        func(a + 1);
        isput[i] = 0;
        isput2[i + a] = 0;
        isput3[a + n - 1 - i] = 0;

    }
}







int main() {
    cin>>n;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    func(0);

    cout<<cnt;



}
