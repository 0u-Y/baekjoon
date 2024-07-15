#include <iostream>

using namespace std;


int main(){
    int n,m;
    cin>>n>>m;



    int a = 1000;
    int b = 1000;

    for(int i=1; i<=m; i++){
        int set, each;
        cin>>set>>each;
        
        a = min(a, min(set, each * 6)); //6개씩
        b = min(b, each); //낱개로
    }


    int mul = n / a;





    cout<<min((n/6 + 1) * a, min((n/6) * a + n%6*b, n * b));

}