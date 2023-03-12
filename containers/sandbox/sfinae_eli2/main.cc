#include "iostream"
#include "../Fmt.hpp"

using	namespace std;

int	negate(int i) {
 	return -i;
}

template<typename T>
typenameT::value_type negate(const T& t) {
  return -T(t);
}
