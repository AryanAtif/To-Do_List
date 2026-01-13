#include <iostream>
#include <cerrno>
#include <fstream>

void open_config_file();
void open_config_file(std::string);


int main(int argc, char* argv[])
{

  std::string command[argc -1];

  for (int i = 1; i < argc; i++)
  {
    command[i] = *argv[i];
    std::cout << "command [" << i << "] = " << command[i] << std::endl;
  }

  if (argc == 1)                                                                              // > ./task
  {
    std::cout << "Syntax: ./task --command <task>" << std::endl;
  }
  else if (argv[1] == "-h" || argv[1] == "--help" )                                           // > ./task -h    ||  > ./task --help
  {
    std::cout << "helping... im helping so hard rn" << std::endl;
  }
  else if (argc <= 3 && (argv[1] == "-a" ||argv[1] == "-l" || argv[1] == "-d"))               // > ./task -l || > ./task -l <something>
  {
    open_config_file();
  }
  /* else if (argc <= 3 && (argv[1] == "--add" ||argv[1] == "--list" || argv[1] == "--delete")) //>./task --list || >./task --list<something>
  {
  
  } */
  else
  {
    std::cout << "in else" << std::endl;
    std::cout << "Syntax: ./task --command <task>" << std::endl; 
  }
}


void open_config_file()
{
  std::ifstream config_file("~/.tasks");
  
  if(!config_file)
  {
    std::cerr << "Error opening the config file" << std::endl;
  }
  else
  {
    std::cout << "File opened!" << std::endl;
  }
}
