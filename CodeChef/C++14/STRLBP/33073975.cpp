#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
	    cin >> s;
	    int ans = 0;
	    if(s[0] != s[s.size()-1])
	        ++ans;
	   for(int i = 0; i < s.size()-1; ++i){
	       if(s[i] != s[i+1])
	        ++ans;
	   }
	   if(ans <= 2)
	    cout << "uniform\n";
	   else
	    cout << "non-uniform\n";
	}
	return 0;
}
