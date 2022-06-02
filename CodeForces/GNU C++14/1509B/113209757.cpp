#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;

int main(){
	fast;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ok = 0;
		for(auto k : s)
			if(k == 'T')
				++ok;
		if(ok != (n / 3)*2){
			cout << "NO\n";
			continue;
		}
		ok = 0;
		bool wot = false;
		int okk = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] == 'T') 
				++ok;
			else{
				okk++;
				if(ok < okk){
					cout << "NO\n";
					wot = true;
					break;
				}
			}
		}
		if(wot) continue;
		ok = okk = 0;
		for(int i = n - 1; i >= 0; --i){
			if(s[i] == 'T') 
				++ok;
			else{
				okk++;
				if(ok < okk){
					cout << "NO\n";
					wot = 1;
					break;
				}
			}
		}
		if(wot) continue;
		cout << "YES\n";
	}
	return 0;
}
