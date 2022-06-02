#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define F first
#define S second
using namespace std;
const int N = 1e6 + 5, MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string temp = s;
	temp[k - 1] = s[0];
	if(k - 2 >= 0) 
		temp[k - 2] = s[k - 1];
	int cur = 1, l = 1, r = k - 2; 
	for(int i = k - 3; i >= 0; i--){
		if(cur % 2){
			char x = s[l];
			temp[i] = x;
			++l;
		}
		else{
			char x = s[r];
			temp[i] = x;
			--r;
		}
		++cur;
	}
	cout << temp << '\n';
}

int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--)
    	solve();
	return 0;
}