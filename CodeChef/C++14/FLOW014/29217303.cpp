#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	while(t--){
		float h, c, s;
		cin >> h >> c >> s;
		 if(h > 50 && c < 0.7 && s > 5600) 
		 	cout << 10 << "\n";
        else if(h > 50 && c < 0.7) 
        	cout << 9 << "\n";
        else if(c < 0.7 && s > 5600) 
        	cout << 8 << "\n";
        else if(h > 50 && s > 5600) 
        	cout << 7 << "\n";
        else if(h > 50 || s > 5600 || c < 0.7) 
        	cout << 6 << "\n";
        else if(h <= 50 && s <= 5600 && c >= 0.7) 
        	cout << 5 <<"\n";
	}
	return 0;
}