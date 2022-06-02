#include <iostream>
using namespace std;

int main() {
	long long int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    long long int a = s.size(), i, ans = 0, bns = 0;
	    for(i = 0; i < a; i++){
	      if(s[i] == 'a')
	        ans++;
	      else if(s[i] == 'b')
	        bns++;
	    }
	    if(bns == 0 || ans == 0)
	        cout << 0 << '\n';
	    else if(ans > bns)
	        cout << bns << '\n';
	    else if(bns > ans)
	        cout << ans << '\n';
	    else 
	        cout << bns << '\n';
	 }
	return 0;
}
