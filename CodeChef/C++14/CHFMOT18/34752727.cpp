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
        ll s, n;
        cin >> s >> n;
        if(n % 2 != 0)
            --n;
        ll ans = s/n;
        ll k = s%n;
        if(k % 2 != 0 && k > 1)
            ans += 2;
        else if(k % 2 != 0 && k == 1)
            ans ++;
        else if(k % 2 == 0 && k != 0)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}