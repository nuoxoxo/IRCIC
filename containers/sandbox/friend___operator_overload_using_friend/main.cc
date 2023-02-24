#include "iostream"

using	namespace std;

class	Single_number
{
private:
	int	m_array {};

public:
	Single_number(int num) : m_array { num } {}

	friend Single_number operator + (
			const Single_number &, const Single_number &);

	int getNum() const { return m_array; }
};

Single_number operator + (const Single_number & n1, const Single_number & n2)
{
	return n1.m_array + n2.m_array;
}

int	main()
{
	Single_number	num1{42};
	Single_number	num2{58};
	Single_number	num3{ num1 + num2 };

	cout << "result : " << num3.getNum() << endl;
}
