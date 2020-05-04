/*****************************************************************************/
/*                                                                           */
/* Function...:  psc - encrypts and decrypts text                            */
/*                                                                           */
/* Usage......:  rc = psc( function, key, textlen, ptext, ctext);            */
/*                                                                           */
/* Inputs.....:  function = 1 - encrypt, 2 - decrypt                         */
/*               key      = integer in range -32768, 32767                   */
/*               textlen  = number of characters to be crypted               */
/*               ptext    = pointer to first character to be crypted         */
/*               ctext    = pointer to buffer for the crypted text           */
/*                                                                           */
/* Outputs....:  The crypted text in the buffer pointed to by ctext          */
/*               return code = 0 if text was crypted -1 if not               */
/*                                                                           */
/* Description:  This function take some text and encrypt or decrypt it      */
/*               using the key provided.                                     */
/*                                                                           */
/*****************************************************************************/

#include "stdio.h"
#include "math.h"

int psc( function, key, textlen, ptext, ctext )

int  function ;                        /* requested function                 */
int  key ;                             /* crypt key                          */
int  textlen ;                         /* length of text                     */

char *ptext ;                          /* pointer to text to be crypted      */
char *ctext ;                          /* pointer to crypted text            */

{
int i, j, k, m ;
double x, z ;
double y = (double)246 ;

/*****************************************************************************/
/* calculate key                                                             */
/*****************************************************************************/

x = (double)key ;
z = fmod( x, y );
x = fabs( z );
k = (int)x ;

/*****************************************************************************/
/* decryption                                                                */
/*****************************************************************************/

if (function == 2)
  for (i=0; i < textlen; i++)
    {
    x = (double)textlen - i ;
    y = (double)11 ;
    z = fmod( x, y );
    j = (int)z + k ;
    m = ptext[ i ];

    if ( m < j ) m = m + 256 - j ;
    else m = m - j ;

    ctext[ textlen-i-1 ] = (char)m ;
    }

/*****************************************************************************/
/* encryption                                                                */
/*****************************************************************************/

else if (function == 1)
  for (i=0; i < textlen; i++)
    {
    x = (double)textlen - i ;
    y = (double)11 ;
    z = fmod(x, y) ;
    j = (int)z + k ;
    m = ptext[ textlen-i-1 ];

    if (j+m >= 256) m = m-256+j ;
    else m = m+j ;

    ctext[i] = (char)m ;
    }

/*****************************************************************************/
/* invalid function                                                          */
/*****************************************************************************/

else
  {
  error( "Text encryption failure - psc", function );
  return( -1 );
  }

/*****************************************************************************/
/* normal return                                                             */
/*****************************************************************************/

return( 0 );
}
