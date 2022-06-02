#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    string s;
    cin >> s;
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll x = s.size();
        // cout << x << ' ';
        if(b > x){
            ll y = b/x;
            b = b - (y*x);
        }
        if(a > x){
            ll y = a/x;
            a = a - (y*x);
        }
        // cout << s[a] << ' ' << s[b] << ' ';
        if(s[a-1] != s[b-1])
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
