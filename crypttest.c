/* CrypTest.C

   By Michael W. Maher

   Ver 1.0 11/3/92

   DESCRIPTION:

*/

/***************************** header files ********************************/
#include <stdio.h>
#include <string.h>
#include "toolkit.h"
#include "crypt.h"

/***************************** source code *********************************/
#include "crypt.c"

/**************************** function prototypes *************************/
void main(void);
char test1(FILE *output);
char *testout(char passfail, char *out);

/*************************** main body of program *************************/
void main(void)
  {
  FILE *output;
  char buf[81];

  output = stdout;
  fprintf(output, "TEST #%d: %s\n", 1, testout(test1(output), buf));
  return;
  }


/****************************************************************************
   function: test1()

 parameters: output - file ptr to output source

    returns: PASS - if successful
	     FAIL - if no successful

    purpose: This function test an text encryption and decryption function.
****************************************************************************/
char test1(FILE *output)
  {
  #define MAXSTR 180
  #define ENCRYPT 1
  #define DECRYPT 2

  int  key,      /* integer in range -32768, 32767 */
       length;
  char test = PASS,
       *ptext,   /* pointer to first character to be crypted */
       ectext[MAXSTR], /* buffer for the encrypted text */
       dctext[MAXSTR]; /* buffer for the encrypted then decrypted text */

  /* setup test */
  ptext  = "This is my big chance to test text encryption and decryption.";
  length = strlen(ptext);
  key    = 69;
  memset(ectext, '\0', MAXSTR);
  memset(dctext, '\0', MAXSTR);

  if (psc(ENCRYPT, key, length, ptext, ectext) != 0)
    {
    fprintf(stderr, "ERROR: text not encrypted.\n");
    test = FAIL;
    }
  if (psc(DECRYPT, key, length, ectext, dctext) != 0)
    {
    fprintf(stderr, "ERROR: text not decrypted.\n");
    test = FAIL;
    }
  /* Verify that the decrypted string is the same as the original.
     Verify that the encrypted string is not the same as the original. */
  if ((strcmp(ptext, dctext) != 0) || (strcmp(ptext, ectext) == 0))
    {
    fprintf(output, "\nERROR: Encryption / Decryption failed\n"
	    " Original: %s\n"
	    "Encrypted: %s\n"
	    "Decrypted: %s\n", ptext, ectext, dctext);
    test = FAIL;
    }
  return(test);
  }

/****************************************************************************
   function: testout()

 parameters: passfail - boolean value (PASS or FAIL)
		  out - 5 character string

    returns: "PASS" is returned in the string (out) if passfail contains
	     a PASS char value.
	     "FAIL" is returned in the string (out) if passfail contains
	     a FAIL char value.

    purpose: This function converts a boolean PASS or FAIL value to a
	     string value "PASS" or "FAIL".
****************************************************************************/
char *testout(char passfail, char *out)
  {
  if (passfail == PASS)
    strcpy(out, "PASS");
  else
    strcpy(out, "FAIL");
  return(out);
  }

