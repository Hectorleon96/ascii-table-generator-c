#include <stdio.h>
#include <string.h>

#define DATA_LENGTH 3
#define NAME_MAX_LENGTH 20
#define POINTS_MAX_LENGTH 5

typedef struct
{
  char name[NAME_MAX_LENGTH];
  int points;
} Data;

int main()
{

  char *headers[] = {"name", "points"};

  Data data[DATA_LENGTH] = {
      {"Hector", 27782},
      {"Shurumbe", 30},
      {"Adrian", 1299},
  };

  int dataLength = sizeof(data) / sizeof(data[0]);

  char namesIterator[NAME_MAX_LENGTH] = "";
  int pointsIterator = 0;

  for (int i = 0; i < dataLength; i++)
  {
    if (strlen(data[i].name) > strlen(namesIterator))
    {
      strcpy(namesIterator, data[i].name);
    }

    if (data[i].points > pointsIterator)
    {
      pointsIterator = data[i].points;
    }
  }

  int namesMaxLength = strlen(namesIterator);
  char maxPointsBuffer[POINTS_MAX_LENGTH];
  int pointsMaxLength = snprintf(maxPointsBuffer, sizeof(maxPointsBuffer), "%d", pointsIterator);

  printf("Name max length: %d\n", namesMaxLength);
  printf("Points max length: %d\n", pointsMaxLength);

  return 0;
}

/*

Output reference:

+----------+-----+-------+
| Name     | Age | Score |
+----------+-----+-------+
| Shurumbe | 30  | 100   |
| Pedro    | 25  | 85    |
| Juan     | 28  | 92    |
+----------+-----+-------+
*/