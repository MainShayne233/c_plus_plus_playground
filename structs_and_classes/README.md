# Structs and Classes

## Intro

In C++, you're used to dealing with different data types. There are primatives like `int`s, `float`s, `string`s, and there
are more complex data types like `array`s, `list`s, `map`s, etc.

Structs and classes can be thought of a way for you to define your own data types!

## Why and how to use

In your program you might want the ability to represent a person. A person might have a
first name, last name, and age. You could use C++'s normal data types to
represent these like;

```c++
string first_name = "Sam";
string last_name = "Williams";
int age = 25;
```

This is fine, and should work, but it's not ideal that all the data is in seperate variables.
Imagine how annoying it would be to track all three variables for every person in your program. That's
where structs and classes come in. If you defined a `Person` type using either a struct or a class,
you could accomplish the same thing like:

```c++
Person person = Person("Sam", "Williams", 25);
```

and then you'd just have a single `person` to deal with. Then you can use your new `person` variable like:

```c++
cout << "name: " << person.first_name << " " << person.last_name << endl;
cout << "age: " << person.age << endl;
```

The output would be:

```
name: Sam Williams
age: 25
```

These custom types can also have `methods`, which are basically their own functions that have access to all their own data.
For example, the `Person` type might have a method called `greet()`, and it could be used like:
```c++
person.greet();
```

and the output might be:

```
Hello Sam, it's nice to meet you!
```

## Okay cool but how do I....like do it?

First and foremost, structs and classes are almost identical, and only have one significant difference
that we will get to later, but for the time being, know that you mostly define/use structs and classes
in exactly the same way.

There are two parts to parts to defining a type using a struct/class. The definition, and the implementation.

### Defintion

The definition for a type basically does the following:
- Declares the name of the type (`Person`, `Student`, `Shape`, etc)
- Declares the data fields, or "members", for the type (`person.first_name`, `student.grade`, `shape.sides`, etc)
- Declares any `methods` the type might have (`person.greet()`, `student.fail()`, `shape.rotate()`)

And by *declare* we mean that it states just what these things will look like, not exactly how they work.

For example, if we were _defining_ the `Person` type, as it could look like:

```c++
// as a struct
struct Person {

  // define fields (members)
  string first_name;
  string last_name;
  int age;
  
  // define methods


  // constructor method
  Person();
  Person(string first_name, string last_name, int age);

  // normal method
  void greet();
}
```

As you can see, we:
- Declared the name of the type as `Person`
- Declared the members as `first_name`, `last_name`, and `age`.
- Declared that there is a method called `greet()`, but we did not implement it/write the actual code for it!
- Declared two `constructor` methods, `Person()` and `Person(string first_name, string last_name, int age);` (more on this later).

This is a complete _definition_for the `Person` type, but we still need to write the _imeplementation_ for it.

### Implementation

After the type has been defined, we can implement the parts of it that need to be implemented.

The memebers, or data fields, do not need to be implemented; the definition takes care of everything for them.

Methods, however, do need to be implemented. Otherwise, how would the computer know what it should do when it sees `person.greet()`?

We can implement the `greet()` method like so:

```c++
void Person::greet() {
  cout << "Hello, " << this->first_name << ", it's nice to meet you" << endl;
}
```

Implementing a method is just like writing a function, except that the function name needs to be preceaded with `TypeName::`,
so in this case, its `Person::greet`. This is the code that will get run when `person.greet()` gets run.

You might be confused by the `this->frst_name` bit. Let's disect it.

`this` is a special keyword in C++. When used inside a method like the one we defined above, `this` is the current
instance of the type you have defined. That might sound confusing, but think about it like this:

```
Person shayne = Person("Shayne", "Tremblay", 22);`
Person aidan = Person("Aidan", "Agee", 23);`

shayne.greet() // `this` in the `greet()` method would now refer to the `shayne` person.
aidan.greet() // `this` in the `greet()` method would now refer to the `aidan` person.
```

`this` is an infamously confusing concept, so don't worry if it's a bit of a struggle to fully grasp at first.

