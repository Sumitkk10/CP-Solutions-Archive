#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, k, a[N], pre_sum[N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    long long ans = INT_MAX;
    for(int i = 1; i <= n; ++i){
        int r = n - i;
        if(pre_sum[i] % k == 0)
            ans = min(ans, (long long) __builtin_popcount(r));
        for(int submask = r; submask; submask = (submask - 1) & (r)){
            if(submask >= i) continue;
            if((pre_sum[i] - pre_sum[submask]) % k == 0)
                ans = min(ans, (long long) __builtin_popcount(r));
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
