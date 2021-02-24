#include <bits/stdc++.h>
using namespace std;
int N,M;
int v[105][3],p[105][3];
int dp[105];
int main()
{
	cin >> N >> M;
	for(int i = 1;i <= M;i ++)
	{
		int V,P,Q;
		cin >> V >> P >> Q;
		if(Q == 0)            //Main kit
		{
			v[i][0] = V;
			p[i][0] = P;
		}
		else if(v[Q][1] == 0) //First recommanded kit
		{
			v[Q][1] = V;
			p[Q][1] = P;
		}
		else                  //Last recommanded kit
		{
			v[Q][2] = V;
			p[Q][2] = P;
		}
	}
	for(int i = 1;i <= M;i ++)
	{
		for(int j = N;j >= 0;j --)
		{
			if(j >= v[i][0])//Can buy
				dp[j] = max(dp[j],dp[j - v[i][0]] + v[i][0] * p[i][0]);
			if(j >= v[i][0] + v[i][1])//Can buy first recommanded kit
				dp[j] = max(dp[j],dp[j - v[i][0] - v[i][1]] + v[i][0] * p[i][0] + v[i][1] * p[i][1]);
			if(j >= v[i][0] + v[i][2])//Can buy second recommanded kit
				dp[j] = max(dp[j],dp[j - v[i][0] - v[i][2]] + v[i][0] * p[i][0] + v[i][2] * p[i][2]);
			if(j >= v[i][0] + v[i][1] + v[i][2])//Can buy all
				dp[j] = max(dp[j],dp[j - v[i][0] - v[i][1] - v[i][2]] + v[i][0] * p[i][0] + v[i][1] * p[i][1] + v[i][2] * p[i][2]);
		}
	}
	cout << dp[N];
	return 0;
}
