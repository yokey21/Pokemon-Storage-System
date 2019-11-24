
#include <iostream>
#include <dirent.h> //https://pubs.opengroup.org/onlinepubs/7908799/xsh/dirent.h.html
using namespace std;

#include "directory.cpp"

const char * DATABASE_PATH = "/Users/adambyron/Pokemon_Data/Gen8_OU";




bool ls(const char* path);

int main()
{
  string path = DATABASE_PATH;
  string input;

  //create new directory with given path
  directory dir(DATABASE_PATH);
  cout << endl << dir.getPath() << endl;

  dir.cd("Weezing-Galar");

  dir.ls();

  dir.cat("Defensive_Tank.pk");

  cout << endl << dir.getPath() << endl;

  //cout << "Select Pokemon: ";
  //cin >> input;
}


/////////////////////////////////////////////////////////////
////////////////////// Helper Methods ///////////////////////
/////////////////////////////////////////////////////////////
