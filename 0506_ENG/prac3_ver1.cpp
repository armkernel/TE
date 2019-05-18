#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::setprecision;
using std::cout; using std::string;
using std::endl; using std::streamsize;
using std::vector; using std::sort; 

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
	//int count = 0;
	//double sum = 0.;

	/* homework vector 컨테이너 -> double type 객체를 담는 공간.. */
	vector<double> homework;
	
	// 입력을 위한 변수
	double x;

	// 불변성: 지금까지 count 개 점수를 입력받았으며 입력받은 점수의 합은 sum
	// end-of-file
	#if 0
	while (cin >> x) {
		++count;
		sum += x;
	}
	#endif

	while (cin >> x) {
		homework.push_back(x);	
	}


	// vector 객체의 개수의 범위.. 
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();

	if (size == 0) {
		cout << endl << "Your must enter your grades. "
		"Please try again. " << endl;
		return 1;
	}
	
	/* 비내림차순 정렬..? */
	sort(homework.begin(),homework.end());
	
	vec_sz mid = size / 2;

	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];


	// 결과를 출력	
	// what is the precision??? 
	streamsize prec = cout.precision();

	cout << "Your final grade is " << setprecision(3) << 
		0.2 * midterm + 0.4 * finalterm + 0.4 * median  
		<< setprecision(prec) << endl;

	return 0; 
}
