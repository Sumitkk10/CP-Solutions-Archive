#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

/*
if both belongs to same group then ok
*/

void solve(){
    ll n, m, q;
    cin >> n >> m >> q;
    ll hcf = __gcd(n, m);
    ll take[3];
    take[1] = n/hcf;
    take[2] = m/hcf;
    while(q--){
        ll x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;
        ll rem = y1%take[x1], rem1 = y2%take[x2];
        if(rem) rem = 1;
        if(rem1) rem1 = 1; 
        if((y1 / take[x1]) + rem == (y2 / take[x2]) + rem1) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
