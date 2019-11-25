# Pokemon-Storage-System
The aim of this project is implement a simple text-based storage system for various competitive pokemon movesets. 

### Set-Up

- This system relies on a specific directory set-up, therefore the program must be updated with the path of a specific user.
1) Update the path in `main.cpp` with the full path to 'Pokemon_Data'
2) Compile the program from terminal using `make`
3) Run Pogram using `./pss`

#### The file architecture should be like so:  
Pokemon_Data/<battle_formats>/<pokemon_name>/<moveset.pk> 
 
#### EX: Pokemon_Data/Gen8_OU/Weezing-Galar/Defensive_Tank.pk

### Usage
1) Enter Pokemon name (case-insensitive)
<img src="https://github.com/yokey21/Pokemon-Storage-System/blob/master/images/pokemon.png"  width="400" height="300" />

2) Select Moveset (case-sensitive, include file extension `.pk`)
<img src="https://github.com/yokey21/Pokemon-Storage-System/blob/master/images/sets.png"  width="400" height="300" />

3) Type 'home' to return to the list of pokemon, or 'back' to return to the list of movesets
<img src="https://github.com/yokey21/Pokemon-Storage-System/blob/master/images/set.png"  width="400" height="300" />

- Type `help` for full command list

## Pokemon_Interface class

```cpp

class Pokemon_Interface
{
  private:
    int gen; //Generation of Pokemon (1-8)
    string format; //OU,UU,etc
    string home; //home directory of database
    directory dir;
  public:
    Pokemon_Interface(int generation, string form, string path); //NOT IMPLEMENTED
    Pokemon_Interface(string path); //default: gen(8), format(OU)

    void add(); //adds a new set
    void launch(); //lauches program
};

bool isPokemonFile(string s); //check if string is a .pk file(1) or directory(0)
void open(string path); //opens given path in textedit


```

## directory class
Implements a simple class for navigating the terminal (unix)

```cpp
//used to navigate directories similar to terminal (UNIX)
class directory
{
  private:
    string path; //stores current path
  public:
    directory(); //constructor
    directory(string p); //constructor

    bool setPath(string newPath);

    bool ls(); //prints contents of directory: returns 1 if successful
    string getPath(); //returns the current path
    bool cd(string dir); //adds dir to the path (only updates if new path is valid)
    bool cat(string file); //prints contents of file
};

//returns 0 if s = '.'/'..'/'.DS_Store' (Used to hide system directories)
bool isFile(string s);
void printFile(string path);

```
