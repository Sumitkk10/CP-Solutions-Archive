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
    int i = s.size() - 1;
    int cnt = 0;
    while(s[i] == ')' and i >= 0){
        --i;
        ++cnt;
    }
    cout << ((cnt > (s.size() - cnt)) ? "Yes\n" : "No\n");
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
