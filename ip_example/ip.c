#include <stdlib.h>
#include "ip.h"

int invert(unsigned int n, unsigned int *a) {
  unsigned int *b;
  int m;
  if (NULL == (b = calloc(n, sizeof(n))))
    barf(MEMERROR);
  /* arg checking */
  /* 1. check for cell range being 0..n-1 */
  for(m=0;m<n;m++)
    if (a[m] >= n) return OUTOFRANGEERROR;
    else b[a[m]] = 1;           /* prepare next check */
  /* 2. check for permutation */
  for(m=0;m<n;m++)
    if (1 != b[m]) return UNINVERTIBLEERROR;
  /* invert */
  for(m=0;m<n;m++)
    b[a[m]] = m;
  /* copy */
  memcpy(a, b, n*sizeof(unsigned int));
  free(b);
  return EXIT_SUCCESS;
}

void barf(int errorcode) {
  switch (errorcode) {
  case MEMERROR:
    fprintf(stderr, "Error: died, couldn't allocate memory.\n"); break;
  case LENGTHREADERROR:
    fprintf(stderr, "Error: died, couldn't read array length.\n"); break;
  case CELLREADERROR: 
    fprintf(stderr, "Error: died, couldn't read array cell.\n"); break;
  case OUTOFRANGEERROR: 
    fprintf(stderr, "Error: died, input value out of range.\n"); break;
  case UNINVERTIBLEERROR: 
    fprintf(stderr, "Error: died, input is not a permutation.\n"); break;
  default:
    fprintf(stderr, "Error: died, unknown cause.\n");
  }
  exit(EXIT_FAILURE);
}
