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
