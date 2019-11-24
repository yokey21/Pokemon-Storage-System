# Pokemon-Storage-System

## directory.cpp
Implements a simple class for navigating the terminal (MAC OSX)

```cpp
class directory
{
  private:
    string path; //stores current path
  public:
    directory(); //constructor
    directory(string p); //constructor

    bool setPath(string newPath); //sets a new path (only updates if new path is valid) @return 1 if successful

    bool ls(); //prints contents of directory @return 1 if successful
    string getPath(); //returns the current path
    bool cd(string dir); //adds dir to the path (only updates if new path is valid) @return 1 if successful
    bool cat(string file); //prints contents of file @return 1 if successful
};
```
