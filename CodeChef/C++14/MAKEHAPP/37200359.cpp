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
        ll n, q; cin >> n >> q;
        ll mat[n + 2];
        for(int i = 0; i < n + 2; ++i) mat[i] = 0;
        while(q--){
            int l, r, v;
            cin >> l >> r >> v;
            mat[l] += v;
            mat[r + 1] -= v;
        }
        ll pre_sum[n + 2], sum = 0;
        for(int i = 0; i < n; ++i){
            if(i == 0) pre_sum[i] = mat[i];
            else pre_sum[i] = pre_sum[i - 1] + mat[i];
            sum += pre_sum[i];
        }
        cout << sum << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}