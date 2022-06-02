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
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    while(k--){
        vector<int> cur;
        cur.push_back(a[n - 1]);
        for(int i = 0; i < n - 1; ++i)
            cur.push_back(a[i]);
        a = cur;
    }
    for(auto k : a)
        cout << k << ' ';
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