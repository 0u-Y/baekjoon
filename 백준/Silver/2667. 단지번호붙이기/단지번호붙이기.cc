#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#define X first
#define Y second


using namespace std;

int n;
char map[26][26];
bool vis[26][26] = {0};
queue<pair<int,int> > Q;
vector<int> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int width;
int cnt = 0;

void bfs(int a, int b){
    vis[a][b] = 1;
    width = 1;
    Q.push({a,b});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(map[nx][ny] == '0' || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
            width++;
        }
    }

}


int main(){
    cin>>n;
    char c;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>c;
            map[i][j] = c;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == '1' && vis[i][j] == 0){
                bfs(i,j);
                cnt++;
                v.push_back(width);

            }
        }
    }

    sort(v.begin(), v.end());

    cout<<cnt<<'\n';

    for(int i=0; i< v.size(); i++){
        cout<<v[i]<<'\n';
    }


    



}