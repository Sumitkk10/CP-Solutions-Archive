#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n, k;
    	cin >> n >> k;
    	vector<ll> a(n);
    	ll sum = 0;
    	for(int i = 0; i < n; ++i){
    		cin >> a[i];
    		sum += a[i];
    	}
    	sort(a.begin(), a.end());
    	ll ans = sum/k;
    	sum -= a[0];
    	if((sum/k) == ans)
    		cout << -1 << endl;
    	else
    		cout << ans << endl;
    }
    return 0;
}