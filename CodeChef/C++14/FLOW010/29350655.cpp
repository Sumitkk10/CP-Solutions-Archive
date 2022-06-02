#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
int main()
{
	ll t, i;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(s[0] == 'B' || s[0] == 'b')
			cout << "BattleShip" << '\n';
		else if(s[0] == 'C' || s[0] == 'c')
			cout << "Cruiser" <<'\n';
		else if(s[0] == 'D' || s[0] == 'd')
			cout << "Destroyer" << '\n';
		else if(s[0] == 'F' || s[0] == 'f')
			cout << "Frigate" << '\n';
	}
	return 0;
}