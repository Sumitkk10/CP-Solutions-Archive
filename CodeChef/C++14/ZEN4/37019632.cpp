#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t; 
    cin >> t;
    while(t--){
        ll x, y, n, ans = 0;
      	cin >> n >> x >> y;
      	ll d = x/y;
      	for (int i = 0; i <= n; i++){
          if(i != 0)
          	ans += d;
          x = x - (y * d);
          if (x == 0)
              break;
          x = x * 10; 
          d = x / y; 
    	} 
      	cout << ans << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}