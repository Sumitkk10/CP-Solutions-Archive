#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    ll sum = 0, a[n + 1];
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, + a + n + 1);
    int q;
    cin >> q;
    while(q--){
        ll def, attack;
        cin >> def >> attack;
        ll res = LLONG_MAX, cur = sum - a[n];
        res = min(res, max(0ll, attack - cur) + max(0ll, def - a[n]));
        cur = sum - a[1];
        res = min(res, max(0ll, attack - cur) + max(0ll, def - a[1]));
        int low = 1, high = n, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(a[mid] >= def){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(ans != -1){
            cur = sum - a[ans];
            res = min(res, max(0ll, attack - cur));
            if(ans != 1){
                cur = sum - a[ans - 1];
                res = min(res, max(0ll, attack - cur) + max(0ll, def - a[ans - 1]));
            }
        }
        low = 1, high = n, ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(sum - a[mid] >= attack){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if(ans != -1)
            res = min(res, max(0ll, def - a[ans]));
        cout << res << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}