#include <cstdio>

int N;
char instructions[100005];

int answer;
/**
 * AIO 2023
 * @link https://orac2.info/problem/aio23teletrip/
 * 
 * @mrmagic2020
*/
int main() 
{
    /* Open the input and output files. */
    FILE *input_file = fopen("telein.txt", "r");
    FILE *output_file = fopen("teleout.txt", "w");

    /* Read the value of N and the instructions from the input file. */
    fscanf(input_file, "%d", &N);
    fscanf(input_file, "%s", instructions);

    int cntr = 1, pos = 0, minPos = 0, maxPos = 0;
    for (int i = 0; i < N; i++)
    {
      if (instructions[i] == 'L') 
      {
        pos --;
        if (pos < minPos)
        {
          minPos = pos;
          cntr ++;
        }
      } else if (instructions[i] == 'R') 
      {
        pos ++;
        if (pos > maxPos)
        {
          maxPos = pos;
          cntr ++;
        }
      } else 
      {
        pos = 0;
      }
    }

    answer = cntr;

    /* Write the answer to the output file. */
    fprintf(output_file, "%d\n", answer);

    /* Finally, close the input/output files. */
    fclose(input_file);
    fclose(output_file);

    return 0;
}
