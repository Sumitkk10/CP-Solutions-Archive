#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    long long int ans = INT_MAX;
    int a1 = -1, b1 = -1, c1 = -1;
    for(int i = 1; i <= 2*a; ++i){
        for(int j = i; j <= 2*b; j += i){
            for(int mul = 0; mul < 2; ++mul){
                int ok = j * (c / j) + j * mul;
                int okk = abs(i - a) + abs(j - b) + abs(ok - c);
                if(okk < ans){
                    ans = okk;
                    a1 = i;
                    b1 = j;
                    c1 = ok;
                }
            }
        }
    }
    cout << ans << '\n' << a1 << ' ' << b1 << ' ' << c1 << '\n';
}

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
