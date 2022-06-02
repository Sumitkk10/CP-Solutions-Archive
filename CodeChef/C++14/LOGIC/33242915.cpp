#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 9; 

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2 == 0){
            ll k = n/2;
            cout << n*k << '\n';
        }
        else{
            ll g = n/2 + 1;
            cout << n * g << '\n';
        }
    }
    return 0;
}