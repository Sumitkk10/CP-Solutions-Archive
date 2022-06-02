#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    // !@#$%^&*()-+
    bool num = 0, upper = 0, lower = 0, special = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' and s[i] <= '9') num = 1;
        if(s[i] >= 'A' and s[i] <= 'Z') upper = true;
        if(s[i] >= 'a' and s[i] <= 'z') lower = true;
        if(s[i] == '!' or s[i] == '@' or s[i] == '#' or s[i] == '$' or s[i] == '%' or s[i] == '^' or s[i] == '&' or s[i] == '*' or s[i] == '(' or s[i] == ')' or s[i] == '-' or s[i] == '+') special = true;
    }
    int len = 0;
    len += (num == 0);
    len += (upper == 0);
    len += (lower == 0);
    len += (special == 0);
    cout << len + max(0, 6 - n - len) << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
    // you should actually read the stuff at the bottom
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * Read other problems if stuck on this one.
*/
