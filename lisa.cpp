#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%d\n",&n)
#define pf(n) printf("%d\n",n)
int dp[25][25];
#define INF 1000000007

void reset()
{
    for(int i=0;i<25;i++)
        for(int j=0;j<25;j++)
            dp[i][j]=-1;
}

int maximize(string &num,string &oper,int i,int j)
{
    
    if(i==j)
        return dp[i][j]=num[i]-'0';
        
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    int ans=-1*INF;
    for(int k=i;k<j;k++)
    {
        if(oper[k]=='+')
            ans=max(ans,maximize(num,oper,i,k)+maximize(num,oper,k+1,j));
            
        else
            ans=max(ans,maximize(num,oper,i,k)*maximize(num,oper,k+1,j));
    }
    
    return dp[i][j]=ans;
}

int minimize(string &num,string &oper,int i,int j)
{
    
    if(i==j)
        return dp[i][j]=num[i]-'0';
        
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    int ans=INF;
    for(int k=i;k<j;k++)
    {
        if(oper[k]=='+')
            ans=min(ans,minimize(num,oper,i,k)+minimize(num,oper,k+1,j));
            
        else
            ans=min(ans,minimize(num,oper,i,k)*minimize(num,oper,k+1,j));
    }
    
    return dp[i][j]=ans;
}
int main() {
    
    int t;
    string s,num,oper;
    sd(t);
    while(t--){
        cin>>s;
        num="";
        oper="";
        
        reset();    
        for(int i=0;s[i];i++){
            if(isdigit(s[i]))
                num+=s[i];
            else
                oper+=s[i];        
        }
        int lisa=maximize(num,oper,0,num.size()-1);
        reset();
        int father=minimize(num,oper,0,num.size()-1);
        pf(lisa);
        pf(father);
    }
	return 0;
}