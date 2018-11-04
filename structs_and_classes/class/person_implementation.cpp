#include <iostream>
#include "person_definition.h"

// Constructors

// Default constructor
Person::Person() {}

// Constructor with parameters for initial values
Person::Person(string first_name, string last_name, int age) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->age = age;
}

// Accessor methods

string Person::getFirstName() {
  return this->first_name;
}

string Person::getLastName() {
  return this->last_name;
}

int Person::getAge() {
  return this->age;
}

// Setter methods

void Person::setFirstName(string first_name) {
  this->first_name = first_name;
}

void Person::setLastName(string last_name) {
  this->last_name = last_name;
}

void Person::setAge(int age) {
  this->age = age;;
}

// Other methods

void Person::greet() {
  cout << "Hello, " << this->first_name << ", it's nice to meet you" << endl;
}
