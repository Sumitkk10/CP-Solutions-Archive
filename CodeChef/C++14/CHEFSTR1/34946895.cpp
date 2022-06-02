#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9+ 7; 

int main() 
{ 
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll a[n], sum = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n -1; ++i)
            sum += abs(a[i] - a[i+1]) - 1;
        cout << sum << "\n";
    }
    return 0; 
} 
