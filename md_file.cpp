#include <iostream>
#include <fstream>
#include <filesystem>

#include "md_file.h"

// open the markdown file 
void open_md_file(std::string& path)
{
  if (is_valid_path(path)) { std::cout << "The path is valid" << std::endl; }

  else { std::cout << "The path is invalid" << std::endl;}

  // Erase the double quotes and the " " and "~" characters from the address.
  path.erase (0,2); // Erase '"~' from the beginning
  path.erase(path.length()-1, path.length());  //  erase the last '"' 

  std::cout << "the path after the ops: " << path << std::endl;

  if (is_valid_path(path)) { std::cout << "The path is valid" << std::endl; }
  else { std::cout << "The path is invalid" << std::endl;}
/*
  const char* home = std::getenv("HOME");
  if (!home) {std::cerr << "There was an error finding the home directory." << std::endl; return;}
  std::filesystem::path md_file_path = home;     

  md_file_path /= path;
  
  std::fstream md_file (md_file_path, std::ios::in | std::ios::out | std::ios::app);  */
}

bool is_valid_path (std::string &path)
{
  // check if the sequence ".md" makes up the last three characters of the string
  size_t path_found = path.rfind(".md");
  int file_extension_size = 3; 
  if (path_found != path.npos && (path.size() - path_found == file_extension_size)) {return 1;} 
  return 0;
} 
