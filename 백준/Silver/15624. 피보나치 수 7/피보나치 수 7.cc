#include <iostream>

using namespace std;

int n;

int dp[1000001];

int main(){
	cin>>n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	

	for(int i=3; i<=n; i++){
		dp[n] = dp[n-1] + dp[n-2];
		
	}

	cout<<dp[n] % 1000000007;


}