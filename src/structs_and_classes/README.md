# Structs and Classes

## Intro

In C++, you're used to dealing with different data types. There are primatives like `int`s, `float`s, `string`s, and there
are more complex data types like `array`s, `list`s, `map`s, etc.

Structs and classes can be thought of a way for you to define your own data types!

## Why and how to use

In your program you might want the ability to represent a person. A person might have a
first name, last name, age, and a number of email addresses. You could use C++'s normal data types to
represent these like;

```c++
string first_name = "Sam";
string last_name = "Williams";
int age = 25;
string emails[3] = { "xXxSlayer420xXx@yahoo.com", "samsmith@gmail.com", "samsmith@ucf.edu" };
```

This is fine, and should work, but it's not ideal that all the data is in seperate variables.
Imagine how annoying it would be to track all four variables for every person in your program. That's
where structs and classes come in. If you defined a `Person` type using either a struct or a class,
you could accomplish the same thing like:

```c++
Person person = new Person("Sam", "Williams", 25, { "xXxSlayer420xXx@yahoo.com", "samsmith@gmail.com", "samsmith@ucf.edu" });
```

and then you'd just have a single `person` to deal with. Then you can use your new `person` variable like:

```c++
cout << "name: " person.first_name << " " << person.last_name << endl;
cout << "age: " << person.age << endl;
cout << "emails:" << endl;
for (int = 0; i < 3; ++i) {
  cout << " - " << person.emails[i] << endl;
}
```

The output would be:

```
name: Sam Williams
age: 25
emails:
 - xXxSlayer420xXx@yahoo.com
 - samsmith@gmail.com
 - samsmith@ucf.edu
```

