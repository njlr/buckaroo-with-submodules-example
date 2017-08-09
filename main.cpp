#include <string>
#include <iostream>

#include <a.hpp> // Provided by a Git Submodule
#include <b.hpp> // Provided by Buckaroo

int main() {
  std::cout << getA() << std::endl;
  std::cout << getB() << std::endl;
  return 0;
}
