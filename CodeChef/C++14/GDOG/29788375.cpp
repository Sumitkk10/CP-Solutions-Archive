#include <iostream>
using namespace std;

int main() {
	long long int t;
	cin >> t;
	while(t--){
	    long long int n, k, i, ans = 0, max = 0;
	    cin >> n >> k;
	    for(i = 1; i <= k; i++){
	        ans = n%i;
	        if(ans > max)
	            max = ans;
	    }
	    cout << max << '\n';
	}
	return 0;
}
