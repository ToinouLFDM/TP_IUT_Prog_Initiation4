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
//Divise l'écran en deux par une ligne verticale Blanche
void diviser_ecran();
//dessine quatre rectangle a patir du point est des 4 angles de la fenêtre
void mondrian(Point);
//dessine un rectangle entre les deux points
void dessiner_rectangle_par_coins(Point,Point, Couleur);
//initialise graphiquement un damier
void damier(int cote,Couleur a, Couleur b);
//renvoie minimum entre les deux nb
int min(int,int);
//revoie la valeur absolue
int abs(int);
// ***************************************************************************
// 3. définition fonction main
// ***************************************************************************

int main(void)
    {
    //indispensable pour commencer
    ouvrir_fenetre(W,H);

		damier(85,gray,darkgray);
		actualiser();
		Point clic1;
		
		
		int i=0;
		for(;i<5;i++)
		{
			clic1=attendre_clic();
			mondrian(clic1);
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
void damier(int cote,Couleur a, Couleur b)
	{
		int i=0, j=0;
		Point p;												/*W-cote et H-cote pour eviter que le */
		int count =0;									/* le damier sorte de la fenetre */
		while(i*cote<(W-cote))				
			{					
				j=0;														
				while(j*cote<(H-cote))
					{
						p.x=i*cote;
						p.y=j*cote;
						dessiner_rectangle(p,cote,cote,(count%2)?a:b);
						count+=1;
						j++;
					}
				i++;
			}
	}
void mondrian(Point a)
	{
		Point p={0,0};
		dessiner_rectangle_par_coins(a,p,jaune);
		p.x=W;
		dessiner_rectangle_par_coins(a,p,vert);
		p.y=H;
		dessiner_rectangle_par_coins(a,p,jaune);
		p.x=0;
		dessiner_rectangle_par_coins(a,p,vert);
	}
void dessiner_rectangle_par_coins(Point a, Point b, Couleur c)
{
	Point S={min(a.x,b.x),min(a.y,b.y)};
	int hauteur=abs(b.y-a.y);
	int longueur=abs(b.x-a.x);
	dessiner_rectangle(S,longueur,hauteur,c);
}

int min(int a,int b)
{
	return (a<b)?a:b;
}
int abs(int a)
{
	return (a<0)?-a:a;
}

