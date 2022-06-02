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
    long long int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    map<long long int, long long int> mp;
    long long int sum = 0;
    for(int i = 1; i <= k; ++i) 
        sum += a[i];
    mp[sum]++;
    for(int i = 2; i <= n - k + 1; ++i){
        sum -= a[i - 1];
        sum += a[i + k - 1];
        mp[sum]++;
    }
    long long int mx = 0, tot = 0;
    for(auto k : mp){
        mx = max(mx, k.second);
        tot += k.second;
    }
    cout << tot - mx << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
