## ¿Por qué se debe hacer esto: estudianteA = estudianteB = estudianteC = NULL;?

Esta línea inicializa los punteros estudianteA, estudianteB y estudianteC en NULL. Esto se hace por dos razones principales:

- Buena práctica de programación: Inicializar los punteros a NULL es una práctica recomendada para evitar errores. Un puntero no inicializado apunta a una ubicación de memoria desconocida, y acceder a ella puede causar errores de ejecución, como violaciones de acceso (segmentation faults).
- Facilitar la comprobación de errores: Si más adelante en el código se intenta acceder a un puntero antes de asignarle memoria con malloc, puede causar problemas. Al inicializarlos en NULL, se facilita la verificación de si un puntero ha sido asignado correctamente al comprobar si sigue siendo NULL.

Es decir que, asignar NULL es una medida preventiva que evita el uso de punteros no inicializados y ayuda a depurar posibles errores de acceso a memoria.

## ¿Por qué se debe hacer esto? nuevoEstudiante = (EstudiantePtr) malloc(sizeof(Estudiante));

Esta línea asigna memoria dinámica para almacenar un objeto de tipo Estudiante. La explicación detallada de cada parte de esta línea es la siguiente:

- malloc(sizeof(Estudiante)): La función malloc (memory allocation) se usa para solicitar una cantidad de memoria específica en bytes. Aquí, sizeof(Estudiante) calcula el tamaño en bytes necesario para almacenar un objeto de tipo Estudiante. Esta función retorna un puntero genérico de tipo void* a un bloque de memoria que puede almacenar el objeto.

 - (EstudiantePtr): Como malloc devuelve un puntero de tipo void*, que no es específico de ningún tipo de dato, se hace un "casting" (conversión de tipo) a EstudiantePtr para que el puntero resultante tenga el tipo adecuado. De esta manera, nuevoEstudiante será un puntero a Estudiante, y así podemos acceder a los campos de la estructura.

malloc devuelve un puntero de tipo void*

- En C, malloc siempre devuelve un puntero de tipo void*, que es un **puntero genérico**. void* significa "puntero a algo", pero **no especifica a qué tipo de dato apunta** (como podría ser int*, float*, o Estudiante*).
    En otras palabras, el puntero void* no tiene un tipo específico, por lo que **es necesario hacer una conversión de tipo para indicar que queremos interpretar este puntero como un puntero a Estudiante ** (casting).

(EstudiantePtr)

- (EstudiantePtr) es un "casting" o conversión de tipo. Esto le dice al compilador de C que interprete el puntero genérico void* devuelto por malloc como un EstudiantePtr.
    EstudiantePtr es una definición de tipo que hicimos antes en el código:



Sin esta asignación de memoria dinámica, nuevoEstudiante no tendría espacio asignado para almacenar datos y el programa fallaría al intentar acceder o modificar sus miembros.

Esta línea asigna espacio de memoria adecuado para un nuevo Estudiante y le permite al puntero nuevoEstudiante apuntar a él.

### Liberar la memoria asignada (free(estudianteA);)

La función free se utiliza en C para liberar la memoria asignada dinámicamente (con malloc, calloc o realloc).

estudianteA es un puntero que apunta a un bloque de memoria en el heap, donde almacenamos una estructura Estudiante.

Al hacer free(estudianteA);, le estamos diciendo al sistema operativo que la memoria a la que apunta estudianteA ya no es necesaria. Esta memoria se marca como disponible, permitiendo que sea reutilizada por el programa u otros procesos.

Asignar NULL al puntero (estudianteA = NULL;)

- Después de llamar a free, estudianteA sigue siendo un puntero válido, pero apunta a una ubicación de memoria que ya no nos pertenece.
    Para evitar usar accidentalmente un puntero a memoria ya liberada (conocido como un dangling pointer), asignamos NULL a estudianteA. Esto lo convierte en un puntero nulo, que indica explícitamente que no apunta a ninguna dirección válida.
- Si intentamos acceder a estudianteA después de asignarle NULL, el programa no intentará leer memoria no válida, evitando errores graves como violaciones de acceso a memoria (segmentation faults).