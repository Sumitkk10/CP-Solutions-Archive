#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	int t;
	cin >> t;
	for(int test = 0; test < t; test++){
		int n, m, s;
		cin >> n >> m >> s;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(a[i] <= s && m != 0){
				cnt++;
				m--;
			}
			else if(a[i] <= s*2 && m >= 2){
				cnt++;
				m = m - 2;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
