#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, a[N], b[N], nodes[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> nodes[i];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    long long ans = 0, pre = 0;
    for(int i = 2; i <= n; ++i){
        long long cur = nodes[i] + abs(a[i] - b[i]) + 1;
        if(a[i] != b[i])
            cur = max(cur, nodes[i] - abs(a[i] - b[i]) + pre + 1);
        ans = max(ans, cur);
        pre = cur;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
