#include <cstdlib>
#include <cstring>
#include <vector>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <iostream>

#include "globals.h"
#include "config_file.h"
#include "md_file.h"

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
    std::string path = open_c_file();
    if (path == "-1") {return 1;}

    std::filesystem::path md_file_path = get_md_file_path(path);
    open_md_file(md_file_path);
    //fstream md_file 
    std::string md_file_name = get_file_name(md_file_path);
    
    
    //initialize_file(path);

  }
  /* else if (argc <= 3 && (argv[1] == "--add" ||argv[1] == "--list" || argv[1] == "--delete")) //>./task --list || >./task --list<something>
  {
  
  } */
  else
  {
    std::cout << "in else" << std::endl; std::cout << "Syntax: ./task --command <task>" << std::endl; 
  }
}
