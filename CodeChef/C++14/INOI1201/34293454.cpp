#include <bits/stdc++.h>
#define ll long long int    
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main() {
    fast;
    ll n;
    cin >> n;
    ll x[n], y[n], z[n], mx = 0, ans = 0;
    pair<ll, ll> sum[n];
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i] >> z[i];
        sum[i].first = y[i] + z[i];
        sum[i].second = i;
    }
    sort(sum + 0, sum + n, greater<>());
    for(int i = 0; i < n; ++i){
        mx =  max(mx, (ans + sum[i].first + x[sum[i].second]));
        ans += x[sum[i].second];
    }
    cout << mx;
    return 0;
}