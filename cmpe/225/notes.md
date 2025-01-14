> Hi there, I'm devsimsek and this is a viable resource to study object oriented programming using c++
> 
> This material is open source, (Licensed by [MIT](https://devsimsek.mit-license.org))
> Contributions are welcome.
### **Object-Oriented Programming (OOP)**

OOP is a programming method that mimics the way we form models of the world. It is based on the concept of objects that have attributes (fields) and behaviour (functions/methods).

**Key Properties of OOP**

- **Encapsulation:**
    
    Encapsulation combines data structure with functions dedicated to manipulating the data. It encompasses:
    - Compiling a useful module
    - Private vs. public
    - Information hiding
    - Interface visibility of members of an object, providing only essential information.

- **Inheritance:**
    Inheritance allows new derived classes to inherit the data and functions from one or more previously designed base classes, while possibly redefining or adding new data & actions. Private stuff is not shared.
    
- **Polymorphism:**
    Polymorphism involves giving an action one name or symbol that is shared up & down the class hierarchy, with each class in the hierarchy implementing the action in a way appropriate to itself.
    
### **Function Overloading**
**Function overloading** is defining functions with the same name but with different sets of parameters in the same scope. This allows you to perform the same operation on different data types without needing separate function names. The compiler uses the parameter types to determine which version of the function to call.

**Example:**
```c++
#include <iostream>
using namespace std;

int area(int t1, int t2) {
return t1 * t2;
}

float area(float t1, float t2){
return t1 * t2;
}

int main() {
int i1 = 4, i2 = 25;
float f1 = 3.5, f2 = 1.5;

cout << "area of integer edges: "<<area(i1, i2)<< '\n';
cout << "area of float edges: "<<area(f1, f2)<< '\n';
return 0;
}

/*
Output:
area of integer edges: 100
area of float edges: 5.25
*/
```

**Explanation:**
1. Two `area()` functions are defined: one takes two integer arguments, and the other takes two float arguments.
2. In `main()`, two integer variables (`i1`, `i2`) and two float variables (`f1`, `f2`) are declared and initialized.
3. The `area()` function is called with integer arguments (`i1`, `i2`) and then with float arguments (`f1`, `f2`).
4. The compiler determines which version of the `area()` function to call based on the argument types and returns the appropriate result.

### **Function Templates**
**Function templates** are a powerful feature in C++ that allows you to write generic functions that can work with various data types without needing to write separate functions for each type. You define a function template using the `template` keyword followed by a template parameter list enclosed in angle brackets (`< >`). The template parameter list specifies the template parameters, which are placeholders for the actual data types that will be used when the function is called.

**Example:**
```c++
#include <iostream>
using namespace std;

template <class Type>
Type area(Type& t1, Type& t2)
{
return t1 * t2;
}

int main() {
int i1 = 4, i2 = 25;
float f1 = 3.5, f2 = 1.5;

cout << "area of integer edges: " << area(i1, i2) << '\n';
cout << "area of float edges: " << area(f1, f2) << '\n';
return 0;
}

/*
Output:
area of integer edges: 100
area of float edges: 5.25
*/
```

**Explanation:**
1. The `area()` function is defined as a template function using the `template` keyword and a template parameter `Type`.
2. The function takes two arguments of type `Type` (passed by reference) and returns a value of type `Type`.
3. In `main()`, two integer variables (`i1`, `i2`) and two float variables (`f1`, `f2`) are declared and initialized.
4. The `area()` template function is called with integer arguments (`i1`, `i2`) and then with float arguments (`f1`, `f2`).
5. When the `area()` template function is called, the compiler generates two separate function instances, one for integers and one for floats, based on the types of arguments passed.

### **Exception Handling**
Exception handling is a mechanism in C++ that allows you to handle runtime errors or exceptional situations in your program gracefully. An **exception** is an object that represents an error or an unusual event that occurs during program execution.

**Keywords:**
- **`try`:** Used to enclose the code block that may potentially throw an exception.
- **`catch`:** Used to catch and handle exceptions thrown within a `try` block.
- **`throw`:** Used to throw an exception when an error or exceptional situation occurs.

**Example:**
```c++
class Complex {
public:
Complex(double r=0, double i=0){Re=r; Im=i;}
double func();
private:
double Re;
double Im;
};

double Complex::func(){
    if(Re==0 && Im==1)
        throw "divide by zero";
    return 1/(pow(Im,2)+ pow(Re,2)+1);
}

int main(){
    Complex a(1,0);
    Complex b(0,1);

    try{
        cout<<a.func()<<endl;
        cout<<b.func()<<endl;
    }
    catch(const char* err){
        cout<<err<<endl;
    }
    return 0;
}

/*
Output:
0.5
divide by zero
*/
```

**Explanation:**
1. The `Complex` class has a member function `func()` that calculates a value based on the real and imaginary parts of a complex number.
2. Inside `func()`, there is a check for a potential division-by-zero error. If the condition (`Re==0 && Im==1`) is true, an exception is thrown using the `throw` keyword with a string message "divide by zero".
3. In `main()`, two `Complex` objects (`a` and `b`) are created.
4. The code that calls the `func()` member function is enclosed in a `try` block.
5. If an exception is thrown inside the `try` block (when `b.func()` is called), the program flow jumps to the matching `catch` block that catches exceptions of type `const char*`.
6. The `catch` block prints the error message ("divide by zero") to the console.

### **Inheritance**
Inheritance is one of the fundamental concepts in OOP that allows you to create new classes (derived classes) based on existing classes (base classes). The derived class inherits the properties and behaviours of the base class, enabling code reusability and establishing a hierarchical relationship between classes.

**Key Concepts:**
- **Base Class:** The existing class from which the derived class inherits properties and behaviours.
- **Derived Class:** The new class that inherits from the base class.
- **`public` Inheritance:** Makes the public members of the base class accessible as public members of the derived class.
- **`protected` Inheritance:** Makes the public and protected members of the base class accessible as protected members of the derived class.
- **`private` Inheritance:** Makes the public and protected members of the base class accessible as private members of the derived class (least common).

**Example:**

```c++
class person
{
protected:
    int data;
public:
    virtual char * who_am_i() { return "person"; }
    char * non_virtual_who_am_i() { return "non_virtual person"; }
};

class child : public person
{
public:
    char * who_am_i() { return "child"; }
    char * non_virtual_who_am_i() { return "non_virtual child"; }
};

class grand_child : public child{
public:
    char * who_am_i() { return "grand_child"; }
    char * non_virtual_who_am_i(){return "non_virtual grand_child";}
};
```

**Explanation:**
1. A base class `person` is defined with a protected data member `data` and two public member functions `who_am_i()` (virtual) and `non_virtual_who_am_i()`.
2. A derived class `child` is defined, inheriting publicly from `person`. It also has its versions of the `who_am_i()` and `non_virtual_who_am_i()` functions.
3. Another derived class `grand_child` is defined, inheriting publicly from `child` and consequently inheriting from `person` as well. It also defines its versions of the `who_am_i()` and `non_virtual_who_am_i()` functions.

### **Virtual Functions and Polymorphism**
**Virtual functions** are member functions in the base class that can be overridden by the derived class. This enables **polymorphism**, the ability of objects of different classes to be treated as objects of a common base class.

**Key Concepts:**
- **`virtual` keyword:** Declares a function in the base class as virtual, allowing it to be overridden in derived classes.
- **Overriding:** Redefining a virtual function in the derived class.
- **Dynamic Binding:** The actual function called is determined at runtime based on the object's type, not at compile time.

**Example:**
```c++
#include <iostream>
using namespace std;

class person
{
protected:
    int data;
public:
    virtual char * who_am_i() { return "person"; }
    char * non_virtual_who_am_i() { return "non_virtual person"; }
};

class child : public person
{
public:
    char * who_am_i() { return "child"; }
    char * non_virtual_who_am_i() { return "non_virtual child"; }
};

class grand_child : public child{
public:
    char * who_am_i() { return "grand_child"; }
    char * non_virtual_who_am_i(){return "non_virtual grand_child";}
};

void identify_yourself(person *p){
    cout << p->who_am_i() << endl;
    cout << p->non_virtual_who_am_i() << endl;
}

int main(){
    person P;
    child C;
    grand_child G;
    identify_yourself(&P);
    identify_yourself(&C);
    identify_yourself(&G);
    return 0;
}

/*
Output:
person
non_virtual person
child
non_virtual person
grand_child
non_virtual person
*/
```

**Explanation:**
1. The base class `person` defines a virtual function `who_am_i()` and a non-virtual function `non_virtual_who_am_i()`.
2. Derived classes `child` and `grand_child` override the virtual function `who_am_i()`.
3. A function `identify_yourself()` takes a pointer to a `person` object as an argument.
4. In `main()`, objects of each class are created, and `identify_yourself()` is called with pointers to each object.
5. When `who_am_i()` is called through the pointer, the overridden version in the derived class is executed due to dynamic binding.
6. However, when `non_virtual_who_am_i()` is called, the base class version is always executed because it's not virtual.

### **Abstract Classes and Pure Virtual Functions**
An **abstract class** is a class that cannot be instantiated. It serves as a blueprint for derived classes. A **pure virtual function** is a virtual function with no implementation in the base class.

**Key Concepts:**
- **`= 0`:** Used to declare a pure virtual function.
- **Abstract Class:** A class containing at least one pure virtual function.
- **Purpose:** Define a common interface for derived classes.

**Example:**
```c++
class shape
{
protected:
    double x;
    double y;
public:
    shape(double x, double y) : x(x), y(y) {}
    virtual void print() = 0; // pure virtual function
};

class circle : public shape
{
private:
    double radius;
public:
    circle(double x, double y, double radius) : shape(x, y), radius(radius) {}
    void print() override { cout << "circle c - center: (" << x << "," << y << ")" << endl; }
};

int main(void){
    circle c(3,4,5);
    cout << "circle c - center: ";
    c.print();
    return 0;
}

/*
Output:
circle c - center: (3,4)
*/
```

**Explanation:**
1. The `shape` class is declared as an abstract class by having a pure virtual function `print()`.
2. The derived class `circle` provides an implementation for the pure virtual function `print()`.
3. You cannot create an object of the `shape` class because it's abstract.
4. An object of the `circle` class can be created, and its `print()` function can be called.

### **Dynamic Memory Allocation**
Dynamic memory allocation allows you to allocate memory for objects and variables during program execution. The `new` operator is used to allocate memory, and the `delete` operator is used to deallocate memory.

**Example:**
```c++
int main ()  {
    int *p;
    int *arr;

    p = new int;           // Allocate memory for a single integer
    arr = new int;     // Allocate memory for an array of 10 integers

    *p = 10;
    cout << *p << endl;

    arr = 78 ;
    cout << arr << endl;

    *(arr+3) = 45;
    cout << *(arr+3) << endl;

    delete p;              // Deallocate memory for the single integer
    delete [] arr;          // Deallocate memory for the array
    return 0;
}
```

**Explanation:**
1. Pointers `p` and `arr` are declared to store memory addresses.
2. `new int` allocates memory for an integer and assigns its address to `p`.
3. `new int` allocates memory for an array of 10 integers and assigns the starting address to `arr`.
4. Values are assigned to the allocated memory locations using the pointers.
5. `delete p` deallocates the memory pointed to by `p`.
6. `delete[] arr` deallocates the memory block pointed to by `arr`.

### **Standard Template Library (STL)**
The STL is a powerful library that provides a collection of template classes and functions for common data structures and algorithms.

**Key Components:**

- **Containers:** Data structures like `vector`, `list`, `set`, `map`, `stack`, and `queue`.
- **Iterators:** Objects that provide a way to access elements of containers.
- **Algorithms:** Functions for performing operations on containers, such as sorting, searching, and transforming.

### **File Input/Output**
The `<fstream>` header file provides classes for file input and output operations in C++.

**Key Classes:**
- **`ofstream`:** For writing to files.
- **`ifstream`:** For reading from files.
- **`fstream`:** For both reading and writing to files.

**File Opening Modes:**
- **`ios::in`:** Open for reading.
- **`ios::out`:** Open for writing.
- **`ios::trunc`:** Truncate the file if it exists.
- **`ios::app`:** Append to the end of the file.

### **References**
A reference is an alias for an existing variable. It provides an alternative name for the same memory location.

**Key Concepts:**
- **`&` symbol:** Used to declare a reference.
- **Initialization:** References must be initialized when declared.
- **Modification:** Modifying a reference variable modifies the original variable.

**Example:**
```c++
using namespace std;

int main () {
    // declare simple variables
    int    i;
    double d;

    // declare reference variables
    int &r = i;
    double &s = d;

    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;

    s = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;

    return 0;
}

/*
Output:
Value of i : 5
Value of i reference : 5
Value of d : 11.7
Value of d reference : 11.7
*/
```

**Explanation:**
1. Integer variable `i` and double variable `d` are declared.
2. Reference variable `r` is declared and initialized to reference `i`.
3. Reference variable `s` is declared and initialized to reference `d`.
4. Assigning a value to `i` also changes the value of `r`, and vice versa.
5. Similarly, assigning a value to `s` changes the value of `d`, and vice versa.

### **Parameter Passing**
**By Value:** A copy of the argument is passed to the function. Modifications inside the function do not affect the original variable.

**By Reference:** A reference to the argument is passed to the function. Modifications inside the function directly affect the original variable.

**By Pointer:** A pointer to the argument is passed to the function. Modifications to the memory location pointed to by the pointer affect the original variable.

### **Operator Overloading**
**Operator overloading** allows you to define the behaviour of operators (like +, -, \*, /, \=\=, etc.) for user-defined data types (classes).

**Key Concepts:**
- **`operator` keyword:** Used to define overloaded operator functions.
- **Friend Functions:** Can be used for operator overloading when the operator needs access to private members of the class.
- **Member Functions:** Can be used for operator overloading when the left operand of the operator is an object of the class.

**Example (Overloading the + operator using a friend function):**
```c++
class myNN {
private:
    int N;
public:
    myNN(int a=0):N(a){}
    int getN(){
        return N;
    }
    friend myNN operator+(myNN &, myNN &);
};

// Define external function
myNN operator+(myNN &c1, myNN &c2){
    return myNN( c1.N + c2.N);
}

int main(){
    myNN a1(5), a2(3);
    myNN c1 = a1 + a2;
    cout << c1.getN() << endl;
}
```

**Explanation:**
1. The `myNN` class has a private member `N` and a constructor to initialize it.
2. A friend function `operator+` is declared inside the class, taking two `myNN` objects as references.
3. The `operator+` function is defined outside the class, returning a new `myNN` object with the sum of the `N` values from the two input objects.
4. In `main()`, two `myNN` objects (`a1`, `a2`) are created, and the overloaded `+` operator is used to add them.

### **Important Notes:**
- **Constructors:** Constructors are special member functions that are automatically called when an object of a class is created. They are used to initialize the data members of the object.
- **Destructors:** Destructors are special member functions that are automatically called when an object of a class is destroyed. They are used to clean up any resources that the object may have allocated.
- **Virtual Destructors:** It's a good practice to declare destructors as virtual, especially in inheritance hierarchies, to ensure proper cleanup of derived class objects.
- **Static Members:** Static members (data members or member functions) belong to the class rather than to any specific object of the class.
### **Friend Functions and Classes**

A **friend function** is a non-member function that has access to the private and protected members of a class. A **friend class** allows another class to access its private and protected members.

**Key Concepts:**
- Declared with the `friend` keyword.
- A friend function is not a member of the class but has access to its private data.
- A friend class is declared in the base class to give access to its private data.

**Example (Friend Function):**
```c++
#include <iostream>
using namespace std;

class Box {
private:
    int length;
public:
    Box() : length(0) {}
    friend void printLength(Box b); // Friend function declaration
};

void printLength(Box b) {
    cout << "Length of box: " << b.length << endl; // Access private member
}

int main() {
    Box b;
    printLength(b);
    return 0;
}

/*
Output:
Length of box: 0
*/
```

**Explanation:**
1. The class `Box` has a private data member `length`.
2. A friend function `printLength` is declared inside the `Box` class but defined outside it.
3. The friend function is allowed to access the private data member `length`.

---

### **Static Members**
**Static members** (data or functions) belong to the class rather than any object. They are shared across all instances of the class.

**Key Concepts:**

- Declared with the `static` keyword.
- Static data members are initialized outside the class.
- Static member functions can be called without creating an object of the class.

**Example:**

```c++
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;
public:
    Counter() { count++; }
    static int getCount() { return count; }
};

int Counter::count = 0; // Initialize static member

int main() {
    Counter c1, c2;
    cout << "Number of objects: " << Counter::getCount() << endl;
    return 0;
}

/*
Output:
Number of objects: 2
*/
```

**Explanation:**
1. `count` is a static data member, shared by all objects of the `Counter` class.
2. The static member function `getCount` can access `count` without requiring an object.
3. Static members are accessed using the class name, e.g., `Counter::getCount()`.

---

### **Constructors and Destructors**

#### **Constructors:**
- Special member functions automatically called when an object is created.
- Used to initialize an object.
- Can be overloaded.
- Cannot have a return type.

#### **Destructors:**
- Special member functions automatically called when an object goes out of scope or is explicitly deleted.
- Used for cleanup.
- Cannot be overloaded and has no parameters.

**Example:**
```c++
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor called" << endl; } // Constructor
    ~Demo() { cout << "Destructor called" << endl; } // Destructor
};

int main() {
    Demo d;
    return 0;
}

/*
Output:
Constructor called
Destructor called
*/
```

---

### **Type Casting**
**Type casting** in C++ allows you to convert a variable from one type to another.

**Types:**

- **Implicit Casting (Type Promotion):** Automatically done by the compiler.
- **Explicit Casting:** Manually performed using cast operators like `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast`.

**Example:**
```c++
#include <iostream>
using namespace std;

int main() {
    double d = 9.7;
    int i = static_cast<int>(d); // Explicit casting
    cout << "Original value: " << d << ", After casting: " << i << endl;
    return 0;
}

/*
Output:
Original value: 9.7, After casting: 9
*/
```

---

### **Multithreading in C++**
Multithreading allows a program to run multiple threads concurrently. Threads can share resources like memory but can execute independently.

**Key Concepts:**

- **`std::thread`:** Provided by the `<thread>` header.
- **Synchronization:** Ensure safe access to shared resources using mutexes (`std::mutex`).

**Example:**
```c++
#include <iostream>
#include <thread>
using namespace std;

void printNumbers() {
    for (int i = 0; i < 5; i++) {
        cout << "Number: " << i << endl;
    }
}

int main() {
    thread t(printNumbers); // Create a new thread
    t.join(); // Wait for thread to complete
    return 0;
}

/*
Output:
Number: 0
Number: 1
Number: 2
Number: 3
Number: 4
*/
```

**Explanation:**
1. The `printNumbers` function runs in a separate thread.
2. The `join` function ensures the main thread waits for `t` to finish.

---

### **Lambda Expressions**
Lambda expressions provide a concise way to define anonymous functions.

**Syntax:**

```c++
[ captures ] ( parameters ) -> return_type { body }
```

**Example:**
```c++
#include <iostream>
using namespace std;

int main() {
    auto add = [](int a, int b) -> int { return a + b; };
    cout << "Sum: " << add(3, 4) << endl;
    return 0;
}

/*
Output:
Sum: 7
*/
```

**Explanation:**
1. The lambda `[ ]` defines an anonymous function.
2. `auto` is used for type deduction.

---

### Final notes
I try my best when it comes to create a viable resource to study, this material is created for Atılım Üniversitesi's students. If you find anything missing, please notify me and I'll update it.

Have a great study my mate.

devsimsek.
