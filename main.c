/** including the file functions.c */
#include "functions.c"


/** Main function */
int main()
{
    starting_promt();
    load_word_list();

    while(!feof(stdin))
    {

        printf("Press ENTER to continue.\n");
        gets(input);
        starting_promt();

        /** Taking Input from User */
        printf("Enter a word in lower case: ");
        scanf("%[^\n]", input);
        getchar();
        putchar('\n');
        if(!strcmp(input, "/exit"))
            break;

        /** finding suggestions using edit distance algorithm */
        edit_Distance(input);

        if(length[0])
            show_meaning(distance[0][0]);
        else
            suggestion();

        putchar('\n');
    }

    exit_message();

    return 0;
}
