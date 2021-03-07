# DAA-P02-SimuladorRAM

Universidad: Universidad de La Laguna.

Asignatura: Diseño y Desarrollo de Algoritmos.

Fecha: 27/07/2021.

Autor: Sebastián Daniel Tamayo Guzmán.

Descripción: Programa en C++ que simula una máquina RAM.

## Instrucciones de uso.

### Compilación.
Es necesario tener g++ instalado en la máquina de trabajo. Sitúese en la carpeta Simulador-RAM-cpp/bin y ejecute el comando 'make'. Se generará un ejecutable main.o.

### Archivos de entrada y salida.
En la carpeta Simulador-RAM-cpp/ioFiles encontrará: 
* input_tape.in: Este archivo contendrá los valores numéricos de entrada que podrá leer el simulador RAM mediante instrucciones read.
* output_tape.out: Este archivo contendrá los valores numéricos de salida que escribirá el simulador RAM mediante instrucciones write.
* ram-programs: Este directorio contiene los programas de prueba propuestos por el profesor, testX.ram, y contiene dos implementaciones para el cálculo de n^n, donde n es un valor leido de input_tape.in. 'exp-lineal.ram' contiene una implementación con orden de complejidad lineal (O(n)), mientras que 'exp-logaritmico.ram' contiene una implementacion con orden de complejidad logarítmica (O(log n)).

### Ejecución.
Para ejecutar el programa es necesario situarse en el directorio Simulador-RAM-cpp/bin y ejecutar el comando 
* ./main.o ram-program.ram input_tape.in output_tape.out debug

El primer argumento corresponderá al nombre del fichero .ram donde se aloje el código RAM que quiera ejecutarse. El segundo y tercer argumento corresponden al nombre de los ficheros que alojen las cintas de entrada y salida. Por último, el cuarto argumento (debug), corresponderá a un entero cuyo valor puede ser 0 (desactivado) o 1 (activado). Cuando debug este desactivado el programa se ejecutará de seguido mostrando por consola solamente el número de instrucciones ejecutadas en total. Cuando debug este activo, se mostrará un menú interactivo por consola con el cual se podrá ir viendo la ejecución de las instrucciones una a una, y revisar los contenidos de las estructuras de datos.

