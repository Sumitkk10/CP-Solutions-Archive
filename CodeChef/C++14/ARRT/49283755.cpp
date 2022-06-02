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
    ll a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    int mn = INT_MAX;
    for(int i = 1; i <= n; ++i)
        if(((a[1] + b[i]) % n) < mn)
            mn = (a[1] + b[i]) % n;
    vector<int> tr;
    for(int i = 1; i <= n; ++i){
        if(((a[1] + b[i]) % n) == mn)
            tr.push_back(i);
    }
    vector<vector<int> > comp;
    for(int i = 0; i < tr.size(); ++i){
        int x = tr[i], p = 1;
        vector<int> cur;
        for(int j = x; j <= n; ++j){
            cur.push_back((a[p] + b[j]) % n);
            ++p;
        }
        for(int j = 1; j <= n - (n - x + 1); ++j){
            cur.push_back((a[p] + b[j]) % n);
            ++p;
        }
        comp.push_back(cur);
    }
    sort(comp.begin(), comp.end());
    for(auto k : comp[0])
        cout << k << " ";
    cout << "\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
