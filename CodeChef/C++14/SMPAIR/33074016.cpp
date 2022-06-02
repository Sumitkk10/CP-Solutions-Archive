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
    	vector<ll> a(n);
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	sort(a.begin(), a.end());
    	cout << a[0] + a[1] << endl;
    }
    return 0;
}