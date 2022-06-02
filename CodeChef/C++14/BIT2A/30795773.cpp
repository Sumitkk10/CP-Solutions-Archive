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
        ll a[n], sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i==j) continue;
                else{
                    if(a[i] < a[j]){
                        sum ++;
                    }
                }
            }
            cout << sum << ' ';
            sum = 0;
        }
        cout << '\n';
    }
    return 0;
}