#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool isprime(ll n){
    ll ans;
    for(int i = 2; i <= sqrt(n); ++i){
        ans = n/i;
        if(n%i == 0 || n%ans == 0)  
            return false;
    }
    return true;
}
 
int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n == 1)
            cout << 1 << '\n' << 1 << ' ' << 1 << '\n';
        else if(n == 2)
            cout << 1 << '\n' << 2 << ' ' << 1 << ' ' << 2 << '\n';
        else if(n == 3)
            cout << 1 << '\n' << 3 << ' ' << 1 << ' ' << 2 << ' ' << 3 << '\n';
        else{
            cout << n/2 << '\n';
            for(int i = 1; i <= n; ++i){
                if(i == 1){
                    cout << 3 << ' ' << 1 << ' ' << 2 << ' ' << 3 << '\n';
                    i += 2;
                }
                else{
                    if(i != n){
                        cout << 2 << ' ' << i << ' ' << i+1 << '\n';
                        i++;
                    }
                    else
                       cout << 1 << ' ' << i << '\n'; 
                }
            }
        }
    }
    return 0;
}
//                                     #!!{*[$um1t_Kum@r]*}!!#