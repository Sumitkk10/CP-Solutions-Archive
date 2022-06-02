#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c, p, q, r;
        cin >> a >> b >> c >> p >> q >> r;
        if(p < a || q < b || r < c){
            cout << "-1\n";
            continue;
        }
        ll k = p - a;
        ll k1 = q - b;
        ll k2 = r - c;
        cout << k + k1 + k2 << '\n';
    }
    return 0;
}