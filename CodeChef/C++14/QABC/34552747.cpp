#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 205;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
    	ll a[n], b[n];
    	for(int i = 0; i < n; ++i)
    		cin >> a[i];
    	for(int i = 0; i < n; ++i)
    		cin >> b[i];
    	int d = 0;
    	for(int i = 0; i < n; ++i){
    		if(a[i] > b[i]){
    			cout << "NIE\n";
    			++d;
    			break;
    		}
    	}
    	if(d == 0){
    		for(int i = 0; i < n-2; ++i){
    			if(a[i] < b[i]){
    				ll k = b[i] - a[i];
    				a[i] = b[i];
    				a[i+1] += (2*k);
    				a[i+2] += (3*k);
    			}
    		}
    		for(int i = 0; i < n; ++i){
    			if(a[i] != b[i]){
    				cout << "NIE\n";
    				++d;
    				break;
    			}
    		}
    		if(d == 0)
    			cout << "TAK\n";
    	}
    }
    return 0;
}