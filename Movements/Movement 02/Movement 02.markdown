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

The fourth and final kind of fundamental type are the integral types, which we have been using in Movement the First without further comment. These are types like `int`, `std::uint64_t` and friends, `bool`, and `char8_t`. These types represent discrete values such as truth values (`bool`), character values in strings (`char8_t`) or the value of numbers (`int`).

These are also arithmetic types, but the degree to which arithmetic operations make sense for them varies.

```c++
constexpr int     { 3 * 4 }        ; // makes sense
constexpr bool    { true * false } ; // does not
constexpr char8_t { 'a' * 'b' }    ; // really does not
```

