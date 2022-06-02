#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	string s[6];
	map<string, int> mp;
	for(int i = 0; i < 6; ++i){ 
		getline(cin, s[i]);
		mp[s[i]]++;
	}
	ld ans = 0;
	for(auto i : mp){
		string a = i.first;
		if(a.find("ACov") != string::npos || a.find("(A)") != string::npos){
			if(a.find("(A)") != string::npos) ans += 0.5;
			if(a.find("ACov") != string::npos)	ans += 0.5;
		} 
		else if(a.find("BCov") != string::npos || a.find("(B)") != string::npos){
			if(a.find("BCov") != string::npos) ans += 0.5;
			if(a.find("(B)") != string::npos) ans += 0.5;
		} 
		else if(a.find("CCov") != string::npos || a.find("(C)") != string::npos){
			if(a.find("CCov") != string::npos) ans += 0.5;
			if(a.find("(C)") != string::npos) ans += 0.5;
		} 
		else if(a.find("DCov") != string::npos || a.find("(D)") != string::npos){
			if(a.find("DCov") != string::npos) ans += 0.5;
			if(a.find("(D)") != string::npos) ans += 0.5;
		} 
		else if(a.find("ECov") != string::npos|| a.find("(E)") != string::npos){
			if(a.find("ECov") != string::npos) ans += 0.5;
			if(a.find("(E)") != string::npos) ans += 0.5;
		} 
		else if(a.find("FCov") != string::npos || a.find("(F)") != string::npos){
			if(a.find("FCov") != string::npos) ans += 0.5;
			if(a.find("(F)") != string::npos) ans += 0.5;
		}
	}
	cout << ans << " out of 6";
	cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
	return 0;
}
