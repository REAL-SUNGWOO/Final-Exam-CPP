//4월 30일 수업 "연산자 다중정의"
//연습문제 7-1,2
//객체간의 연산을 수행하고자 함.
// "operator" 키워드 이용
// operator 뒤에 오는 연산자에 따라서 어떤 기능을 할지 블록({})으로 정의
// 멤버함수가 하나 추가된 것

// ###추가로 공부한 내용###

//"this"라는 키워드는 현재 호출된 객체 자기 자신을 가리키는 포인터이다.
//클래스의 멤버 함수 안에서만 사용 가능하다.
//만약 객체가 p 라면 this === &p
#include<iostream>

using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0);
	// 인수를 참조형으로 받는 이유는 새로운 객체로 받게 되면 (예를 들어 Point p)
	// 복사생성자가 호출되므로 메모리 낭비 및 속도 저하.
	Point operator+(Point& b); 
	Point operator+(int a);
	Point operator-(Point& b);
	//  += 연산은 자기 자신에 어떤 값을 더한 결과를 다시 자기 자신에 저장하는 연산자이다.
	// 따라서 반환형을 참조형&으로 하여 자기 자신을 반환 할 수 있도록 설계한다.
	Point& operator+=(const Point &p);
	Point& operator++(); // 전위 증가
	Point& operator++(int); // 후위 증가, 내부적으로 이렇게 하도록 되어있음.
	void showpoint(void);
	//friend Point operator+(int num, const Point &p);
	/*friend Point operator+(const Point& a, int num);*/
	//friend Point& operator+=(Point& p1, const Point& p2);
private:
	int x_;
	int y_;
};
Point::Point(int x, int y) {
	x_ = x;
	y_ = y;
}
void Point::showpoint(void) {
	cout << "(" << x_ << ", " << y_ << ")" << endl;
}
//(1) 객체 + 객체를 수행
Point Point::operator+(Point& b) {
		return Point(x_ + b.x_, y_ + b.y_);
}
//(2) 객체 + int 변수 수행
Point Point:: operator+(int a) {
	return Point(x_ + a, y_ + a);
}
//(3) 객체 - 객체를 수행
Point Point::operator-(Point& b) {
	return Point(x_ - b.x_, y_ - b.y_);
}
//(4) 자기 자신의 값에 새로운 객체의 값을 더한 것을 수행
Point& Point::operator+=(const Point& p) {
	
	x_ += p.x_;
	y_ += p.y_;
	return *this; // 자기 자신을 반환
	// 여기서 만약에 반환형이 그냥 Point형 이였다면, 
	// 자기 자신을 반환하는데 반환 형은 그것의 복사본이다.
	// 따라서 &를 통해 완벽히 자기 자신을 반환할 수 있다.
}
Point& Point:: operator++() {
	x_++;
	y_++;
	return *this; // 자기 자신의 값 반환
} // 전위 증가
Point& Point:: operator++(int) {
	x_++;
	y_++;
	return *this; // 자기 자신의 값 반환
} // 후위 증가


////(5)일반함수를 이용한 객체 연산 함수
//// int 변수 + 객체인 경우만 동작
//Point operator+(int num, const Point& p) {
//	return Point(p.x_ + num, p.y_ + num);
//};

// 객체 + int 변수인 경우만 동작
//Point operator+(const Point& p, int num) {
//	return Point(p.x_ + num, p.y_ + num);
//};
//
//(6) 자기 자신의 값에 새로운 객체의 값을 더한 것을 수행 (일반 함수)
//Point& operator+=(Point& p1, const Point& p2) {
//
//	p1.x_ += p2.x_;
//	p1.y_ += p2.y_;
//	return p1; // 자기 자신을 반환
//};





int main(void)
{
	Point p1(10, 20);
	cout << "p1: "; p1.showpoint();

	Point p2(30, 40);
	cout << "p2: "; p2.showpoint();

	Point p3 = p1 + p2;
	cout << "p3 = p1 + p2" << endl;
	cout << "p3: "; p3.showpoint();
	/*Point p3 = operator+(p1, 10);
	cout << "p3 = p1 + p2" << endl;
	cout << "p3: "; p3.showpoint();*/

	Point p4 = p1 - p2;
	cout << "p4 = p1 - p2" << endl;
	cout << "p4: "; p4.showpoint();

	p1 += p2;
	cout << "p1 += p2" << endl;
	cout << "p1: "; p1.showpoint();

	//p1.operator+=(p2);
	//cout << "p1 += p2" << endl;
	//cout << "p1: "; p1.showpoint();

	++p1;
	cout << "++p1: "; p1.showpoint();
	p1++;
	cout << "p1++: "; p1.showpoint();

}
