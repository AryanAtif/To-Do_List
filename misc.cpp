#include <fstream>
#include <iostream>
#include <vector>  // for the vectors
#include <sstream> // for std::istringstream


int get_file_length (std::fstream& file)
{
  file.seekg(0, file.end);         // move from the first character to the last one.
  int length = file.tellg();  // tell where the g pointer is right now -- it should be at the end of the file, telling the file size
  file.seekg (0, file.beg);
  
  return length;
}

std::vector <std::string> break_file_into_lines ( std::fstream& file)
{
  int length = get_file_length(file); // from misc.h // get the number of characters inside in the file

  char* data = new char [length];
  
  file.read (data, length);

  if(file) { std::cout << "Data read successfully. " << file.gcount() << " out of " << length << " read." << std::endl; }
  else 
  {std::cerr << "Error: reading the file, only " << file.gcount() << " characters out of " << length << " could be read." << std::endl; exit(-1);}
  
  // convert the data read from the file into a string stream
  std::istringstream data_stream (data); // so that we can stream in the data into getline
  std::vector <std::string> data_in_line; // so that we have a dynamic array
  std::string buf; //temp buffer 
  int line = 0;
  

  // Break down the file data into separate lines
  
  for (int i = 0; !data_stream.eof(); i++) // run until i < the number of characters in data
  {
      std::getline(data_stream, buf);
      data_in_line.push_back(buf);
  }

  return data_in_line;
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
