#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		int n;
		cin >> n;
		int p, q, sum = 0;
		int b[9];
		for(int i = 0; i < 9; i++)
			b[i] = 0;
		for(int i = 0; i < n; i++){
			cin >> p >> q;
			if(p <= 8){
				if(b[p] == 0)
					b[p] = q;
				else if(b[p] < q)
					b[p] = q;
			}
		}
	
		for(int i = 0; i < 9; i++){
			 sum += b[i];
		}
		cout << sum << '\n';
	}
	return 0;
}