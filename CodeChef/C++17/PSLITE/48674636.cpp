#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    // this is the bruteforce solution
    /*
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        ans += (k/i);
    }
    cout << ans << '\n';
    */
    long long ans = 0, ok;
    for(int i = 1; i <= sqrt(n) and i <= k; ++i){
        ans += (n/i);
        ok = n/i;
    }
    while(ok--){
        if(!ok) break;
        int cur = n/ok;
        int cur_1 = n/(ok + 1);
        int res = cur - cur_1;
        if(k <= cur_1)
            res = 0;
        else if(k < cur)
            res = k - cur_1;
        ans += res*ok;
    }
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
