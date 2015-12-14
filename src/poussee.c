#include "poussee.h"
#include "api_siam.h"
#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "jeu_siam.h"
#include "piece_siam.h"
#include "plateau_siam.h"
#include "joueur.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int poussee_etre_valide(const plateau_siam* plateau, int x, int y, orientation_deplacement orientation)
{ 
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  
  
  
  
  
  return 0;
}




void poussee_realiser(plateau_siam* plateau, int x, int y, type_piece type, orientation_deplacement orientation, condition_victoire_partie victoire)
{
    //seance 4
}
