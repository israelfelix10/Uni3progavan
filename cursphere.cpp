#include "cutsphere.h"

/*
Método utilizado para "cortar" esfera de raio rd e centro (x, y, z)
Parâmetros:
x0 - Inteiro referente ao centro no eixo x
y0 - Inteiro referente ao centro no eixo y
z0 - Inteiro referente ao centro no eixo z
rd - Inteiro referente ao tamanho do raio da esfera
*/

CutSphere::CutSphere(int x0, int y0, int z0, int rd): p_x0(x0), p_y0(y0), p_z0(z0), p_rd(rd)
{
}

/*
Esse método será utilizado para modificar as variáveis
Em seguida, corta a esfera no objeto t se a distância do centro a um ponto é >= raio(ou seja, exterior à esfera)
*/

void CutSphere::draw(Sculptor& t)
{
    int i, j, k;
    float DisX, DisY, DisZ;

    for (i = p_z0-p_rd; i < p_z0+p_rd; i++) {
        DisZ = ((float)(i - p_z0)) / ((float)(p_rd));
        for (j = p_y0 - p_rd; j < p_y0 + p_rd; j++) {
            DisY = ((float)(j - p_y0)) / ((float)(p_rd));
            for (k = p_x0 - p_rd; k< p_x0 + p_rd; k++) {
                DisX = ((float)(k - p_x0)) / ((float)(p_rd));
                if ((DisX * DisX + DisY * DisY + DisZ * DisZ) <= 1.00) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}
