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
//dessiner un carre a partir d'un p de coté 25
void dessiner_carre(Point);
//dessine une verticalse sur le point 
void dessiner_verticale(Point);
//Divise l'écran en deux par une ligne verticale Blanche
void diviser_ecran();
//dessine une verticale si p est a gauche, un carre sinon
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
		int gauche;
		Point clic;
		for(i; i<5;i++)
		{
			clic=attendre_clic();
			a_gauche(clic);
			actualiser();
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
		if(p.x < W/2)
		{
			dessiner_verticale(p);
		}
		else
		{
			dessiner_carre(p);
		}
		
	}
void dessiner_verticale(Point p)
	{
		Point a={p.x,0}, b={p.x,H};
		dessiner_ligne(a,b,jaune);
	}
void dessiner_carre(Point p)
	{
		
		dessiner_rectangle(p,25,25,jaune);
	}
