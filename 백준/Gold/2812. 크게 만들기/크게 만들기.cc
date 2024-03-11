#include <iostream>
#include <vector>

using namespace std;

int n,k;

string a;




int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;

    cin>>a;
    


    vector<char> num;

    int idx = 0;
    int min = -1;


    for(int i=0; i<n; i++){
        while(k > 0 && !num.empty() && num.back() < a[i]){
            num.pop_back();
            k--;
        }
        num.push_back(a[i]);
    }

    while(k--){
        num.pop_back();
    }
    
    
    
    for(int i=0; i<num.size(); i++){
        cout<<num[i];
    }

}