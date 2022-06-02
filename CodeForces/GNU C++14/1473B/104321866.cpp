#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    string a, b;
    cin >> a >> b;
    string pre = a, pre1 = b;
    long long int lcm = ((a.size() * b.size()) / __gcd(a.size(), b.size()));
    long long int lcm1 = lcm;
    lcm = lcm / a.size();
    lcm -= 1;
    while(lcm--)
        a += pre;
    lcm1 = lcm1 / b.size();
    lcm1 -= 1;
    while(lcm1--)
        b += pre1;
    if(a == b)
        cout << a << '\n';
    else
        cout << "-1\n";
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();    
    return 0;
}
