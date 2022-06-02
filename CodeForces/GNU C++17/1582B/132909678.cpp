#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
long long n, zero, ones;

void solve(){
    cin >> n;
    zero = 0;
    ones = 0;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        zero += (x == 0);
        ones += (x == 1);
    }
    long long k = pow(2, zero);
    cout << k * ones << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
