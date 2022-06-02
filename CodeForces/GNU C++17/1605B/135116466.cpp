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
    string t = s;
    sort(t.begin(), t.end());
    if(t == s){
        cout << "0\n";
        return;
    }
    vector<int> pos;
    int cnt1 = 0, cnt0 = 0;
    for(int i = 0; i < s.size(); ++i){
        cnt1 += s[i] == '1';
        cnt0 += s[i] == '0';
    }
    for(int i = 0; i < cnt0; ++i)
        if(s[i] == '1') pos.push_back(i + 1);
    for(int i = cnt0; i < n; ++i)
        if(s[i] == '0') pos.push_back(i + 1);
    cout << "1\n";
    cout << pos.size() << ' ';
    for(auto k : pos) cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
