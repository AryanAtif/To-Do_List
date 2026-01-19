#include <fstream>


int get_characters (std::fstream& file)
{
  file.seekg(0, file.end);         // move from the first character to the last one.
  int characters = file.tellg();  // tell where the g pointer is right now -- it should be at the end of the file, telling the file size

  return characters;
}
