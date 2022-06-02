#include "bits/stdc++.h"
#define ll long long int
#define ld long double
using namespace std;

int main(){
	long long int t;
	cin >> t;
	while(t--){
		string a, s;
		cin >> a >> s;
		ll hash[28] = {0};
		for(int i = 0; i < s.size(); ++i){
			hash[s[i] - 'A']++;
		}
		for(int i = 0; i < a.size(); ++i){
			if(hash[a[i] - 'A'] == 0)
				cout << a[i];
		}
		cout << '\n';
	}
	return 0;
}