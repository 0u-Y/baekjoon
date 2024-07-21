#include <iostream>
#include <string>

using namespace std;




int main(){
    
    int n;
    cin>>n;


    string str = "";
    string ans = "";

    for(int i=0; i<n; i++){
        char c;
        cin>>c;
        str+=c;
    }

    int st = 0;
    int en = n - 1;


    while(st <= en){
        if(str[st] > str[en]){
            ans+=str[en];
            str.erase(en, 1);
            en--;
        }
        else if(str[st] < str[en]){
            ans+=str[st];
            str.erase(st, 1);
            en--;
        }
        else{
            int left = st;
            int right = en;
            bool select_left = false;
            while(left < right){
                if(str[left] != str[right]){
                    select_left = (str[left] < str[right]);
                    break;
                }
                left++;
                right--;
            }
            if(select_left){
                ans += str[st];
                str.erase(st, 1);
                en--;
            }
            else{
                ans += str[en];
                str.erase(en, 1);
                en--;
            }
        }
    }

    if(st == en){
        ans += str[st];
    }

    
    
    
    for(int i=0; i<n; i++){
        if(i % 80 == 0 && i != 0){
            cout<<'\n';
        }
        cout<<ans[i];
    }







}