#include <iostream>
#include <queue>

#define X first
#define Y second


using namespace std;


int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int map[301][301];
int temp[301][301];

bool vis[301][301];

queue<pair<int,int> > Q;

int n,m;





void bfs(int x, int y){



    Q.push(make_pair(x,y));
    vis[x][y] = true;

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;

            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(map[nx][ny] != 0 && vis[nx][ny] == false){
                vis[nx][ny] = true;
                Q.push(make_pair(nx,ny));
            }
        }


    }


}




void melt(int x, int y){

    int cnt = 0;


    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(map[nx][ny] == 0) cnt++;
    }


    if(map[x][y] <= cnt) temp[x][y] = 0;
    else temp[x][y] = (map[x][y] - cnt);

}






int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin>>n>>m;


    int year = 0;








    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>map[i][j];
        }
    }




    while(true){


        int land = 0;

        for(int i=1; i<=n; i++){
            fill(vis[i], vis[i] + m + 1, 0);
            fill(temp[i], temp[i] + m + 1, 0);
        }



        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j] != 0 && vis[i][j] == false){
                    land++;
                    bfs(i,j);
                }
            }
        }



        if(land >= 2){
            cout<<year;
            return 0;
        }
        else if(land == 0){
            cout<<0;
            return 0;
        }



        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(map[i][j] != 0){
                    melt(i,j);
                }

            }
        }



        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                map[i][j] = temp[i][j];
            }
        }



        year++;
        
        


    }



    

}