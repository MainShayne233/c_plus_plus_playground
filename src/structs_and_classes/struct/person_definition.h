#include <string.h>

using namespace std;

struct Person {

  // Default constructor
  Person();

  // Constructor with parameters for initial values
  Person(string first_name, string last_name, int age);

  // Accessor methods
  string getFirstName();
  string getLastName();
  int getAge();

  // Setter methods
  void setFirstName(string first_name);
  void setLastName(string last_name);
  void setAge(int age);

  // Other methods
  void greet();

  // Private data
private:
  int age;
  string first_name;
  string last_name;
};
