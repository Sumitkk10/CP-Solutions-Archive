#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    long long int a, b;
    cin >> a >> b;
    long long pro = a * b;
    if(b == 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << a << ' ' << pro << ' ' << a * (b + 1) << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}