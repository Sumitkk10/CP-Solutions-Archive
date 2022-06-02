#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll l, b;
        cin >> l >> b;
        cout << __gcd(l, b) << '\n';
    }
    return 0;
}
//                              This_Code_Is_Written_By_Sumit!!