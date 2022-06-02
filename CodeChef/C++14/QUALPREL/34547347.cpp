#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5+5;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a+n, greater<>());
        ll ans = 0;
        for(int i = 0; i < m; ++i)
            ++ans;
        for(int i = m; i < n; ++i){
            if(a[i] == a[m-1])
                ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}