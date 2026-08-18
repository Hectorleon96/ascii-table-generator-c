#include <stdio.h>
#include <string.h>

#define DATA_LENGTH 3

typedef struct
{
  char name[20];
  int age;
} Data;

int main()
{

  char *headers[] = {"name", "age"};

  Data data[DATA_LENGTH] = {
      {"Hector", 27},
      {"Shurumbe", 30},
      {"Adrian", 19},
  };

  int dataLength = sizeof(data) / sizeof(data[0]);

  char namesIterator[20] = "";

  for (int i = 0; i < dataLength; i++)
  {
    if (strlen(data[i].name) > strlen(namesIterator))
    {
      strcpy(namesIterator, data[i].name);
      continue;
    }
  }

  int namesMaxLength = strlen(namesIterator);
  printf("%d\n", namesMaxLength);

  return 0;
}

/*
+----------+-----+-------+
| Name     | Age | Score |
+----------+-----+-------+
| Shurumbe | 30  | 100   |
| Pedro    | 25  | 85    |
| Juan     | 28  | 92    |
+----------+-----+-------+
*/