#include "suggestion.c"



/** Function to load all words and their meanings in the structure dictionary
  * It loads each word and their meaning in respective dictionary array
  * It also calculates and stores each word_length
  */
void load_word_list()
{
    /** Opening Dictionary */
    FILE *data_file;
    if((data_file = fopen("dictionary.txt", "r")) != NULL) /** Checks if the file is opened successfully or not */
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
    int i;

    fscanf(data_file, "%d", &total_words);               /** Inputs total number of words */

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


/** Function to show the meaning of a word using index number of dictionary array */
void show_meaning(int position)
{
    printf("Word: %s\n\n", dictionary[position].word);
    printf("Meaning:\n");
    printf("%s\n", dictionary[position].meaning);
    putchar('\n');

    return;
}


/** Starting message */
void starting_promt()
{
    system("cls"); /** Clears the terminal */

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


