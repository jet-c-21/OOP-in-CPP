#include <sys/stat.h>
#include <iostream>

//using namespace std;

bool dirExists(const std::string &path) {
  struct stat info;
  if (stat(path.c_str(), &info) == 0 && info.st_mode & S_IFDIR) {
    return true;
  }
  return false;
}

int main() {
  std::cout << dirExists("foo") << std::endl;


  return 0;
}