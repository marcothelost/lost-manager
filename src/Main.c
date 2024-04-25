#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char         INPUT_SYMBOL     = '$';
const int          STRINGS_MATCHING = 0;
const unsigned int BUFFER_SIZE      = 128;

void clearScreen();
void foo();
void bar();

int main()
{
  char* buffer = (char*)malloc(sizeof(char) * BUFFER_SIZE);
  bool running = true;

  clearScreen();

  while (strcmp(buffer, "exit"))
  {
    printf("%c ", INPUT_SYMBOL);
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    if (strcmp(buffer, "exit") == STRINGS_MATCHING)
    {
      continue;
    }

    if (strcmp(buffer, "foo") == STRINGS_MATCHING)
    {
      foo();
    }
    else if (strcmp(buffer, "bar") == STRINGS_MATCHING)
    {
      bar();
    }
    else if (strcmp(buffer, "clear") == STRINGS_MATCHING)
    {
      clearScreen();
    }
    else
    {
      printf("Command \"%s\" does not exist!\n", buffer);
    }
  }

  free(buffer);
  return EXIT_SUCCESS;
}

void clearScreen() { printf("\e[1;1H\e[2J"); }
void foo() { printf("Foo!\n"); }
void bar() { printf("Bar!\n"); }
