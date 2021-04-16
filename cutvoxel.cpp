#include "cutvoxel.h"
#include <iostream>

/*
Método para "cortar" voxel/matriz de coordenadas (x, y, z)
Parâmetros:
x - Inteiro correspondente à coordenada x de corte
y - Inteiro correspondente à coordenada y de corte
z - Inteiro correspondente à coordenada z de corte
*/

CutVoxel::CutVoxel(int x, int y, int z) : p_x(x), p_y(y), p_z(z)
{
}

/*
Método para cortar voxel no objeto t.
*/

void CutVoxel::draw(Sculptor& t)
{
    t.cutVoxel(p_z, p_y, p_x);
}
