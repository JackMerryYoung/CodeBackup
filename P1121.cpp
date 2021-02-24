#include <bits/stdc++.h>
using namespace std;
//O(N)
//1.Segment overbound
//2.No segment overbound
int N,sum,cnt;
int z[200005],f[200005],a[200005];
int Query()
{
	int ans = -0x7fffffff;
	for(register int i = 1;i <= N;++ i) z[i] = max(z[i - 1],0) + a[i];
	for(register int i = N;i >= 1;-- i) f[i] = max(f[i + 1],0) + a[i];
	//Merge
	for(register int i = 1;i <= N;++ i) z[i] = max(z[i - 1],z[i]);
	for(register int i = N;i >= 1;-- i) f[i] = max(f[i + 1],f[i]);
	//Get the answer
	for(register int i = 1;i < N;++ i) ans = max(ans,z[i] + f[i + 1]);
	return ans;
}
int main()
{
	cin >> N;
	memset(z,~0x3f,sizeof(z));
	memset(f,~0x3f,sizeof(f));
	for(register int i = 1;i <= N;++ i) 
	{
		scanf("%i",&a[i]);
		sum += a[i];
		if(a[i] > 0) ++ cnt;
	}
	int tmp1 = Query();
	if(cnt == 1) printf("%i",tmp1);
	else 
	{
		for(register int i = 1;i <= N;++ i) a[i] = -a[i];
		int tmp2 = sum + Query();
		if(!tmp2) tmp2 = -0x7fffffff;
		printf("%i",max(tmp1,tmp2));
	}
	return 0;
}
