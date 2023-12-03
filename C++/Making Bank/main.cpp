#include <cstdio>
#include <algorithm>

using namespace std;

int N;
char days[100005];

/**
 * AIO 2023
 * @link https://orac2.info/problem/aio23bank/
 * 
 * @mrmagic2020
*/
int main(void) {
    /* Open the input and output files. */
    FILE *input_file = fopen("bankin.txt", "r");
    FILE *output_file = fopen("bankout.txt", "w");

    /* Read the value of N and the string of characters from the input file. */
    fscanf(input_file, "%d", &N);
    fscanf(input_file, "%s", days);

    int ans = N; // min(MCCCC) = 5
    int money = 0;
    int skill = 1;
    for (int i = 0; i < N; i++)
    {
        if (days[i] == 'C')
        {
            skill++;
        } else {
            money += skill;
        }

        // 到底什么时候停止学习？
        int leftDays = N-i-1; // 5-1-1 = 3
        ans = max(ans, money+skill*leftDays);
    }

    /* Write the answer to the output file. */
    fprintf(output_file, "%d\n", ans);

    /* Finally, close the input/output files. */
    fclose(input_file);
    fclose(output_file);

    return 0;
}
