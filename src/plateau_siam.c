#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (1,2), (2,2) et (3,2)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0 ; kx<NBR_CASES ; ++kx)
    {
        int ky=0;
        for(ky=0 ; ky<NBR_CASES ; ++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre(plateau));
}

int plateau_etre_integre(const plateau_siam* plateau)
{

/* Verifie si chaque piece du plateau est integre, si il existe au
* plus 3 rochers sur le plateau, entre 0 et 5 elephants et entre 0
* et 5 rhinoceros sur le plateau.
* Elle renvoie la valeur 1 si toutes ces conditions sont verifiees
* et 0 sinon.
*/
    
    assert(plateau!=NULL);
    
    int kx=0;
    int ro=0, el=0, rh=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            assert(plateau_obtenir_piece_info(plateau,kx,ky)!=NULL);
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==rocher)
                ro++;
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==elephant)
                el++;
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==rhinoceros)
                rh++;
        }
    }
    
    int condition_rocher=0;
    if(ro>0 &&ro<=3)
        condition_rocher=1;
    
    int condition_elephant=0;
    if(el>=0 && el<=5)
        condition_elephant=1;
    
      int condition_rhinoceros=0;
    if(rh>=0 && rh<=5)
        condition_rhinoceros=1;  
    
    if(condition_elephant==1 && condition_rhinoceros==1 && condition_rocher==1)
        return 1;
    else
        return 0;
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
  /* Fonction qui vérifie que le pointeur n'est pas NULL 
 * et stop le programme si cette condition n'est pas vérifiée
 * Puis, vérification que la case demandee est bien une case du tableau 
 * c'est à dire avec des coordonnees en x et y <5 (entree 0 et 5, 5 exclu))
 */
 assert(plateau!=NULL);
 assert(x>=0 && x <5);
 assert(y>=0 && y <5);
 
 return &(plateau->piece[x][y]); // retourne la piece située en (x,y) sur le plateau
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    /* Fonction qui vérifie que le pointeur n'est pas NULL 
 * et stop le programme si cette condition n'est pas vérifiée
 * Puis, vérification que la case demandee est bien une case du tableau 
 * c'est à dire avec des coordonnees en x et y <5 (entree 0 et 5, 5 exclu))
 */
 assert(plateau!=NULL);
 assert(x>=0 && x <5);
 assert(y>=0 && y <5);
 
 return &(plateau->piece[x][y]); // retourne la piece située en (x,y) sur le plateau 
}



int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
/*    
/ Cette fonction denombre le nombre de pieces de type 'type' 
/ et affiche le nombre de fois que cette piece est presente
/ sur le plateau entree.
*/
    assert(plateau!=NULL);
    
    int compteur=0;
    int kx=0;
    
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
            assert(piece!=NULL);
            
            if(piece->type==type)
                compteur++;
        }
    }
    return compteur;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
  /*Verifie que le pointeur n'est pas NULL sinon stop le programme
   * renvoie 0 si la case aux coordonées (x,y) est une case vide 
   * renvoie 1 si la case n'est pas vide
   */
  const piece_siam* existence_piece=plateau_obtenir_piece_info(plateau,x,y);
  
  assert(plateau!=NULL);
  
  if(existence_piece->type==case_vide)
  {
    return 0;
  }
  else
  {
    return 1;
  }  
}


void plateau_afficher(const plateau_siam* plateau)
{
    assert(plateau!=NULL);

    //utilisation d'une fonction generique d'affichage
    // le parametre stdout permet d'indiquer que l'affichage
    // est realise sur la ligne de commande par defaut.
    entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}
