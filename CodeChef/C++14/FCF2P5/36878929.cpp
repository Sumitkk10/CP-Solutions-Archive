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
    ll n, q;
    cin >> n >> q;
    ll a[n], pos[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    ll dp[n];
    dp[0] = 0;
    for(int i = 1; i < n; ++i)
        dp[i] = dp[i - 1] + abs(pos[i] - pos[i - 1]);
    while(q--){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        cout << abs(dp[a[x]] - dp[a[y]]) << "\n" ;
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}