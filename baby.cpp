#include<bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)
const int INF=1e9+7;
int dist[17][17];
int n;
int dp[1<<17][17];

int assign(int mask,int pos)
{
    
    if(mask+1==(1<<n))
        return dp[mask][pos]=0;
        
    if(pos==n)
        return dp[mask][pos]=INF;
        
    if(dp[mask][pos]!=-1)
    {
        //cout<<"MAsk"<<"\t"<<mask<<"\t"<<"POS"<<"\t"<<pos<<"\t"<<"VALUE"<<"\t"<<dp[mask][pos]<<"\n";
        return dp[mask][pos];
    }   
    dp[mask][pos]=assign(mask,pos+1);
    for(int i=0;i<n;i++){
        
        if( ( mask & ( 1 <<  i) ) == 0)
            dp[mask][pos]=min(dp[mask][pos],dist[i][pos]+assign(mask|(1<<i),pos+1));
    }
    
    return dp[mask][pos];
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
        
        memset(&dp,-1,sizeof(dp));     
        pf(assign(0,0));
                
    }
    
    return 0;
}