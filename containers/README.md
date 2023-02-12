# Things to learn
```
std::iterator_traits
std::reverse_iterator
std::enable_if	{c++11}
std::is_integral
std::pair
std::make_pair
std::equal
std::lexicographical_compare
```

# Red black tree
- principle
- implementation




# Stack
\<cstddef> : what's inside

what is 2nd param: `typename Container = vector<T>`
- template<typename T, typename Container = vecotr<T>>

explicit
```
public: 
explicit 
stack(container_type const& c = container_type()) : c(c) 
{}
```

friend in Non-member fn overloads
- `friend bool operator == (stack const & l, stack const & r)`

container_type
- protected: container_type c;



# Pair (unrel. to stack/vector yet ez to do)
todolist
- class pair only has public mems
- occf
  - beware of copy constr
- operators == != < <= > >=
- make_pair
  - fn: 
`templ<typename X,typename Y> pair<X,Y> make_pair(X x, Y y) -> pair<X, Y>(x, y)`







# Vector
what is 2nd param: `typename Allocator = std::allocator<T>`
- template<typename T, typename Allocator = std::allocator<T>>



# vector_iterator - (Virtual Class)
\<iterator> : what's inside

std::random_access_iterator_tag
```
public: 
typedef
  std::random_access_iterator_tag  iterator_catorgory
```

std::ptrdiff_t
```
public:
typedef
  std::ptrdiff_t	difference_type
```

explicit
```
public:

explicit vector_iterator(pointer ptr) : m_ptr(ptr) {
}

virtual ~vector_iterator(void) {
}
```



# vector_const_iterator - (Virtual Class)
explicit
```
public:

explicit vector_const_iterator(pointer ptr) : m_ptr(ptr){
}

virtual ~vector_const_iterator(void) {
}
```






