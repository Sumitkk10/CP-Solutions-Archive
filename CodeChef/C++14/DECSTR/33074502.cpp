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
    	char s[n+100];
    	ll k = 'a';
    	for(int i = 0; i < n + 1; ++i){
    		s[i] = k;
    		if(k != 'z')
    			++k;
    		else{
    			k = 'a';
    			if(i != n)
    				++n;
    		}
    	}
    	for(int i = n; i >= 0; --i)
    		cout << s[i];
    	cout << endl;
    }
    return 0;
}