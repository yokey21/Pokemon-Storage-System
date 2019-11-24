#include "directory.hpp"
#include <fstream>

directory::directory() : path("\0")
{
}

directory::directory(string p) : path(p)
{
}

//prints contents of directory: returns 1 if directory is valid
bool directory::ls()
{
  DIR *dir;
  struct dirent *ent;
  const char* path_c = path.c_str();    //convert path to const char*

  if ((dir = opendir (path_c)) != NULL)
  {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL)
    {
      //Hides System Directories (./../.DS_Store)
      if(isPokemon(ent->d_name))
      {
        //print directory name
        cout << "- " << ent->d_name << endl;
      }
    }
    closedir (dir);
    return true;    //return true if successful
  }
  return false;   //return false if path is invalid
}

//returns path of directory
string directory::getPath()
{
  return path;
}

bool directory::cd(string dir)
{
  //create temporary path to check validity
  string tempPath = path + "/" + dir;
  const char* path_c = tempPath.c_str();

  //check for '..' operator (back directory)
  if(dir=="..")
  {
    size_t find = path.rfind("/"); //find last '/' in string
    path.erase(find,path.length()); //remove text from last '/' to end of string
    return 1;
  }

  //check if path is valid
  if ((opendir (path_c)) != NULL)
  {
    //update path if valid
    path = tempPath;
    return true;
  }
  return false;     //return false if path is invalid */
}

bool directory::setPath(string newPath)
{
  //create temporary path to check validity
  string tempPath = newPath;
  const char* path_c = tempPath.c_str();

  //check if path is valid
  if ((opendir (path_c)) != NULL)
  {
    //update path if valid
    path = tempPath;
    return true;
  }
  return false;
}

bool directory::cat(string filename)
{
  //create temporary path to file
  string file_path = path + "/" + filename;

  //path to parent directory (const char*)
  const char* path_c = path.c_str();

  DIR *dir;
  struct dirent *ent;

  if ((dir = opendir (path_c)) != NULL)
  {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL)
    {
      //If "file" is found
      if(ent->d_name==filename)
      {
        //cout << "- " << ent->d_name << endl;
        printFile(file_path);
      }
    }
    closedir (dir);
    return true;    //return true if successful
  }
  return false;   //return false if path is invalid
}

//Returns false if s = '.', '..' or '.DS_Store'
bool isPokemon(string s)
{
  if(s == "." || s == ".." || s == ".DS_Store")
  {
    return false;
  }
  return true;
}

void printFile(string path)
{
  ifstream f;
  f.open(path);
  cout << endl << f.rdbuf();
  f.close();
}
