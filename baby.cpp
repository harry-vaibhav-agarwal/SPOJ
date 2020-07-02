#include<bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)
const int INF=1e9+7;
int dist[17][17];
int n;
int dp[1<<17];

int assign(int mask,int pos)
{
    
    if(pos==n)
        return dp[mask]=0;
        
        
    if(dp[mask]!=-1)
        return dp[mask];
       
    dp[mask]=INF;
    for(int i=0;i<n;i++){
        
        if( ( mask & ( 1 <<  i) ) == 0)  //ithqueen has not been assigned a pos
            dp[mask]=min(dp[mask],dist[i][pos]+assign(mask|(1<<i),pos+1));
    }
    
    return dp[mask];
}


int main()
{
    while(true){
        sd(n);
        if(n==0)
            return 0;
            
        int orig[n+1],valid[n+1];
        
        for(int i=1;i<=n;i++)
            sd(orig[i]);
            
        for(int i=1;i<=n;i++)
            sd(valid[i]);
            
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i-1][j-1]=abs(j-i)+abs(orig[i]-valid[j]);
        
        memset(dp,-1,sizeof(dp));     
        pf(assign(0,0));
                
    }
    
    return 0;
}