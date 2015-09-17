#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"

int main()
{
	int a = 0; //Premier entier
	int b = 0; //Deuxieme entier

	printf("Rentrez le premier entier : "); //Saisie du premier entier
	scanf("%d", &a);

	printf("Rentrez le deuxieme entier : "); //Saisie du deuxième entier
	scanf("%d", &b);

	printf("Le resultat de l'addition de %d et %d est %ld\n", a, b, addition(a, b)); //Appelle de la fonction addition
	printf("Le resultat de la soustraction de %d par %d est %ld\n", a, b, soustraction(a, b)); //Appelle de la fonction soustraction
	printf("Le resultat de la multiplication de %d et %d est %ld\n", a, b, multiplication(a, b)); //Appelle de la fonction multiplication
	printf("Le resultat de la division de %d par %d est %f\n", a, b, division(a, b)); //Appelle de la fonction division
	return 0;
}
