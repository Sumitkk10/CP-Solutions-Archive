#include <iostream>
using namespace std;

int main() {
	long long int t, i;
	cin >> t;
	while(t--){
	    long long int n;
	    cin >> n;
	    long long int a[n], max = 0;
	    for(i = 0; i < n; i++)
	        cin >> a[i];
        for(i = 0; i < n; i++){
            if(a[i] > max)
                max = a[i];
        }
        cout << max << '\n';
	}
	return 0;
}
