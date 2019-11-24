#include "Pokemon_Interface.hpp"

const string GEN8OU = "Gen8_OU"; //file location

//NOT FUNCTIONAL (other generations/formats)
Pokemon_Interface::Pokemon_Interface(int g, string f, string path)
: gen(g), format(f), home(path)
{
  dir.setPath(home);
}

Pokemon_Interface::Pokemon_Interface(string path)
: gen(8), format("OU"), home(path)
{
  dir.setPath(home);
  dir.cd(GEN8OU);
}

void Pokemon_Interface::launch()
{
  bool pokemonView = 0; //1 if you a pokemon is selected
  bool setView = 0; //1 if you are viewing a moveset
  string curPokemon;
  string input;
  while(1)
  {
    //clears screen (MAC ONLY)
    system("clear");

    //Check which view you are in (pokemon,set)
    if(setView) // SET VIEW (viewing set)
    {
      cout << "*** Viewing " << input << " ***" << endl;
      dir.cat(input);
      setView = 0; //Go back After viewing
    }
    else if(pokemonView) //POKEMON VIEW (viewing list of sets)
    {
      cout << "Sets for " <<  curPokemon << endl;
      dir.ls();
      pokemonView = 0; //Go back after viewing
    }
    else //FORMAT VIEW (viewing pokemon in given format)
    {
      cout << format << " Gen " << gen << " Pokemon" << endl;
      dir.ls();
    }




    cout << endl << "€ ";
    cin >> input;

    //Check if input is a file
    if(isPokemonFile(input))
    {
      setView = 1;
      cout << endl;
    }
    else
    {
      if(dir.cd(input))
      {
        pokemonView = 1;
        curPokemon = input;
      }
    }
  }
}

bool isPokemonFile(string s)
{
  size_t find = s.rfind(".");
  if(find == string::npos) //if no "." found
  {
    return 0;
  }
  return 1;
}
