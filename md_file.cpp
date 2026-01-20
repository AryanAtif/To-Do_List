#include <iostream>
#include <fstream>
#include <filesystem>


// open the markdown file 
void open_md_file(std::string& path)
{
  bool is_valid_path (std::string &path);

  // Erase the double quotes and the " " and "~" characters from the address.
  path.erase (0,2); // Erase '"~' from the beginning
  path.erase(path.length()-1, path.length());  //  erase the last '"' 

  std::cout << "the path after the ops: " << path << std::endl;
/*
  const char* home = std::getenv("HOME");
  if (!home) {std::cerr << "There was an error finding the home directory." << std::endl; return;}
  std::filesystem::path md_file_path = home;     

  md_file_path /= path;
  
  std::fstream md_file (md_file_path, std::ios::in | std::ios::out | std::ios::app);  */
}

bool is_valid_path (std::string &path)
{
  char file_format[4];
  std::size_t length = path.copy(file_format, 3, path.length()-4);

  if (file_format = ".md") {return 1;}
  return 0;
}
