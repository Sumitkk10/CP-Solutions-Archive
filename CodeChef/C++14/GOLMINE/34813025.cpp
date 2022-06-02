#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
    	ld g[n], a[n], b[n], ans = 0, ans1 = 0;
    	for(int i = 0; i < n; ++i)
    		cin >> g[i] >> a[i] >> b[i];
    	for(int i = 0; i < n; ++i){
    		ld r = a[i] * (g[i]/(b[i] + a[i]));
    		ans1 += r;
    		ld l = b[i] * (g[i]/(b[i] + a[i]));
    		ans += l;
    	}
    	cout << fixed << setprecision(6) << ans << " " << ans1 << '\n';
    }
    return 0;
}