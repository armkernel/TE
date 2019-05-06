#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;

int main () {

	// 학생의 이름을 묻고 입력 받음	
	cout << "Please enter your first name : ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!" << endl;

	// 중간 기말 점수 묻고 입력받음
	cout << "Please enter your midterm and final exam grades : ";
	double midterm, finalterm;
	cin >> midterm >> finalterm;

	// 과제 점수를 물음 
	cout << "Enter all your homework grades, " "followed by end-of-file: ";

	// 지금까지 입력된 과제 점수의 개수와 합
	int count = 0;
	double sum = 0.;

	// 입력을 위한 변수
	double x;

	// 불변성: 지금까지 count 개 점수를 입력받았으며 입력받은 점수의 합은 sum
	// end-of-file
	while (cin >> x) {
		++count;
		sum += x;
	}

	// 결과를 출력	
	// what is the precision??? 
	streamsize prec = cout.precision();

	cout << "Your final grade is " << setprecision(3) << 
		0.2 * midterm + 0.4 * finalterm + 0.4 * sum / count 
		<< setprecision(prec) << endl;

	return 0; 
}
