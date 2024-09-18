# Dlaczego?
Program rozwiązujący podane zadanie rekrutacyjne:
Proszę przygotować program wczytujący dwie wartości (ze standardowego wejścia) w formie c stringów. Następnie należy sprawdzić czy obie wartości są liczbami (bez użycia funkcji konwertujących stringi na typy liczbowe) i przekonwertować je na liczby. Jeśli obie wartości są liczbami należy dodać je do siebie i przekonwertować na c string (również bez używania funkcji konwertujących typy liczbowe na tekst) i wypisać je na standardowe wyjście.
# Budowa bezpośrednia
* mkdir build
* cd build
* cmake ..
* make

# Uruchomienie bezspośrednie
 * Dla testów :
 * ./Tests
 * Dla programu:
 * ./Main liczba1 liczba2
 * Na przykład:
 *  ./Main 101 0x101
*  Sum: 358.00
# Docker 
 *   docker build -t my_cpp_project .
 *   docker run -it --name my_cppproject my_cpp_project /bin/bash
 *   cd build
 *    Dla testów :
 * ./Tests
 * Dla programu:
 * ./Main liczba1 liczba2
 * Na przykład:
  * ./Main 101 0x101
  *  Sum: 358.00