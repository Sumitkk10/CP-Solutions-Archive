#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    vector<int> a(n + 1, 0);
    ll res = n - 1;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = n; i >= 1; --i){
        ll cur = a[i];
        ll req = (cur + 1) / 2;
        ll low = 1, high = i - 1, ans = -1;
        while(low <= high){
            ll mid = (low + high) / 2;
            if(a[mid] >= req){
                ans = mid;
                high = mid - 1; 
            }
            else
                low = mid + 1;
        }
        // cout << i << " " << ans << " " << (n - i) + ans - 1 << "\n";
        if(ans == -1) continue;
        res = min(res, (n - i) + ans - 1);
    }
    cout << res << "\n";
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
