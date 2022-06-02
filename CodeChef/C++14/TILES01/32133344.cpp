#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll MOD = 15746;

int main(){
    fast;
    ll n;
    cin >> n;
    ll pos[n+1];
    pos[1] = 1;
    pos[2] = 2;
    for(int i = 3; i <= n; ++i)
        pos[i] = ((pos[i-1]%MOD)+(pos[i-2]%MOD))%MOD;
    cout << pos[n];
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
