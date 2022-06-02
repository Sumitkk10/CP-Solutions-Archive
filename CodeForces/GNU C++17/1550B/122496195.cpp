#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    if(b >= 0)
        cout << s.size()*a + s.size()*b << '\n';
    else{
        long long int ct = 0, ct1 = 0;
        for(int i = 0; i < n; ++i){
            ct += (s[i] == '0');
            ct1 += (s[i] == '1');
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') continue;
            char x = s[i];
            int ok = 0;
            while(s[i] == x and i < n){
                ++i;
                ++ok;
            }
            ans += a*ok + b;
        }
        long long ans1 = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '1') continue;
            char x = s[i];
            int ok = 0;
            while(s[i] == x and i < n){
                ++i;
                ++ok;
            }
            ans1 += a*ok + b;
        }
        cout << max(ct*a + ans + b, ct1*a + ans1 + b) << '\n';
    }
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
