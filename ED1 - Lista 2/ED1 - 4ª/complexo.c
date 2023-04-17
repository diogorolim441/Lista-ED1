#include <stdio.h>
#include "complexo.h"
#include <stdlib.h>

complexo *criar_complexo(float x, float y){
    complexo* a = (complexo*) malloc(sizeof(complexo));
    a->x=x;
    a->y=y;
    return a;
}

void deletar_complexo(complexo* a){
    free(a);
}

complexo* somar_complexo(complexo* a, complexo* b){
    float c = a->x + b->x;
    float d = a->y + b->y;
    return(c,-d);
}

complexo* multiplicar_complexo(complexo* a, complexo* b){
    return (criar_complexo(a->x * b->x + (a->y * b->y),(a->x * b->y)*-1 - (a->y + b->x)));
}

int main(){
    complexo* a = criar_complexo(2,3);
    printf("%f", a->x);
    return 0;
}