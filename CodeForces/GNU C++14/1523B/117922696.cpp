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
    vector<pair<long long, pair<long long int, long long int> > > ans; 
    for(int i = n; i >= 1; i -= 2){
        long long x = -a[i], x1 = -a[i - 1];
        while(true){
            if(ans.size() > 5000) break;
            a[i] -= a[i - 1];
            ans.push_back({2, {i - 1, i}});
            a[i - 1] += a[i];
            ans.push_back({1, {i - 1, i}});
            if(a[i] == x and a[i - 1] == x1) break;
        }
    }
    cout << ans.size() << '\n';
    for(auto k : ans)
        cout << k.first << ' ' << k.second.first << ' ' << k.second.second << '\n';
    // for(int i = 1; i <= n; ++i)
        // cout << a[i] << ' ';
    // cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve(); 
    return 0;
}
