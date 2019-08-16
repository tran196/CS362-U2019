#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char inputChar()
{
  // TODO: rewrite this function
  char randomletter = (rand() % (94)) + 32; //Used Ascii Table 126 - 32 = 94 (include every character in the ASCII code, include every lowercase letter in the alphabet, include only the letters used in the target statement, etc.)
  return randomletter;
}

char *inputString()
{
  // TODO: rewrite this function
  int stringSize = 6;
  char *randString = malloc(sizeof(char) * stringSize);

  int i;
  for (i = 0; i < stringSize; i++)
  {
    randString[i] = inputChar();
  }
  return randString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;

  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();

    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0)
      state = 1;
    if (c == '(' && state == 1)
      state = 2;
    if (c == '{' && state == 2)
      state = 3;
    if (c == ' ' && state == 3)
      state = 4;
    if (c == 'a' && state == 4)
      state = 5;
    if (c == 'x' && state == 5)
      state = 6;
    if (c == '}' && state == 6)
      state = 7;
    if (c == ')' && state == 7)
      state = 8;
    if (c == ']' && state == 8)
      state = 9;
    if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
    {
      printf("error ");
      exit(200);
    }

    if (tcCount == 1000)
      break;
  }

}

int main(int argc, char *argv[])
{
  srand(time(NULL));
  testme();
  return 0;
}
