#include "View.h"
#include <string>
int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Invalid arguments\n";
    return 1;
  }
  std::string firstOption(argv[1]);
  bool comp = 0;
  if (firstOption == "ascending")
  {
    comp = 0;
  }
  else if (firstOption == "descending")
  {
    comp = 1;
  }
  else
  {
    std::cerr << "Invalid first arg\n";
    return 1;
  }
  int size = std::stoi(argv[3]);
  if (size <= 0)
  {
    std::cerr << "Invalid size\n";
    return 1;
  }
  std::string secondOption(argv[2]);
  if (secondOption == "ints")
  {
    sviridenko::viewSort< int >(comp, size);
  }
  else if (secondOption == "floats")
  {
    sviridenko::viewSort< float >(comp, size);
  }
  else
  {
    std::cerr << "Invalid second argument\n";
    return 1;
  }
}
