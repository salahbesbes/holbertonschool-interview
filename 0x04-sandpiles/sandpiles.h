#ifndef SANND_PILES
#define SANND_PILES

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);

typedef struct coord
{
    int x;
    int y;

} coord_t;

#endif
