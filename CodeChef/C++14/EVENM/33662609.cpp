#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
const int MOD = 1000000007;

bool pow(ll n){ 
   if(n == 0) 
        return false; 
   return (ceil(log2(n)) == floor(log2(n))); 
} 

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n][n], k = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i%2 == 0){
                    a[i][j] = k;
                    ++k;
                }
                else{
                    a[i][j] = k;
                    --k;
                }
            }
            if(i%2 == 0)
                --k;
            else
                ++k;
            k += n;
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}