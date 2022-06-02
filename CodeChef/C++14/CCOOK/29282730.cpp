#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
int main()
{
	ll t, a, b, c, d, e;
	cin >> t;
	while(t--){
		ll ans = 0;
		cin >> a >> b >> c >> d >> e;
		ans = a + b + c + d + e;
		if(ans == 0) 
			cout << "Beginner" << '\n';
		else if(ans == 1) 
			cout << "Junior Developer" << '\n';
		else if(ans == 2) 
			cout << "Middle Developer" << '\n';
		else if(ans == 3) 
			cout << "Senior Developer" << '\n';
		else if(ans == 4) 
			cout << "Hacker" << '\n';
		else if(ans == 5) 
			cout << "Jeff Dean" << '\n';   
	}
	return 0;
}