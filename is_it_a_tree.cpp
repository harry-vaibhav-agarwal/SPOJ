#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug3(a,b,c) cout<<#a<<"::"<<a<<"\t"<<#b<<"::"<<b<<"\t"<<#c<<"::"<<c<<"\n";

#define pb push_back
int n,m;
vector<vector<int>>adj;
enum colour {WHITE,GRAY,BLACK};
vector<int>color;


bool dfs(int u){
    
    color[u]=GRAY;
    
    for(auto v:adj[u]){
        if(color[v]==GRAY)
            return true;
            
        if(color[v]==WHITE && dfs(v))
            return  true;
    }
    
    color[u]=BLACK;
    return false;
}

int main() {

    FAST_IO
    
    int a,b;
    cin>>n>>m;
    adj.resize(n+1);
    color.resize(n+1,WHITE);
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        adj[a].pb(b);
    }
    
    if(m+1!=n)
        cout<<"NO\n";
        
    else
    {
        if(dfs(1)){
            cout<<"NO\n";
            return 0;
        }
        
        for(int i=1;i<=n;i++){
            if(color[i]==WHITE){
                cout<<"NO\n";
                return 0;
            }
            
        }
        
        cout<<"YES\n";
    }
    
    
    
	return 0;
}