/*
A friend class 
 * Can access private & protected members of other classes 
 	* in which it is declared as a friend.
 * For example
 	* a LinkedList class may be allowed to access private members of Node.
 */

#include "iostream"

using	namespace std;

class	Me	/* I hereby declare a friend. */
{

friend class	Friend; // It doesn't matter if friend is decalred in public/private

private:
	string	private_stuff;
protected:
	string	protected_stuff;
public:
	Me() { private_stuff = "Private. "; protected_stuff = "Protected. "; }
	~Me() {}
};

class	Friend	/* someone says I am his/her friend */
{
public:
	Friend() {}
	~Friend() {}
	// void	reveal( Me const & me )
	inline void	reveal( Me const & me )
	{
		cout << "Printing private: " << me.private_stuff << '\n';
		cout << "Printing protected: " << me.protected_stuff << '\n';
	}
};

int	main()
{
	Me	me;
	Friend	they;

	they.reveal(me);
}
