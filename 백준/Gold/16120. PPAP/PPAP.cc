#include <iostream>
#include <stack>

using namespace std;




int main(){
    string str = "";
    cin>>str;




    stack<char> st;


    for(int i=0; i<str.length(); i++){
        if(str[i] == 'P'){
            st.push(str[i]);

        }
        else if(str[i] == 'A'){
            if(st.size() >= 2 && str[i+1] == 'P' && i + 1 < str.length()){
                st.pop();
                st.pop();
            }
            else{
                cout<<"NP";
                return 0;
            }
        }
    }


    if(st.size() == 1 && st.top() == 'P'){
        cout<<"PPAP";
    }
    else{
        cout<<"NP";
    }

}