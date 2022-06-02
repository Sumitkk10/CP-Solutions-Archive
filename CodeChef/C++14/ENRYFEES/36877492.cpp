#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t; 
    cin >> t;
    while(t--){
        ll x, y, p;
        cin >> x >> y >> p;
        y += p;
        if(y % x == 0) cout << y/x << "\n";
        else cout << (y/x) + 1 << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}