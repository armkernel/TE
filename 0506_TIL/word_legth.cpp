#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout; using std::cin;
using std::vector; using std::endl; 
using std::string;

int main() {

	// string legth type
	typedef string::size_type str_len;
	str_len max_size = 0;
	str_len min_size = 9999999999;
	string x;

	string max_str;
	string min_str;

	vector<string> contain;

	while(cin >> x) {
		contain.push_back(x);
	}

	vector<string>::iterator iter = contain.begin();

	for( ; iter != contain.end(); iter++) {
		str_len tmp_size = (*iter).size();
	
		/* 문자열 복사는 아직 안됨 */	
		if (tmp_size > max_size) {
			//max_str((iter).begin() + 1, (iter).end() - 1);
			max_size = tmp_size;	
		} 

		if (tmp_size < min_size) {
			//min_str.copy(*iter,tmp_size);
			min_size = tmp_size;
		}

	}	
		
	cout << "max size : " << max_size  << endl
		<< "min size : " << min_size  << endl;

	return 0;
}

