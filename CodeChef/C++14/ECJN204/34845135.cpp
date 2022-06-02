#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vii vector<ll> 
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int MOD = 1e9 + 7, N = 2e5 + 3;

int main(){
    fast;
    ll t;
    cin >> t;
    while(t--){
    	ll n, sum = 0, sum1 = 0, sum2 = 0;
    	cin >> n;
    	for(int i = 0; i < n; ++i){
    		char a, b, c;
    		cin >> a >> b >> c;
    		// cout << a << " " << b << " " << c << "\n";
    		ll hash[200] = {0};
    		hash[a]++;
    		hash[b]++;
    		hash[c]++;
    		if(a == 'R'){
    			sum += hash['S'];
    			sum -= hash['P'];
    		}
    		else if(a == 'P'){
    			sum += hash['R'];
    			sum -= hash['S'];
    		}
    		else if(a == 'S'){
    			sum += hash['P'];
    			sum -= hash['R'];
    		}
    		if(b == 'R'){
    			sum1 += hash['S'];
    			sum1 -= hash['P'];
    		}
    		else if(b == 'P'){
    			sum1 += hash['R'];
    			sum1 -= hash['S'];
    		}
    		else if(b == 'S'){
    			sum1 += hash['P'];
    			sum1 -= hash['R'];
    		}
    		if(c == 'R'){
    			sum2 += hash['S'];
    			sum2 -= hash['P'];
    		}
    		else if(c == 'P'){
    			sum2 += hash['R'];
    			sum2 -= hash['S'];
    		}
    		else if(c == 'S'){
    			sum2 += hash['P'];
    			sum2 -= hash['R'];
    		}
    	}
    	cout << sum << " " << sum1 << " " << sum2 << "\n";
    }
    return 0;
}