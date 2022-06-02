#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n, n1, n2;
    cin >> n >> n1 >> n2;
    ll a[n], b[n1], c[n2], hash[1500005] = {0}, cnt = 0; 
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        hash[a[i]]++;
    }
    for(int i = 0; i < n1; ++i){
        cin >> b[i];
        hash[b[i]]++;
    }
    for(int i = 0; i < n2; ++i){
        cin >> c[i];
        hash[c[i]]++;
    }
    for(int i = 0; i < 1500005; ++i){
        if(hash[i] > 1)
            ++cnt;
    }
    cout << cnt << '\n';
    for(int i = 0; i < 1500005; ++i){
        if(hash[i] > 1)
            cout << i << '\n';
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#
