//Testfil til opgave 3.b

#include <assert.h>
#include <stdio.h>
#include "include/exercise3.h"

int main(){
    queue q; 

    //testværdier til at gemme resultater
    int x0 = 42;
    int x1 = 99;
    int y0;
    int y1;

    //Test for første funktion
    initialize(&q); //initialisering af kø
    assert(empty(&q)); //skal bekræfte om køen er tom
    printf("Funktion 1 virker :)\n");

    //Test for anden funktion
    enqueue(&q, x0); //tilføjelse af x0 til køen
    y0 = dequeue(&q); //fjerner og gemmer element fra fronten
    assert(x0 == y0); //skal bekræfte det element der blev fjernet og tilføjet er det samme
    assert(empty(&q)); //skal bekræfte tom kø igen
    printf("Funktion 2 virkerrrrr\n");

    //Test for tredje funktion
    enqueue(&q, x0); //tilføjer x0 først
    enqueue(&q, x1); //tilføjer x1 efter
    y0 = dequeue(&q); //fjerner første element
    y1 = dequeue(&q); //fjerner anden element
    assert(x0 == y0); //skal bekræfte x0 kom ud først
    assert(x1 == y1); //skal bekræfte x1 kom ud efter
    assert(empty(&q)); //køen er tom igen
    printf("Funktion 3 virker :)))\n");

    //Test for fjerde funktion
    //Tilføjer værdier:
    enqueue(&q, 10);  
    enqueue(&q, 20);
    enqueue(&q, 30);
    print_queue(&q); //skal printe køens indhold

    //Test for femte funktion
    assert(dequeue(&q) == 10); //Fjern den første værdi
    assert(dequeue(&q) == 20); //Fjern den anden værdi
    assert(dequeue(&q) == 30); //Fjern den tredje værdi
    assert(empty(&q)); //Køen skal tømmes igen
    printf("Funktion 4 & 5 virker!");

    return 0;

}
