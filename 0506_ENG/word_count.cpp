#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout; using std::cin;
using std::vector; using std::string;
using std::endl; using std::find;

int main() 
{
	string x;
	vector<string> contain;
	typedef vector<string>::size_type vec_sz;
	vec_sz cnt = 0;

	while (cin >> x) {
		cout << x << endl;

		
		if ( find(contain.begin(), contain.end(), x) != contain.end()) {
			cout << "haha" << endl;
		} else {
			contain.push_back(x);
			cnt++;
		}
		
	}
	
	printf("%lu",cnt);

	return 0;
}
