#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;


int main(){
	fast;
	ll q;
	cin >> q;
	stack<int> a;
	while(q--){
		int x, y; 
		cin >> x;
		if(x != -1){
			cin >> y;
			a.push(y);
		}
		else{
			if(a.size() == 0){ 
				cout << "kuchbhi?\n";
				continue;
			}
			else cout << a.top() << "\n";
			a.pop();
		}
	}
	return 0;
}
