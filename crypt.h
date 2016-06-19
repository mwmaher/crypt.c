/* Text.H

   By Michael W. Maher

   Ver 1.0 11/3/92


   DESCRIPTION:

   OPERATORS:
*/

/*************************** defined constants *****************************/

/***************************** header files ********************************/
#include <stdio.h>
#include <float.h>
#include <math.h>

/************************** function prototypes ****************************/

/* text encryption and decryption routine */
int psc(int function, int key, int textlen, char *ptext, char *ctext);

