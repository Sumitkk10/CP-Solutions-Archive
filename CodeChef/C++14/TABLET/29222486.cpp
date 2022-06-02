#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	long long int t;
	cin >> t;
	while(t--){
		long long int n, b;
		cin >> n >> b;
		long long int w, h, p, ans = 0, max = 0;
		for(int i = 0; i < n; i++){
			cin >> w >> h >> p;
			if(p <= b){
				ans = w * h;
				if(ans > max){
					max = ans;
				}
			}
		}
		if(max == 0)
			cout << "no tablet" << '\n';
		else 
			cout << max << '\n';
	}
	return 0;
}