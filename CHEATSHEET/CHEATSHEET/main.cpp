/*                               C++ CHEATSHEAT                          
FAST C++:
Use ++I so that you do not store and create a copy inside the memory register, but just increment the value.
Try to avoid copying big objects into and out of functions - use addresses and pointers.
Always implement Move constructor to avoid unnecessary deep copies.
Use initialisation lists to declare and initialise simultaneously!
Use inline functions for one time functions to generate assembly code. Not good for repeating funcs!
Use constexpr do define items that can be evaluated at compile time and don't have to be computed at run time!
Template <int N> - create structures at compile time. (maybe)
Use emplace_back with vectors to create the object inside the vector without unnecessary copies and without moving. Will do an inplace construction.

Poco library and JSON header file.

COMMENTS - /* *\
IMPORTS - include<iostream>, include"my_personal_header"
HEADER .h FILES - used to store to Prototype of the function so that a program can have access to it but its implementation is hidden. Not for Open Source.



VS SET UP:
Each program has to have its own project. The project has its own configuration and own folder. The program launches from the main() function, so there
can only be one main() function per project.



DECLARATION and INITIALIZATION:
int number {10};
vector<int> {10, 10, 10};
Its better to always initialize variables since otherwise they will most likely end up holding whatever data was at that address -> Garbage.



FUNCTIONS: 
Just one main function.

void main(int age, int number){

}



PROTOTYPE:
A function declaration for the compiler. To be put at the top of the file.
void main(int age, int number);

void main(int age, int number){
		some code
	}



FUNCTION OVERLOADING:
You can have multiple functions with the same name, but with different parameters inside. When passing the data inside those functions, the compiler will
decide on its own which one to use based on the data.

void main(int age);
void main(string name);

void main(int age){
	code for age
}

void main(string name){
	code for name
}



INLINE FUNCTION:
An inline function tells the compiler to generate assembly code in its space in order to save time and skip the function call.
That is useful for fast one time functions, but not good for anything that has to be repeated multiple times.

inline int do_compute(int age, int time){
	some code
	}


PASS BY REFERENCE IN FUNCTION: 
When passing objects, integers, doubles, except array to a function, they get copied and you work with the copy instead.
That is good because it protects the original data from mutation. Unfortunately, the data to be copied might be very big 
and our program may end up using a ton of memory. To fix this, we can pass the variable inside the function by its reference.
This will save space but allow for mutation.

To signify you want the reference of a variable do &var_name.

void main(vector<int> &vec){
	some code
}

Now if you modify vec, it will also be modified outside the function.
To prevent such behaviour but also save space and time by not copying the whole structure use const:


void main(const vector<int> &vec){
	will throw error if one tries to change data in vector.
}
without the &, we are creating a copy of str in each iteration. So we replace the value of the copy. If we pass a reference though, it is not
a copy anymore, but the real item. Saves time and memory from copying each item from the array.
for (auto &str: string){
	str = "Funny" - will put each element of the string vector to funny cus you are using the reference.
}

HOW MEMORY WORKS:

Stack - memory for fast allocation where local variables and function definitions go. Each thread has its own stack. No need to destroy manually.
The stack is very fast. Short life.
Heap - dynamic memory where global variables go. Also variables added with "new" keyword. All threads have access to the stack. Need to destroy variables,
else: memory leak. Slow compared to the Stack. Long life in the program.

How are variables represented in memory?
For example the variable int num {10}. 10 is the value of the variable that is written in the memory. This same memory space, has its address.
So value in memory -> [10] --address--> 2000 for example. In the address 2000 we can find the variable with value 10.



POINTERS:

Now what about pointers? Pointers are variables that point store an address as a value. So for example if we do int *p = &num we now have the following:
Pointer with value in memory -> [2000] --address--> 3000 since the pointer also has its own memory address where the value is found.
Now, the funny part. From this point on, after we declare to which address the pointer points to, if we change the value of the pointer,
we will also end up changing the value of the variable that the pointer is pointing to!

When declaring a pointer, we must also declare its type! A non initialized pointer will have garbage data inside it.

nullptr - makes it so that the pointer points to nowhere.

string food = "Pizza";
string *ptr = &food;

// Change the value of the pointer - dereferencing.
(*ptr).at(0) - if it points to a vector and you want to use one of its methods.s
*ptr = "Hamburger";

// Output the new value of the pointer (Hamburger)
cout << *ptr << "\n";

// Output the new value of the food variable (Hamburger)
cout << food << "\n";

To loop through an array using a pointer, just do *(pointer + 1) until you reach the sentinel value (aka poison pill).
cout << *pointer++  - basically return the dereferenced pointer value and update the pointer address with 1 to get next value in loop.

POINTER CONSTANTS:
const int *pointer {&data}; - the data pointed to by the pointer is constant and cannot be change but the pointer itself can move to another data.
int *const pointer {&data}; - the data pointed to by the pointer can be changed, but the pointer itself cannot move to another data.
const int *const pointer {&data}; - neither the data, nor the reference can be changed.

POINTER ARITHMETIC:
point++ will give us the next element. Same as pointer + 1
pointer - pointer will give us the amount of items between the 2 pointers.
pointer == pointer will check addresses 
*pointer == *pointer will check values

POINTER RETURN FUNCTIONS:

type *function_name(arg, arg)

int *return_pointer_to_biggest(num_1, num_2) - will return a pointer to the biggest num

!!! never return a pointer to a local variable! Once the function terminates, so will the variable! Instead, create a new variable on the HEAP and
return a pointer to it!

!!! POINTER PITFALLS!
-	uninitialized pointers are dangerous! Access random data and can corrupt data!
-   pointers pointing to invalid data. For example a pointer pointing to a long gone local variable. (Use NEW for HEAP!)
-	having 2 pointers point at the same memory, then releasing one pointer (delete) and trying to access memory with another. Will corrupt data.
-	not checking if new fails with try/except#
-	leaking memory - losing pointer to data on HEAP




ARRAYS:
Arrays must be declared with their size. This must also be passed to the function using the array,
since there is no other way to know how big the array is.

double getAverage(int arr[], int size) {
  int i, sum = 0;
  double avg;

   for (i = 0; i < size; ++i) {
	  sum += arr[i];
   }
   avg = double(sum) / size;

   return avg;
}

Declare an array:
type array_name[size] where [] is the actual array declaration.
As such it is normal to see: int array[3] {1, 2, 3}; and string my_strings[2] {"string_1", "string_2"}
We can also declare an array of chars. 

To dynamically declare arrays, one must use the new keyword. Pointer to new array.
int* array_pointer = new int [10];
This has now allocated an array of size 10 on the Heap. Don;t forget to delete it afterwards! delete[] array_pointer

The value of an array is the address of the first element in the array.
So basically int arr[2] {1, 2};
arr = the address of arr[0] or the address of 1.
If we dereference arr like *arr, since arr is an address, we will get... 1!
So basically doing int *pointer {arr} makes it so that the pointer is pointing to the address of arr[0]! 

How do pointer[0] and pointer[1] give 1 and 2 then!? This basically means arr[0][0] which is 1[0]? Well, not exactly.
Yes, if you dereference it. But if you don't and you say pointer[0], you mean this address. Now pointer[1] is the address + 1.
What is this 1 though? Its the size of the type we have chosen for the pointer. And since array is a collection of entries, contiguous in memory,
that simply means that pointer[1] is the next address in memory, which for our array means the next element! We can also do it with *(pointer + 1).




C-STYLE STRING - perfectly explained by Kevin:
The array must have a \0 which is the point at which the loop stops. Otherwise, it does not know when to end.

char str1[] = {'a', 'b', 'c'}; creates an array of 3 characters, with the values 'a', 'b', and 'c'.
The size of the array is 3, which you can see with sizeof str1 (this returns the number of bytes,
but as a char is defined to be 1 byte it's the same as the number of elements).
Trying to calculate the length of the string contained in this array causes undefined behavior,
since str1 does not contain a C-style string as it has no '\0' terminator.
Your loop calculating this goes out of the bounds of the array.

char str2[10] = {'a', 'b', 'c'}; creates an array of 10 characters, with the values 'a', 'b', 'c', and 7 '\0's.
The size of the array is 10. Calculating the length of the string in str2 gives you 3, since str2[3] is '\0';

If you want to create an array containing a C-style string without specifying the size,
you can do char str[] = {'a', 'b', 'c', '\0'};, or more simply, char str[] = "abc";.

answered Jan 24, 2021 at 1:46
Kevin



VECTORS - basically Python lists.
vector<type> vector_name {}




++I VS I++
In short ++I increments first and returns the result, but I++ returns the old version and increments after. So you need 2 memory spaces in I++.
There are some significant performance differences discussed below (in C, last paragraph is for C++):
Peter Schachte
Originally Answered: Why is ++i more efficient than i++?
It depends on your compiler and the context. With a good compiler, ++i is only more efficient than i++
when you dont really have a choice of which one to use.

With the pre-increment (++i), first i is updated and then it is used. There is no need for two separate values,
so only one register is needed. With the post-increment, the old value must be retained while i is incremented,
and then the old value returned, so two registers must be used. Early, non-optimising C compilers were too crude
to notice when the expression is just used for its side-effect, and its value ignored.

When ++i or i++ is used as a statement (including in the increment part of a for loop), the two are semantically
identical, and there is no reason for holding on to the old value of i. So in the 1970s or 80s, when C compilers
were pretty weak, you were better off with ++i than with i++ because it wouldnt copy the value of i to a different
register, or possibly to memory, for no reason. Modern compilers (for a couple of decades now) are smart enough to
recognise that it doesnt need to save the old value in this case, and will generate the same code for both.

When using i++ as an expression, where you really do care about the difference, and assuming you cant reorganise your code
so that you can use ++i, the compiler probably wont be able to reorganise your code either, so although ++i is more efficient
than i++, you dont have a choice.

Dmitriy Genzel makes a good point that the difference is much greater in C++ when working with objects,
where preserving the old value requires copying an object and not just copying a register. Nevertheless,
knowing what a good job modern C/C++ compilers do, I would be very surprised if they did not optimise the
case of post-increment used as a statement. Its a very simple optimisation to always transform post-increments
to pre-increments when the value is ignored, and I cant see how post-increment could ever be more efficient that pre-increment.



LOOPS:
Normal:
for (size_t i{0}; i<10; ++i){ --- size_t is always 0 or positive.
	SOME CODE
}
For entry in items:
for (auto entry: vec){  --- use auto when you are not sure which type you have.
	SOME CODE
}

While:
while (true){
	some code
}

Do while:
do {

} while (true);

Do while will always enter first time to DO and then check if the condition is covered to continue looping.



CONDITIONAL STATEMENTS: Bro just look them up.
Also, always use a break; statement after each case in a switch case (don't use switch cases) otherwise you will not check the condition,
but keep executing the code until you reach a break even if the cases don't match. Its wild, and please, don't try to use it for monkey patches
and "cool" hacks...



VON NEUMANN BOTTLENECK - Found it online, so you are about to read it now. Its a good read, trust me.
Basically modern computers have 2 parts. CPU and Memory and the are separated, but communicate through the system BUS.
Cool, but the transfer rates are limited. So in the end, a fast CPU is mostly idle if it cannot get the data it needs.
Solutions:
Caching in L1 (per core), L2 and L3 (shared) cache. Optimizing for less cache misses is important. 
Basically you load some data in the cache. Next time you need a variable, you search for it in the cache.
If its there, cool, else - cache miss, now need to load more.
Prefetching the data in cache at startup so the data is ready.
Branch prediction - literally insane.
Multithreading - also insane though less so.
NDP - near data processing. Cool but too distant I think. I mean, for me.
Hardware acceleration - ship the stuff to the GPU.
SoC - system on a chip. Most stuff are on the same chip. Pretty good, Phones, Apple M2 ARM designs, its how they get those insane performance stuff..



DYNAMIC MEMORY ALLOCATION - at HEAP.
Easy, just use the keyword "new".
Basically: int *pointer = new int; MUST ALWAYS BE A POINTER!  
Now we have a pointer that points to the new int variable. Unfortunately, it is garbage, so you need to dereference it and set it a new value.
*pointer = 200. Now that new int has the value of 200. Be careful! If you lose the pointer, you lose access to the value forever. It becomes a
MEMORY LEAK!!!
To remove the variable from the HEAP, just do "delete" pointer_name.
TY Mr Fooz
For each malloc or calloc, there should be exactly one free.
For each new there should be exactly one delete.
For each new[] there should be exactly one delete[].

delete *pointer
delete [] pointer

Creating an array gives us the first entry as the memory address variable to the pointer.

double *pointer {nullpointr};
pointer = new double[size];

pointer points to the first address in the array. Do not lose it, no other way to access.


L AND R VALUES.

L VALUE - has an address and is addressable.

str = 100

str is L Value, its addressable, but 100 is not, its an R value.

WHEN TO USE WHICH IN FUNCTIONS:

- pass by value - value is not modified and parameters are small and efficient to copy. (int, chars)
- pass by pointer - value is expensive to copy and may be modified (yes to null reference) - the pointer can be a null pointr
- pass by reference - value is expensive to copy and may be modified (no null reference) - the address is always valid, can never be null


CLASSES

create using the class keyword.

class MyClass {
	(class Attributes)
public:
 int attribute_1 {10} (this is public)
 double attribute_2 {20.0} (this is also public)
	(class Methods)
private:
 void say_hi {cout << hi}; (this is private)
 void say_bye {cout << bye}; (this is also private)

}

set a class:

MyClass class_1; 
MyClass *class_2 = new MyClass;

now class_2 is a pointer to the object in the HEAP.

to access the variables use (*class_2).attribute_1 or class_2 -> attribute_1


public - can be accessed outside of the class
private - cannot be viewed or accessed outside of the class
protected - cannot be viewed/accessed from outside of the class but can be accessed from child classes through inheritance

Specify methods either in the class or as following:

MyClass::method_1(){ 
	return 1
};

Consider separating class declaration and implementation in .cpp and .h files.

Use guards:
#ifndef _MYCLASS_H_
#define _MYCLASS_H_

#endif

Used to stop double declarations if imported in multiple files.

#include "MyClass.h" use "" for self defined classes.

How to use .h and .cpp files.

Write the declaration in a .h file.
In a guard:
#ifndef _MYCLASS_H_
#define _MYCLASS_H_
Basically class MyClass {
	Attributes
	Method DECLARATIONS ONLY! (Prototypes basically)
}
#endif

In a .cpp file write the implementation of the methods:
#include "MyClass.h"
voic MyClass::my_method() {
	return 1
}


#include "MyClass.h" in main or whenever you use the class.

Constructors - Have the class name and are called on class creation.

Can be overloaded!
Define them where methods are defined.
MyClass(int attribute_1, int attribute_2)
MyClass(double attribute_1, double attribute_2) 

Destructors - Have the class name with a ~ in front and are called automatically on class destruction.
A good place to free up memory that was being held by the class.

~MyClass()

~ is the char on the left of the 1 with + shift.

Default constructor - when no other constructor is provided.

Be careful. As soon as we define a constructor, the default destructor disappears. If we want to define objects with the default constructor,
we need to define it ourselves. MyClass(){}

Initialisation lists - when using the constructor the usual way, the values are first initialised to some garbage data and then afterwards,
assigned the data that we pass through the constructor. This is inefficient. Instead, use initialisation lists, that will initialise the variable with
the passed value and do it together, in one go.

Player::Player(str name, int health) : name(name), health(health){

of course, those values have to be declared as private/public/protected at the top of the class, where attributes are declared.
	
}

Delegating constructors - useable only with initialisation lists. Basically it allows you to call a different constructor overload from within
your constructor in order to reuse code. Basically, the first constructor does all the heavy lifting, constructor delegation allows us to call the first
constructor with some predefined variables when calling other constructors. 

Player::Player(str name, int health) : name(name), health(health) {
	Here we can have some more logic or code.
}


Player::Player() : Player {"None", 100} {
	When the constructor with no arguments is called, the above constructor with args
	"None" and 100 will be called.
}

Player::Player(str name) : Player {name, 100) {
	The first constructor with name = name and health 100 will be called.

}

Important to note. The first constructor calls the second which constructs the object. The program then recursively returns to the first and executes the code in the body of
that constructor as well.

Using defaults in constructors:
First define a prototype with the defaults:
Player::Player(name="Tony"){};
Then define the actual implementation using initialisation lists:
Player::Player(name_val) : name(name_val){};


COPY CONSTRUCTOR

The copy constructor is used whenever an object has to be copied. It basically takes all class members and copies them. Such a constructor is automatically provided 
from the compiler.
When is it being used? Whenever we pass an object as value to a function, return an object from a function or try to copy an object.

Copying an object:
Object copy_object {old_object}; - This will produce a copy.

Creating a copy constructor:

Object::Object(const Object &source) : first_attribute(source.first_attribute), second_attribute(source.second_attribute) {
   - const so that we cannot change the source.\
   - The source is an address so that we have access to the previous object. If it were value, we would call the copy constructor
   and have an endless recursive loop.
   - We can use initialisation lists to assign the values immediately or call the constructor through delegation (see above). Just use
   &source.value for the values.
   - Be careful when dealing with pointers and addresses. Only the pointer value will be copied, not the data itself. As such, this will 
   produce a shallow copy!
}

DEEP AND SHALLOW COPIES:

Be extra careful when using addresses and pointers with classes.
If you pass a pointer to a class, when the class is copied, that pointer will be copied as well BUT NOT the value that it is pointing to!
Why is that a problem? Because when the object with the pointer gets out of scope, the memory that was pointed to will be freed, despite
it still being referenced by other objects! This is called a shallow copy. Always implement deep copies by copying the data when working
with pointers and classes!

For example - shallow copy:
class MyClass {
	MyClass::MyClass (int pointer_to_data){
		data_pointer = pointer_to_data
	}
}

For example - deep copy:

class MyClass {
	int* new_pointer;
	MyClass::MyClass (int* pointer_to_data){
		new_pointer = new int - this creates a new pointer on the heap
		*new_pointer =  *pointer_to_data - this sets the data from the new_pointer to the data from pointer_to_data creating a deep copy.
	}
}
Alternatively, in the copy constructor:

MyClass::MyClass (const MyClass &source) {
	new_pointer = new int;
	*new_pointer = *source.new_pointer;
	
}

//class MyClass {
//	public:
//		int *data;
//
//	MyClass(int* pointer) {
//		data = pointer;
//	};
//
//	MyClass(const MyClass& source) {
//		data = source.data;
//	};
//
//};
//
//
//void main() {
//	//int value{ 10 };
//	//int* pointer{ &value };
//	//MyClass first = MyClass(pointer);
//	//cout << first.data << std::endl;
//	//MyClass second = test_func(first);
//	//cout << second.data << std::endl;
//}

// - This code will produce an error since a shallow copy will be used and the memory will be freed.

// - To fix, use deep copy:

//#include <iostream>;
//using std::cout;
//
//class MyClass {
//	public:
//		int* data;
//
//		MyClass(int* pointer_to_data) {
//			data = new int;
//			*data = *pointer_to_data;
//		};

	deallocate when using destructor.
//};
//
//MyClass test_func(MyClass first) {
//	return first;
//};
//
//void main() {
//	int value{ 10 };
//	int* pointer{ &value };
//	MyClass first = MyClass(pointer);
//	cout <<  first.data << std::endl;
//	MyClass second = test_func(first);
//	cout <<	 second.data << std::endl;
//	cout << &first.data << std::endl;
//	cout << &second.data << std::endl;
//	cout << *first.data << std::endl;
//	cout << *second.data << std::endl;
//}


DONT FORGET TO IMPLEMENT THE DESTRUCTOR AND REMOVE THE OBJECTS FROM THE HEAP! MEMORY LEAK!!!!


However, copying objects can be a significant performance bottleneck! The problem gets even higher if we have to
do deepcopies as well. As such, as of c++ 11, we can use the Move constructor:

Copy elision - Return Value Optimisation - compiler technique to remove unnecessary copying.

MOVE CONSTRUCTOR:
First, what is the problem? We inject an object into a function, that object gets copied with all its pointers values (shallow copy).
When the function returns, the first object is copied and the copy is returned, then the first object is deleted.
Now the copy has an pointer that points to data that has been deleted from first object. Trying to access this data will result in an error.
To fix this, we do deep copies where we create a new pointer and copy the data to a new memory address. As such when the first object gets deleted,
the copy has the data in a new memory address. That is time consuming. When doing it with R values, we have to continue deep copying classes that 
we were never going to use anyway. So what we do is we move the data, since we don't care about copying it and accessing it later. 
We set the pointer of the R value to the new object and we then nullpointr it. That means than when it gets garbage collected, 
it won't free the memory in the pointer because it isn't pointing anywhere! Now of course that means that we can no longer access source.data from
the R value, but we were never going to anyway. This was just temporary so that we can skip the tedious process of copying everything. We just move it.


The move constructor is as simple as it is complicated. Even though such a statement may puzzle you at first,
take a look at what I mean:

First, we need to remember what are L and R values. Now R values do not have a specific reference, so to say. They are 200, 100, Class(20), 
one time created values, stored in a collection maybe, that cannot be accessed except through the collection.
Vector(1, 2, 3, 4, 5) - all of them are R values. Now, assume we have to push all of those values in the vector. Well to do it, we
use a function that takes this R value, copies it and then stores the copy in the vector. Moreover, as the vector increases in size, it has to
move - recopy - its contents. That can end up being a significant performance hog! As such, implementing a Move constructor is a good idea.
It takes the reference of the R value, creates a new R value but does not copy the pointers, instead it sets the data to the new object and 
sets the old object pointer to a nullpointr. That prevents all of the deepcopies and achieves the same result with very good performance gains.

To access the address of an R value, use &&.
MyClass::MyClass (MyClass &&source) {
	data = source.data;
	source.data = nullpointr;
}
	
.THIS POINTER:

The this pointer is equivalent to the python self keyword. You can skip them in the class since the compiler is smart enough to know what
you want. If you want to have the same variable names though, you CANNOT skip it.

this -> balance = balance

return this - returns pointer to the object
return *this - dereference - returns a copy of the object


CONST CORRECTNESS:
Working with const classes in C++ is a little weird.
You declare a class as const and declare a getter method for its private attributes.
All is fine, no harm done right? So you try to access the getter method. BAM! Error! Why?
Well, the compiler has no idea this is a getter method so of course, it just forbids everything.
To tell the compiler this method won't modify anything, do the following:

My Class {
	private:
		int age;
	public:
		int get_age() const {
			return age;
		}

}

Add const after the method that you want to mark as non changing. This will allow the compiler to run it.


STATIC MEMBERS:
Static members of a class are basically attributes that can be described as global and shared between all instances.
For example, a counter of how many instances of a class are currently created. Static members can be accessed by static
functions, which cannot access other members of the class.

Just put the static keyword in front of the variable/method.

static int age;
static int get_age(){};

Declare the static members in the .h header file. Then in the .cpp file, instantiate them.
For example, in the .cpp file, set the amount of created instances to 0 like that:
int Player::instances {0};. Then in the Constructor and Destructor increment and decrement the count
accordingly.

STRUCT VS CLASS:
Structs are a relic of the C language. Basically used to hold data. They have NO methods and 
all of the data is public.

Classes can have methods and some of the data may be private.

FRIENDS:
A class can designate a function or another class as their friend and as such, this function or 
class will get access to all private members.

Declare friends at the top of the class, where you also declare the other variables. For example:

class MyClass {
	friend void display_class(MyClass &my_class_address){}; - only this function has access to all private variables
	friend void Person::speak(MyClass &my_class_address){}; - only this method has access to all private variables
	friend class Other_class; - all methods of this class have access to MyClass private attributes
	private:
		int age;
		string private_variable;
}

void display_class(MyClass &my_class_address){ cout << my_class_address.private_variable } 

OPERATOR OVERLOADING:

Operators like +, *, /, - etc can be overloaded to do whatever the programmer wishes them to do for that specific class.
Basically the equivalent of magic methods in Python.

MyClass one {Variable};
MyClass two = one - this is a copy operator. Same as MyClass two {one}; This is copying.
two = one - this is ASSIGNMENT and NOT copying.

*Check for if class is same:
* if (this == &class_to_compare_with) - basically check if the pointer value address of this class is the same as the 
* address to the class we are comparing with. If yes, we have same class.

OVERLOADING THE ASSIGNMENT OPERATOR - COPY - Assignment will now copy.
MyClass &operator=(const MyClass &right_hand_side){}; - this in .H file.
MyClass &MyClass::operator=(const MyClass &right_hand_side){ function body } - this in .CPP file.

(Return an address since an address is "a pointer to an existing object that cannot be Null" - Carl.)



B = A

Make sure we are not assigning to ourselves.
Deallocate the memory that was taken by the variables of B. (this is not creation, B already exists). (ABSOLUTELY ALWAYS DEALLOCATE MEMORY FROM THE HEAP!)
Deep Copy all memory from A to the variables of B.
Return B address.

OVERLOADING THE ASSIGNMENT OPERATOR - MOVE - Assignment will now move. Works with R values.

MyString s1;
s1 = MyString{"Frank"} - this is an R value, used constructed only once and then discarded.

MyClass &MyClass::operator=(MyClass &&right_hand_side) { function body }

- check if we are assigning to ourselves.
- delete any pointer variables of left_hand_side
- move pointer from right_hand_side to left_hand_side
- null the pointer on the right_hand_side so when it gets garbage collected, it doesn't free the memory its pointing to and the data with it.

MEMBER FUNCTION OVERLOADING:
Translates to A.add(B). Now it is required for A to be before B if B doesn't implement the overload.
C = A + 10 will work.
C = 10 + A will NOT work since 10.add(A) - 10 doesn't have the implementation for class A. 

NON MEMBER FUNCTION OVERLOADING:
Fixes the above ordering problem.

ReturnType operator+(const Type &left, const Type &right).

In order to have access to private members of left and right,
both left and right have to define the global overload function as a friend.

Supposedly the preferred way to code overloading, but oh my, I hate it.
Implement them in the MyClass.cpp file. Declare in the MyClass.h file as friends.

OVERLOADING THE STREAM INSERTION AND EXTRACTION OPERATORS << AND >> :
https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/

#include <iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i =0)
	{ real = r; imag = i; }
	friend ostream & operator << (ostream &out, const Complex &c);
	friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c)
{
	out << c.real;
	out << "+i" << c.imag << endl;
	return out;
}

istream & operator >> (istream &in, Complex &c)
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imaginary Part ";
	in >> c.imag;
	return in;
}

int main()
{
Complex c1;
cin >> c1;
cout << "The complex object is ";
cout << c1;
return 0;
}


bool Money::operator==(const Money& right_hand_side) const  - the const after the function
means that the this.object will not be changed, it is const qualified. Available only on 
member functions, not global ones.

Rule of five
Because the presence of a user-defined (or = default or = delete declared) destructor,
copy-constructor, or copy-assignment operator prevents implicit definition of the move constructor
and the move assignment operator, any class for which move semantics are desirable,
has to declare all five special member functions.


INHERITANCE:

There are 3 types of inheritance. Public, private and protected. Public inheritance is an "is-A" type.
To inherit, do:

class Derived: public Base {
	public:
 		void say_hello(){
   			says hello
      			Base::say_hello() - invoke the method of Base.
		}
}

Now the way that constructors and destructors work:
Base constructor
Derived constructor
Derived destructor
Base destructor

Now if we have multiple overloads in Derived and in Base and we call an overloaded constructor in Derived,
the base constructor in Base will be called unless otherwise specified.

For example with initialisation lists:

Derived::Derived(int value, int x) : Base{x}, value_double{value * 2} {}; (value_double is a value defined in derived, the x is defined in Base class.)

This will now call the Base{x} constructor.

You can also redefine existing methods in the derived class. See above for more info.

CONSTEXPR:
constexpr is a feature added in C++ 11. The main idea is a performance improvement of programs by doing computations at compile time rather than run time.
(GEEKS for GEEKS)
// C++ program to demonstrate constexpr function for product
// of two numbers. By specifying constexpr, we suggest
// compiler to evaluate value at compile time
#include <iostream>
 
constexpr int product(int x, int y) { return (x * y); }
 
int main()
{
    constexpr int x = product(10, 20);
    std::cout << x;
    return 0;
}

POLYMORPHISM:

Static Binding:

Normal methods in inherited classes - They use STATIC BINDING, meaning that they are compile time functions.
For example:
Account *p = Trust()
p.withdraw will now call Account::withdraw because it sees its of type Account.

Static Binding is defined on compile time and prevents us from using polymorphism optimally.

Dynamic Binding:

To correct that, we can use virtual functions - DYNAMIC BINDING - run time functions.
Dynamic Binding works only with pointers and with objects at the Heap or with references and objects at the Stack. The pointer has to point to the
Base class.
So you will have to do Base *p = new Derived();
Otherwise you will get static binding.
If you are using smart pointer, you may need to do (*my_class)->attribute to access the attribute.

Declare a function (method) as a virtual:

virtual void method_1(){};

You always need a virtual destructor if you have virtual functions. If you provide a virtual destructor in the Base class,
then all Derived classes inherit the virtual destructor and don't need to define it. Otherwise, on delete, you will call the 
Base destructor which may leave some memory leaks behind. It is also classified as undefined behaviour.

Use reference functions to call methods of dynamically bounded classes or pointer functions.
As a class, always use the Base class in the function! So reference to Base class!
!!!ALWAYS WORK WITH REFERENCES/POINTERS WITH VIRTUAL FUNCTIONS AND DYNAMIC BINDING!!!
void func (Account &account){
	account.withdraw()
}

Override:

Overriding is dynamically bound, while redefinition is statically bound.
Functions on Base and Derived must be exactly the same. If they are not, then that will be considered as redefinition and
not override, leading to hard to find errors.

To fix it, use override specifier.

virtual void method_1() const override{} - use on the Derived class to specify that this function overrides the Base class version.

Final:

Prevents a class from being derived from.
Prevents a method from being overriden.


class MyClass final {}
virtual void do_something () final {}

Pure virtual classes:
- Used to define abstract classes. (templates that have no instances)
- Need at least one pure virtual function

void virtual draw () = 0; (Prototype) - just the template. No implementation. That is a pure virtual function.

If you don't override the pure virtual function in the derived class, they are also considered abstract classes.

SMART POINTERS:
#include<memory>

Pointer arithmetic is unfortunately not supported within smart pointers.
Automatically take care for new and deletion.
Use the HEAP.

Using smart pointers:
std::smart_pointer<My_class> var_poitner_name = ...
var_pointer_name -> method()
*var_pointer_name - dereference.

RAII - Resource Acquisition is Initialisation
Resource is acquired and initialised in object constructor and released in the destructor.

UNIQUE_POINTER: HEAP
unique_ptr - Only one pointer pointing to an object on the HEAP, no copy or assignment but move is there. When pointer is destroyed,
whatever it was pointing to is destroyed as well.
std::unique_ptr<int> pointer {10};
pointer.get() - returns a raw pointer.
pointer.reset() - frees memory, deletes object.
if (pointer) - checks if it exists (not reset)

vector.push_back(pointer) will not work because copy is not allowed (unique_ptr).
Instead use vector.push_back(std::move(pointer)) to change ownership of the pointer.
std::make_unique() - can be used to initialise a unique pointer.

std::unique_ptr<int> my_int = std::make_unique<int>(100)
std::unique_ptr<Class> my_class = std::make_unique<Class>(arg1, arg2, arg3)
auto my_something = std::make_unique<Class>(arg1, arg2, arg3) - will deduce the type automatically.

If you want to reassign a unique pointer (pointer_new = pointer), use the std::move() function as described above.
After we move pointer to pointer_new, pointer will be a nullptr and will return false on if (pointer):

WE CANNOT COPY UNIQUE POINTERS IN ANY WAY! IF YOU PASS A UNIQUE POINTER TO A FUNCTION OR A FOR LOOP, IT HAS TO BE 
THROUGH A REFERENCE! CONST REFERENCE MOST OFTEN THAN NOT!

SHARED_POINTER: HEAP
shared_ptr - Many pointers can point to an object on the HEAP, copy, assignment and movee are allowed. When no pointer is pointing
to the object, that object is destroyed.
Does NOT support managing arrays.

std::shared_ptr<int> pointer {10};
pointer.use_count(); - displays the amount of currently active references.
pointer.reset(); - will set pointer to nullpointr and do -1 on the shared_ptr reference.
std::make_shared() - same as make unique 
Since copy is allowed, we do not need to use references.

If you use a vector with vector.push_back(pointer), you create a copy of the pointer and push it back into the vector.
When the vector is destroyed, the copied pointer is destroyed is as well, but the object is not! This is unlike the usage
with unique_ptr.

WEAK_POINTER: HEAP
weak_ptr - does not OWN the object.
Is always created from shared pointers but does not increment the reference counter.
They prevent circular reference that ultimately prevents HEAP deallocation.
To use a weak pointer, promote it to a shared pointer and check if its null.
Follow: https://stackoverflow.com/questions/67977119/how-to-access-the-class-member-functions-from-a-weak-pointer-in-c

A (b) <---> B(a)
A has a shared pointer to B and B has a shared pointer to A.
Now what ultimately happens is that when A and B are requested for deletion, A points to B and B points to A, references stay at 1
and deletion of the objects is not performed, only the pointers on the stack. Memory leak.
Weak pointers solve this problem.

Use make_shared(), no make_weak(). 
Use when we have to traverse graphs and multiple objects that may end up having a circular reference. (A doubly linked list for example)

CUSTOM DELETERS: - to be used when we need to delete some allocated resources that are managed by the pointer. For example, a connection can be closed, or a log
can be written.

Cannot use make_unique/make_shared since we need to provide our custom deleter.
Custom deleters are called on pointer cleanup.

void my_deleter(Class *pointer){
	some other stuff
	delete pointer;
}

std::unique<Class> my_class_pointer {new Class{}, my_deleter} - pass the deleter as a function argument.

USE:
1. Unique pointers first.
2. Shared pointers if unique pointers do not work for this implementation.
3. Weak pointers if shared pointers create strong circular references. A points to B and B points to A. (Doubly linked list).

EXCEPTION HANDLING:

DO NOT THROW EXCEPTIONS IN DESTRUCTORS!

noexcept - states when the function will definitely not throw any exceptions.

Basically the same exception handling as in other languages.

class MyException {
	public:
 		MyException() = default; - constructor
   		~MyExcetpion() = default; - destructor
     }

throw MyException{}; - instance of MyException.
throw 0;

try {}

catch(const MyException &exception)
{
exception.what() - string error representation if std::exception is inherited.
}

To handle multiple exception, do multiple catch() es.

catch(const int &exception)
catch(const std::string &exception)

std::exception - STD Exception library.
The exception.what() method returns a string of the error.
To use the .what() method, override:
virtual const char *what() const noexcept;

class MyException public std::exception {
	public:
 		MyException() = default; - constructor
   		~MyExcetpion() = default; - destructor
     		virtual const char *what() const noexcept {
       			return "MyExcetption string"
		}
     }

STL: A set of libraries that provide useful classes and algorithms.

MACROS: (BEWARE - OLD - USE TEMPLATES) #define max_size 100 (preprocessor sets those variables and it doesn't know C++, it just replaces. VERY error prone.)

FUNCTION TEMPLATES: - happens at compile time!

template<typename T> or template<class T> or template<typename T1, typename T2>
T my_func(T value) {
	return value
}

my_func<int>(5);

template<int N> - can be used for when the class is known, but we want to pass the value as a template parameter. (For example, when something has to be executed at compile time and not at runtime.)


CLASS TEMPLATES: - happen at compile time + implement only in .h files!
template <typename T, int N>
class MyClass {
	T value;
}	int value_2 {N}; - at compile time, this will become equal to int value_2 {2}; for example

MyClass<int, 2>(100)

CONTAINERS:
Array, Vector, Map, Set, List- (doubly linked list)
https://en.cppreference.com/w/cpp/container
emplace_back - inplace creation for an object in a vector.
back_inserter - an iterator to signify the end of the vector at which elements are to be inserter. Use that instead of vector.end(), since using end() has undefined
behaviour.
advance - a function to move the iterator. advance(2) will move the iterator 2 spots forwards.

ITERATORS: - used to iterate through collections. The for range loop is implemented by an iterator. To be used when the for range loop cannot be
used and a custom iterator is needed.
Iterators are very near to poiters, can be dereferenced.

std::vector<int>::iterator it1;

for (auto it = vec.begin(); it != vec.end(); ++it){
	dereferenced iterator object - *it
 }

normal - begin, end
const - cbegin, cend
reverse - rbegin, rend
const_reverse - crbegin, crend

end is after the last element of the iterator.

ALGORITHMS:
#include<algorithms>

std::find - basically if N in vector<std::string> {A, B, C, D, N} either finds it or returns v.end()
To check, do if result == std::end(vector)

Remember to implement custom < and == operators for your objects, since the std::algorithms functions use those 2 operators very often
to compare and reorder the objects, same with the containers.

ENUMERATIONS:
Used to provide clearer code.

Unscoped enumeration - sometimes creates issues when the names of multiple enumerations intertwine or the values are the same (0 == 0) etc.
enum Colour int {Green = 1, Red = 2, Blue = 3};

Scoped enumerations - solve the problems of unscoped enumerations. Just use those.
enum class Colour int {Green = 1, Red = 2, Blue = 3};

int green = int(Colour::Green); - need to be cast if scoped!

Colour my_colour = 2; (this will not be Red). 
Functions can return Colour, (enums), that way you can be sure that a function will return an integer, but it will in range for the enum.
Use switch cases so that all cases have equal access time!

underlying_type_t<Colour> - will return the type of Colour.

A cool thing to do is to overload to scope insertion operator (>>) and check if the input is whatever we expected from the user.
If not, an error can be returned or an Unknown entry can be set with a specific number.

An enum in a class has to provide the whole path - Player::Mode::Attack for example.

Basically, always use scoped enumerations.

NAMESPACES: - used to combat name collisions.

Defining namespaces

namespace myNamespace
{
  int a, b;
}
These variables can be accessed from within their namespace normally, with their identifier (either a or b), but if accessed from outside the myNamespace namespace they have to be properly qualified with the scope operator ::. This is why your second example is working fine, as you are using MyClass within the namespace that defines it.

Usage

myNamespace::a
myNamespace::b 
Using using

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using first::x;
  using second::y;
  cout << x << '\n';
  cout << y << '\n';
  cout << first::y << '\n';
  cout << second::x << '\n';
  return 0;
}
or

#include <iostream>
using namespace std;

namespace first
{
  int x = 5;
  int y = 10;
}

namespace second
{
  double x = 3.1416;
  double y = 2.7183;
}

int main () {
  using namespace first;
  cout << x << '\n';
  cout << y << '\n';
  cout << second::x << '\n';
  cout << second::y << '\n';
  return 0;
}

(I wrote a lof stuff but I didn't save it so...just check the links below, its more or less covered...)

FILE I/O:
https://www.geeksforgeeks.org/file-handling-c-classes/

STRINGSTREAMS: 
https://www.geeksforgeeks.org/stringstream-c-applications/

LAMBDA EXPRESSIONS:
https://builtin.com/software-engineering-perspectives/c-plus-plus-lambda

Basically, lambda expressions are anonymous functions. Who knew, right?
Well, some C++ background. Before Lambda expressions, people used to use functors, function objects.
Those are classes with the () operator overloaded, so that when you call the class, you actually execute a function.

MyClassFunctor(10) will call the operator() method of MyClassFunctor which if it does value * 10, we will get 100 as a result.
Well Lambdas compile to such classes under the hood.

[](int value_1, int value_2) - return type{
	function logic.
};

Thats it.

STATELESS LAMBDAS - Stateless lambdas have no knowledge of any arguements that have not been passed to them. They have no idea of what is outside of their scope.
The lambda above is a stateless lambda.

STATEFULL LAMBDAS - Statefull lambdas have knowledge of arguements that have not been passed to them, but that have been marked to them in their scope.
That happens the following way:
int x {10}

[x](int value_1) -> return type {
	have access to x but by value, meaning that is a copy of X and changing it works only inside the lambda, no changes are noted outside.
}

[this] - will capture by reference all the values in the class if the lambda is defined inside a class. In a class, always use this since values are captured
by reference regardless. [=] will capture by reference.
[&] - will capture by reference all the values in the scope of the lambda.
[=] - will capture by value (copy) all the values in the scope of the lambda.

How do those scope values work? Well they are simply this.value parameters in the creater Functor Class!
What this means is that [x](){}; will capture X the first time, and each time the lambda is called, it will use the already captured [x].

For example:
x = 100
auto my_lambda = [x](){ return x + 100}

first call will return 200 (100 + 100)
second call will return 200 (200 + 100) since the captured X is left out in a closure from the previous use as a class value element.
MyClass {
	int x = 100 (first call - 200, second call - 300 etc) The state is kept here and is not redeclared.
}

Passing functions as function arguments:
Pointers, std::function or lambdas: https://www.geeksforgeeks.org/passing-a-function-as-a-parameter-in-cpp/
Alternatively, you can just use auto.
auto my_function = auto function(auto func){ return func()};


C++ CONCURRENCY IN ACTION: 
In this huge chapter to follow, I will sum up my experience with C++ threading and concurrency, over the CPU. 

*/
