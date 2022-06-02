#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int N = 402;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a = n/2;
        ll ans =  a/2;
        a = ans + a%2;
        cout << a*ans << endl;
        
    }
    return 0;
}