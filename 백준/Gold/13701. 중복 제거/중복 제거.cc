#include <iostream>
#include <bitset>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    bitset<1<<25> set;



    while(!cin.eof()) {
        int x;
        cin>>x;
        if(set[x] == 0) {
            set[x] = 1;
            cout<<x<<" ";
        }
    }


}