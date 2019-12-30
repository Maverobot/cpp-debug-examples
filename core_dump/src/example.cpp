#include <signal.h>
#ifndef NDEBUG
#warning Debug build is not advised!
#endif

int main(int argc, char *argv[]) {

  int index = 0;

  while (index < 100) {
    if (index == 55) {
      raise(SIGABRT);
    }
    index++;
  }

  return 0;
}
