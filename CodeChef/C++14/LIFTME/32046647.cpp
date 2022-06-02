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
        ll n, q;
        cin >> n >> q;
        ll a[q], b[q];
        for(int i = 0; i < q; ++i){
            cin >> a[i] >> b[i];
        }
        ll ans = a[0];
        ans += abs(a[0] - b[0]);
        for(int i = 1; i < q; ++i){
            ans += abs(b[i-1] - a[i]);
            ans += abs(a[i] - b[i]);
        }
        cout << ans << '\n'; 
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
