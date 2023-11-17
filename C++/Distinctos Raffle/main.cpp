#include <cstdio>
#include <iostream>
#include <cstring>

int N, K, numbers[100005];
int cntr[100005];

int answer;
/**
 * AIO 2023
 * @link https://orac2.info/problem/aio23raffle/
 * 
 * @mrmagic2020
*/
int main(void) {
    memset(cntr, 0, sizeof(cntr));

    FILE *input_file = fopen("rafflein.txt", "r");
    FILE *output_file = fopen("raffleout.txt", "w");

    fscanf(input_file, "%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        fscanf(input_file, "%d", &numbers[i]);
        cntr[numbers[i]]++;
        std::cout << "cntr[" << numbers[i] << "] = " << cntr[numbers[i]] << std::endl;
    }

    int min = -1;
    for (int i = 1; i <= K; i++)
      if (cntr[i] == 1)
      {
        min = i;
        break;
      }
    
    answer = min;

    fprintf(output_file, "%d\n", answer);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
