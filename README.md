# Pokemon-Storage-System
The aim of this project is implement a storage system for various competitive pokemon movesets. 
This system relies on a specific directory set-up, therefore the program must be updated with the path of a specific device.

#### The file architecture should be like so: 
Pokemon_Data/<battle_formats>/<pokemon_name>/<moveset.pk> 
 
###### EX: Pokemon_Data/Gen8_OU/Weezing-Galar/Defensive_Tank.pk





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
