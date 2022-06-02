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
        ll n, ct = 1; 
        cin >> n;
        ll a[n + 1][n + 1];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin >> a[i][j];
        bool mat[n + 1];
        for(int i = 2; i <= n; ++i){
            if(a[i][1] == ((i - 1) * n) + 1){ 
            	mat[i] = 0;
            	++ct;
            }
            else mat[i] = true;
        }
        if(ct == n){
        	cout << "0\n";
        	continue;
        }
        int j = n;
        while(mat[j] == 0 && j >= 0)
        	--j;
        ll ans = 1;
        for(int i = 3; i <= j; ++i)
            if(mat[i] != mat[i - 1]) ++ans;
        cout << ans << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}