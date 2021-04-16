#include "putvoxel.h"

/*
Método para criar voxel/matriz de coordenadas (x, y ,z)
Parâmetros:
x - Inteiro correspondente à coordenada do eixo x
y - Inteiro correspondente à coordenada do eixo y
z - Inteiro correspondente à coordenada do eixo z
r,g,b [0,1] correspondem à ausência total(0) ou presença total(1) dos componentes de cor vermelha, verde e azul respectivamente
a [0,1] corresponde à transparência total(0) ou opacidade total(1)
*/

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a)
    : p_x(x), p_y(y), p_z(z), p_r(r), p_g(g), p_b(b), p_a(a)
{
}

/*
Método para desenhar no objeto t.
*/

void PutVoxel::draw(Sculptor& t) {
    t.setColor(p_r, p_g, p_b, p_a);
    t.putVoxel(p_z, p_y, p_x);
}

PutVoxel::~PutVoxel()
{
}
