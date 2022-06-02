#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;
map<string, int> mp;

int main(){
    fast;
    ll n, m, ans = 0;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    cin >> m;
    string a;
    cin >> a;
    string h = a;
    vector<string> v;
    for(int i = 0; i < m; ++i){
        h = a[i];
        for(int j = i; j < m; ++j){
            if(i != j)
                h += a[j];
            mp[h]++;
            if(mp[h] == 1) v.pb(h);
        } 
    }
    for(int i = 0; i < v.size(); ++i){
        // cout << v[i] << " ";
        for(int k = 0; k < n; ++k){
            if(v[i] == s[k]){
                ++ans;
                break;
            }
        }
    }
    cout << ans;
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}