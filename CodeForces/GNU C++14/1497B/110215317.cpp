#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
using namespace std;
const int N = 5e3 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    long long int a[n], cnt[k + 1] = {0};
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i] % k]++;
    }
    long long ans = 0;
    for(int i = 0; i < k; ++i){
        if(!cnt[i]) 
            continue;
        if(!i){
            ++ans;
            continue;
        }
        long long find = (k - i) % k;
        long long mn = min(cnt[i], cnt[find]);
        if(mn != 0 and max(cnt[i], cnt[find]) > mn)
            ++mn;
        // cout << i << ' ' << mn << '\n';
        if(mn > 0)
            ++ans;
        cnt[i] = max(0LL, cnt[i] - mn);
        if(find != i)
            cnt[find] = max(0LL, cnt[find] - mn);
        if(cnt[i])
            ans += cnt[i];
    }
    cout << ans << "\n";
}

int main() {
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}