#include <iostream>

class Log {
 public:
  enum Level

  const int kLogLevelError = 0;
  const int kLogLevelWarning = 1;
  const int kLogLevelInfo = 2;

 private:
  int m_log_level = kLogLevelInfo;

 public:
  void set_level(int level) {
    m_log_level = level;
  }

  void warn(const char *message) {

  }
};

int main() {
  Log log;
  log.set_level(1);
  log.warn("Hello!");

}