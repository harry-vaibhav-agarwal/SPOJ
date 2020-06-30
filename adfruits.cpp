#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define ll long long

int main() {

    string x,y;
    
    while(cin>>x && cin>>y)
    {
    
        int n=x.size();
        int m=y.size();
        
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)                             //computing lcs 
        {
            for(int j=0;j<=m;j++)
            {
                
                if(i==0 || j==0)
                    dp[i][j]=0;
                    
                else
                {
                    if(x[i-1]==y[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
                }
            }
        }
    
        int index=dp[n][m];
        string lcs="";           //getting string of longest common characters
        
        int i=n,j=m;
        
        while(i>0 && j>0)
        {
            if(x[i-1]==y[j-1])
            {
                lcs=x[i-1]+lcs;
                i--;
                j--;
                
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
        
                
                else
                    j--;
    
            }
        }
        
        i=0,j=0;
        string p="";
        for(int k=0;k<lcs.size();k++)   
         {
                while(i<n && x[i]!=lcs[k])  //printing uncommon part
                {
                    p+=x[i];
                    i++;
                }
                
                while(j<m && y[j]!=lcs[k])   //printing uncommon part
                {
                    p+=y[j];
                    j++;
                }
                
                p+=lcs[k];   //printing common part
                i++;
                j++;
                
         }
         
         while(i<n)
            p+=x[i++];  //printing leftoverpart
            
        while(j<m)
            p+=y[j++];  //printing leftover part
            
        cout<<p<<"\n";
    }
	 return 0;
	
}