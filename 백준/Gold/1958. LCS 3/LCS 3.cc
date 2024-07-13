#include <iostream>
#include <cstring>


using namespace std;



int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int dp[101][101][101];


	string a,b,c;

	cin>>a;
	cin>>b;
	cin>>c;

	int size_a = a.length();
	int size_b = b.length();
	int size_c = c.length();


	memset(dp, 0, sizeof(dp));
	int ans = 0;
	



	for(int i=1; i<=size_a; i++){
		for(int j=1; j<=size_b; j++){
			for(int k=1; k<=size_c; k++){
				if(a[i-1] == b[j-1] && b[j-1] == c[k-1]){
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else{
					dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
				}
			}
		}
	}

	cout<<dp[size_a][size_b][size_c];





}