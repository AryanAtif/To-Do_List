#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

#include <vector>
#include <fstream>


std::string read_file(std::fstream& file);
int find_sequence (std::vector <std::string>& file_lines, std::string& required_sequence);
std::string get_md_file_path ();

std::string open_c_file();
std::string open_c_file(std::string);

int find_sequence (std::vector <std::string>& string, std::string& required_sequence);
std::string find_path (std::string path_line, std::string requried_sequence);

#endif 
