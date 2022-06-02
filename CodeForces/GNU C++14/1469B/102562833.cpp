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
    int a[n + 1], pre_sum[n + 1], mx = 0, mxx = 0;
    pre_sum[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre_sum[i] = pre_sum[i - 1] + a[i];
        mx = max(mx, pre_sum[i]);
    }
    int m;
    cin >> m;
    int b[m + 1], pre_sum1[m + 1];
    pre_sum1[0] = 0;
    for(int i = 1; i <= m; ++i){
        cin >> b[i];
        pre_sum1[i] = pre_sum1[i - 1] + b[i];
        mxx = max(mxx, pre_sum1[i]);
    }
    cout << max(0, mx+ mxx) << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
