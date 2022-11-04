# Evaluacion-Practica-1
Repositorio para entregar la primera evaluacion practica

Descripción:
El código consiste de 4 funciones “main”, “burbuja”, “insert” y “selección”.
En el caso de la función burbuja recibe 2 parametros el arreglo a ordenar y su tamaño, con estos recorre el arreglo llevan al número más grande hasta el final, esto lo logra almacenando el número más grande que encuentre, recorriendo el arreglo si encuentra otro número más grande cambiará a este numero y segura hasta terminar el ciclo momento en el cual habrá colocado al número más grande al final, repite este proceso sin tomar en cuenta al número más grande del siglo pasado hasta que ya no hay números por acomodar.

La función insert agarra al primer número del arreglo y lo compara con el que tiene por delante, en caso de ser menor al de enfrente lo deja asi y pasa al siguiente, en caso contrario cuando es más grande que el número que sigue moverá hacia atrás el número más pequeño y revisando que los números precedentes sean menores, en caso de que no se volverá a mover hacia atrás y moverá el más grande delante del mismo.

la función de seleccion utiliza el algoritmo de selección para ordenar el arreglo que recibe, recorre una vez el arreglo buscando el menor número, una vez lo encuentra lo intercambiara con el número que esté en la primera posición, volverá a recorrer el arreglo ignorando la posición anterior buscando una vez mas el numero mas pequeño, una vez termine dará tantas vueltas como datos haya en el arreglo para terminar de ordenarlo.

En la función main se ejecuta la lectura del archivo "setdatosedades.txt" que contendrá todos los números que entraran al arreglo, se crea de forma dinámica un arreglo para después cambiar su tamaño. Se recorren los números del archivo para encontrar la cantidad de números a leer, una vez se termina de leer se volverá a cargar el archivo, se le asignará un tamaño arreglo conforme el número de elementos y se recorrió una vez más el archivo para introducir los elementos al arreglo. Ahora el programa a través de la consola le pedirá al usuario escoger una de 4 opciones:
Burbuja: Al seleccionar esta opción se mandara a llamar a la función burbuja ya descrita copiara e imprimirá el arreglo ya modificado.
Inserción: Al seleccionar esta opción se mandara a llamar a la función insert ya descrita copiara e imprimirá el arreglo ya modificado.	
Selección: Al seleccionar esta opción se mandara a llamar a la función selección ya descrita copiara e imprimirá el arreglo ya modificado.
Comparar tiempos de ejecución: Mandara a llamar a un reloj  que contará el tiempo de ejecución de una función, se ejecuta cada función y se medirá el tiempo, imprimiendo junto a cada resultado el tiempo que le tomó a la máquina obtener el resultado.
