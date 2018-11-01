/////////////////////////////////////////////////////////////////////////////
// This program will read in a file and print out each line of it.         //
//                                                                         //
// It serves as an example of how to process a file line by line.          //
//                                                                         //
// If running from the command line (such as with g++), run with:          //
//                                                                         //
// g++ -o read_file.o read_file.cpp && ./read_file.exe some_input_file.txt //
/////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

/**
 * Here we are reading the file in line by line.
 *
 * We use an `ifstream`, which you can just think of as a pipeline that pipes data into your program.
 *
 * We attempt to open our file with `input_stream.open(file_path.c_str())`
 *  - We need to use `.c_str()` since the `.open()` method expects a C-string, not a C++ string.
 *
 * If we were successful, the `input_stream` is a truthy value, so `if (input_stream)` will result
 * in the `if (true)` block.
 *
 * If we weren't successful, we tell the user something bad happened and exit.
 *
 * To get a usable string from the stream, you first need a strin variable defined.
 * In this case, we're using `string line = "";`
 *
 * When you run `input_stream >> line`, `line` is now the string representing the next line in
 * the file.
 *
 * Once you run out of lines in the file, `input_stream >> line` will make `line` a falsey value, so
 * it will exit the while loop.
 */
void process_file(string file_path) {
  string line = "";
  ifstream input_stream;
  input_stream.open(file_path.c_str());
  if (input_stream) {
    while (input_stream >> line) {
      // do something with the line of the file
      cout << "Reading line: " << line << endl;
    }
  } else {
    cout << "failed to read input file: " << file_path << endl;
    exit(1);
  }
}

/**
 * `argc` is the number of arguments you gave the program.
 *
 * By default, the first argument is the name of the program's file (this file), so `argc` will always be >= 1
 *
 * If you pass an argument to the program, like:
 *   `name_of_program.exe input_file.txt`
 * The second argument will be `"input_file.txt"`, and `argc` will == 2;
 *
 * `argv` is an array of strings that contain the arguments you've passed to the program
 * If you ran your program like:
 *   `name_of_program.exe input_file.txt`
 * Then:
 *   `argv[0] == "name_of_program.exe"`
 *   `argv[1] == "input_file.txt"`
 *
 * So all we're doing here is:
 * - Checking to see if you supplied an input file to the program
 * - If you did, we pass the input file path to the `process_file` function.
 * - Otherwise, we display a message ot help the user.
 */
int main(int argc, char *argv[]) {
  if (argc == 2) {
    process_file(argv[1]);
  } else {
    cout << "usage: readfile.exe path_to_file.txt" << endl;
  }
  return 0;
}

