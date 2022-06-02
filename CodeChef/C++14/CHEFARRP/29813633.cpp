#include <iostream>
using namespace std;

int main() {
	long long int t, i, j;
	cin >> t;
	while(t--){
	    long long int n, ans = 0;
	    cin >> n;
	    long long int a[n];
	    for(i = 0; i < n; i++){
	        cin >> a[i];
	    }
	    for(i = 0; i < n; i++){
	        long long sum = a[i], pro = a[i];
	        for(j = i+1; j < n; j++){
	            sum += a[j];
	            pro *= a[j];
	            if(pro == sum)
	                ans++;
	        }
	    }
	    cout << ans + n << '\n';
	}
	return 0;
}
