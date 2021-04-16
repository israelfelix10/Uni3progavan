#include "cutellipsoid.h"

/*
Método utilizado para "cortar" elipsóide de raio (rx,ry,rz) e centro (x,y,z).
Parâmetros:
rdX - Inteiro referente ao tamanho do raio no eixo x
rdY - Inteiro referente ao tamanho do raio no eixo y
rdZ - Inteiro referente ao tamanho do raixo no eixo z
x - Inteiro referente ao centro no eixo x
y - Inteiro referente ao centro no eixo y
z - Inteiro referente ao centro no eixo z
*/

CutEllipsoid::CutEllipsoid(int x0, int y0, int z0, int rdX, int rdY, int rdZ) : p_x0(x0), p_y0(y0), p_z0(z0), p_rdX(rdX), p_rdY(rdY), p_rdZ(rdZ)
{
}

/*
 Esse método é utilizado para modificar as variáveis e cortar o elipsóide no objeto "t"
*/

void CutEllipsoid::draw(Sculptor& t){

    int i, j, k;
    double DisX, DisY, DisZ;

    for (i = p_z0-p_rdZ; i < p_z0 + p_rdZ; i++) {
        DisX = ((double)(i - p_z0)) / (double)(p_rdZ);
        for (j = p_y0 - p_rdY; j < p_y0 + p_rdY; j++) {
            DisY = ((double)(j - p_y0)) / (double)(p_rdY);
            for (k = p_x0 - p_rdX; k < p_x0 + p_rdX; k++) {
                DisZ = ((double)(k - p_x0)) / (double)(p_rdX);
                if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
