#include "iostream"
#include "memory"

int	main()
{
	int			Size = 10, i;
	std::cout << "::: testing int ::: \n\n";
	{
		std::allocator<int>	at;
		int	*a = at.allocate(Size);

		a[1] = 42;
		a[5] = 1024;
		i = -1;
		while (++i < Size)
			std::cout << i << ": " << a[i]
			<< (i ^ Size - 1 ? "\n" : "\n\n");

		// cleanup

		at.deallocate(a, Size);
	}
	std::cout << "::: testing string ::: \n\n";
	{
		std::allocator<std::string>	at;
		std::string	*a = at.allocate(Size);

		a[1] = "ft::";
		a[2] = "std::";
		at.construct(a + 3, "Good ");
		at.construct(a + 4, "Morning, ");
		at.construct(a + 5, "Vietnam! ");

		i = 0;
		while (++i < Size)
			std::cout << i << ": " << a[i] 
			<< (i ^ Size - 1 ? "\n" : "\n\n");
		i = -1;
		while (++i < 5)
			at.destroy(a + i);

		// cleanup

		at.deallocate(a, Size);
	}
	std::cout << "::: testing float ::: \n\n";
	{
		std::allocator<float>	at;
		float	*a = at.allocate(Size);

		at.construct(a + 1, 0.01f);
		a[3] = 3.1415f;
		a[7] = 42.42f;
		i = -1;
		while (++i < Size)
			std::cout << i << ": " << a[i]
			<< (i ^ Size - 1 ? "\n" : "\n\n");
		
		// cleanup

		at.destroy(a + i);
		at.deallocate(a, Size);
	}
	std::cout << "::: testing double ::: \n\n";
	{
		std::allocator<double>	at;
		double	*a = at.allocate(Size);

		at.construct(a + 2, 0.01);
		a[3] = 3.1415;
		a[7] = 42.42;
		i = -1;
		while (++i < Size)
			std::cout << i << ": " << a[i]
			<< (i ^ Size - 1 ? "\n" : "\n\n");

		// cleanup

		at.destroy(a + 2);
		at.deallocate(a, Size);
	}
}
