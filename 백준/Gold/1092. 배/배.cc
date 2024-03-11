#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

vector<int> crain;
vector<int> box;

int cnt = 0;

int a;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a;
        crain.push_back(a);
        
    }

    cin>>m;


    for(int i=0; i<m; i++){
        int b;
        cin>>b;
        box.push_back(b);
    }

    sort(crain.rbegin(), crain.rend());
    sort(box.rbegin(), box.rend());


    if(box[0] > crain[0]){
        cout<<-1;
        return 0;
    }


    while(!box.empty()){
        cnt++;
        for(int i=0; i<crain.size(); i++){
            for(int j=0; j<box.size(); j++){
                if(crain[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }

    cout<<cnt;







}