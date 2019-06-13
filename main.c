#include "io.c"


/** Main function */
int main()
{
    starting_promt();
    load_word_list();   /** Calling load_word_list() function to load all words */

    while(!feof(stdin)) /** Continues loop until break condition is reached */
    {

        printf("Press ENTER to continue.\n");
        gets(input);

        starting_promt();

        /** Taking Input from User */
        printf("Enter a word in lower case: ");
        scanf("%[^\n]", input);
        getchar();                  /** Takes the newline character from buffer */
        putchar('\n');

        if(!strcmp(input, "/exit")) /** Breaks loop if input is /exit */
            break;

        /** Finding suggestions using edit distance algorithm */
        edit_distance(input);

        /** Checks if there is any element of edit-distance 0 */
        if(length[0])
            show_meaning(distance[0][0]);

        /** If no words match with input, shows some suggestion */
        else
            suggestion();

        putchar('\n');
    }

    /** Exits the program */
    exit_message();

    return 0;
}


