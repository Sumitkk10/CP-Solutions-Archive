#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, i;
	cin >> n;
    for(i = 0; i < n; i++)
	{
	    string s[4];
	    string h[4];
	    int count = 0;
	    for(int j = 0; j < 4; j++)
	    {
	        cin >> s[j];
	    }
	    for(int j = 0; j < 4; j++)
	    {
	        cin >> h[j];
	    }
	    for(int j = 0; j < 4; j++)
	    {
	        if(s[0] == h[j] || s[1] == h[j] || s[2] == h[j] || s[3] == h[j])
	            count++;
	    }
	    if(count >= 2)
	        cout << "similar" << '\n';
	    else
	        cout << "dissimilar" << '\n';
	}
	return 0;
}
