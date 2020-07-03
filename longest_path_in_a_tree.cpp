#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
int n;
vector<vector<int>>adj;
vector<int>h;


int compute_height(int u,int par){

    for(auto v:adj[u])
        if(v!=par)
            h[u]=max(h[u],compute_height(v,u));

    h[u]+=1;
    return h[u];
}

int diameter(int u,int par){
    
    int mx1=0,mx2=0,mx_subtree=0;  //mx2 should be 0 not any other value consider the case if there is only one child of current node u 
    
    for(auto v:adj[u]){
        if(v==par)
            continue;
            
        if(h[v]>mx1){
            mx2=mx1;
            mx1=h[v];
        }
        else if(h[v]>mx2)
            mx2=h[v];
        
    }
    //first maximum and second maximum heights
    for(auto v:adj[u])
        if(v!=par)
            mx_subtree=max(mx_subtree,diameter(v,u));  //diameter lies in subtree
        
    
    
    return max(mx_subtree,mx1+mx2);  //diameter lies in subtree or it passes through current node not added 1 as we are counting edges height will already accomadate that
}

int main() {

    FAST_IO
    int a,b;
    cin>>n;
    adj.resize(n+1);
    h.resize(n+1,0);
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    compute_height(1,-1);
    cout<<diameter(1,-1)<<"\n";

    
	return 0;
}