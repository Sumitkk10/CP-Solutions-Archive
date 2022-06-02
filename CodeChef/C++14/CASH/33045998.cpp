#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, k, ans = 0;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0 ; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i){
            ans += a[i]%k;
            ans %= k;
        }
        cout << ans << endl;
    }
    return 0;
}