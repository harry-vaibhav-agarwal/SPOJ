#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define debug(a) cout<<#a<<" :: "<<a<<"\n"
#define debug2(a,b) cout<<#a<<" :: "<<a<<"\t"<<#b<<" :: "<<b<<"\n"
#define debug(a) cout<<#a<<" :: "<<a<<"\n"

int main(){
    
    IOS;
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    
    
    vector<bool>visited(f+1,false);
    queue<int>q;
    q.push(s);
    visited[s]=true;
    
    int moves=0;
 
     
     
    while(!q.empty()){ 
        
        int i=0;
        int sz=q.size();
        while(i<sz){
            
            int x=q.front();
            q.pop();
            
            if(x==g){
                cout<<moves<<"\n";
                return 0;
            }
            
            if(x+u<=f && !visited[x+u]){
                q.push(x+u);
                visited[x+u]=true;
            }
            
            if(x-d>=1 && !visited[x-d]){
                q.push(x-d);
                visited[x-d]=true;
            }
            i++;
        }
        moves++;
    }
    
    cout<<"use the stairs\n";
    
    return 0;
}
