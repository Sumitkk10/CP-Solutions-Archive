#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    if(a.second > b.second)
        return true;
    return false;
}

void solve(){
    long long n;
    cin >> n;
    pair<long long, long long> a[n];
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }
    sort(a, a + n, cmp);
    long long int ans = 0, pre = n - 1, cur = 0, i = 0;
    while(pre >= i){
        if(pre == i){
            if(cur >= a[i].second){
                ans += a[i].first;
                break;
            }
            long long req = min(a[i].first, a[i].second - cur);
            ans += 2*req;
            a[i].first -= req;
            ans += a[i].first;
            break;
        }
        if(cur + a[i].first < a[pre].second){
            long long req = min(a[i].first, a[i].second - cur);
            ans += 2*req;
            cur += req;
            a[i].first -= req;
            ans += a[i].first;
            cur += a[i].first;
            ++i;
            // cout << ans << ' ' << cur << '\n';
            continue;
        }
        long long req = max(0LL, a[pre].second - cur);
        ans += (2*req);
        cur += req;
        ans += (a[pre].first);
        cur += a[pre].first;
        a[i].first -= req;
        a[i].first = max(0LL, a[i].first);
        a[pre].first = 0;
        if(a[i].first == 0) ++i;
        pre--;
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
