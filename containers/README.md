# Stack
## <cstddef> : what's inside
## what is 2nd param: `typename Container = vector<T>`
- template<typename T, typename Container = vecotr<T>>

## explicit
```
public: 
explicit 
stack(container_type const& c = container_type()) : c(c) 
{}
```
## friend in Non-member fn overloads
- friend bool operator == (stack const & l, stack const & r)

## container_type
- protected: container_type c;



# Pair (unrel. to stack/vector yet ez to do)
todolist
- class pair only has public mems
- occf
  - beware of copy constr
- operators == != < <= > >=





# Vector
## what is 2nd param: `typename Allocator = std::allocator<T>`
- template<typename T, typename Allocator = std::allocator<T>>



# Vector . vector_iterator - (Virtual Class)
## <iterator> : what's inside

## std::random_access_iterator_tag
```
public: 
typedef
  std::random_access_iterator_tag  iterator_catorgory
```

## std::ptrdiff_t
```
public:
typedef
  std::ptrdiff_t	difference_type
```

## explicit
```
public:

explicit vector_iterator(pointer ptr) : m_ptr(ptr) {
}

virtual ~vector_iterator(void) {
}
```



# Vector . vector_const_iterator - (Virtual Class)
## explicit
```
public:

explicit vector_const_iterator(pointer ptr) : m_ptr(ptr){
}

virtual ~vector_const_iterator(void) {
}
```






