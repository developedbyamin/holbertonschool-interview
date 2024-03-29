#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stddef.h>


static void print_grid(int grid[3][3]);


int stable(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
#endif /* _SANDPILES_H_ */