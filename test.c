#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buf = "123456789\n";
  write(1, buf, strlen(buf));
  return 0;
}
