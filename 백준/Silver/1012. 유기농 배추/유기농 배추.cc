#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int m,n,k,t;
int x,y;

bool vis[51][51] = {false};
int farm[51][51] = {0};

queue<pair<int,int> > Q;



void bfs(int a, int b){
    vis[a][b] = 1;
    Q.push({a,b});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if(vis[nx][ny] ==1 || farm[nx][ny] == 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}



int main(){
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>m>>n>>k;
        int cnt = 0;
        for(int j=0; j<k; j++){
            cin>>x>>y;
            farm[y][x] = 1;
        }


        for(int j=0; j<n; j++){
            for(int k=0; k<m; k++){
                if(farm[j][k] == 1 && vis[j][k] == 0){
                    bfs(j,k);
                    cnt++;
                }
            }
        }

        for(int j=0; j<n; j++){
            fill(vis[j], vis[j] + m, 0);
            fill(farm[j], farm[j] + m, false);
        }
        cout<<cnt<<'\n';
    }


}