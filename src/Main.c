#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Todo.h"

const char         INPUT_SYMBOL     = '$';
const int          STRINGS_MATCHING = 0;
const unsigned int BUFFER_SIZE      = 128u;

void clearScreen();
void printTodos();

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

    if (strcmp(buffer, "todos") == STRINGS_MATCHING)
    {
      printTodos();
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

void clearScreen() {
  printf("\e[1;1H\e[2J");
}

void printTodos() {
  Todo* currentTodo = loadTodos();
  while (currentTodo != NULL)
  {
    printf("%s (%s)\n", currentTodo->text, currentTodo->completed ? "Done" : "Undone");
    currentTodo = currentTodo->next;
  }
}
