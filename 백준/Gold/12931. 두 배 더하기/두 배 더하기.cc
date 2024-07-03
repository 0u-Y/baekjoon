#include <iostream>
#include <algorithm>
using namespace std;




int main(){
    int mul[51];
    int add[51];





    int n;
    cin >> n;

    fill(mul, mul + n, 0);
    fill(add, add + n, 0);








    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num != 0){
            while(num > 0){
                if(num % 2 != 0) {
                    add[i]++;
                    num--;  
                } else {
                    num /= 2;
                    mul[i]++;
                }
            }
        }
    }

    int mul_cnt = 0;



    for(int i = 0; i < n; i++){
        mul_cnt = max(mul_cnt, mul[i]);

    }


    int ans = mul_cnt;

    for(int i = 0; i < n; i++){
        ans += add[i];
    }



    cout << ans << endl;





}
