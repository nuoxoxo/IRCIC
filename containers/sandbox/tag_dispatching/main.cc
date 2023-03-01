#include "iostream"


/*
 * tag dispatching allows us to have several constructors taking 
 * the same types of data, but with different behaviours
 */

using	namespace std;

class	ClassA
{

public:
	ClassA();
	ClassA(int);
	ClassA(string);
	void	doThis();
	void	doThat();




};





