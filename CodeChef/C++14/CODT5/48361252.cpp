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
    int a[n + 1];
    multiset<int> s;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    s.insert(a[1]);
    for(int i = 2; i <= n; ++i){
        auto fnd = s.upper_bound(a[i]);
        if(fnd != s.end())
            s.erase(fnd);
        s.insert(a[i]);
    }
    cout << s.size() << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}