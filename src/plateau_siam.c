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
    
    assert(plateau!=NULL);
    int kx=0;
    if(NBR_CASES>=5 && NBR_CASES<=10)
    {
        for(kx=0 ; kx<NBR_CASES ; ++kx)
        {
            int ky=0;
            for(ky=0 ; ky<NBR_CASES ; ++ky)
            {
                piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
                assert(piece!=NULL);
                if(NBR_CASES%2==0)
                {
                    if(ky==(NBR_CASES/2-1) && (kx>=(NBR_CASES)/2-1 && kx<=(NBR_CASES)/2+1))
                        piece_definir_rocher(piece);
                    else
                        piece_definir_case_vide(piece);
                }
                else
                {
                    if(ky==((NBR_CASES-1)/2) && (kx>=(NBR_CASES-3)/2 && kx<=(NBR_CASES+1)/2))
                        piece_definir_rocher(piece);
                    else
                        piece_definir_case_vide(piece);
                }
            }
        }
        assert(plateau_etre_integre(plateau));
    }
    else
        printf("Le plateau ne peut avoir moins de 5 cases ou plus de 10 cases.");
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
    int compteur_ro=0, compteur_el=0, compteur_rh=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            const piece_siam *info_piece=plateau_obtenir_piece_info(plateau,kx,ky);
            assert(info_piece!=NULL);
            if (piece_etre_integre(info_piece)==0)
            {
                return 0;
            }
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==rocher)
            {
                compteur_ro++;
            }
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==elephant)
            {
                compteur_el++;
            }
            if(plateau_obtenir_piece_info(plateau,kx,ky)->type==rhinoceros)
            {
                compteur_rh++;
            }
        }
    }
    
    int condition_rocher=0;
    if(compteur_ro>0 && compteur_ro<=NBR_ROCHERS)
    {
        condition_rocher=1;
    }
    int condition_elephant=0;
    if(compteur_el>=0 && compteur_el<=NBR_ANIMAUX)
    {
        condition_elephant=1;
    }
    
    int condition_rhinoceros=0;
    if(compteur_rh>=0 && compteur_rh<=NBR_ANIMAUX)
    {
        condition_rhinoceros=1;
    }
    
    if(condition_elephant==1 && condition_rhinoceros==1 && condition_rocher==1)
    {
        return 1;
    }
    else
    {
        return 0;
        
    }
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    /* Fonction qui vérifie que le pointeur n'est pas NULL 
     * et stop le programme si cette condition n'est pas vérifiée
     * Puis, vérification que la case demandee est bien une case du tableau 
     * c'est à dire avec des coordonnees en x et y <5 (entree 0 et 5, 5 exclu))
     */
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y)==1);
    
    return &(plateau->piece[x][y]); // retourne la piece située en (x,y) sur le plateau
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    /* Fonction qui vérifie que le pointeur n'est pas NULL 
     * et stop le programme si cette condition n'est pas vérifiée
     * Puis, vérification que la case demandee est bien une case du tableau 
     * c'est à dire avec des coordonnees en x et y <5 (entree 0 et 5, 5 exclu))
     */
    //  assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y)==1);
    return &(plateau->piece[x][y]); // retourne la piece située en (x,y) sur le plateau.
    
}

int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
    /*    
     * / Cette fonction denombre le nombre de pieces de type 'type' 
     * / et affiche le nombre de fois que cette piece est presente
     * / sur le plateau entree.
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
    assert(coordonnees_etre_dans_plateau(x,y)==1);
    
    if(existence_piece->type!=case_vide)
    {
        return 1;
    }
    else
    {
        return 0;
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
