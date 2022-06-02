#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MOD = 15746;
const int N = 1e6 + 5;
bool vis[N];

int main(){
    fast;
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> ans[1005];
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i]) continue;
        ans[cnt].push_back(i);
        int j = i;
        vis[j] = true;
        while(a[j] != i) {
            j = a[j];
            vis[j] = true;
            ans[cnt].push_back(j);
        }
        vis[a[j]] = true;
        ans[cnt].push_back(a[j]);
        ++cnt;
    }
    cout << cnt << '\n';
    for(int i = 0; i < cnt; ++i) {
        for (auto k : ans[i])
            cout << k << ' ';
        cout << '\n';
    }
    return 0;
}