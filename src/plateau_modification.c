#include "plateau_modification.h"
#include "coordonnees_plateau.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau,
							int x,int y,
							type_piece type,
							orientation_deplacement orientation)
{
  //cas sans poussee
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  
  
  if(coordonnees_etre_bordure_plateau(x,y)==1)
  {
    if (plateau_modification_changer_orientation_piece_etre_possible(plateau,x,y,orientation)==1)
    {
      return 1;
    }
  }
  
  return 0;
}





void plateau_modification_introduire_piece(plateau_siam* plateau,
                                           int x,int y,
                                           type_piece type,
                                           orientation_deplacement orientation)
{
  //cas sans pussee
  plateau_modification_changer_orientation_piece(plateau,x,y,orientation); //tout les assert sont dans cette fonction
  //cas avec poussee
   
  assert(plateau_etre_integre(plateau)==1);
}


int plateau_modification_changer_orientation_piece_etre_possible(const plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x0,y0)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  
  int existence_piece=plateau_exister_piece(plateau,x0,y0);
  const piece_siam* info_piece=plateau_obtenir_piece_info(plateau,x0,y0); //renvoie type et orientation de piece
  int animal=piece_etre_animal(info_piece);
  const orientation_deplacement orientation0=info_piece->orientation; //selectionne orientation uniquement
 
  
  if(existence_piece==1 && animal==1)
  {
    if(orientation0!=orientation)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}



void plateau_modification_changer_orientation_piece(plateau_siam* plateau,int x0,int y0,orientation_deplacement orientation)
{
    assert(plateau_modification_changer_orientation_piece_etre_possible(plateau,x0,y0,orientation)==1);
    
    piece_siam* info_piece=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece
    info_piece->orientation=orientation;
    
    assert(plateau_etre_integre(plateau)==1);
}


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau,
                                                      int x0,int y0,
                                                      orientation_deplacement direction_deplacement,
                                                      orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x0,y0)==1);
  
  assert(orientation_etre_integre_deplacement(orientation)==1); 
  //verification deplacement legitime en bord de plateau
  
  if(x0==0 && direction_deplacement==gauche)
  {
    return 0;
  }
  if(x0==4 && direction_deplacement==gauche)
  {
    return 0;
  }
  if(y0==0 && direction_deplacement==bas)
  {
    return 0;
  }
  if(y0==4 && direction_deplacement==haut)
  {
    return 0;
  }
  //presence ou non de piece sur la case ou on veut deplacer l animal
  //cas de la pousse
    return 1;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau,
                                         int x0,int y0,
                                         orientation_deplacement direction_deplacement,
                                         orientation_deplacement orientation_final)
{
  
  //cas sans poussee
  assert(plateau_modification_deplacer_piece_etre_possible(plateau,x0,y0,direction_deplacement,orientation_final)==1);
  coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement); //la piece est maintenant sur une autre case mais avec son ancienne orientation
  //changment orientation finale
  plateau_modification_changer_orientation_piece_etre_possible(plateau,x0,y0,orientation_final);
  //cas avec poussee
  
  assert(plateau_etre_integre(plateau)==1);
  
}


