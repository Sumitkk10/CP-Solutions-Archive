#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool isvowel(char s){
	if(s == 'A' || s == 'I' || s == 'E' || s == 'O' || s == 'U')
		return true;
	return false;
}

int main(){
	fast;
	string s;
	cin >> s;
	map<char, int> mp;
	bool ok = false;
	for(int i = 0; i < s.size(); ++i){
		mp[s[i]]++;
		if(isvowel(s[i]) && isvowel(s[i + 1]) && isvowel(s[i + 2]))
			ok = true;
	}
	if(!ok){
		cout << "-1";
		return 0;
	}
	int ans = 0;
	for(auto k : mp)
		if(!isvowel(k.first))
			++ans;
	cout << (ans >= 5 ? "GOOD\n" : "-1\n");
	return 0;
}