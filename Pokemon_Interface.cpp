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
  string curSet;
  string input;
  while(1)
  {
    //clears screen (MAC ONLY)
    system("clear");

    //Check which view you are in (pokemon,set)
    if(setView) // SET VIEW (viewing set)
    {
      cout << termcolor::bold << termcolor::underline; //Format text (Bold/Underline)
      cout << "*** Viewing " << curSet << " ***" << endl;
      cout << termcolor::reset; //Reset Formatting

      dir.cat(curSet);
      //setView = 0; //Go back After viewing
    }
    else if(pokemonView) //POKEMON VIEW (viewing list of sets)
    {
      cout << termcolor::bold << termcolor::underline; //Format text (Bold/Underline)
      cout << "Sets for " <<  curPokemon << endl;
      cout << termcolor::reset; //Reset Formatting

      dir.ls();
      //pokemonView = 0; //Go back after viewing
    }
    else //FORMAT VIEW (viewing pokemon in given format)
    {
      cout << termcolor::bold << termcolor::underline; //Format text (Bold/Underline)
      cout << format << " Gen " << gen << " Pokemon" << endl;
      cout << termcolor::reset; //Reset Formatting
      dir.ls();
    }


    cout << endl << "€ ";
    cin >> input;

    if(input == "exit") //"exit" Command
    {
      return; //exit function and end program
    }
    else if(input == "back") //"back" Command
    {
      if(setView)
      {
        //dir.cd("..");
        setView = 0;
        pokemonView = 1;
      }
      else if(pokemonView)
      {
        dir.cd("..");
        setView = 0;
        pokemonView = 0;
      }
    }
    else if(input == "home") //"home" command
    {
      if(setView)
      {
        dir.cd("..");
        setView = 0;
        pokemonView = 0;
      }
      else if(pokemonView)
      {
        dir.cd("..");
        setView = 0;
        pokemonView = 0;
      }
    }
    else if(isPokemonFile(input)) //Check if input is a file
    {
      setView = 1;
      pokemonView = 1;
      curSet = input;
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
