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
    vector<pair<int, int> > l, r; 
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        l.push_back({x, i});
        r.push_back({y, i});
    }
    int ans[n];
    sort(l.begin(), l.end());
    sort(r.rbegin(), r.rend());
    for(int i = 0; i < n; ++i)
        ans[l[i].second] = (n - i - 1);
    for(int i = 0; i < n; ++i)
        ans[r[i].second] += (n - i - 1);
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
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
