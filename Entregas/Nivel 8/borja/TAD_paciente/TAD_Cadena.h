#ifndef TAD_CADENA_H
#define TAD_CADENA_H
#define TMC	20
typedef char TCadena [TMC];

void cargar_cadena(TCadena cad);
void leeCad(TCadena cad, int);
void leecadrec(TCadena cad, int, int);
int compara_cadena(TCadena, TCadena);
#endif
