#ifndef SANND_PILES
#define SANND_PILES

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid_sum(int grid1[3][3], int grid2[3][3]);
void print_grid(int grid[3][3]);
void stretch(int gr[3][3]);
int check_before_stretch(int gr[3][3]);
int calculate_sum(int grid1[3][3], int grid2[3][3]);
void init_corresponded_grid(int corres[3][3]);
#endif
