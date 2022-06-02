#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;
vector<pair<int, int> > v;

bool check(ll mid){
    ll cur = mid;
    for(int i = 0; i < v.size(); ++i){
        if(v[i].first >= cur)
            return false;
        cur += v[i].second;
    }
    return true;
}

void solve(){
    cin >> n;
    v.clear();
    for(int i = 0; i < n; ++i){
        int k, ct = 0, mx = 0;
        cin >> k;
        int kk = k;
        while(k--){
            int x;
            cin >> x;
            mx = max(mx, x - ct);
            ++ct;
        }
        v.push_back({mx,kk});
    }
    sort(v.begin(), v.end());
    ll low = 0, high = 1e12, ans;
    while(low <= high){
        ll mid = (low + (high - low)/2);
        if(check(mid)){
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << ans << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
