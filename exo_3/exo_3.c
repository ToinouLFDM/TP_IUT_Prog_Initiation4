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

//divise l'ecran en deux par une ligne blanche
void diviser_ecran();
//renvoie 1 si le point est a gauche de la ligne 0 sinon
int a_gauche(Point p);

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
		int gauche;
		Point clic;
		for(i; i<5;i++)
		{
			clic=attendre_clic();
			gauche=a_gauche(clic);
			printf("%d \n",gauche);
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

int a_gauche(Point p)
	{
		return (p.x < W/2);
		
	}

