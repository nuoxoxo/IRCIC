```c
#include "iostream"

using	namespace std;

class	Single_number
{
private:
	int	m_number {};

public:
	Single_number(int num) : m_number { num } {}

	// overload outside the class
	friend Single_number operator + (
			const Single_number &, const Single_number &);
	friend Single_number operator - (
			const Single_number &, const Single_number &);

	// same overload, inside the class
	friend Single_number operator * (
		const Single_number & n1, const Single_number & n2) {
		return n1.m_number * n2.m_number;
	}
	friend Single_number operator / (
		const Single_number & n1, const Single_number & n2) {
		return n1.m_number / n2.m_number;
	}

	int getNum() const { return m_number; }
};

Single_number operator + (const Single_number & n1, const Single_number & n2)
{ return n1.m_number + n2.m_number; }

Single_number operator - (const Single_number & n1, const Single_number & n2)
{ return n1.m_number - n2.m_number; }


// Drive

int	main()
{
	{
		Single_number	num1{42};
		Single_number	num2{58};
		Single_number	res1{ num1 + num2 };
		Single_number	res2{ num1 - num2 };

		cout << "a: " << num1.getNum() << endl;
		cout << "b: " << num2.getNum() << endl;
		cout << "result : " << res1.getNum() << endl;
		cout << "result : " << res2.getNum() << endl;
	}
	{
		Single_number	num1{99};
		Single_number	num2{3};
		Single_number	res1{ num1 * num2 };
		Single_number	res2{ num1 / num2 };

		cout << "a: " << num1.getNum() << endl;
		cout << "b: " << num2.getNum() << endl;
		cout << "result : " << res1.getNum() << endl;
		cout << "result : " << res2.getNum() << endl;
	}


}
```
