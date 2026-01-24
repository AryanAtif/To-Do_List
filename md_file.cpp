#include <iostream>
#include <fstream>
#include <filesystem>
#include "md_file.h"

// open the markdown file 
void clear_the_path (std::string& path)
{
  path.erase (0,2); // Erase '"~' from the beginning
  path.erase(path.length()-1, path.length());  //  erase the last '"' 

  std::cout << "the path after the ops: " << path << std::endl;

}
std::filesystem::path get_md_file_path (std::string& path)
{
  // Erase the double quotes and the " " and "~" characters from the address.
  clear_the_path(path);

  // Check validity of the path
  if (is_valid_path(path)) { std::cout << "The path is valid" << std::endl; }
  else { std::cout << "The path is invalid" << std::endl;}

  // Make the path absolute
  const char* home = std::getenv("HOME");
  if (!home) {std::cerr << "There was an error finding the home directory." << std::endl; return {};}
  std::filesystem::path md_file_path = home;     
  md_file_path /= path;

  // Open/Create the md file with the path created above
  std::fstream md_file (md_file_path, std::ios::in | std::ios::out | std::ios::app);  
  return md_file_path;
}

bool is_valid_path (std::string &path)
{
  // check if the sequence ".md" makes up the last three characters of the string
  size_t path_found = path.rfind(".md");
  int file_extension_size = 3; 
  if (path_found != path.npos && (path.size() - path_found == file_extension_size)) {return 1;} 
  return 0;
} 

std::string get_file_name (std::filesystem::path &file_path)
{
  return (std::string)file_path.filename(); 
}

/*
void initialize_file (fstream file)
{
  file << "###"
}*/

