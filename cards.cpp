#include <bits/stdc++.h>
using namespace std;
#define sd(n) scanf("%lld",&n)
#define ll long long
const int m=1e6+7;
 
int main() {
	ll t,n,ans;
	sd(t);
	
	while(t--){
		sd(n);
		ans=(3*n*n+n)/2;
		printf("%lld\n",ans%m);
	}
	return 0;
} 