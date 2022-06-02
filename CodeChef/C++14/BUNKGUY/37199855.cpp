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
        ll n; cin >> n;
        ll sum = 0;
        for(int i = 1; i < n; ++i){
            ll x; cin >> x;
            sum += x;
        }
        ll ans = (n*(n + 1))/ 2;
        cout << ans - sum << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}