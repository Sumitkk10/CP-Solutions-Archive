#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
string s;

bool search(int from, string which){
	string ok;
	for(int j = from; j < s.size(); ++j)
		ok.push_back(s[j]);
	// cout << ok << '\n';	
	size_t where = ok.find(which);
	if(where == string::npos) return false;
	return true;
}

int main(){
	fast;
	cin >> s;
	int ans1 = 0;
	for(int len = 1; len < s.size(); ++len){
		for(int i = 0; i < s.size() - len + 1; ++i){
			string ans;
			for(int j = i; j < i + len; ++j)
				ans.push_back(s[j]);
			// if(ans == "aba") cout << i << ' ';
			if(search(i + 1, ans))
				ans1 = max(ans1, len);
		}
	}
	cout << ans1 << '\n';
	return 0;
}
