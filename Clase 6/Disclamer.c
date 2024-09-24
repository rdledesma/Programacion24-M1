En C, los arreglos se pasan por referencia de manera implícita. 
Cuando pasas un arreglo como parámetro a una función, 
en realidad estás pasando un puntero al 
primer elemento del arreglo, no una copia completa del arreglo.

¿int arr[] y int *arr son equivalentes?

Cuando defines un parámetro de función 
como int arr[] o int *arr, ambos son tratados 
como un puntero (int *arr). Esto se debe a que, 
en el contexto de los parámetros de función, 
la declaración int arr[] 
se convierte automáticamente en int *arr.

void funcion(int arr[]);
Es equivalente a:
void funcion(int *arr);

Diferencia con int *arr[]:

int *arr[] es diferente. 
Aquí, arr es un arreglo de punteros a int, 
es decir, cada elemento de arr es un puntero a un entero. 
Esto se usa comúnmente para pasar arreglos 
de arreglos (como una matriz o arreglos dinámicos).

