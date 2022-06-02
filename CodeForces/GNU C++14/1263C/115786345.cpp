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
    if(floor(n/floor(sqrt(n))) == floor(sqrt(n))) cout << (2 * floor(sqrt(n))) << '\n';
    else cout << (2 * floor(sqrt(n))) + 1 << '\n';
    set<int> s;
    s.insert(0);
    for(int i = 1; i <= floor(sqrt(n)); ++i){
        s.insert(n/i);
        s.insert(i);
    }
    for(auto k : s)
        cout << k << ' ';
    cout << '\n';
}

int main(){
    fast;
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
