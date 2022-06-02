#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> v;
    string pre, cur;
    for(int i = 0; i < s.size(); ++i){
        pre.push_back(s[i]);
        cur = pre; 
        while(cur.size() < k)
            cur += cur;
        while(cur.size() > k)
            cur.pop_back();
        v.push_back(cur);
    }
    sort(v.begin(), v.end());
    cout << v[0] << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
