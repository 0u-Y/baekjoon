#include <iostream>
#include <set>

using namespace std;




int main(){
    int t;
    cin>>t;



    for(int i=0; i<t; i++){
        multiset<int> mul;
        int k;
        cin>>k;
        
        for(int j=0; j<k; j++){
            char c;
            cin>>c;
            if(c == 'D'){
                int n;
                cin>>n;
                if(mul.empty()) continue;
                if(n == 1) mul.erase(prev(mul.end()));
                else{
                    mul.erase(mul.begin());
                }
            }
            else{
                int m;
                cin>>m;
                mul.insert(m);
            }
        }
        if(mul.empty()) cout<<"EMPTY"<<'\n';
        else{
            cout<< *prev(mul.end()) <<" " <<*mul.begin() << '\n';
        }
    }


}