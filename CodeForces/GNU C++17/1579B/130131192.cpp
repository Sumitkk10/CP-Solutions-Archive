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
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<pair<int, int> > ans;
    for(int i = 1; i <= n; ++i){
        int pos = 0;
        int mn = INT_MAX;
        for(int j = i; j <= n; ++j){
            if(a[j] < mn){
                mn = a[j];
                pos = j;
            }
        }
        if(i == pos) continue;
        ans.push_back({i, pos});
        int x = a[pos];
        for(int j = pos; j >= i + 1; --j)
            a[j] = a[j - 1];
        a[i] = x;
    }
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k.first << ' ' << k.second << ' ' << k.second - k.first << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
