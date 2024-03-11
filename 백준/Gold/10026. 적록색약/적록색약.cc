#include <iostream>

using namespace std;




char map[101][101];
bool vis[101][101] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int n;


void dfs(int a, int b){
    vis[a][b] = 1;
    for(int i=0; i<4; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];
        if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
        if(vis[nx][ny] == 0 && (map[nx][ny] == map[a][b])){
            dfs(nx,ny);
        }
    }
}



int main(){
    cin>>n;
    int a=0, b=0;



    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] == 0){
                dfs(i,j);
                a++;
            }
        }
    }

    for(int i=0; i<n; i++){
        fill(vis[i], vis[i] + n, 0);
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 'R'){
                map[i][j] = 'G';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] == 0){
                dfs(i,j);
                b++;
            
            }
        }
    }


    cout<<a<<" "<<b;





}