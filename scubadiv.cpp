#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%intd",&n)
#define pf(n) printf("%d\n",n)
int dp[1002][23][82];
#define INF 900000

struct Cylinder
{
	int oxygen;
	int nitrogen;
	int weight;
};

void reset()
{
	for(int i=0;i<1002;i++)
		for(int j=0;j<23;j++)
			for(int k=0;k<82;k++)
				dp[i][j][k]=-1;
}

int minimumWeight(int oxy,int nit,int n,vector<Cylinder> &cylinder)
{
    if(dp[n][oxy][nit]!=-1)
		return dp[n][oxy][nit];
		
		
	if(oxy==0 && nit==0)
		return dp[n][0][0]=0;
		
    else if(n==0)
        return dp[n][oxy][nit]=INF;
		
	int include=cylinder[n-1].weight+minimumWeight(max(0,oxy-cylinder[n-1].oxygen),max(0,nit-cylinder[n-1].nitrogen),n-1,cylinder);
	int exclude=minimumWeight(oxy,nit,n-1,cylinder);
	
	return dp[n][oxy][nit]=min(include,exclude);
}

int solve()
{
	int oxy,nit,n;
	sd(oxy);
	sd(nit);
	sd(n);
	
	vector<Cylinder> cylinder(n);
	reset();
	
	for(int i=0;i<n;i++)
	{
		sd(cylinder[i].oxygen);
		sd(cylinder[i].nitrogen);
		sd(cylinder[i].weight);
	}
	
	return minimumWeight(oxy,nit,n,cylinder);

}

int main() {
	
	
	int t;
	sd(t);
	while(t--)
		pf(solve());
	return 0;
}