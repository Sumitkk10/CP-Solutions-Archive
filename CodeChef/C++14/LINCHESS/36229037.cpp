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
        ll n, k;
        cin >> n >> k;
        ll a[n], mx = 0;
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i){
            if(a[i] > k) continue;
            if(k % a[i] == 0) mx = max(mx, a[i]);
        }
        if(mx == 0) cout << "-1\n";
        else
            cout << mx << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}