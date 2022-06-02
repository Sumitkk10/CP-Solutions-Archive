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
    int a[n + 1];
    map<int, int> deg, mp;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        // i wants to make gift for a[i];
        deg[a[i]]++;
        mp[i] = a[i];
    }
    vector<pair<int, int> > v;
    for(int i = 1; i <= n; ++i)
        v.push_back({deg[i], i});
    sort(v.begin(), v.end());
    vector<int> ans(n + 1, -1), vis(n + 1, 0);
    int res = 0;
    for(int i = 0; i < n; ++i){
        int node = v[i].second;
        int dest = mp[node];
        if(vis[dest]) continue;
        ++res;
        vis[dest] = true;
        ans[node] = dest;
    }
    cout << res << '\n';
    vector<int> temp;
    for(int i = 1; i <= n; ++i)
        if(vis[i] == 0)
            temp.push_back(i);
    reverse(temp.begin(), temp.end());
    int j = 0;
    for(int i = 1; i <= n; ++i){
        if(ans[i] != -1){
            cout << ans[i] << ' ';
            continue;
        }
        if(temp[j] == i){
            swap(temp[j], temp[j + 1]);
            cout << temp[j] << ' ';
            ++j;
            continue;
        }
        cout << temp[j] << ' ';
        ++j;
    }
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
