#include "person_implementation.cpp"

using namespace std;

int main() {
  Person person = Person("Sam", "Williams", 25);

  // Display data
  cout << "First Name: " << person.getFirstName() << endl;
  cout << "Last Name: " << person.getLastName() << endl;
  cout << "Age: " << person.getAge() << endl;

  cout << endl << "Changing values..." << endl << endl;

  // Change data
  person.setFirstName("Michael");
  person.setLastName("Jordan");
  person.setAge(64);

  // Display data (again)
  cout << "First Name: " << person.getFirstName() << endl;
  cout << "Last Name: " << person.getLastName() << endl;
  cout << "Age: " << person.getAge() << endl;

  cout << endl;

  person.greet();
}
