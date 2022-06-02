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
    long long a[n + 1], suf[n + 2];
    suf[n + 1] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = n; i >= 1; --i)
        suf[i] = suf[i + 1] + a[i];
    while(q--){
        long long len;
        cin >> len;
        int low = 1, high = n, ans = 0;
        while(low <= high){
            int mid = (low + high) / 2;
            if(a[mid] < len){
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        int res = 0;
        low = 0, high = ans;
        while(low <= high){
            int mid = (low + high) / 2;
            long long x = suf[ans + 1 - mid] - suf[ans + 1];
            x = (mid*len) - x;
            if(x <= (ans - mid)){
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << n - ans + res << '\n';
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
