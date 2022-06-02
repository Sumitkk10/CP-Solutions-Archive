#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll n;
	cin >> n;
	ll sum = 0, j = 0, cnt = 1, cur = 2;
	for(int i = 1; i <= n; i++){
		if(j % 2 == 0){
			sum += pow(cnt, 2);
			cnt += 2;
		}
		else{
			sum += pow(cur, 2);
			cur += 2;
		}
		++j;
	}
	// cout << sum << " ";
	cout << (sum % 2 ? "Jhon\n" : "Ravi\n");
	return 0;
}
