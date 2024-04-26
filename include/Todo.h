#ifndef LMGR_TODO_H
#define LMGR_TODO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

static const char*    TODO_FILE_NAME = "todos.txt";
static const unsigned TODO_PATH_SIZE = 128u;
static const unsigned TODO_LINE_SIZE = 128u;

typedef struct Todo
{
  char* text;
  bool completed;
  struct Todo* next;
} Todo;

Todo* loadTodos();
void addTodo(Todo* todo);
void removeTodo(Todo* todo);

#endif // LMGR_TODO_H
