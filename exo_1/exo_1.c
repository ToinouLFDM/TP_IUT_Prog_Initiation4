// ***************************************************************************
// 1. directives préprocesseur
// ***************************************************************************
#include "../lib/libgraphique.h"
#include<stdio.h>
#define H 600
#define W 800

// ***************************************************************************
//2. déclarations des fonctions
// ***************************************************************************
//Divise l'écran en deux par une ligne verticale blanche
void diviser_ecran();
// print "a Gauche" si le clik est a gauhe de la ligne sion "a Droite"
void a_gauche(Point p);

// ***************************************************************************
// 3. définition fonction main
// ***************************************************************************
int main(void)
    {
    //indispensable pour commencer
    ouvrir_fenetre(W,H);
		diviser_ecran();
		actualiser();
		int i=0;
		Point clic;
		for(i; i<5;i++)
		{
			clic=attendre_clic();
			a_gauche(clic);
		}
  
    
    //fin du programme
    attendre_clic() ;
    fermer_fenetre() ;
    return 0 ;
    }

// ***************************************************************************
// 4. définition autres fonctions
// ***************************************************************************
void diviser_ecran()
	{
		Point a={W/2,0}, b={W/2,H};
		dessiner_ligne(a,b,white);
	}

void a_gauche(Point p)
	{
		if (p.x < W/2)
		{
			printf("a Gauche\n");
		}
		else
		{
			printf("a Droite\n");
		}
	}
