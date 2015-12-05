#include "jeu_siam.h"
#include "joueur.h"

#include "entree_sortie.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


int jeu_etre_integre(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //verification du joueur integre
    const int joueur=jeu->joueur;
    if(joueur_etre_integre(joueur)==0)
        return 0;

    //verification du plateau integre
    const plateau_siam* plateau=&jeu->plateau;
    if(plateau_etre_integre(plateau)==0)
        return 0;

    return 1;
}


void jeu_initialiser(jeu_siam* jeu)
{

    assert(jeu!=NULL);

    //initialise le plateau
    //initialise le joueur

    plateau_initialiser(&jeu->plateau);
    jeu->joueur=0;
}





void jeu_changer_joueur(jeu_siam* jeu)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu));

    joueur_changer(&jeu->joueur);

    assert(jeu_etre_integre(jeu)==1);

}


int jeu_verifier_type_piece_a_modifier(const jeu_siam* jeu,int x,int y)
{
    assert(jeu!=NULL);
    assert(jeu_etre_integre(jeu)==1);
    const plateau_siam *plateau=NULL;
    const piece_siam *info_piece=plateau_obtenir_piece_info(plateau,x,y);
    if (info_piece->type==elephant && jeu->joueur==0)
    {
      return 1;
    }
    if (info_piece->type==rhinoceros && jeu->joueur==1)
    {
      return 0;
    }
    return 0;

}

void jeu_afficher(const jeu_siam* jeu)
{
    assert(jeu!=NULL);

    //utilisation d'une fonction generique avec affichage sur
    //  la ligne de commande.
    entree_sortie_ecrire_jeu_pointeur_fichier(stdout,jeu);
}



type_piece jeu_obtenir_type_animal_courant(const jeu_siam* jeu)
{
  
  assert(jeu!=NULL);
  if(jeu->joueur==0)
  {
    return elephant;
  }
  else
  {
    return rhinoceros;
  }
  
}

