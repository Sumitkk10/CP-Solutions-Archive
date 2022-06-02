#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, ans = INT_MAX;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < 26; ++i){
        char cur = 'a' + i;
        int l = 0, r = s.size() - 1, del = 0;
        while(l <= r){
            if(s[l] != s[r]){
                if(s[l] == cur){
                    ++del;
                    ++l;
                    continue;
                }
                else if(s[r] == cur){
                    ++del;
                    --r;
                    continue;
                }
                del = -1;
                break;
            }
            else{
                ++l;
                --r;
            }
        }
        if(del != -1)
            ans = min(ans, del);
    }
    cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}