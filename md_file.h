#ifndef MD_FILE_H
#define MD_FILE_H

#include <filesystem>

void clear_the_path (std::string& path);
std::filesystem::path get_md_file_path (std::string& path);
bool is_valid_path (std::string &path);
std::string get_file_name (std::filesystem::path &file_path);
void open_md_file (std::filesystem::path &md_file_path);

#endif 
