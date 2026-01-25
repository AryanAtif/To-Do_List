#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cstring>
#include <cstdlib>
#include <vector>

#include "globals.h"
#include "config_file.h"
#include "misc.h"

std::string open_c_file() // throughout this method, the prefix "c_" shall mean "config_", e.g "c_file" would mean "config_file"
{
  const char* home = std::getenv("HOME");

  if (!home) {std::cerr << "There was an error finding the home directory." << std::endl; return "-1";} // TODO: add exceptions
                                                                                                  
  // create an object of the class std::filesystem::path and assign the path to the home directory to it.
  std::filesystem::path c_file_path = home;     

  c_file_path /= ".task_conf";
  
  c_file.open ( c_file_path, std::ios::in | std::ios::out | std::ios::app);  // the config file
  c_file.flush();
  c_file.seekg(0, c_file.beg);         // move the cursor to the beginning

  if(!c_file) { std::cerr << "Error opening the config file" << std::endl; return "-1";} // TODO: Add exceptions
  

  // Reading the number of character in a file
  int c_characters = get_characters(c_file); 
  if(c_characters == 0) { std::cerr << "The config file is empty. Run ./tasks -c or ./tasks --config to create it." << std::endl; return "-1";}

  std::string path = read_file(c_file);
  
  if (path == "-1") {return "-1";}

  return path; 

}

// PLAN: to take the last 'source =' line as the path of the .md file  
std::string read_file(std::fstream& file)
{
  int length = get_characters(file); // from misc.h // get the number of characters inside in the file
  file.seekg(0, file.beg);         // move the cursor to the beginning

  char* data = new char [length];
  
  file.read (data, length);

  if(file) { std::cout << "Data read successfully. " << file.gcount() << " out of " << length << " read." << std::endl; }
  else 
  {std::cerr << "Error: reading the file, only " << file.gcount() << " characters out of " << length << " could be read." << std::endl; return "-1";}
  
  // convert the data read from the file into a string stream
  std::istringstream data_stream (data); // so that we can stream in the data into getline
  std::vector <std::string> data_in_line; // so that we have a dynamic array
  std::string buf; //temp buffer 
  int line = 0;
  

  // Break down the file data into separate lines
  // Doing this because:
  //      1. Breaking down the data of the file will help to find the line with "source =" which then can be used to find the absolute
  //         address of the .md file
  //      2. There can be more than one address lines, we need to make sure we choose the latest one, that should be the last source lines
  //         in the file.
  //
  for (int i = 0; !data_stream.eof(); i++) // run until i < the number of characters in data
  {
      std::getline(data_stream, buf);
      data_in_line.push_back(buf);
  }

  // find the last occurance of the sequence: "source ="
  std::string required_sequence = "source =";
  int md_file_path = find_sequence (data_in_line, required_sequence);
 
  if (md_file_path == -1) { std::cout << "There was an error finding the saved file. Make sure the config file holds the path to the file." << std::endl; return "-1";}

  std::string path = find_path(data_in_line.at(md_file_path), required_sequence);

  std::cout << "The path to the md file: " << path << std::endl;

  return path;
}

int find_sequence (std::vector <std::string>& file_lines, std::string& required_sequence)
{
  int sequence_size = int(size(required_sequence));
  int lines = file_lines.size();
  int match_count;

  for (int i = lines - 1; i > 0; i--)
  {
    match_count = 0;
    for (int j = 0; j < sequence_size; j++)
    {
      if (file_lines.at(i)[j] == '\0') { break; } // if we go over the bounds of file_lines

      else if (file_lines.at(i)[j] == required_sequence [j])
      {
        match_count++;
      }
    }
    if (match_count == sequence_size) {return i;}
  }
  return -1;
}

std::string find_path (std::string path_line, std::string required_sequence)
{
  size_t sequence_size = std::size(required_sequence);
  std::string path = path_line.substr(sequence_size);

  return path;
}
