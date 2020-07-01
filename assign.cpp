#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(n) scanf("%lld",&n)
ll arr[21][21];
ll dp[21][1<<21];
ll n;
ll solve(ll index,ll mask)
{
    ll ans=0;
    
	if(index==n)
		return dp[index][mask]= 1;
 
	if(dp[index][mask]!=-1)
	return dp[index][mask];
    
	for(ll j=0;j<n;j++)
	{
		if(arr[index][j] && ((mask&(1<<j))==0) )
		ans+=solve(index+1,mask|(1<<j));
		
	}
 
	return dp[index][mask]=ans;
}
 
int main()
{
	ll t,i,j;
	sd(t);
	while(t--)
	{
		sd(n);
	    memset(&dp,-1,sizeof(dp));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				sd(arr[i][j]);
 
		cout<<solve(0,0)<<endl;
	}
	return 0;
} 