#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

int main(){
	fast;
	int a, b, c;
	cin >> a >> b >> c;
	a = c - a;
	int number_of_socks = a / b;
	cout << (number_of_socks % 2 ? "Unlucky Chef\n" : "Lucky Chef\n");
	return 0;
}
