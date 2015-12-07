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
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    //coder cette fonction
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
  
  if(jeu_verifier_type_piece_a_modifier(jeu,x,y)==1)
  {
    if(coordonnees_etre_dans_plateau(x,y)==1)
    {
      if (plateau_modification_changer_orientation_piece_etre_possible(&(jeu->plateau),x,y,orientation)==1)
      {
	coup.valide=1;
      }
    }
  }
  return coup;
}
