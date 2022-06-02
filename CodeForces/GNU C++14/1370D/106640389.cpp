#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;
const int N = 2e5 + 2;
int n, k, a[N];

bool possible(int mid){
    bool ok = 0;
    int ct = 0;
    for(int i = 0; i < n; ++i){
        if(ok){
            if(a[i] <= mid) {
                ++ct;
                ok = 0;
            }
        }
        else{
            ++ct;
            ok = 1;
        }
    }
    if(ct >= k)
        return true;
    ok = 1, ct = 0;
    for(int i = 0; i < n; ++i){
        if(ok){
            if(a[i] <= mid){
                ++ct;
                ok = 0;
            }
        }
        else{
            ok = 1;
            ++ct;
        }
    }
    return (ct >= k);
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    long long int low = 0, high = 1e9 + 5, ans;
    while(low <= high){
        long long mid = (low + high) / 2;
        if(possible(mid)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}