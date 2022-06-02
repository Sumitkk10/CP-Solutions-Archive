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
    	string s, a;
    	cin >> s >>  a;
    	ll ans = 0, ans1 = 0;
    	for(int i = 0; i < s.size(); ++i){
    		if(s[i] == a[i] || s[i] == '?' || a[i] == '?')
    			++ans;
    		if(s[i] != a[i] || s[i] == '?' || a[i] == '?')
    			++ans1;
    	}
    	cout << s.size() - ans << ' ' << ans1 << endl;
    }
    return 0;
}