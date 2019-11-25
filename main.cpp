
#include <iostream>
#include <dirent.h> //https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
#include "termcolor.hpp" //text formatting - https://termcolor.readthedocs.io/

using namespace std;

#include "directory.cpp"
#include "Pokemon_Interface.cpp"

void add();

const char * DATABASE_PATH = "/Users/adambyron/Documents/GitHub/Pokemon-Storage-System/Pokemon_Data";

int main()
{
  string path = DATABASE_PATH;
  string input;

  Pokemon_Interface pki(path);

  pki.launch();

  system("clear");
}
