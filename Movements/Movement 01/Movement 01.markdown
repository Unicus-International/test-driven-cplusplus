# Movement the First – Giving Names to Things

## Anatomy of a C++ Program

The following is (almost) the very simplest C++ program imaginable; it will be used as an example to give us the names of the parts of a program:

```c++
// Copyright © 2020 Unicus AS
#include <iostream>

constexpr int exit_status();

int main() {
  constexpr auto greeting { "Hello world!" };

  std::cout << greeting << std::endl;

  return exit_status();
}

constexpr int exit_status() {
  constexpr auto status { 0 };

  return status;
}
```

### Comments

The first line, starting with `//`, is a comment. On any line of a C++ program, anything starting with `//` and to the end of the line is ignored by the compiler. As an alternative, you can also use multiline comments; these start with `/*` and end with `*/`; everything between the starting tag and the ending tag (including the tags themselves) is ignored by the compiler.

Comments can be used for many purposes, but one of the most useful is including human-readable stuff of various kinds that belongs to a source file (such as the copyright notice in the example).

### Preprocessor instructions

The next line is a preprocessor instruction. Before a C++ program is fed into the compiler, it's processed by what is called a preprocessor (In principle! In reality, these steps are more intertwined!), which does things like stripping out comments and acting on preprocessor instructions. This tutorial will not cover preprocessing instructions in any great detail.

The exception to this is the instruction `include`: The instruction `include` is used to include another file in the current file, as if it was copied and pasted into it. This is used both with system headers (marked with angle brackets `<>`) and project headers (marked with double quotes `""`).

In most cases, the two ways of marking the name of the files to be imported are interchangeable, and either way will work for any file, with two crucial caveats:

  1. The search order for files may be different, so if a name could be either a project header or a system header, `<angle brackets>` will find the system header and `"quotes"` will find the project header.
  2. The use of one or the other communicates _intent_; with `<angle brackets>` a system file is desired, with `"quotes"` a project file is desired.

### Function declaration

Following the `include` directive, there is a function declaration, for a function named `exit_status`. This declaration consists of a number of parts:

```c++
constexpr int exit_status() ; /*
 ^         ^   ^          ^ ^
 |         |   name       |statement terminator
 |        return type    argument list
constant expression specifier
*/
```

#### Constant expression specifier

The constant expression specifier `constexpr` tells the compiler that the expression can be resolved during compilation. This allows the expression to be optimised, or potentially removed entirely. Throughout this tutorial, this specifier will be used wherever possible, and in the code you write to solve the tasks, you should use it as often as possible as well.

#### Return type

The return type of a function is the type of the value that calling the function will result in. Types will be explored more fully in a later movement; right now it's enough to know that `int` is the name of a type (specifically for a signed integral type of a platform-defined size).

#### Name

The name is largely self-explanatory: It's the name of the function, and the main way by which it can be interacted with. There are not a lot of restrictions on the name of a function, but generally it's best to limit the name of functions to `snake_case`, using the letters a through z, the numbers 0 through 9, and the underscore (`_`) character. Names of functions also need to be unique, in order to refer to them, but what exactly "unique" means in the context of C++ names will be explored in a later movement.

#### Argument list

The argument list is a list of arguments to be passed to the function when called. In this case, the list is empty, but an example of an argument list that's not empty might look something like this:

```c++
constexpr int multiply(int a, int b);
```

Here, there are two arguments in the list, `int a` and `int b`; each entry has a type (`int`) and a name (`a`, `b`). In a function declaration, the names of arguments don't need to be included:

```c++
constexpr int multiply(int, int);
```

In cases where it's clear what the arguments are for, omitting them can help make the code more readable, but take care not to omit names that communicate intent! For example, the below names should _not_ be omitted:

```c++
constexpr int subtract(int minuend, int subtrahend);
```

#### Statment terminator

In most statements in C++, the semicolon (`;`) is used as a statement terminator. This tells the compiler that the statment is over, and to proceed to the next statement. It can also be used in the middle of a line to put more than one statement on one line, but as a rule of thumb this is best avoided.

### Function definition

Following the function declaration is a function definition. In most respects, these two are identical, with the exception that where a function declaration has a statement terminator, the function definition has a block, which forms the _function body_. A block is a foundational construct in C++, and consists of a series of statemements, all within curly braces (`{}`). A block also introduces what is called a _scope_, and on the exit from a block, things that only exist in the scope of that block are destroyed and reclaimed by the system. (Scope and storage will be explored further in a later movement.)

### Constant declaration and initialisation

