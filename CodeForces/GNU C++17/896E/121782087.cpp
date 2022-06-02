#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= m; ++i){
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        if(t == 1){
            for(int j = l; j <= r; ++j)
                a[j] = (a[j] > x ? a[j] - x : a[j]);
        }
        else{
            int ans = 0;
            for(int j = l; j <= r; ++j)
                ans += (a[j] == x);
            cout << ans << '\n';
        }
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
