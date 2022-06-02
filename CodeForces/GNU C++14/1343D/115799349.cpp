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
    map<int, int> mp;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n / 2; ++i)
        mp[a[i] + a[n - i - 1]]++;
    int pre[2*k + 1];
    memset(pre, 0, sizeof pre);
    for(int i = 0; i < n / 2; ++i){
        int l = a[i] + 1, r = a[i] + k;
        int l1 = a[n - i - 1] + 1, r1 = a[n - i - 1] + k;
        pre[min(l, l1)]++;
        pre[max(r, r1) + 1]--;
    }
    for(int i = 1; i < 2*k + 1; ++i)
        pre[i] += pre[i - 1];
    int ans = INT_MAX;
    for(int i = 2; i < 2*k + 1; ++i)
        ans = min(ans, (pre[i] - mp[i]) + (n/2 - pre[i]) * 2);
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
