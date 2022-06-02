#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 103;

int main(){
    fast;
    ll n, q;
    cin >> n >> q;
    map<int, int> mp;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        mp[i] = x;
    }
    while(q--){
        ll a, b;
        cin >> a >> b;
        ll ans = abs(mp[a] - mp[b]);
        cout << ans << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}