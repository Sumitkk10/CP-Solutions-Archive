#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s;
    cin >> s;
    vector<int> v;
    map<int, int> mp;
    int pos = 0;
    for(int i = 0; i < s.size(); ++i){
        v.push_back(s[i] - 'a');
        mp[s[i] - 'a']++;
        if(s[i] == 'a')
            pos = i;
    }
    if(s.size() == 1){
        if(s[0] == 'a') cout << "YES\n";
        else cout << "NO\n";
        return;
    }
    int ct = 1;
    for(int i = 0; i < 26; ++i){
        if(ct == 0 and mp[i]){
            cout << "NO\n";
            return;
        }
        if(!mp[i]) ct = 0;
        if(mp[i] > 1){
            cout << "NO\n";
            return;
        }
    }
    int x = pos + 1;
    while(x < v.size()){
        if(s[x] < s[x - 1]){
            cout << "NO\n";
            return;
        }
        ++x;
    }
    x = pos - 1;
    while(x >= 0){
        if(s[x] < s[x + 1]){
            cout << "NO\n";
            return;
        }
        --x;
    }
    cout << "YES\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
