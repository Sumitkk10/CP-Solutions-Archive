#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 50003 + 2;

void solve() {
    int n;
    cin >> n;
    long long int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long ans = 0;
    for(int i = 1; i < n - 1; ++i){
        long long cur = abs(a[0] - a[i]) + abs(a[i] - a[n - 1]) + abs(a[n - 1] - a[0]);
        ans = max(ans, cur);
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}