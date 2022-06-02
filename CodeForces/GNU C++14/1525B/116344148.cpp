#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;

int main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	int n;
	    cin >> n;
	    long long int a[n + 1];
	    bool ans = 1;
	    for(int i = 1; i <= n; ++i){
	        cin >> a[i];
	        if(a[i] != i)
	        	ans = false;
	    }
	    if(ans){
	    	cout << 0 << '\n';
	    	continue;
	    }
	    if(a[1] == 1 or a[n] == n){
	    	cout << 1 << '\n';
	    	continue;
	    }
	    else if(a[n] == 1 and a[1] == n){
	    	cout << 3 << '\n';
	    	continue;
	    }
	    cout << "2\n";
    }
    return 0;
}
