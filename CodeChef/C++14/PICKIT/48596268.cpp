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
    int a[n + 2];
    a[0] =  1; 
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = 1000000;
    sort(a, a + n + 2);
    long long int pre[n + 2], suf[n + 2];
    pre[0] = 0;
    suf[0] = 1000000 - 1;
    suf[n + 1] = 0;
    pre[n + 1] = 1000000 - 1;
    for(int i = 1; i <= n + 1; ++i)
        pre[i] = pre[i - 1] + (a[i] - a[i - 1]);
    for(int i = n; i >= 1; --i)
        suf[i] = suf[i + 1] + (a[i + 1] - a[i]);
    long long ans = INT_MAX;
    for(int i = 0; i <= n; ++i){
        ans = min(ans, max(pre[i], suf[i + 1]));
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
