namespace	ft
{

	template<typename T_1, typename T_2>
	class	pair
	{

	public:
		T_1	first;
		T_2	second;
	public:
		pair() : first(), second() {}
		~pair() {}
		
		pair(const T_1 & l, const T_2 & r) : first(l), second(r) {}
		
		template<typename L, typename R>
		pair(const pair<L, R> & p) : first(p.first), second(p.second) {}

		pair & operator = (const pair & p)
		{
			if (this != & dummy)
			{
				first = dummy.first;
				second = dummy.second;
			}
			return (*this);
		}
	}

	// operators

}
