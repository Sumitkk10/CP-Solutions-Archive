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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll x = abs(d-(a + c));
        cout << x << ' ';
        ll y = abs(d-(x+(a-x)+b));
        cout << y << ' ';
        cout << abs(d-(x+y)) << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!