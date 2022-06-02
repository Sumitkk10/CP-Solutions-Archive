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
        ll n, s;
        cin >> n >> s;
        ll a[n], b[n], min = 100000000001, min1 = 100000000001;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            if(a[i] < min && b[i] == 0)
                min = a[i];
            if(a[i] < min1 && b[i] == 1)
                min1 = a[i];
        }
        ll ans = 100-s;
        if(min <= ans && min1 <= ans-min) 
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#