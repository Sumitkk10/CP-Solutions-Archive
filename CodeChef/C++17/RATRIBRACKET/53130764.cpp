#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;

void solve(){
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '{' or s[i] == '[') s[i] = '(';
        else if(s[i] == '}' or s[i] == ']') s[i] = ')';
    }
    int ct = 0;
    for(int i  = 0; i < s.size(); ++i){
        if(s[i] == '(') ++ct;
        else --ct;
        if(ct < 0){
            cout << "NO\n";
            return;
        }
    }
    cout << (ct == 0 ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
