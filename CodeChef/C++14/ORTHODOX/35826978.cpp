#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e3 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n] ;
      	for(int i = 0; i < n; ++i) cin >> a[i] ;
      	sort(a, a+n, greater<ll>()) ;
      	// unordered_set<int> cnt;
  		// cnt.insert(a[0]);
    	ll ans = a[0]; 
  		bool ok = 1;
   		for (int i = 1; i < n; ++i){
      	 	if(ans == (ans | a[i])){
           		ok = 0;
              	// cout << "yo" ;
           		break;
        	} 
      	 	else ans |= a[i] ;
      	 	// cnt.insert(ans);
   	 	}
    	if(ok) cout << "YES\n";
  		else cout << "NO\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}