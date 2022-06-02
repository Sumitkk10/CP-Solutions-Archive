#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int idx = -1, low = i + 1, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(abs(a[mid] - a[i]) >= k){
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        if(idx != -1)
            ans += (n - idx);
    }
    cout << ans << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}