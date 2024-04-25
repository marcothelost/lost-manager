#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char INPUT_SYMBOL = '$';

int main()
{
  char buffer[64];
  while (strcmp(buffer, "exit"))
  {
    printf("%c ", INPUT_SYMBOL);
    scanf(" %s", &buffer);
  }

  return EXIT_SUCCESS;
}
