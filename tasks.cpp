#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>


void open_config_file();
void open_config_file(std::string);

void read_file(std::fstream file);

int main(int argc, char* argv[])
{
  //for debugging
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
    std::cout << "in else" << std::endl; std::cout << "Syntax: ./task --command <task>" << std::endl; 
  }
}


void open_config_file()
{
  const char* home = std::getenv("HOME");

  if (!home) {std::cerr << "There was an error finding the home directory" << std::endl; return;} // TODO: add exceptions
                                                                                                  
  // create an object of the class std::filesystem::path and assign the path to the home directory to it.
  std::filesystem::path config_file_path = home;     

  config_file_path /= ".task.conf";

  std::fstream config_file(config_file_path, std::ios::in | std::ios::out | std::ios::app);
  
  if(!config_file) { std::cerr << "Error opening the config file" << std::endl; return;} // TODO: Add exceptions
  
  if(config_file.gcount() == 0) { std::cerr << "The config file is empty. Run ./tasks -c or ./tasks --config to create it." << std::endl; return;}
  
  // For debugging
  std::cout << "File opened!" << std::endl;

  //TODO: Read the config file to get the path for the md file.
}


void read_file(std::fstream file)
{
  
  //for (int i = 0; ; i++)
   
}


