#include <iostream>
using namespace std;

int main() {
	long long int t, i, j;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    long long int n = s.size(), ans = 1, max = 0;
	    for(i = 0; i < n; i++){
	        for(j = i + 1; j < n; j++){
	            if(s[i] == s[j])
	                ans++;
	        }
	        if (ans > max)
	            max  = ans;
	       ans = 1;
	    }
	    if(n%2 != 0)
	        cout << "NO" << '\n';
	    else if (max == n/2)
	        cout << "YES" << '\n';
	    else
	        cout << "NO" << '\n';
	}
	return 0;
}
