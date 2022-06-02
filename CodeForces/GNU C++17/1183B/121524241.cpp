#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k, a[N];

bool check(int mid){
    for(int i = 1; i <= n; ++i){
        if(abs(mid - a[i]) > k)
            return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    vector<pair<int, int> > v;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        v.push_back({max(1, a[i] - k), a[i] + k});
    }
    sort(v.begin(), v.end());
    long long int ans = v[0].second, pre = 0;
    for(int i = 1; i < n; ++i){
        if(v[i].second >= ans and v[i].first <= ans) continue;
        else if(v[i].second < ans and v[i].first > v[pre].first){
            ans = v[i].second;
            pre = i;
            continue;
        }
        else{
            cout << "-1\n";
            return;
        }
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
