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
        ll n, m;
        cin >> n >> m;
        cout << (n-1) * (m-1) << '\n';
    }
    return 0;
}