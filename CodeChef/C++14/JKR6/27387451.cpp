#include <iostream>
using namespace std;
 
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int size = j - i + 1;
			int ans = 0;
			for(int k = 0; k < size; k++){
				if(s[k + i] == s[j - k]) ans++;
			}
			if(ans == size){
				res = max(res, size);
			}
		}
	}
	cout << res;
	return 0;
}