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
//Rempli l'ecran de ces trois couleur de facon aleatoire
void trois_couleur(Couleur a, Couleur b, Couleur c);
//rempli l'écran avec des couleurs totatalement aleatoire
void toutes_les_couleurs();
//Rempli l'Ecran avec la couleur du point 
void unicolore(Point);
//dessiner un carre de centre Point et de cote 50 avec un contour de la couleur
//donné mais rempli par des pixel de toute les couleurs
void	dessiner_rectangle50_fondu(Point,Couleur);
// ***************************************************************************
// 3. définition fonction main
// ***************************************************************************

int main(void)
    {
    //indispensable pour commencer
    ouvrir_fenetre(W,H);
    int i;
    Point test;
    for(i=0; i<10;i++)
    	{
    		test=attendre_clic();
   			dessiner_rectangle50_fondu(test,white);
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

void trois_couleur(Couleur a, Couleur b, Couleur c)
	{
		int i=0, j=0;
		Point p;											
		int alea =0;								
		while(i<W)				
			{					
				j=0;														
				while(j<H)
					{
						p.x=i;
						p.y=j;
						alea=entier_aleatoire(3);
						changer_pixel(p,((!alea)?a:((alea==1)?b:c)));						
						j++;
					}
				i++;
			}
	}
void toutes_les_couleurs()
	{
		int i=0, j=0;
		Point p;											
		Couleur c;							
		while(i<W)				
			{					
				j=0;														
				while(j<H)
					{
						p.x=i;
						p.y=j;
						c=fabrique_couleur(entier_aleatoire(255),entier_aleatoire(255),entier_aleatoire(255));
						changer_pixel(p,c);						
						j++;
					}
				i++;
			}
	}
void unicolore(Point color)
	{
		int i=0, j=0;
		Point p;											
		Couleur c=couleur_point(color);							
		while(i<W)				
			{					
				j=0;														
				while(j<H)
					{
						p.x=i;
						p.y=j;
						changer_pixel(p,c);						
						j++;
					}
				i++;
			}
	}
void	dessiner_rectangle50_fondu(Point clic,Couleur c)
	{
		Point s={clic.x-25,clic.y-25};
		dessiner_rectangle(s,50,50,c);
		int i=clic.x-24, j=clic.y-24;
		Point p;											
		Couleur c2;							
		while( i<(clic.x+24)	)			
			{					
				j=clic.y-24;														
				while( j<(clic.y+24))
					{
						p.x=i;
						p.y=j;
						c2=fabrique_couleur(entier_aleatoire(255),entier_aleatoire(255),entier_aleatoire(255));
						changer_pixel(p,c2);						
						j++;
					}
				i++;
			}
	}
