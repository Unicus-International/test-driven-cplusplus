# Movement the Third – My Toys and Your Toys: Access Specifiers

```c++
struct temperature {
  enum struct scale : char {
    celcius    = 'C',
    kelvin     = 'K',
    fahrenheit = 'F',
    rankine    = 'R',
  };

  constexpr temperature(double v, scale s) : _value { v }, _scale { s } { }

  constexpr temperature convert(scale target_scale) {
    // ...
  }

  constexpr double value(scale target_scale) {
    // ...
  }

  const double _value;
  const scale  _scale;
}
```

Returning to the example from the last movement, we see that we have a problem with `temperature`. Just as anyone can call the member functions `value` and `convert`, anyone can access the values of the fields `_value` and `_scale`. If someone were to access the field `_value` without checking `_scale`, they might easily introduce an error. In most languages, fields starting (or sometimes ending) with an underscore are generally considered to be internal, and not to be touched by others, but this is just a suggestion.

Instead of relying on programmers understanding and respecting this suggestion, we can use the compiler to enforce it, with the help of access specifiers:

```c++
struct temperature {
public: // open for anyone to use
  enum struct scale : char {
    celcius    = 'C',
    kelvin     = 'K',
    fahrenheit = 'F',
    rankine    = 'R',
  };

  constexpr temperature(double v, scale s) : _value { v }, _scale { s } { }

  constexpr temperature convert(scale target_scale) {
    // ...
  }

  constexpr double value(scale target_scale) {
    // ...
  }

private: // usable only by member functions
  const double _value;
  const scale  _scale;
}
```

There are three access levels in C++: `private`, `protected` and `public`. `private` is the most restrictive, and should be what you default to unless you have a good reason. `private` members of a type can only be accessed by members of the type itself. `protected` is slightly less restrictive, and allows access to members by friends of the type, as well as derived types. (Both these things will be covered in a later movement.) Finally, `public` is the least restrictive, and `public` members of a type are accessible to anyone.

`public` members of a type form the public interface, so it's good to be very careful about what you add to it, especially if your code is used by other people. (For the purposes of this discussion, "me, in the future" is another person.)

Up until now, the examples have used the `struct` class type specifier so as to avoid having to talk about access specifiers, but in most cases the use of the `class` class type specifier is appropriate. The two specifiers are identical, but for one important difference: In a `class`, the default access specifier is `private`, and in a `struct` the default access specifier is `public`.
