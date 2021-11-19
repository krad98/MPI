// Adamou Walkao

/*
programme sequentiel qui prend un tableau de 2 elements, pour chaque element du tableau fait l'addition à lui même 1.000.000.000 fois
puis remplace les elements du tableau par les valeurs retournés avec la fonction somme

execution a donné un resultat de 5.2 sec:
    tab[2] = {1, 2}
    valeur retourné tab[2] = {1.000.000.000, 2.000.000.000}
    
    temps d'execution 5.2 sec
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int somme(int n);

int main(int argc, char* argv[])
{	
	
	long clk_tck = CLOCKS_PER_SEC;
	clock_t start, end;

	int tab[2] = {1, 2};
	int i, x, j;


	start = clock();

	for (i = 0; i < 2; i++)
	{
		x = tab[i];

		tab[i] = somme(x);
	}

	end = clock();

	for (j = 0; j < 2; j++)
	{
		printf("%d\n", tab[j]);
	}

	printf("Temps consommer (s) : %lf\n", (double)(end-start)/(double)clk_tck);


	return 0;
}



int somme(int n)
{
	int x = 0;
    for (int i = 0; i < 1000000000; i++)
    {
   
    	x = x + n;

    }
    return x;
}
