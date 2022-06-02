#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1e9 + 7;
const long long int N = 1e6 + 5;


void solve(){
    int a, b;
    cin >> a >> b;
    if(a > b){
        cout << a - b << '\n';
        return;
    }
    cout << (b - a + 1) / 2 + ((abs(a) % 2) != (abs(b) % 2) ? 1 : 0) << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}