# Veintiuno

Simulador del popular juego de dedos 'Veintiuno' escrito en C. Es un progrma CLI que permite ejecutar miles de simulaciones del juego para mostrar estadísticas empíricas.

## Explicación del juego
Para jugar se necesita formar un grupo, idealmente e 4 a 6 personas, y que se coloquen en un circulo. Uno de los participantes debe ser seleccionado como el contador. Él dirá "Veintiuno dos o uno pan con queso en el desayuno" o una frase similar, y entonces todos tendrán que mostrar su puño elevando uno o dos dedos. Posteriormente, el contador contará cada dedo levantado, comenzando por su propia mano, hasta llegar a **Veintiuno**. Aquel a quien le corresponda el dedo número 21 es el perdedor, y deberá complir un castigo.

En términos matemáticos se puede decir que el dedo perdedor es aquel en la posición *p*:

$p=S\bmod(\sum_{i=1} ^{n} x_i)$

Donde:

$S=21$

$x_i\in\{1,2\}$

$n:\text{número de jugadores}$

La partida esperada sería $p=S\bmod(n\bar{x})$ pero se sabe que $E(x_i)=\bar{x}=1.5$

## Build
Para buildear el .exe puede utilizar una herrameinta como GCC de la siguiente manera:

```bash
gcc .\source\veintiuno.c -o .\bin\veintiuno.exe -Wall
```

## Hoja de cálculo
También se encuentra en el repositorio una [hoja de cálculo](veintiuno.ods) que cuenta con algunos resultados de las simulaciones así como una aproximación matemática del juego. Un hallazgo sumamente interesante es que la única partida justa, en la que todos los jugadores tienen la misma probabilidad de perder, es la de dos jugadores.
