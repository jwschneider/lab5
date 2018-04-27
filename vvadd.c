// See LICENSE for license details.

#include "stdlib.h"
#include "dataset.h"

//--------------------------------------------------------------------------
// vvadd function

void __attribute__((noinline)) vvadd(int coreid, int ncores, size_t n, const data_t* x, const data_t* y, data_t* z)
{
   size_t i;

   // interleave accesses
   for (i = coreid; i < n; i+=ncores)
   {
      z[i] = x[i] + y[i];
   }
}

void __attribute__((noinline)) vvadd_opt(int coreid, int ncores, size_t n, const data_t* x, const data_t* y, data_t* z)
{
  // TODO: Your code here
    size_t chunk = n / ncores;
    size_t i;
    for (i = chunk * coreid; i < chunk * (coreid + 1); i++)
    {
        z[i] = x[i] + y[i];
    }
    // tail case
    for (i = (chunk*ncores) + coreid; i < n; i += ncores)
    {
        z[i] = x[i] + y[i];
    }
}
