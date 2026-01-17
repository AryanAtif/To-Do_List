#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

void open_c_file();
void open_c_file(std::string);

void read_file(std::fstream& file);
int get_characters(std::fstream& file);

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
    open_c_file();

  }
  /* else if (argc <= 3 && (argv[1] == "--add" ||argv[1] == "--list" || argv[1] == "--delete")) //>./task --list || >./task --list<something>
  {
  
  } */
  else
  {
    std::cout << "in else" << std::endl; std::cout << "Syntax: ./task --command <task>" << std::endl; 
  }
}


void open_c_file() // throughout this method, the prefix "c_" shall mean "config_", e.g "c_file" would mean "config_file"
{
  const char* home = std::getenv("HOME");

  if (!home) {std::cerr << "There was an error finding the home directory." << std::endl; return;} // TODO: add exceptions
                                                                                                  
  // create an object of the class std::filesystem::path and assign the path to the home directory to it.
  std::filesystem::path c_file_path = home;     

  c_file_path /= ".task_conf";
  
  std::fstream c_file (c_file_path, std::ios::in | std::ios::out | std::ios::app); 
  c_file.flush();
  c_file.seekg(0, c_file.beg);         // move the cursor to the beginning

  if(!c_file) { std::cerr << "Error opening the config file" << std::endl; return;} // TODO: Add exceptions
  

  // Reading the number of character in a file
  int c_characters = get_characters(c_file); 
  if(c_characters == 0) { std::cerr << "The config file is empty. Run ./tasks -c or ./tasks --config to create it." << std::endl; return;}
  else {std::cout << "The file does exist." << std::endl;}
  
  // For debugging
  std::cout << "File opened!" << std::endl;


  //TODO: Read the config file to get the path for the .md file.
  
  read_file(c_file);
}



int get_characters (std::fstream& file)
{
  file.seekg(0, file.end);         // move from the first character to the last one.
  int characters = file.tellg();  // tell where the g pointer is right now -- it should be at the end of the file, telling the file size

  return characters;
}


///  PLAN: to take the last 'source =' line as the path of the .md file  
void read_file(std::fstream& file)
{
  int length = get_characters(file); // get the number of characters inside in the file
  file.seekg(0, file.beg);         // move the cursor to the beginning

  char* data = new char [length];
  
  file.read (data, length);

  if(file) { std::cout << "Data read successfully. " << file.gcount() << " out of " << length << " read." << std::endl; }
  else 
  {std::cerr << "Error: reading the file, only " << file.gcount() << " characters out of " << length << " could be read." << std::endl; return;}

 /* 
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
      std::cout << data_in_line.back() << std::endl;
  }
*/
  // convert the data read from the file into a string stream
  std::istringstream data_stream (data); // so that we can stream in the data into getline
  std::vector <const char *> data_in_line; // so that we have a dynamic array
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
      data_in_line.push_back(buf.c_str());
      std::cout << data_in_line.back() << std::endl;
  }

}
