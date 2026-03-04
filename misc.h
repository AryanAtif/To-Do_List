#ifndef MISC_H 
#define MISC_H

#include <fstream>
#include <vector>
#include <iostream>

int get_file_length (std::fstream& file);
std::vector <std::string> break_file_into_lines ( std::fstream& file);
int find_sequence (std::vector <std::string>& file_lines, std::string& required_sequence);
#endif
