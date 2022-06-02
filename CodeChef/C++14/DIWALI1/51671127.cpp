#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long tot, a, b, c, x, y;
    cin >> tot >> a >> b >> c >> x >> y;
    b = b + x*a;
    c = c + y*a;
    cout << tot / min(b, c) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
