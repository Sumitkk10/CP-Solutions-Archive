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
    string s;
    cin >> s;
    for(int l = 0; l < s.size(); ++l){
        for(int r = l + 1; r < s.size(); ++r){
            int cnt = 0, cnt1 = 0;
            for(int j = l; j <= r; ++j){
                if(s[j] == 'a') ++cnt;
                else ++cnt1;
            }
            if(cnt == cnt1){
                cout << l + 1 << ' ' << r + 1 << '\n';
                return;
            }
        }
    }
    cout << "-1 -1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
