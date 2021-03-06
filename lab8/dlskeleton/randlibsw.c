#include "randlib.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *urandstream;

__attribute__ ((__constructor__))
static void
software_rand64_init (void)
{
  urandstream = fopen ("/dev/urandom", "r");
  if (! urandstream)
    abort ();
}

extern unsigned long long
software_rand64 (void)
{
  unsigned long long int x;
  if (fread (&x, sizeof x, 1, urandstream) != 1)
    abort ();
  return x;
}

__attribute__ ((destructor))
 void
software_rand64_fini (void)
{
  fclose (urandstream);
}
