/*                               C++ CHEATSHEAT                          


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
Basically: *pointer = new int
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

*/
#include <iostream>;
using std::cout;

void main() {
	int num{ 10 };
	int* pointr{&num};
	cout << *pointr;
}
