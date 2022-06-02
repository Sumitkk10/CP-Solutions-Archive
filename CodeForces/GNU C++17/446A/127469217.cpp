#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    long long a[n + 2];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int left[n + 1], right[n + 2];
    left[0] = 0;
    a[0] = -10;
    for(int i = 1; i <= n; ++i){
        if(a[i] > a[i - 1]) left[i] = left[i - 1] + 1;
        else left[i] = 1;
    }
    a[n + 1] = 1e14;
    right[n + 1] = 0;
    for(int i = n; i >= 1; --i){
        if(a[i] < a[i + 1]) right[i] = right[i + 1] + 1;
        else right[i] = 1;
    }
    int ans = 1;
    for(int i = 1; i <= n; ++i){
        if(a[i - 1] + 1 < a[i + 1])
            ans = max(ans, left[i - 1] + right[i + 1] + 1);
        ans = max({ans, left[i] + 1, right[i] + 1});
    }
    cout << min(n, ans) << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
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
