#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>


void open_config_file();
void open_config_file(std::string);


int main(int argc, char* argv[])
{
  std::cout << "argc = " << argc << std::endl;

  std::string command[argc - 1];

  for (int i = 1; i < argc; i++)
  {
    command[i] = std::string(argv[i]);
    std::cout <<"command [" << i << "] = " << command[i] << std::endl;
  }

  if (argc == 1)                                                                              // > ./task
  {
    std::cout << "Syntax: ./task --command <task>" << std::endl;
  }
  else if ( command[1] == "-h" || command [1] == "--help" )                                           // > ./task -h    ||  > ./task --help
  {
    std::cout << "helping... im helping so hard rn" << std::endl;
  }
  else if (argc <= 3 && (command[1] == "-a" || command[1] == "-l" || command[1] == "-d"))               // > ./task -l || > ./task -l <something>
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
  const char* home = std::getenv("HOME");

  if (!home) {std::cerr << "There was an error finding the home directory" << std::endl; return;} // add exceptions here later

  // create an object of the class std::filesystem::path and assign the path to the home directory to it.
  std::filesystem::path config_file_path = home;     

  config_file_path /= ".tasks";

  std::ofstream config_file(config_file_path);
  
  if(!config_file)
  {
    std::cerr << "Error opening the config file" << std::endl;
  }
  else
  {
    std::cout << "File opened!" << std::endl;
  }
}
