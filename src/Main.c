#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char INPUT_SYMBOL = '$';
const int STRINGS_MATCHING = 0;

void foo();
void bar();

int main()
{
  char buffer[64];
  bool running = true;
  while (strcmp(buffer, "exit"))
  {
    printf("%c ", INPUT_SYMBOL);
    scanf(" %s", &buffer);

    if (strcmp(buffer, "foo") == STRINGS_MATCHING)
    {
      foo();
      continue;
    }
    else if (strcmp(buffer, "bar") == STRINGS_MATCHING)
    {
      bar();
      continue;
    }
  }

  return EXIT_SUCCESS;
}

void foo()
{
  printf("Foo!\n");
}

void bar()
{
  printf("Bar!\n");
}
