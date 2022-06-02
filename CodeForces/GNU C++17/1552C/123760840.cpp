#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i = (n - k) - 1; i >= 1; --i)
        ans += i;
    bool vis[2*n + 2];
    memset(vis, 0, sizeof vis);
    vector<pair<int, int> > v;
    for(int i = 1; i <= k; ++i){
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.push_back({x, y});
        vis[x] = vis[y] = true;
    }
    for(int i = 0; i < v.size(); ++i){
        int x = v[i].first, y = v[i].second;
        for(int j = i + 1; j < v.size(); ++j){
            if(i == j) continue;
            int a = v[j].first, b = v[j].second;
            if(x < a and x < b and y > a and y < b){
                ++ans;
                // cout << x << " " << y << " " << a << " " << b << endl;
            }
            else if(x > a and x < b and ((y > b and y > a) or (y < a and y < b))){
                ++ans;
                // cout << x << " " << y << " " << a << " " << b << endl;
            }
            else if(((x > b and x > a) or (x < a and x < b)) and y > a and y < b){
                ++ans;
                // cout << x << " " << y << " " <<  a << " " << b << endl;
            }
        }
        int ct = 0, ct1 = 0;
        for(int j = x; j <= y; ++j){
            if(vis[j]) continue;
            ++ct;
        }
        for(int j = x; j >= 1; --j){
            if(vis[j]) continue;
            ++ct1;
        }
        for(int j = 2*n; j >= y; --j){
            if(vis[j]) continue;
            ++ct1;
        }
        ans += min(ct, ct1);
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
