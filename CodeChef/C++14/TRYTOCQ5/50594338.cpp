#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    ll n, m;
    cin >> n >> m;
    int lst = -1;
    int ans = 0;
    vector<int> primes;
    for (int i = 2; i*i <= 1e9; i++) {
        bool ok = true;
        for (int j = 2; j*j <= i; j++) {
            if (i % j == 0) {
                ok = false;
                break;
            }
        }
        if (ok && i > 1)
            primes.push_back(i);
    }
    for (int i = n; i <= m; i++) {
        bool ok = true;
        for (int j = 0; j < primes.size() && primes[j]*primes[j] <= i; j++){
            if (i % primes[j] == 0){
                ok = false;
                break;
            }
        }
        if(ok && i > 1) {
            ans += (lst == i - 2);
            lst = i;
        }
    }
    cout << ans << '\n';
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
