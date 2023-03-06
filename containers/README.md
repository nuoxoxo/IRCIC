# __Mar Updates__

![](https://i.imgur.com/tJx6k1V.jpg)




# _Resources_



___What is wchar_t?___
- _idem._


___enable_if___
- [cppreference](https://en.cppreference.com/w/cpp/types/enable_if)



___is_integral______
- what are type traits in C - [HERE](https://dev.to/sandordargo/what-are-type-traits-in-c-18j5) 
- type_traits - [HERE](https://cplusplus.com/reference/type_traits/is_integral/?kw=is_integral)
- type_traits/const - [HERE](https://cplusplus.com/reference/type_traits/integral_constant)\
(is_integral dep of integral_constant) 
- sfinae & enable_if - [eli](https://eli.thegreenplace.net/2014/sfinae-and-enable_if)



___BinaryPredicate___
- named requirements : BinaryPredicate - [cppreference](https://en.cppreference.com/w/cpp/named_req/BinaryPredicate)
- STL sort() function, BinaryPredicate - [stof](https://stackoverflow.com/questions/7372132/c-stl-sort-function-binary-predicate)



___BST and algorithms___

- Introduction to Algorithms - 3th [ed.](https://edutechlearners.com/download/Introduction_to_algorithms-3rd%20Edition.pdf) \
... deletion algorithm : _cf. page 315_
- ___Binary Search Tree___ - insert, [etc.](https://www.cs.dartmouth.edu/~thc/cs10/lectures/0428/0428.html)
- ___Red Black Tree___ \
... Pseudocode - [programiz](https://www.programiz.com/dsa/red-black-tree) \
... Expl. & impl. - [LMU](https://cs.lmu.edu/~ray/notes/redblacktrees) \
... Visualizer - [visualizer](https://www.cs.usfca.edu/~galles/visualization/RedBlack.html) \
... Java impl. - [JAVA](https://www.happycoders.eu/algorithms/red-black-tree-java)
- INTRO : [intro](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=gcse)
- INSERT : C [implementation](https://www.geeksforgeeks.org/c-program-red-black-tree-insertion)
- INSERT : [programiz](https://www.programiz.com/dsa/insertion-in-a-red-black-tree)
- ROTATE : [data structure](https://www.codesdope.com/course/data-structures-red-black-trees-insertion)
- ERASE : [delete](https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2)
- REBIND : [stof](https://stackoverflow.com/questions/14148756/what-does-template-rebind-do)




___Iterators___

- libstdc++ api - [stl_iterator.h](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html)
- Implement stl style iterators & avoid common pitfalls \
... std::tag, etc. [HERE](https://stackoverflow.com/questions/8054273/how-to-implement-an-stl-style-iterator-and-avoid-common-pitfalls)
- Define Iterators for Containers - [HERE](https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html)
- Tag dispatching - [HERE](https://www.fluentcpp.com/2018/04/27/tag-dispatching)
- Iterator Traits - [HERE](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits)
- iterators on `cplusplus.com` \
... iterator - [HERE](https://m.cplusplus.com/reference/iterator/iterator) \
... traits - [HERE](https://m.cplusplus.com/reference/iterator/iterator_traits)\
... reverse_it - [HERE](https://m.cplusplus.com/reference/iterator/reverse_iterator)\
... random [ ] - [HERE](https://m.cplusplus.com/reference/iterator/RandomAccessIterator)



___General___

- C++ ISO 14882 - [ISO](https://kaltofen.math.ncsu.edu/courses/Languages/C++Examples/iso14882.pdf)
- Comprendre ___enable_if___ - [FR.](https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html)
- Custom STL-Like Containers and Iterators - [HERE](https://web.stanford.edu/class/cs107l/handouts/04-Custom-Iterators.pdf)
- ___SFINAE___ \
... Comprendre ___SFINAE___ (Substitution Failure is not an Error) - [FR.](https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/SFINAE.html) \
... Understand ___SFINAE___ - [Lecture 1](https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code) \
... Understand ___SFINAE___ - [Lecture 1](https://www.fluentcpp.com/2018/05/18/make-sfinae-pretty-2-hidden-beauty-sfinae) 
... SFINAE en francais - [moins](https://www.developpez.com/actu/94611/SFINAE-Interlude-moins-Cplusplus-avance-exemple-d-implementation)
- Containers library \
... 🟢 Super Useful - [containers](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2011/n3242.pdf#page=731&zoom=100,96,712)\
... Chapter 11 : memory & vector example - [Vec](https://tfetimes.com/wp-content/uploads/2015/11/Accelerated_C-_Practical_Programming_by_Example_-_Andrew_Koenig_Barbara_E._Moo_-_Addison-Wesley_-_2000.pdf#page=250) \
... implementation specific size_type - [size_type](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2011/n3242.pdf#page=789&zoom=100,96,712)
- most readable STL implementation by Alexander Stepanov & Meng Lee \
... [stof](https://stackoverflow.com/questions/2127612/is-there-a-readable-implementation-of-the-stl) \
... [butler](http://stepanovpapers.com/butler.hpl.hp/stl/stl)
- Set impl. at GCC official github \
... [gcc mirror](https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/include/bits/stl_set.h)
- C++ named requirements: Compare \
... [HERE](https://en.cppreference.com/w/cpp/named_req/Compare)



___Stack___
- [cpluspluc](https://cplusplus.com/reference/stack/stack/?kw=stack) \
... page 181 ISO 1998



# _Rules_


```c
/**
 *  Rb tree rules
 * 
 *  1. a node is either red or black
 *  2. the root and leaves (NIL) are black
 *  3. if a node is red, then its children are black
 *  4. all paths from a node to its NIL descendants
 * 		contain the same number of black nodes
 * 
 *           8                            8
 *         /   \                        /   \
 *        /     \                      /     \
 *       5       15                   B        R               
 * 	/ \     /   \                / \     /   \
 *    nil nil  12     19           nil nil  B      B               
 *            /  \   /   \                 / \    / \
 *          9    13 nil   23             R    R  nil R    
 *         /  \  / \     /  \          /  \   / \    / \
 *      nil nil nil nil nil nil     nil nil nil nil nil nil
 *  
 * Notes:
 *    The longest path (root to farthest NIL) is no more
 *  than twice the length of shortest path (root to nearest NIL)
 *   - SHortest path: all black nodes
 *   - Longest path: alernating red and black
 *
 */
```

# _How to rotate_

```c
/*      y   right rotate     x
/      / \  ------------>   / \ 
/     x	  c                a   y 
/    / \     left rotate      / \ 
/   a   b   <------------    b   c
*/
```


# __Feb Updates__

![](https://i.imgur.com/3znf2g8.jpg)



# _Resources_



[@](https://m.cplusplus.com/reference/iterator/iterator) cplusplus/iterator  
[@](https://m.cplusplus.com/reference/iterator/iterator_traits) cplusplus/iterator_traits  \
[@](https://m.cplusplus.com/reference/iterator/RandomAccessIterator) cplusplus/RandomAccessIter  

[@](https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a01052_source.html) gcc.gnu.stl_iterator.h  \
[@](https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits) iterator_traits w/ distance() example 





# _To know_

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

# _Things to learn_

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

# _Red black tree_
- principle
- implementation




# _Stack_
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



# _Pair (unrel. to stack/vector yet ez to do)_
todolist
- class pair only has public mems
- occf
  - beware of copy constr
- operators == != < <= > >=
- make_pair
  - fn: 
`templ<typename X,typename Y> pair<X,Y> make_pair(X x, Y y) -> pair<X, Y>(x, y)`







# _Vector_
what is 2nd param: `typename Allocator = std::allocator<T>`
- template<typename T, typename Allocator = std::allocator<T>>



# _vector_iterator - (Virtual Class)_
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



# _vector_const_iterator - (Virtual Class)_
explicit
```
public:

explicit vector_const_iterator(pointer ptr) : m_ptr(ptr){
}

virtual ~vector_const_iterator(void) {
}
```



