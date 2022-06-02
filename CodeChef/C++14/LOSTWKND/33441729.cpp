#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll a[5], b[5];
        for(int i = 0; i < 5; ++i){
            cin >> a[i];
        }
        ll p, sum = 0;
        cin >> p;
        for(int i = 0; i < 5; ++i){
            b[i] = a[i]*p;
            sum += b[i];
        }
        if(sum <= (5*24))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}