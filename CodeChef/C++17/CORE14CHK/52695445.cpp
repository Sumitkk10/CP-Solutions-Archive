#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;

void solve(){
    long long n, p, k;
    cin >> n >> p >> k;
    long long a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    long long cur = 1, ans = 1, mn = a[0] + k;
    for(int i = 1; i < n; ++i){
        if(cur >= p){
            cur = 1;
            mn = a[i] + k;
            ++ans;
            continue;
        }
        if(a[i] > mn){
            cur = 1;
            ++ans;
            mn = a[i] + k;
            continue;
        }
        ++cur;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    while(t--)
        solve();
    return 0;
}