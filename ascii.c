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
      {"Briones", 27782},
      {"Shurumbe", 30},
      {"Bertha nates", 12995732},
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

  const int SPACES_BETWEEN_DATA = 7;
  int horizontalTableLength = (namesMaxLength + pointsMaxLength) + SPACES_BETWEEN_DATA;

  const int LINES_BETWEEN_DATA = 4;
  const int NULL_TERMINATOR_SIZE = 1;
  int totalTableLength = (horizontalTableLength * (dataLength + LINES_BETWEEN_DATA)) + NULL_TERMINATOR_SIZE;

  char tableBuffer[totalTableLength];

  tableBuffer[0] = '\0';

  // open table

  appendLine(tableBuffer, namesMaxLength, pointsMaxLength);

  // append headers

  strcat(tableBuffer, "| ");
  strcat(tableBuffer, headers[0]);

  for (int i = 0; i < (namesMaxLength - strlen(headers[0])); i++)
  {
    strcat(tableBuffer, " ");
  }

  strcat(tableBuffer, " ");
  strcat(tableBuffer, "| ");
  strcat(tableBuffer, headers[1]);

  for (int i = 0; i < (pointsMaxLength - strlen(headers[1])); i++)
  {
    strcat(tableBuffer, " ");
  }

  strcat(tableBuffer, " ");
  strcat(tableBuffer, "|\n");

  // separator

  appendLine(tableBuffer, namesMaxLength, pointsMaxLength);

  // append data

  for (int i = 0; i < dataLength; i++)
  {
    strcat(tableBuffer, "| ");
    strcat(tableBuffer, data[i].name);

    for (int j = 0; j < (namesMaxLength - strlen(data[i].name)); j++)
    {
      strcat(tableBuffer, " ");
    }

    strcat(tableBuffer, " ");
    strcat(tableBuffer, "| ");

    char pointBuffer[pointsMaxLength + 1];
    snprintf(pointBuffer, sizeof(pointBuffer), "%d", data[i].points);
    strcat(tableBuffer, pointBuffer);

    for (int j = 0; j < (pointsMaxLength - strlen(pointBuffer)); j++)
    {
      strcat(tableBuffer, " ");
    }

    strcat(tableBuffer, " ");
    strcat(tableBuffer, "|\n");
  }

  // close table

  appendLine(tableBuffer, namesMaxLength, pointsMaxLength);

  printf("%s\n", tableBuffer);

  return 0;
}
