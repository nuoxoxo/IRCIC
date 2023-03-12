#include "iostream"
#include "type_traits"
#include "../Fmt.hpp"

using	namespace std;
 
int	main()
{
	cout << boolalpha;

	cout
	<< "int: " << is_integral<int>::value << nl
	<< "longint: " << is_integral<long int>::value << nl
	<< "bool: " << is_integral<bool>::value << nl
	<< "char: " << is_integral<char>::value << nl
	<< "wchar_t: " << is_integral<wchar_t>::value << nl
	<< "unsigned short int: " << is_integral<unsigned short int>::value << nl2;

	cout
	<< "float: " << is_integral<float>::value << nl
	<< "double: " << is_integral<double>::value << nl
	<< "long double: " << is_integral<long double>::value << nl2;

	cout
	<< "... \n"
	<< "Built-in types (also called fundamental types) " 
	<< "are specified by the C++ language standard and "
	<< "are built into the compiler. \n"
	<< "Built-in types aren't defined in any header file. \n\n"
	<< "Built-in types are divided into three main categories: \n"
	<< "integral, floating-point, and void. \n\n"
	<< "Integral types represent whole numbers. \n"
	<< "Floating-point types specify values w/ or w/o fractional parts. \n"
	<< "Most built-in types are treated as distinct types by the compiler. \n"
	<< "Some types are synonyms, "
	<< "or treated as equivalent types by the compiler. \n"
	<< "... \n\n";
}
