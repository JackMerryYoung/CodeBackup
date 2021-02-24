#include <bits/stdc++.h>
using namespace std;
int N,M;
long long l[10005],r[10005];
int dp[10005][10005];
int main()
{
	cin >> N >> M;
	if(N < M)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= N;i ++)
	{
		scanf("%i %i",&l[i],&r[i]);
	}
	for(int i = 1;i <= N;i ++)
	{
		dp[i][0] = i;//No plant and i zombies can get in
	}
	for(int i = 1;i <= N;i ++)
	{
		for(int j = 1;j <= M;j ++)
		{
			if(r[i - 1] <= l[i] && r[i] > r[i - 1])//Two segments doesn't cross
				dp[i][j] = dp[i - 1][j];//Kill Zombie
			else//Two segments cross
			{
				dp[i][j] = dp[i - 1][j] + 1;//Let zombie get in;
				if(j - 1 >= 0)//If can fight
					dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);//Choose a min one
			}	
		}
	}
	cout << dp[N][M];
	return 0;
}
