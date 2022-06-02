#include <iostream>
using namespace std;

int main() {
	long long int t;
	cin >> t;
	while(t--){
	    long long int n, i, ans = 0, a = 0;
	    cin >> n;
	    string s;
	    cin >> s;
	    for(i = 0; i < n; i++){
	        if(s[i] == 'Y')
	            ans++;
	        else if (s[i] == 'I')
	            a++;
	    }
	    if(ans > 0)
	        cout << "NOT INDIAN" << '\n';
	    else if (a > 0)
	        cout << "INDIAN" << '\n';
	    else
	        cout << "NOT SURE" << '\n';
	}
	return 0;
}
