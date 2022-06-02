#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 3;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ld a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        ld k = (a[2] * a[2]);
        k += ((a[0] + a[1]) * (a[0] + a[1]));
        k = sqrt(k);
        cout << (int) ceil(k) << "\n";
    }
    return 0;
}