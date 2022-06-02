#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, q;
    cin >> n >> q;
    int a[n + 1], pre_even[n + 1];
    pre_even[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        pre_even[i] = pre_even[i - 1] + (a[i] % 2 == 0);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        if(r - l + 1 < 3){
            cout << "0\n";
            continue;
        }
        // for three numebrs to be even : 
        // either all three are even
        // either two odd and one even
        long long int even = pre_even[r] - pre_even[l - 1], odd = (r - l + 1) - even;
        long long ans = (even * (even - 1) * (even - 2)) / 6;
        ans += ((odd * (odd - 1)) / 2) * even;
        cout << ans << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
