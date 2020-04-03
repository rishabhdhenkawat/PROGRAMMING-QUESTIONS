#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll anc[510][510]={0};
int main(){
	ll n, K;cin>>n>>K;
	assert(0 <= K and K <= 1e9);
	assert(1 <= n and n <= 500);
	ll a[1000];
	ll par[1000];
	for(ll i=1; i<=n; i++){
		cin>>a[i];
		assert(0 <= a[i] and a[i] <= 1e9);
	}
	for(ll i=2; i<=n; i++){
		ll temp; cin>>temp;
		assert(1 <= temp and temp <= i);
		par[i] = temp;
	}
	for(ll i=2; i<=n; i++){
		ll x = i;
		while(x != 1){
			x = par[x];
			anc[x][i] = 1;
		}
	}
	ll ans = 0;
	for(ll i=1; i<=n; i++)
	for(ll j=1; j<=n; j++)
	for(ll k=1; k<=n; k++){
		if(i == j or j == k or i == k)continue;
		if(anc[i][j] and anc[i][k] and a[i]+a[j]+a[k] >= K){
		  //cout<<i<<" "<<j<<" "<<k<<endl;
			ans++;
		}	
	}	
	cout<<ans/2<<endl;	
	return 0;
}