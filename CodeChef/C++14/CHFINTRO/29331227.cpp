#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll n, r, R;
	cin >> n >> r;
	while(n--){
		cin >> R;
		if(R >= r)
			cout << "Good boi" << '\n';
		else
			cout << "Bad boi" <<'\n';
	}
	return 0;
}