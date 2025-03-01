#ifndef DUBL2210_LIBRARY_H
#define DUBL2210_LIBRARY_H

#define MAX_STRING_SIZE 200
#define MAX_N_WORDS_IN_STRING 200

#include <stdint.h>

size_t strlen_(char *s);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char* findNonSpaceReverse(char *rbegin, char *rend);

char* findSpaceReverse(char *rbegin, char *rend);

int strcmp_(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

int checkIfNotNum(int i);
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));
char* copyIf2(char *beginSource, const char *endSource, char *beginDestination, int appendStringEnd, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

//---------------------------------------------------------------------------------------------------------------

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

extern char _stringBuffer[MAX_STRING_SIZE + 1];
extern char _stringBuffer2[MAX_STRING_SIZE + 1];
extern BagOfWords _bag;
extern BagOfWords _bag2;

void removeNonLetters(char *s);

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line);

void removeAdjacentEqualLetters(char *s);

int getWord(char *beginSearch, WordDescriptor *word);
void digitInWordShift(WordDescriptor word);
void digitToStart(WordDescriptor word);
void wordInStringProcessor(char *beginString, void(*f)(WordDescriptor));

void digitInWordShift2(WordDescriptor word);
void digitToEnd(WordDescriptor word);

void numToSpace(char *source);

int findWord(char *beginSearch, WordDescriptor *patternWord, WordDescriptor *resWord);
void replace(char *source, char *w1, char *w2);

int isOrdered(char *source);

void getBagOfWords(BagOfWords *bag, char *s);
void printBagOfWordsReverse(BagOfWords *bag);
void printWord(const WordDescriptor *word);
void clearBagOfWords(BagOfWords *bag);

int countPalindroms(char *s);

void getMixedString(char *res, char *s1, char *s2);

void stringReverse(char *s);

void printWordBeforeFirstWordWithA (char *s);
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *source, WordDescriptor *w);

void assertString(const char *expected, char *got,char const *fileName, char const *funcName, int line) ;

void findLastWord(char *s1, char *s2);

int hasSameWords(char *s);

int hasWordsWithSameLetters(char *s);

void getStringWithoutEndWords(char *s);

int findWordBefore(char *s1, char *s2, char *res);

void deletePalindromes(char *s);

void appendMissingWords(char *s1, char *s2);

int isStringIncludeLetters(char *s, char *word);

int compareLetters(const void* charPtr1, const void* charPtr2);

int isPatternInWord(WordDescriptor word, const char* pattern);

int compareWordDescriptorsByLen(const void *wordPtr1, const void *wordPtr2);

#endif //DUBL2210_LIBRARY_H