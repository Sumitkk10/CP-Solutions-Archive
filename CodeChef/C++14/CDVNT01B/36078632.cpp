#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e4 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s; cin >> s;
        map<char, int> mp;
        pair<char, pair<int, int> > size[27];
        for(int i = 0; i < 27; ++i){ 
            size[i].first = (char) 'a' + i;
            size[i].second.first = -1;
            size[i].second.second = -1;
        }
        for(int i = 0; i < n; ++i){
            mp[s[i]]++;
            if(mp[s[i]] == 1) size[s[i]].second.first = i;
            size[s[i]].second.second = i;
        }
        int mx = 0, mn = 1e8, mnn = 1e8;
        for(auto i : mp)
            mx = max(mx, i.second);
        for(auto i : mp){
            if(i.second == mx){
                int k = size[i.first].second.second - size[i.first].second.first + 1;
                mn = min(mn, k);
            }
        }
        for(auto i : mp){
            if(i.second == mx){
                int k = size[i.first].second.second - size[i.first].second.first + 1;
                if(k == mn)
                    mnn = min(mnn, i.first - 'a');
            }
        }
        char x = (char) mnn + 'a';
        cout << x << " " << mn << "\n";
    }
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}