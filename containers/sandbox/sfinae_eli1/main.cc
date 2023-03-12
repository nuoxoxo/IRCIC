#include "iostream"
#include "Fmt.hpp"

using	namespace std;

//	Funciton 1

//void	func(unsigned int i) { cout << Y << "uint: " << i << nl2reset; }
void	func(unsigned int i) {
	cout << Y << "uint: " << i << nlreset;
	cout << "(type: " << typeid(i).name() << ")" << nl2;
}

//	Funciton 2: template

template<typename T>
// void	func(const T & t) { cout << C << "template: " << t << nlreset; }
void	func(const T & t) {
	cout << C << "template: " << t << nlreset;
	cout << "(type: " << typeid(t).name() << ")" << nl2;
}


int	main()
{
	func(42); // int => signed by default
	func((uint8_t) 42); // ascii char
	func((uint32_t) 42); // // normal
	func((unsigned int) 42); // idem
}

