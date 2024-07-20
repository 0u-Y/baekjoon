#include <iostream>

using namespace std;



bool isPalindrome(string a, int left, int right){
    while(left < right){
        if(a[left] != a[right]){
            return false;
        }
        left++;
        right--;
    }

    return true;
}


int main(){

    int t;
    cin>>t;


    for(int i=0; i<t; i++){
        string a = "";
        cin>>a;

        int st = 0;
        int en = a.length() - 1;


        bool palindrome = true;
        bool nearPalindrome = false;



        while(st < en){
            if(a[st] != a[en]){
                palindrome = false;
                if(isPalindrome(a, st + 1, en) || isPalindrome(a, st, en - 1)){
                    nearPalindrome = true;
                }
                break;
            }

            st++;
            en--;
        }

        if(nearPalindrome){
            cout<<1<<'\n';
        }
        else if(palindrome){
            cout<<0<<'\n';
        }
        else{
            cout<<2<<'\n';
        }

        


    }
}