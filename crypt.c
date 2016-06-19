/* Crypt.C

   By Michael W. Maher

   Ver 1.0 11/3/92

   DESCRIPTION:

   OPERATORS:

*/

/***************************************************************************
   function: psc()

 parameters: function = 1 - encrypt, 2 - decrypt
	     key      = integer in range -32768, 32767
	     textlen  = number of characters to be crypted
	     ptext    = pointer to first character to be crypted
	     ctext    = pointer to buffer for the crypted text

    returns: The crypted text in the buffer pointed to by ctext return
	     code = 0 if text was crypted -1 if not

    purpose: The following function encrypts and decrypts text using a
	     key provided.
****************************************************************************/
int psc(int function, int key, int textlen, char *ptext, char *ctext)
  {
  int    i,
	 j,
	 k,
	 m;
  double x,
	 z;

  /* calculate key */
  x = (double)key;
  z = fmod(x, (double)256);
  x = fabs(z);
  k = (int)x;

  /* decryption */
  if (function == 2)
    for (i=0; i < textlen; i++)
      {
      x = (double)textlen - i;
      z = fmod(x, (double)11);
      j = (int)z + k;
      m = ptext[i];
      if (m < j)
	m = m + 256 - j;
      else
	m = m - j;
      ctext[textlen-i-1] = (char)m;
      }
  /* encryption */
  else if (function == 1)
    for (i=0; i < textlen; i++)
      {
      x = (double)textlen - i;
      z = fmod(x, (double)11);
      j = (int)z + k;
      m = ptext[textlen-i-1];
      if (j+m >= 256)
	m = m - 256 + j;
      else
	m = m + j;
      ctext[i] = (char)m;
      }
  /* invalid function */
  else
    return(-1);
  /* normal return */
  return(0);
  }

