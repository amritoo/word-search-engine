/** Necessary library files */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>



#define MAX_WORD 112000              /** Maximum number of words in dictionary  */
#define NUMBER_OF_SUGGESTIONS 10     /** minimum number of words suggested      */
#define MAX_DISTANCE 10              /** minimum distance between words         */
#define WORD_LENGTH 100              /** Maximum length of word                 */
#define MEANING_LENGTH 1600          /** maximum length of any word meaning     */



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
void load_word_list();

/** Function to find the minimum number out of three numbers */
int minimum(int a, int b, int c);

/** Function to implement levenshtein-distance algorithm
  * It finds the distance between inputted word and each word of the dictionary
  * After finding the distance, it stores the value in distance array
  */
void edit_distance(char input[]);

/** Function to show the meaning of a word using index number of dictionary array */
void show_meaning(int position);

/** Function to show word suggestions
  * it shows some suggestion and choices
  * Afterwards it shows the chosen word meaning
  */
void suggestion();

/** Starting message */
void starting_promt();

/** exiting message */
void exit_message();


