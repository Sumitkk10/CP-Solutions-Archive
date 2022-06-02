#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
	double n;
	cin >>t;
	while(t--){
	    cin >> n;
	    if (n < 1500){
	        double a, b;
	        a = (n/10);
	        b = (0.9 * n);
	        cout << fixed << setprecision(2)<< a+b+n <<'\n';
	    }
	   else {
	        double b;
	        b = (0.98 * n);
	        cout << fixed << setprecision(2) << 500+b+n <<'\n';
	    }
	  }
	return 0;
}
