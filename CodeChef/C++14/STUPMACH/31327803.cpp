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
        ll n;
        cin >> n;
        ll a[n], b[n], sum = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        b[0] = a[0];
        for(int i = 1; i < n; ++i){
            if(a[i] < b[i-1])
                b[i] = a[i];
            else
                b[i] = b[i-1];
        }
        for(int i = 0; i < n; ++i){
            sum += b[i];
        }
        cout << sum << '\n';
    }
    return 0;
}