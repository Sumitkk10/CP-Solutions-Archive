#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string s, t;
    cin >> s >> t;
    if(t.size() > s.size()){
        cout << "NO\n";
        return;
    }
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    int j = 0;
    for(int i = 0; i < s.size(); ++i){
        if(j < t.size() and s[i] == t[j])
            ++j;
        else
            ++i;
    }
    cout << (j == t.size() ? "YES\n" : "NO\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
