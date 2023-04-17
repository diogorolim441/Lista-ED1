#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"
#include <math.h>
#define _USE_MATH_DEFINES

Esfera* criar_esfera(float raio){
    Esfera* esfera=(Esfera*) malloc(sizeof(Esfera));
    esfera->raio = raio;
    return esfera; 
}

float Raio(Esfera* esfera){
    return esfera->raio;
}

float Area(Esfera* esfera){
    return 4 * M_PI * pow(esfera->raio,2);
}

float Volume(Esfera* esfera){
    return (4/3) * M_PI * pow(esfera->raio,3);
}