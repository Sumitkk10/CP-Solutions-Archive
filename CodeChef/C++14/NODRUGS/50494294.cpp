#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, l, k;
    cin >> n >> k >> l;
    ll a[n], mx = 0, cnt = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    if(k > 0)
        a[n - 1] += k*(l - 1);
    for(int i = 0; i < n; ++i)
        mx = max(mx, a[i]);
     for(int i = 0; i < n; ++i){
        if(a[i] == mx)
            cnt++;
     }
     if(cnt == 1 and a[n - 1] == mx){
        cout << "Yes\n";
        return;
     }
     cout << "No\n";
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
