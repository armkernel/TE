#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() {

	double a;

	/* 더이상 읽을 수 없는 데이터 이거나 파일의 끝을 나타낼때.. */
	while (cin >> a) cout << a;
	return 0;
}
