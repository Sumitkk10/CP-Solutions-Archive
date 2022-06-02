#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c, d, e = 0;
        cin >> a >> b >> c >> d;
        if(a != b && a != c && a != d){
            cout << "NO\n";
            ++e;
        }
        else if(b != a && b != c && b != d){
            cout << "NO\n";
            ++e;
        }
        else if(c != a && c != b && c != d){
            cout << "NO\n";
            ++e;
        }
        else if(d != a && d != c && d != b){
            cout << "NO\n";
            ++e;
        }
        if(e == 0)
            cout << "YES\n";
    }
    return 0;
}
