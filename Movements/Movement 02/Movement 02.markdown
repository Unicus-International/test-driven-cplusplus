# Movement the Second – Objects and Types

## The Object

In C++, an object is something that exists in memory. It has a size, a type, a value, and properties related to its lifetime and scope. It may also have a name (although this is not always the case).

For the purposes of this movement, only three of these properties matter: The type, the value, and the name of an object. When we declare a constant as we have been doing in Movement the First, we declare these three properties:

```c++
constexpr std::uint64_t some_value { 15 } ; /*
           ^             ^            ^
          type          name         value
*/
```

This declaration creates an object of the type `std::uint64_t` named `some_value`, with a value of `15`.

## The Type

In C++, every object has a type, and these types can be either fundamental types, or compound types.

### Fundamental Types

Fundamental types are the simplest types, and come in four varieties.

The first is the `void` type, a type that represents a generic or sizeless nothing. No objects can have the type `void`, although `void` typed expression can be returned from functions with a return type of `void`.

```c++
constexpr void some_function() {
  return;
}

constexpr void some_other_function() {
  return some_function();
}
```

The second is the `std::nullptr_t` type, which will be discussed in a later movement.

The third are floating point types, such as `double`. These types are used to represent real numbers (e.g. 5.0, 31.51 or -17.5) and are an arithmetic type, meaning that a range of mathematical operations are defined for them:

```c++
constexpr double multiply(double a, double b) {
  constexpr double product { a * b } ;

  return product;
}
```

The fourth and final kind of fundamental type are the integral types, which we have been using in Movement the First without further comment. These are types like `int`, `std::uint64_t` and friends, `bool`, and `char`. These types represent discrete values such as truth values (`bool`), character values in strings (`char`) or the value of numbers (`int`).

These are also arithmetic types, but the degree to which arithmetic operations make sense for them varies.

```c++
constexpr int  { 3 * 4 }        ; // makes sense
constexpr bool { true * false } ; // does not make sense
constexpr char { 'a' * 'b' }    ; // really does not make sense
```

### Compound Types

Compound types come in several different varieties; only two of which will be covered in this movement.

The first variety are reference types, such as references and pointers. These will be explored in a later movement, but in short they represent ways to refer to objects.

The second variety are array types, which are contiguous runs of objects of a single type. These will not be explored in this tutorial.

The third variety are function types, which will be explored in a later movement.

The fourth variety are enumeration types. These are used to give names to constants of an underlying (integral) type, and group related constants together. For example, a temperature converter might use the following enumeration:

```c++
enum struct temperature_scale : char { /*
             ^                   ^
            name     underlying type */
  celcius    = 'C',
  kelvin     = 'K',
  fahrenheit = 'F',
  rankine    = 'R',
};
```

The fifth and final variety are class types. These are used to group related values (called members) together in a single object to manipulate as a whole. Class types are introduced by one of three keywords, `struct`, `class` or `union`, the latter two of which will be explored in a later movement. Members of a class type come in two broad varieties, `static` and non-`static` members; `static` members will also be explored in a later movement.

Members of a class can be either types, data members, or member functions, including special member functions such as operators, constructors and destructors. Continuing the hypothetical temperature converter from above, an object type that might be used could look something like this:

```c++
struct temperature {
  // member type
  enum struct scale : char {
    celcius    = 'C',
    kelvin     = 'K',
    fahrenheit = 'F',
    rankine    = 'R',
  };

  // constructor
  constexpr temperature(double v, scale s) : _value { v }, _scale { s } { }

  // member functions (also called "methods")
  constexpr temperature convert(scale target_scale) const {
    // ...
  }

  constexpr double value(scale target_scale) const {
    // ...
  }

  // data members (also called "fields")
  const double _value;
  const scale  _scale;
}
```

Of special note is the form of the constructor:

```c++
constexpr temperature(double v, scale s) : _value { v }, _scale { s } { } /*
           ^                              ^                            ^
          name (same as type)            initialiser list             function body
*/
```

This is much like a normal function, but between the declaration and the function body, we have a member initialiser list. This is much like the initialisers we've already seen for constants, except that the type and constant expression specifier aren't necessary. In the above example, the field `_value` is initialised with the value of `v`, and the field `_scale` is initialised with the value of `s`.

In general, the members of types are referenced using the namespace operator (`::`) and accessed using member operators (`.` and `->`):

```c++
int main() {
  constexpr double input_value { /* ... */ } ;

  // referencing member type using ::                    v
  constexpr temperature::scale input_scale  { temperature::scale::celcius    } ;
  constexpr temperature::scale output_scale { temperature::scale::fahrenheit } ;

  constexpr temperature input_temperature { input_value, input_scale };

  // accessing member function with the . operator v
  constexpr double output_value { input_temperature.value(output_scale) } ;
}
```
