//4월 30일 수업 "연산자 다중정의"
//표준 입출력에 대한 연산자 다중정의
#include<iostream>
#include<cstdio>

namespace mystd {
	const char* endl = "\n"; 
	// 이렇게 하면 << mystd::endl 하면 ostream 클래스의 첫번째 멤버함수가 실행되며,
	// printf함수를 통해 줄바꿈을 실행하게 된다.


	//출력을 담당하는 스트림 클래스
	//왜 자기 자신을 반환형으로 사용하는가?
	// 그 이유는 <<를 여러개 연속으로 사용하기 위해서
	// 만약 mystd::cout << "문자열" << 12 << 12.123 << mystd::endl; 이런식으로 했다면,
	// 객체가 계속 반환되기 때문에 아래와 같은 동작이 가능하다.
	// (((mystd::cout << "문자열") << 12) << 12.123) << mystd::endl;
	// 
	// mystd::cout << printf가 수행됨. cout << prinf가 수행됨 cout << printf가 수행됨 cout << mystd::endl 이런 느낌
	class ostream {
	public:
		//<<다음에 있는 값을 printf로 출력한 다음 혹시 << 가 더 있을 경우를 대비해서 자기자신을 return
		ostream& operator<<(const char* str) {
			printf("%s", str); 
			// printf 함수 사용법, printf("출력할 자료형",변수)
			//printf 함수가 문자열 배열의 첫번째 요소부터 \n(null)을 만날때까지 하나씩 문자를 출력한다.
			return *this;
		};
		ostream& operator<<(int num) {
			printf("%d", num);
			return *this;
		};
		ostream& operator<<(double d) {
			printf("%lf", d);
			return *this;
		};
	};
	class istream {
	public:
		istream& operator>>(const char* str) {
			scanf_s("%s", str,1024);
			return *this;
			//ostream과 마찬가지로 자기 자신을 반환함으로서 <<를 계속해서 사용할 수 있도록
		};
		istream& operator>>(int &num) {
			scanf_s("%d", &num);
			return *this;
		};
		istream& operator>>(double &d) {
			scanf_s("%lf", &d);
			return *this;
		};
	};
	//mystd라는 namespace에 ostream 클래스와 istream클래스의 객체를 선언해놓음
	ostream cout;
	istream cin; 
	//ostream print;
	//istream sacn; // 이렇게 해도됨.
}



int main(void)
{
	mystd::cout << "문자열(Hello)" <<"정수(" <<777<<"), " <<"실수(" <<10.5<<")" << mystd::endl;

	int i=0;
	double d=0;
	char str[1024];

	mystd::cout << "문자열을 입력하세요: "; mystd::cin >> str;
	mystd::cout << "정수를 입력하세요: "; mystd::cin >> i;
	mystd::cout << "실수를 입력하세요: "; mystd::cin >> d;

	mystd::cout << "입력하신 문자열 : " << str << ", 입력한 정수: " << i << ", 입력한 실수: " << d << mystd::endl;
	
	return 0;
}
