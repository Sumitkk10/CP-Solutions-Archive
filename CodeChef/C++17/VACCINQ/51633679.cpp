#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, p, x, y;
    cin >> n >> p >> x >> y;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= p; ++i)
        ans += (a[i] == 1 ? y : x);
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}