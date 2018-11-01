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

int main(int argc, char *argv[]) {
  if (argc == 2) {
    process_file(argv[1]);
  } else {
    cout << "usage: sim.exe <name>.obj" << endl;
  }
  return 0;
}

