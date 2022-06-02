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
        ll a, b, n;
        cin >> a >> b >> n;
        if(n%2 == 0){
            a = abs(a);
            b = abs(b);
        }
        if(a > b)
            cout << 1 << '\n';
        else if(a == b)
            cout << 0 << '\n';
        else
            cout << 2 << '\n';
    }
    return 0;
}
