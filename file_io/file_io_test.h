#ifndef LAB_FILE_IO_TEST_H
#define LAB_FILE_IO_TEST_H
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__);

#define MAX_LINE_SIZE 1024
char testBuff[MAX_LINE_SIZE];

int strcmp_(const char *lhs, const char *rhs)
{
    while (*lhs == *rhs++)
        if (*lhs++ == 0) return (0);
    return (*(unsigned char *) lhs - *(unsigned char *) --rhs);
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line)
{
    if (strcmp_(expected, got))
    {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
    {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

void testAll_rowsToColumnsInMatrix();

#endif //LAB_FILE_IO_TEST_H