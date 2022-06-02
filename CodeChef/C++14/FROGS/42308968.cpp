#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 50003 + 2;

void solve() {
    int n;
    cin >> n;
    int w[n + 1], l[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> w[i];
    for(int i = 1; i <= n; ++i)
        cin >> l[i];
    if(n == 2){
        if(w[1] <= w[2]) {
            cout << "0\n";
            return;
        }
        if(l[1] == 1){
            cout << "2\n";
            return;
        }
        cout << "1\n";
        return;
    }
    map<int, int> mp;
    for(int i = 1; i <= n; ++i)
        mp[w[i]] = i;
    long long ans = 0;
    for(int i = 2; i <= n; ++i){
        int mx = 0;
        for(int j = 1; j < i; ++j)
            mx = max(mx, mp[j]);
        int cur = mp[i];
        while(cur <= mx){
            cur += l[mp[i]];
            ++ans;
        }
        mp[i] = cur;
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