#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pre[n + 1], pre1[n + 1];
    pre[0] = pre1[0] = 0;
    map<pair<int, int>, int> mp;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1];
        pre1[i] = pre1[i - 1];
        if(s[i - 1] == 'D') pre[i] += 1;
        else pre1[i] += 1;
        int cur = pre[i], cur1 = pre1[i];
        if(__gcd(cur, cur1) != 1){
            int x = __gcd(cur, cur1);
            cur /= x;
            cur1 /= x;
        }
        mp[{cur, cur1}]++;
        cout << mp[{cur, cur1}] << ' ';
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}