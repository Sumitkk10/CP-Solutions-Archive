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
    if(s.size() == 1){
        cout << "0\n";
        return;
    }
    int ans = 0;
    map<char, int> pos;
    for(int i = 0; i < s.size(); ++i){
        if(pos[s[i]]){
            int pre = pos[s[i]];
            if(pre == i or pre == i - 1){
                ++ans;
                continue;
            }
        }
        pos[s[i]] = i + 1;
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
