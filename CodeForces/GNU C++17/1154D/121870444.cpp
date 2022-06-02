#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int mx_a = a, mx_b = b;
    int s[n], ct = 0;
    for(int i = 0; i < n; ++i)
        cin >> s[i];
    for(int i = 0; i < n; ++i){
        if(a <= 0 and b <= 0) break;
        if(s[i] == 1 and b < mx_b){
            if(a > 0){
                --a;
                ++b;
            }
            else
                --b;
        }
        else if(s[i] == 1){
            if(b > 0)
                --b;
            else{
                --a;
                ++b;
            }
        }
        else{
            if(b > 0)
                --b;
            else
                --a;
        }
        ++ct;
        a = min(a, mx_a);
        b = min(b, mx_b);
    }
    cout << ct << '\n';
}

int main(){
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}
