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
    vector<int> a(n);
    for(auto &val : a)
        cin >> val;
    long long ans = 0;
    map<int, int> mp;
    for(int i = 0; i < n; ++i)
        mp[a[i]] = i + 1; 
    for(int i = 1; i <= 2*n; ++i){
        for(int j = 1; j*j <= i; ++j){
            if(i % j == 0){
                int x = j, y = i/j;
                if(x == y) continue;
                if(!mp[x] or !mp[y]) continue;
                if(mp[x] + mp[y] == i)
                    ++ans;
            }
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
