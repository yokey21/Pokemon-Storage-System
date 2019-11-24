
#include <iostream>
#include <dirent.h> //https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
using namespace std;

#include "directory.cpp"
#include "Pokemon_Interface.cpp"

const char * DATABASE_PATH = "/Users/adambyron/Pokemon_Data";

int main()
{
  string path = DATABASE_PATH;
  string input;

  Pokemon_Interface pki(path);

  pki.launch();

}
