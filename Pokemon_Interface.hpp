
class Pokemon_Interface
{
  private:
    int gen; //Generation of Pokemon (1-8)
    string format; //OU,UU,etc
    string home; //home directory of database
    directory dir;
  public:
    Pokemon_Interface(int generation, string form, string path);
    Pokemon_Interface(string path); //default: gen(8), format(OU)
    void launch();
};

//check if string is a .pk file(1) or directory(0)
bool isPokemonFile(string s);
