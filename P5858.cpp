#include <bits/stdc++.h>
using namespace std;
int N,W,S;
long long a[5005];
long long dp[5005][5005];
long long q[5005];
long long pos[5005];
int main()
{
	cin >> N >> W >> S;
	for(int i = 1;i <= N;i ++)
	{
		cin >> a[i];
	}
	memset(dp,0xaf,sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1;i <= N;i ++)
	{
		int l = 1,r = 1;
		q[l] = dp[i - 1][W];
		pos[l] = W;
		for(int j = W;j >= 1;j --)
		{
			int R = S + j - 1; 
			while(pos[l] > R && l <= r) l ++;
			while(q[r] < dp[i - 1][j - 1] && l <= r) r --;//Keep it 
			pos[++ r] = j - 1;
			q[r] = dp[i - 1][j - 1];//Push
			dp[i][j] = q[l] + a[i] * j;
		}
	}
	long long ans = -0x7fffffff;
	for(int i = 1;i <= W;i ++)
	{
		ans = max(ans,dp[N][i]);
	}
	cout << ans;
	return 0;
}
