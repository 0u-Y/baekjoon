#include <iostream>
#include <queue>
#define X first
#define Y second


using namespace std;

char board[101][101];
int dist[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

int main(){
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        fill(dist[i], dist[i] + m, -1);
    }
    queue<pair<int,int> > Q;

    Q.push({0,0});
    dist[0][0] = 0;

    while(!Q.empty()){
        pair<int,int> cur;
        cur = Q.front();
        Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
            if(board[nx][ny] != '1' || dist[nx][ny] >= 0) continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    cout<<dist[n-1][m-1] + 1;

}