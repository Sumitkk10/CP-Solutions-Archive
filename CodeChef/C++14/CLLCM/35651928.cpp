#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main(){
    fast;
    ll t;
    cin >> t;   
    while(t--){
        ll n;
        cin >> n;
        ll a[n], eve = 0;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] % 2 == 0) eve++;
        }
        if(eve > 0) cout << "NO\n";
        else cout << "YES\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}