#include <cstdio>

/* R is the number of rows. */
int R;

/* C is the number of columns. */
int C;

/* grid contains the initial state of each light. */
char grid[205][205];

/*
 * answer should contain the number of cross-flips in your sequence, or -1 if
 * it is impossible to turn all the lights on.
 */
int answer;

/*
 * cross_flips should contain your sequence of cross-flips. For example, if
 * your first cross-flip is (2, 3), then you should set cross_flips[0][0] = 2
 * and cross_flips[0][1] = 3.
 */
int cross_flips[40005][2];

/**
 * AIO 2023
 * @link https://orac2.info/problem/aio23yalp/
 * 
 * @mrmagic2020
*/
int main(void) {
    /* Open the input and output files. */
    FILE *input_file = fopen("yalpin.txt", "r");
    FILE *output_file = fopen("yalpout.txt", "w");

    /*
     * Read the values of R, C and the initial state of each light from the
     * input file.
     */
    fscanf(input_file, "%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        fscanf(input_file, "%s", grid[i]);
    }

    /* TODO: This is where you should compute your solution. */

    /*
     * You should store the number of cross-flips in your sequence, or -1 if it
     * is impossible, into the variable answer. If it is possible, then your
     * sequence of cross-flips should be stored in the array cross_flips, using
     * indices 0 to answer-1.
     */

    /* Write the answers to the output file. */
    fprintf(output_file, "%d\n", answer);
    if (answer != -1) {
        for (int i = 0; i < answer; i++) {
            fprintf(output_file, "%d %d\n", cross_flips[i][0],
                    cross_flips[i][1]);
        }
    }

    /* Finally, close the input/output files. */
    fclose(input_file);
    fclose(output_file);

    return 0;
}
