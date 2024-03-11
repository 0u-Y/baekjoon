#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};


int w,h;
int map[51][51];
bool vis[51][51];

queue<pair<int,int> > Q;

void dfs(int a, int b){
    Q.push({a,b});
    vis[a][b] = 1;
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<8; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx >= h || nx < 0 || ny >= w || ny < 0) continue;
            if(vis[nx][ny] == 0 && map[nx][ny] == 1){
                dfs(nx,ny);
            }
        }
    }


}


int main(){

    while(true){
        cin>>w>>h;
        if(w==0 && h==0){
            break;
        }
        int cnt = 0;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>map[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(vis[i][j] == 0 && map[i][j] == 1){
                    dfs(i,j);
                    cnt++;
                }

            }
        }
        cout<<cnt<<'\n';
        for(int i=0; i<h; i++){
            fill(vis[i], vis[i] + w, 0);
            fill(map[i], map[i] + w, 0);
        }
        





    }





}
