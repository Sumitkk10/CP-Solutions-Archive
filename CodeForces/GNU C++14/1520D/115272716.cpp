#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n;
    cin >> n;
    long long int a[n + 1];
    unordered_map<long long int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i] - i]++;
    }
    long long  ans = 0;
    for(auto k : mp){
        long long int ok = k.second;
        ans += ((ok * (ok - 1)) / 2);
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
