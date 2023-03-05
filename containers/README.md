# __Mar Updates__


<!--
![](https://i.imgur.com/tJx6k1V.jpg)
-->


## _Rabbit rotates_
```
/*      y   right rotate     x
/      / \  ------------>   / \ 
/     x	  c                a   y 
/    / \     left rotate      / \ 
/   a   b   <------------    b   c
*/
```


# __Feb Updates__



## _Todo_



[@](https://m.cplusplus.com/reference/iterator/iterator) cplusplus/iterator  
[@](https://m.cplusplus.com/reference/iterator/iterator_traits) cplusplus/iterator_traits  \
[@](https://m.cplusplus.com/reference/iterator/RandomAccessIterator) cplusplus/RandomAccessIter  

[@](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html) gcc.gnu.stl_iterator.h  \
[@](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits) iterator_traits w/ distance() example 


<!--
![](https://i.imgur.com/3znf2g8.jpg)
-->


## _Containers_

Iterator traits
Member type | Definition
:-- | :--
difference_type | Iter::difference_type
value_type | Iter::value_type
pointer | Iter::pointer
reference | Iter::reference
iterator_category | Iter::iterator_category

5 main types of iterators
- Random-access iterators 
- Bidirectional iterator
- Forward iterator 
- Input iterators
- Output iterator 

lvalue \
rvalue

## _Things to learn_

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

## _Red black tree_
- principle
- implementation




## _Stack_
\<cstddef> : what's inside

what is 2nd param: `typename Container = vector<T>`
- `template<typename T, typename Container = vector<T>>`

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



## _Pair (unrel. to stack/vector yet ez to do)_
todolist
- class pair only has public mems
- occf
  - beware of copy constr
- operators == != < <= > >=
- make_pair
  - fn: 
`templ<typename X,typename Y> pair<X,Y> make_pair(X x, Y y) -> pair<X, Y>(x, y)`







## _Vector_
what is 2nd param: `typename Allocator = std::allocator<T>`
- template<typename T, typename Allocator = std::allocator<T>>



## _vector_iterator - (Virtual Class)_
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



## _vector_const_iterator - (Virtual Class)_
explicit
```
public:

explicit vector_const_iterator(pointer ptr) : m_ptr(ptr){
}

virtual ~vector_const_iterator(void) {
}
```



