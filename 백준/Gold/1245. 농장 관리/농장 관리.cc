#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int n,m;
int farm[101][71];
bool vis[101][71];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,0,-1,1};
int cnt = 0;

bool isHigh = true;

void dfs(int a, int b){
    vis[a][b] = 1;
    for(int i=0; i<8; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
        if(farm[a][b] < farm[nx][ny]) isHigh = false;
        if(!vis[nx][ny] && farm[nx][ny] == farm[a][b]){
            vis[nx][ny] = 1;
            dfs(nx,ny);
        }
    }
}




int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>farm[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j]){
                isHigh = true;
                dfs(i,j);
                if(isHigh){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
}
