#include "main.h"



/** Function to find the minimum number out of three numbers */
int minimum(int a, int b, int c)
{
    if(a <= b && a <= c)
        return a;

    if(b <= a && b <= c)
        return b;

    return c;
}


/** Function to implement levenshtein-distance algorithm
  * It finds the distance between inputted word and each word of the dictionary
  * After finding the distance, it stores the value in distance array
  */
void edit_distance(char input[])
{
    int i, j, k, input_length = strlen(input);

    for(i = 0; i < MAX_DISTANCE; i++)    /** Initializes length array */
        length[i] = 0;

    for(k = 0; k < total_words; k++)     /** Checks each word from dictionary against inputted word */
    {
        if(abs(dictionary[k].word_length - input_length) < 4)
        {
            int levenshtein_matrix[input_length + 1][dictionary[k].word_length + 1];

            for(i = 0; i <= input_length; i++)
            {
                for(j = 0; j <= dictionary[k].word_length; j++)
                {
                    if(i == 0)
                        levenshtein_matrix[i][j] = j;

                    else if(j == 0)
                        levenshtein_matrix[i][j] = i;

                    else if(input[i - 1] == dictionary[k].word[j - 1])
                        levenshtein_matrix[i][j] = levenshtein_matrix[i - 1][j - 1];

                    else
                        levenshtein_matrix[i][j] = 1 + minimum(levenshtein_matrix[i][j - 1],        /** Insert */
                                                               levenshtein_matrix[i - 1][j],        /** Remove */
                                                               levenshtein_matrix[i - 1][j - 1]);   /** Replace */
                }
            }
            if(levenshtein_matrix[input_length][dictionary[k].word_length] < MAX_DISTANCE)
            {
                int x = levenshtein_matrix[input_length][dictionary[k].word_length];
                distance[x][length[x]] = k;
                length[x]++;            /** Saves the number of elements stored in distance array */
            }
            if(length[0])               /** returns if there is any element in the 0th row of distance array */
                return;
        }
    }

    return;
}


