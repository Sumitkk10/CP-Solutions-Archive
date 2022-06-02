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
    vector<long long int> a;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<long long> ans(n);
    long long mn = INT_MAX, idx;
    bool ok = 0, vis[n];
    memset(vis, 0, sizeof vis);
    for(int i = 1; i < n; ++i){
        if(a[i] == a[i - 1]){
            ans[0] = a[i];
            ans[n - 1] = a[i];
            idx = i;
            break;
        }
        else{
            if(a[i] - a[i - 1] < mn){
                mn = a[i] - a[i - 1];
                idx = i;
                ans[0] = a[i - 1];
                ans[n - 1] = a[i];
            }
        }
    }
    vis[idx] = vis[idx - 1] = true;
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        if(a[i] >= ans[0]){
            idx = i;
            ok = 1;
            break;
        }
    }
    if(!ok) idx = n;
    int ct = 1;
    for(int i = idx; i < n; ++i){
        if(vis[i]) continue;
        ans[ct] = a[i];
        vis[i] = true;
        ++ct;
    }
    for(int i = 0; i < n; ++i){
        if(vis[i]) continue;
        ans[ct] = a[i];
        ++ct;
        vis[i] = true;
    }

    for(auto k : ans) 
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
