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
        ll n, k, m;
        cin >> n >> m >> k;
        vector<ll> a(m), b(k);
        for(int i = 0; i < m; ++i)
            cin >> a[i];
        for(int i = 0; i < k; ++i)
            cin >> b[i];
        ll ans = 0;
        for(int i = 0; i < m ; ++i){
            ll x = a[i];
            for(int j = 0; j < k; ++j){
                if(x == b[j]){
                    ++ans;
                    break;
                }
            }
        }
        cout << ans << ' ';
        ans = 0;
        ll d = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < m; ++j){
                if(i == a[j]){
                    ++d;
                    break;
                }
            }
            if(d == 0){
                for(int j = 0; j < k; ++j){
                if(i == b[j]){
                    ++d;
                    break;
                    }
                }
                if(d == 0)
                    ++ans;
            }
            d = 0;
        }
        cout << ans << endl;
    }
    return 0;
}