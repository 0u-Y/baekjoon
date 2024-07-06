#include <iostream>
#include <queue>
#include <climits>
#define X first
#define Y second



using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int map[51][51];
int cnt[51][51];







int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    char a;



    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a;
            map[i][j] = a - '0';
        }
    }


    for(int i=1; i<=n; i++){
        fill(cnt[i], cnt[i] + n + 1, INT16_MAX);
    }

    cnt[1][1] = 0;




    queue<pair<int,int> > Q;

    Q.push(make_pair(1,1));

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();

        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            

            if(nx <= 0 || nx > n || ny <= 0 || ny > n) continue;

            if(map[nx][ny] == 1){
                if(cnt[nx][ny] > cnt[cur.X][cur.Y]){
                    cnt[nx][ny] = cnt[cur.X][cur.Y];
                    Q.push(make_pair(nx,ny));
                }
            }
            else{
                if(cnt[nx][ny] > cnt[cur.X][cur.Y] + 1){
                    cnt[nx][ny] = cnt[cur.X][cur.Y] + 1;
                    Q.push(make_pair(nx,ny));

                }
            }

        }

    }



    cout<<cnt[n][n];






}