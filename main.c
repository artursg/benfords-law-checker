#include <stdio.h>
#include <string.h>

char accumulator[10];

int main(int argc, char ** argv)
{
  if (argc != 2)
    {
      printf("Benford law checker.\nUsage: ./benford [filename]\n");
      return -1;
    }
  FILE * f = fopen(argv[1], "r");
  memset(accumulator, 0, 10);
  if (f == NULL)
    {
      printf("Error. File is not available.\n");
      return -1;
    }
  char c = 0;
  int total = 0;
  while((c = fgetc(f)) != EOF)
    {
      if (c >= '0' && c <= '9')
	{
	  accumulator[c - '0'] += 1;
	  total++;
	}
    }
  printf("Total digits: %d\n", total);
  int i = 0;
  for (i; i < 10; i++)
    printf("%d: %d\n", i, accumulator[i]);
  fclose(f);
  return 0;
}
