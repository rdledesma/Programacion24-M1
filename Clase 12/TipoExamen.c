//Realice la traza para fun(1011,0).
// Indique qué tarea realiza el módulo.

int fun(int x, int e){
    if (x > 0)
       return (x%10)*pow(2,e)+fun(x/10,e+1);
}  


x
