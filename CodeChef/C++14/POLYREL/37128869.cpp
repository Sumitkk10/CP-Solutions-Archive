#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(int i = 0; i < n; ++i){
            int x, y; 
            cin >> x >> y;
        }
        if(n <= 5) cout << n << "\n";
        else{
            ll ans = n;
            while(n > 5){
                ans += n/2;
                n /= 2;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
