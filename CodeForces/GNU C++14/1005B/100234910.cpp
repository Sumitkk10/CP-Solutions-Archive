#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	string a, b;
	cin >> a >> b;
	int i = a.size() - 1, j = b.size() - 1;
	while(i >= 0 and j >= 0 and a[i] == b[j]){
		--i, --j;
	}
	++i, ++j;
	cout << i + j << '\n';
	return 0;
}
