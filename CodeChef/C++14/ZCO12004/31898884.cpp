#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
 
int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ll king[n], knight[n];
    king[0] = a[0];
    king[1] = a[0]+a[1];
    knight[0] = a[0];
    knight[1] = a[1];
    for(int i = 2; i < n; ++i){
        king[i] = a[i] + min(king[i-1], king[i-2]);
        knight[i] = a[i] + min(knight[i-1], knight[i-2]);
    } 
    cout << min(min(king[n-1], king[n-2]), knight[n-1]);
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#