Now the next bit is the `->` operator. Whenever you see `something->other_thing`, you can basically think of it as `something.other_thing`, meaning
"I want to access the `other_thing` field on `something`". The only difference is that `->` is used when `something` is a pointer versus an actual data value.
If you don't understand pointers very well, don't worry too much about this for now. Just remember that you need to use `->` when accessing values on `this`.

So `this->first_name` can be thought of as "Give me the first name value of the current person I am calling this method on".

#### Okay cool, but what is that `Person()` thing doing, and what's a constructor?

Glad you asked! So when you want to create a new `Person` variable, the code would look like:

```c++
Person myPerson = Person();
```

The `Person()` bit is essentially calling a function to create the person. This function is called a constructor.
Constructors are just like any other method defined for a type, except they're called when you create a variable of that type.
So you can almost think of the code above as:

```c++
Person myPerson = createANewPerson();
```

Constructors need be defined like any other method on a type, like a function. We can implement the `Person()` constructor like:

```c++
Person::Person() {
}
```

You might ask yourself, "that's it?". Yeah! We basically just have to tell the C++ compiler that we want this constructor
to exist, and that it doesn't need to do anything special.

This constructor takes 0 arguments and doesn't do anything special. This is called the *default constructor*.

Constructors can do more. It's convienent to be able to set the initial data values for a new value we're creating, and this can be done
in the constructor. To do this, we will implement the other constructor we defined: `Person(string first_name, string last_name, int age);`

```c++
Person(string first_name, string last_name, int age) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->age = age;
}
```

This allows us to create a `Person` with initial values that we pass it. Example:

```c++
// Will use the default `Person()` constructor, and have no inital values set.
Person person = Person();

// Will use the `Person(string first_name, string last_name, int age)` constructor, and have inital values set.
Person person_with_values = Person("Sam", "Williams", 25);
```

## Okay, mostly makes sense. What's the diff between structs and classes though?

Yes! Last important thing we need to know about, and what makes stucts and classes so different, is the idea of `public` and `private`.

When you defined a new type using a struct class, you have the ability to make any memebers, methods, constructors, etc either `public` or `private`.

When something is `public`, this means it can be freely used from outside of the class. If something is made `private`, it can only be used from within the class.

For example, if we have the following `Person` type defined:

```
struct Person {

  public:
  
  string first_name;
  string last_name;
  
  private:
  int age;
};
```

There is nothing stopping us from calling `person.first_name`, or `person.last_name`, but if we were try to access `age` like:

```c++
cout << person.age;
```

We'd get an error that looks like:

```
main.cpp:38:18: error: ‘int Person::age’ is private within this context
   cout << person.age;
                  ^~~
main.cpp:19:7: note: declared private here
   int age;
   
```

However, though we can't access `age` directly on the `person` value itself, we could define a method on the `Person` type
that would have access to it:

```
struct Person {

public:

  string first_name;
  string last_name;
 
  // new public method for accessing `age`
  int getAge();

private:
  int age;
};

int Person::getAge() {
  return this->age;
}
```

and then we could call `person.getAge()` with no problem!

### Why not just make everything public all the time?

Making things `private` is useful when you want to hide details from the client of a type. Maybe you defined a `BitCoinWallet` type,
and maybe the `BitCoinWallet` type actually has 100+ data fields on it that all affect what the `current_amount` value would be, instead
of having every programmer who wants to use the `BitCoinWallet` type know how all the fields work, all those fields could be made `private`, and a single
`getCurrentAmount()` method could be defined so that they all have easy access to what they care about, and don't have to deal with things they don't care about.

## Structs vs. Classes

Finally, now that that's all said, here's the difference betwen classes and stucts:

Structs make everything public by default.

Classes make everything private by default.

That's it.

For example,

```c++
class Person {
 
  string name;
}
```

is equivalent to:

```c++
struct Person {

private:

  string name;
}
```

and

```c++
struct Person {
  string name;
}
```

is equivalent to:

```c++
class Person {

public:

  string name;
}
```


So in classes you have to explictly state that a member/method is `public`, and in structs you have to
explicitly state that a member/method is `private`.

Typically, you want to use a `Struct` when you are just trying to lump a bunch of related data together, and you
want to use a `Class` when you're defining a type that has a lot of behavior/methods.
