#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<string> v(n*3);
    map<string, int> mp;
    for(string &i : v){
        cin >> i;
        int ct;
        cin >> ct;
        mp[i] += ct;
    }
    vector<int> ans;
    for(auto k : mp)
        ans.push_back(k.second);
    sort(ans.begin(), ans.end());
    for(auto k : ans) cout << k << ' ';
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
