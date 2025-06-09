#include <iostream>
#include <queue>

using namespace std;


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int> > Q;

char map[51][51];
int visited[51][51];

int r,c;

void bfs(int x, int y) {
    visited[x][y] = 1;

    while(!Q.empty()) {
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[cur_x][cur_y] == 'S' && (map[nx][ny] == '.' || map[nx][ny] == 'D')) {
                visited[nx][ny] = visited[cur_x][cur_y] + 1;
                map[nx][ny] = 'S';
                Q.push(make_pair(nx, ny));
            }

            if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[cur_x][cur_y] == '*' && (map[nx][ny] == '.' || map[nx][ny] == 'S')) {
                map[nx][ny] = '*';
                Q.push(make_pair(nx, ny));
            }
        }
    }
}






int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>r>>c;

    int start_x, start_y;
    int end_x, end_y;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin>>map[i][j];

            if(map[i][j] == 'S') {
                start_x = i;
                start_y = j;
                Q.push(make_pair(i,j));
            }
            if(map[i][j] == 'D') {
                end_x = i;
                end_y = j;
            }
        }
    }

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(map[i][j] == '*') {
                Q.push(make_pair(i, j));
            }
        }
    }

    bfs(start_x, start_y);


    if(visited[end_x][end_y] == 0) {
        cout<<"KAKTUS"<<endl;
    }
    else {
        cout<<visited[end_x][end_y]-1<<'\n';
    }
    





}