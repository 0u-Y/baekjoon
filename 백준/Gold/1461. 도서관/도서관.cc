#include <iostream>
#include <algorithm>

using namespace std;




int main(){


    int n,m;
    cin>>n>>m;

    int sum = 0;
    int cnt = 0;

    int book[10001];


    for(int i=0; i<n; i++){
        cin>>book[i];
        if(book[i] < 0){
            cnt ++;
        }
    }

    sort(book, book + n);


    for(int i=0; i<cnt; i+=m){
        sum += abs(book[i] * 2);
    }

    for(int i=n-1; i>=cnt; i-=m){
        sum += book[i] * 2;
    }


    sum -= max(abs(book[0]), abs(book[n-1]));


    cout<<sum;

    
    




    

}