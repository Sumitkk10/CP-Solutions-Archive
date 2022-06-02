#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n + 1], ans = 0;
        for(int i = 1; i <= n; ++i)
        	cin >> a[i];
        for(int i = 1; i <= n - 1; ++i)
        	for(int j = i + 1; j <= n; ++j)
        		if((a[i] & a[j]) == a[i])
        			ans += 1;
        cout << ans << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}