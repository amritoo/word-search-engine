

/** Function to show word suggestions
  * it shows some suggestion and choices
  * Afterwards it shows the chosen word meaning
  */
void suggestion()
{
    int num = 0, i, j;

    printf("The word could not be found in dictionary.\n");

    printf("Word suggestion:\n");
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
    } while(choice < 1 || choice > num);
    getchar();                              /** Takes newline from buffer */
    putchar('\n');

    num = 0;
    for(i = 1; i < MAX_DISTANCE; i++)
    {
        for(j = 0; j < length[i]; j++)
        {
            if(num + 1 == choice)           /** To find the matching choice position */
            {
                show_meaning(distance[i][j]);

                return;
            }
            num++;
        }
    }
}