The first line in the function body declares a constant, and initialises it. Again, this consists of a number of parts, where some are known and some are new:

```c++
constexpr auto greeting { "Hello world!" }; /*
           ^    ^       ^  ^             ^
          type name     | string literal |
                        initialiser braces
*/
```

#### Type

In this declaration, the type has a slightly different meaning from the function declaration: While in the function declaration we were giving the return type for the function, here we're giving the type of the declared object itself. (Functions also have a type, in addition to their return type, which will be covered in a later movement.) Declaring the type with the name `auto` allows more compact code, especially when the type names are ugly, and will be used liberally throughout this tutorial.

#### Name

For constants, the same rules apply to names as do for functions.

#### Initialiser braces

The initialiser braces contains a list of 0 or more elements to initialise the constant with. The specifics of how this works will be covered in a later movement, so for now expect to see exactly one entry in the list. While initialisers also use curly braces (`{}`), this is not a block, which is why it's followed by a statement terminator.

#### String literal

A string literal is a sequence of letters, all enclosed in double quotes (`""`). A string literal may also have a prefix, such as in `u8"Hællå wørld."`, or `R"x( "double quotes" )x"`, these will be seen in other movements.

Other literal types also exist, such as integer literals (`0`, `-3`, `0xff`), floating point literals (`1.0`, `2.1e3`, `-13.0`), character literals (`'a'`) and boolean literals (`true`, `false`).

### I/O operations

On the following line, a pair of I/O (input/output) operations are performed. The actual operations themselves are not crucial to understand now, and will be revisited in a later movement. What is important here is observing the use of the constant declared earlier, `greeting`.

### Return statement and function call

The final statement in the `main` function is a return statement. The return statement takes the value of the expression following `return` (in this case `exit_status()`) and returns it as the value of the function. The request for the value is the function call, which is the name of the function, followed by an argument list (such as, for example, `exit_status()`).

### The `exit_status()` function

Concluding this program is the definiton of `exit_status()`. Its declaration here is identical to the initial declaration, as it should be (with the exception of things like argument names, which are allowed to differ). Its body is otherwise quite similar to `main()`, and by applying the information learnt above, you should be able to figure out what happens here.

## Basic arithmetic

Previously, a pair of functions were offered as examples, without offering definitions: `multiply(int,int)` and `subtract(int,int)`. Having explored the structure of a function, defining these can now be used to give examples of another kind of statement: The application of an operator.

```c++
constexpr int subtract(int minuend, int subtrahend) {
  constexpr auto difference { minuend - subtrahend };

  return difference;
}

int multiply(int a, int b) {
  constexpr auto product { a * b };

  return product;
}
```

These methods are both largely redundant, since they do exactly the same as the two operators shown here; `*` and `-`. For doing basic arithmetic, C++ has the following operators:

    + addition
    - subtraction
    * multiplication
    / division
    % modulo

Additionally, for comparing values, there are the following operators:

    == equals
    != not equals
    >= greater than or equals
    <= less than or equals
     > greater than
     < less than

For composing logic statements, there are the following operators:

    && and
    || or
     ! not

Finally, for selecting between two values of the same type, there is the ternary operator:

    predicate ? true-value : false-value

The ternary operator works as follows: If the predicate (a boolean value) is true, the `true-value` leg is returned, otherwise the `false-value` leg is returned. The two values must be of the same type.

## All Together Now

With all of this under our belt, we can now put together an example of a function using some operators, function calls and return: The factorial function. For this purpose, we'll introduce a new type, a different integral type: The unsigned integer called `std::uint64_t`. This name looks a bit dense and intimidating at first, but we can break it up into pieces:

```c++
std:: // from the standard library
u     // unsigned, meaning it can contain a value of 0 or up
int   // integral type, meaning it contains whole numbers
64    // 64 bits of size, meaning it can contain values from 0 to 2^64 - 1, inclusive
_t    // short for type
```

Other types named like this include `std::uint32_t`, `std::int16_t` and std::uint8_t`, and so on, all of which are avilable in the standard library from `<cstdint>`.

### Why Use an Unsigned Integer?

By using an unsigned value here, we are communicating intent, by constraining the _domain_ of the function. We are promising that we will always return a whole, nonnegative number, and that we only accept a whole, nonnegative number. The factorial function can be implemented with a broader domain than that, but that's not what we're doing here.

```c++
#include <cstdint>

constexpr std::uint64_t factorial(std::uint64_t n) {
  return n <= 1 ? 1 : n * factorial(n - 1);
}
```

Once you are satisfied that you understand what this function does, you can switch over to the task for this movement!
