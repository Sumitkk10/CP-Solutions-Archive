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
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> v;
    for(auto k : mp)
        v.push_back(k.second);
    sort(v.rbegin(), v.rend());
    int ans = v[0], ct = v[0];
    for(int i = 1; i < v.size(); ++i){
        if(ct <= 0) break;
        if(v[i] >= ct){
            ans += ct - 1;
            ct--;
        }
        else{
            ans += v[i];
            ct = v[i];
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
