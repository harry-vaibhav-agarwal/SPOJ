/*Formula for perimeter is 
n=no of rectangles


Perimeter=2*n+height[first rectangle]+height[last rectangle] + sum of absolute difference of adjacent rectangles

*/

#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%d",&n)
#define pf(n) printf("%d\n",n)
#define pb push_back
#define ll long long
#define debug3(a,b,c) printf("%s\t%d\t%s\t%d\t%s\t%d\n",#a,a,#b,b,#c,c)
#define debug2(a,b) printf("%s\t%d\t%s\t%d\n",#a,a,#b,b)
#define debug(a) printf("%s\t%d\n",#a,a)

const ll m=1e9+7;
int n;
int dp[1<<16][16];   //mask with fixed last rectangle
int nop[1<<16][16];
int height[16];

int perimeter(int mask,int curr)
{
    if(dp[mask][curr]!=-1)
        return dp[mask][curr];
    
    
    if(mask+1 == (1<<n))
    {
        nop[mask][curr]=1;
        return height[curr];    //for last rectangle
    }   
    int p=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
        {
            p=abs(height[i]-height[curr])+perimeter(mask|(1<<i) ,i);
            if(p>ans)
            {
                ans=p;
                nop[mask][curr]=0;
            }
            if(p==ans)
                nop[mask][curr]+=nop[mask|1<<i][i];
        }
    }
    
    return dp[mask][curr]=ans;
}
int main()
{
    
    while(true)
    {
        sd(n);
        if(n==0)
            return 0;
            
    
        for(int i=0;i<n;i++)
            sd(height[i]);
            
        memset(&dp,-1,sizeof(dp));
        memset(nop,0,sizeof(nop));
        
        int ans=0,ans2=0;
        int mask=0;
        for(int i=0;i<n;i++)
        { 
            int p=perimeter(mask|(1<<i),i)+height[i];   //Setting up first rectangle
            if(p>ans)
            {
                ans=p;
                ans2=nop[1<<i][i];
            }
            else if(p==ans)
                ans2+=nop[1<<i][i];
        }
        printf("%d %d\n",ans+2*n,ans2);
    }
    return 0;
}
