#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 3;
 
int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n, m, b;
        cin >> n >> b >> m;
        ll a[m], ans = 1;
        for(int i = 0; i < m; ++i)
            cin >> a[i];
        ll k = a[0]/b;
        for(int i = 1; i < m; ++i){
            ll o = a[i]/b;
            if(o != k){
                k = o;
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}