/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE127_Buffer_Underread__malloc_char_cpy_10.c
Label Definition File: CWE127_Buffer_Underread__malloc.label.xml
Template File: sources-sink-10.tmpl.c
*/
/*
 * @description
 * CWE: 127 Buffer Under-read
 * BadSource:  Set data pointer to before the allocated memory buffer
 * GoodSource: Set data pointer to the allocated memory buffer
 * Sink: cpy
 *    BadSink : Copy data to string using strcpy
 * Flow Variant: 10 Control flow: if(globalTrue) and if(globalFalse)
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

#ifndef OMITBAD

void CWE127_Buffer_Underread__malloc_char_cpy_10_bad()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            /* FLAW: Set data pointer to before the allocated memory buffer */
            data = dataBuffer - 8;
        }
    }
    {
        char dest[100*2];
        memset(dest, 'C', 100*2-1); /* fill with 'C's */
        dest[100*2-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strcpy(dest, data);
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B1() - use goodsource and badsink by changing the globalTrue to globalFalse */
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(globalFalse)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = dataBuffer;
        }
    }
    {
        char dest[100*2];
        memset(dest, 'C', 100*2-1); /* fill with 'C's */
        dest[100*2-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strcpy(dest, data);
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the if statement */
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(globalTrue)
    {
        {
            char * dataBuffer = (char *)malloc(100*sizeof(char));
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            /* FIX: Set data pointer to the allocated memory buffer */
            data = dataBuffer;
        }
    }
    {
        char dest[100*2];
        memset(dest, 'C', 100*2-1); /* fill with 'C's */
        dest[100*2-1] = '\0'; /* null terminate */
        /* POTENTIAL FLAW: Possibly copy from a memory location located before the source buffer */
        strcpy(dest, data);
        printLine(dest);
        /* INCIDENTAL CWE-401: Memory Leak - data may not point to location
         * returned by malloc() so can't safely call free() on it */
    }
}

void CWE127_Buffer_Underread__malloc_char_cpy_10_good()
{
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE127_Buffer_Underread__malloc_char_cpy_10_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE127_Buffer_Underread__malloc_char_cpy_10_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
