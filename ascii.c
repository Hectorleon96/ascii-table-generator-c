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

void appendLine(char *buffer, int iterator1, int iterator2)
{
  strcat(buffer, "+-");

  for (int i = 0; i < iterator1; i++)
  {
    strcat(buffer, "-");
  }

  strcat(buffer, "-");
  strcat(buffer, "+-");

  for (int i = 0; i < iterator2; i++)
  {
    strcat(buffer, "-");
  }

  strcat(buffer, "-+\n");
}

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

  if (strlen(headers[0]) > namesMaxLength)
  {
    namesMaxLength = strlen(headers[0]);
  }

  char maxPointsBuffer[POINTS_MAX_LENGTH];
  int pointsMaxLength = snprintf(maxPointsBuffer, sizeof(maxPointsBuffer), "%d", pointsIterator);

  if (strlen(headers[1]) > pointsMaxLength)
  {
    pointsMaxLength = strlen(headers[1]);
  }

  int spacesBetweenData = 7;
  int horizontalTableLength = (namesMaxLength + pointsMaxLength) + spacesBetweenData;

  int linesBetweenData = 4;
  int totalTableLength = horizontalTableLength * (dataLength + linesBetweenData);

  char linesBuffer[totalTableLength + 1];
  linesBuffer[0] = '\0';

  char tableBuffer[horizontalTableLength + 1];
  tableBuffer[0] = '\0';

  appendLine(tableBuffer, namesMaxLength, pointsMaxLength);

  printf("%s\n", tableBuffer);

  return 0;
}

/*
+----------+--------+
| name     | points |
+----------+--------+
| Hector   | 27782  |
| Shurumbe | 30     |
| Adrian   | 1299   |
+----------+--------+
*/