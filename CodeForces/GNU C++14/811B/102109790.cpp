#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 105;
const int MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r, --x;
        int diff = x - l, smaller = 0;
        for(int i = l; i <= r; ++i){
            if(i == x) continue;
            if(a[i] < a[x])
                ++smaller;
        }
        if(diff == smaller) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
