#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
ll n, k, x, a[N], sum;

void solve(){
    cin >> n >> k >> x;
    sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, greater<ll>());
    int cur = 1;
    while(k-- and cur < n){
        if(cur >= n) break;
        if(a[cur] + a[cur - 1] < x) break;
        sum -= (a[cur] + a[cur - 1]);
        sum += x;
        cur += 2;
    }
    cout << sum << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
