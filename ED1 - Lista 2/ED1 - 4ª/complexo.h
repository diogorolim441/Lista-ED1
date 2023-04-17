#include <stdio.h>

typedef struct complexo{
    float x;
    float y;
}complexo;

complexo *criar_complexo(float x, float y);
void destruir_complexo(complexo* n);
complexo* somar_complexo(complexo* a, complexo* b);
complexo* multiplicar_complexo(complexo* a, complexo* b);