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
    int a[n + 1], b[n + 1], mx[n + 1], mxx[n + 1];
    mxx[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        mxx[i] = max(mxx[i - 1], a[i]);
    }
    mx[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
        mx[i] = max(mx[i - 1], b[i]);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; ++i){
        // i want to make this element come at the first;
        int low = 1, high = n, res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mx[mid] > a[i]){
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(res == -1) continue;
        ans = min(ans, i + res - 2);
    }
    for(int i = 1; i <= n; ++i){
        // i want to make this element come at the first;
        int low = 1, high = n, res = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mxx[mid] < b[i]){
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(res == -1) continue;
        ans = min(ans, i + res - 2);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
