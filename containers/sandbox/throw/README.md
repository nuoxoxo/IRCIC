# Throwing Exceptions in C++

Exceptions provide a way to react to exceptional circumstances in programs by transferring control to special functions called handlers.

Throwing exceptions are preferred in modern C++ over traditional error handling for the following reasons:

C++ exceptions force the calling code to identify error conditions and handle them. This prevents them from stopping program execution.

C++ destroys all objects in scope after an exception occurs, thereby reducing resource usage.

An exception provides a clean separation between the code that identifies an error and the code that throws and handles the C++ error.

C++ error types can be grouped together, which allows creating a hierarchy of exception objects, grouping them in namespaces or classes and categorizing them according to type.



# C++ try catch and throw

Exception handling in C++ is done using three keywords: try, catch and throw.

To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing this portion of code in a try block. When an exception occurs within the try block, control is transferred to the exception handler. If no exception is thrown, the code continues normally and the handlers are ignored.

An exception in C++ is thrown by using the throw keyword from inside the try block. The throw keyword allows the programmer to define custom exceptions.

Exception handlers in C++ are declared with the catch keyword, which is placed immediately after the try block. Multiple handlers (catch expressions) can be chained - each one with a different exception type. Only the handler whose argument type matches the exception type in the throw statement is executed.

C++ does not require a finally block to make sure resources are released if an exception occurs.


```c
#include "iostream"
#include "stdexcept"

using	namespace std;

int	add2positive(int, int);

int	main()
{
	try
	{
		cout << add2positive(-21, 42); //exception
	}
	catch (std::invalid_argument & e)
	{
		cerr << e.what() << endl;
		return -1;
	}

	return 0;
}

// helper
int	add2positive(int l, int r)
{
	if (l < 0 || r < 0)
		throw std::invalid_argument("positive arguments needed");
	return (l + r);
}
```


In this C++ throw exception example, the `add2pos` function is called from inside the try block in the `main()`. The `add2positive()` expects two integers a and b as arguments, and throws an `invalid_argument` exception in case any of them are negative.

The `std::invalid_argument` class is defined in the standard library in the `<stdexcept>` header file. 

This class defines types of objects to be thrown as exceptions and reports errors in C++ that occur because of illegal argument values.

The catch block in the main() function catches the `invalid_argument` exception and handles it.



