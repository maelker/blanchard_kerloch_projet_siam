#include "api_siam.h"
#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "jeu_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
							       int x,int y,
							       orientation_deplacement orientation)
{
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu)==1);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  if(coordonnees_etre_dans_plateau(x,y)==1);
  {
    if(coordonnees_etre_bordure_plateau(x,y)==1)
    {
      if(plateau_exister_piece(&(jeu->plateau),x,y)==1)
      {
	piece_siam *piece_info=plateau_obtenir_piece(&(jeu->plateau),x,y); 
	if (joueur_obtenir_animal(&(jeu->joueur)==0)) //joueur 0 dc elephant
	{
	  piece_info->type=elephant;
	  coup.valide=1;
	}
	else
	{
	  piece_info->type=rhinoceros;
	  coup.valide=1;
	}
      }
    }
  }
  
  return coup; //retourne 0 par défault car coup initialise à 0
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    
    
    
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
  
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu)==1);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  
//   if(plateau_modification_introduire_piece_etre_possible(&(jeu->plateau),x,y,&(jeu->plateau.piece.type,orientation))==1)
//   {
// 	coup.valide=1;
//   }
//   return coup;
}
