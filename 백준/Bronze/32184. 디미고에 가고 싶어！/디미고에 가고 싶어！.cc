#include <iostream>

using namespace std;


int main() {
    int a,b;
    cin>>a>>b;


    int temp = b - a;

    if((a % 2 == 0) && (b % 2 != 0)){
        cout<<(temp / 2) + 2;
    }
    else {
        cout<<(temp / 2) + 1;
    }
}