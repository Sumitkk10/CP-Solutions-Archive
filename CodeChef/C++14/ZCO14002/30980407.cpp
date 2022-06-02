#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    fast;
    ll n;
    cin >> n;
    ll a[n], b[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i = 3; i < n; ++i){
        b[i] += min(b[i-1], min(b[i-2], b[i-3]));
    }
    cout << min(b[n-1], min(b[n-2], b[n-3]));
    return 0;
}