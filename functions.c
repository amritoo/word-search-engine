/** Necessary library files */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



#define MAX_WORD 112000              /** Maximum number of words in dictionary  */
#define NUMBER_OF_SUGGESTIONS 10     /** minimum number of words suggested      */
#define MAX_DISTANCE 10              /** minimum distance between words         */
#define WORD_LENGTH 100              /** Maximum length of word                 */
#define MEANING_LENGTH 1500          /** maximum length of any word meaning     */



/** Declaring structure used to store words and their meaning
  * word and meaning is to store a word and its meaning
  * and word_length is to store the length of word
  */
struct Dictionary
{
    char word[WORD_LENGTH];
    char meaning[MEANING_LENGTH];
    int word_length;
} dictionary[MAX_WORD]; /** Declaring structure array dictionary of size MAX_WORD */



/** Declaring global variables
  * total_words will store the total numbers of words in dictionary
  * distance array to store the levenshtein distance(edit distance)
  * length array to store the number of elements in each row of distance array
  * input string to store the inputted word from user
  */
int total_words, distance[MAX_DISTANCE][MAX_WORD], length[MAX_DISTANCE];
char input[WORD_LENGTH];



/** Function to load all words and their meanings in the structure dictionary
  * It loads each word and their meaning in respective dictionary array
  * It also calculates and stores each word_length
  */
void load_word_list()
{
    /** Opening Dictionary */
    FILE *data_file;
    if((data_file = fopen("Dictionary.txt", "r")) != NULL)
    {
        printf("Word list opened successfully.\n");
    }
    else
    {
        printf("ERROR opening word list.\n");
        printf("Terminating the program.\n");
        exit(1);
    }

    /** Loading Words and meanings */
    int i, j;
    fscanf(data_file, "%d", &total_words);
    for(i = 0; i < total_words; i++)
    {
        fscanf(data_file, " %[^\n]", dictionary[i].word);
        fscanf(data_file, " %[^\n]", dictionary[i].meaning);
        dictionary[i].word_length = strlen(dictionary[i].word);
    }
    printf("All words loaded successfully.\n");

    /** Closing Dictionary */
    fclose(data_file);
    printf("Word list closed successfully.\n");
    putchar('\n');

    return;
}


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
void edit_Distance(char input[])
{
    int i, j, k, input_length = strlen(input), cnt = 0;

    for(i = 0; i < MAX_DISTANCE; i++)
        length[i] = 0;

    for(k = 0; k < total_words; k++)
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
                        levenshtein_matrix[i][j] = 1 + minimum(levenshtein_matrix[i][j - 1], levenshtein_matrix[i - 1][j], levenshtein_matrix[i - 1][j - 1]);
                }
            }
            if(levenshtein_matrix[input_length][dictionary[k].word_length] < MAX_DISTANCE)
            {
                distance[levenshtein_matrix[input_length][dictionary[k].word_length]][length[levenshtein_matrix[input_length][dictionary[k].word_length]]] = k;
                length[levenshtein_matrix[input_length][dictionary[k].word_length]]++;
            }
            if(length[0])
                break;
        }
    }

    return;
}


/** Function to show the meaning of a word using index number of dictionary array */
void show_meaning(int position)
{
    printf("Word: %s\n\n", dictionary[position].word);
    printf("Meaning:\n");
    printf("%s\n", dictionary[position].meaning);
    putchar('\n');

    return;
}


/** Function to show word suggestions
  * it shows some suggestion and choices
  * Afterwards it shows the chosen word meaning
  */
void suggestion()
{
    int num = 0, i, j;
    printf("Suggested words:\n");
    for(i = 1; i < MAX_DISTANCE; i++)
    {
        for(j = 0; j < length[i]; j++)
        {
            if(num <= NUMBER_OF_SUGGESTIONS)
                printf("%3d. %s\n", ++num, dictionary[distance[i][j]].word);
        }
    }
    if(!num)
    {
        printf("No suggestions found\n");
        return;
    }
    putchar('\n');

    int choice;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
    } while(choice < 1 || choice > num);
    putchar('\n');

    num = 0;
    for(i = 1; i < MAX_DISTANCE; i++)
    {
        for(j = 0; j < length[i]; j++)
        {
            if(num + 1 == choice)
            {
                show_meaning(distance[i][j]);
                return;
            }
            num++;
        }
    }
}


/** Starting message */
void starting_promt()
{
    system("cls");
    printf("\n\tWord Search Engine\n");
    printf("\tEnter /exit to exit\n");
    printf("_________________________________________________________________\n");
    putchar('\n');

    return;
}


/** exiting message */
void exit_message()
{
    printf("Exiting Word Search Engine...\n");
    printf("Word Search Engine closed.\n");

    return;
}

