#include "Todo.h"

Todo* loadTodos()
{
  char* todoLocation = (char*)malloc(sizeof(char) * TODO_PATH_SIZE);
  strcpy(todoLocation, "resources/");
  strcat(todoLocation, TODO_FILE_NAME);
  FILE* todoFile = fopen(todoLocation, "r");

  if (todoFile == NULL)
  {
    fprintf(stderr, "Failed to open the todo file (%s)!\n", todoLocation);
    free(todoLocation);
    return NULL;
  }
  free(todoLocation);

  char* line = (char*)malloc(sizeof(char) * TODO_LINE_SIZE);
  Todo* head = NULL;
  Todo* tail = NULL;

  while (fgets(line, TODO_LINE_SIZE, todoFile))
  {
    bool emptyLine = true;
    for (int i = 0; line[i] != '\0'; i++)
    {
      if (!isspace(line[i])) emptyLine = false;
    }
    if (emptyLine) continue;

    Todo* loadedTodo = (Todo*)malloc(sizeof(Todo));
    if (loadedTodo == NULL)
    {
      fprintf(stderr, "Failed to allocate memory for todo!\n");
      break;
    }

    char* token = strtok(line, ";");
    if (token == NULL)
    {
      free(loadedTodo);
      continue;
    }

    loadedTodo->text = strdup(token);
    token = strtok(NULL, ";");

    if (token == NULL)
    {
      free(loadedTodo);
      free(loadedTodo->text);
      continue;
    }

    loadedTodo->completed = atoi(token);
    loadedTodo->next = NULL;

    if (head == NULL)
    {
      head = loadedTodo;
      tail = loadedTodo;
    }
    else
    {
      tail->next = loadedTodo;
      tail = loadedTodo;
    }
  }

  free(line);
  fclose(todoFile);
  return head;
}
