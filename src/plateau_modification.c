#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "type_piece.h"
#include "plateau_siam.h"
#include "piece_siam.h"
#include "poussee.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



int plateau_modification_introduire_piece_etre_possible(const plateau_siam* plateau, int x,int y, type_piece type, orientation_deplacement orientation)
{
  //cas sans poussee
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  assert(type_etre_integre(type)==1);
  
  if(coordonnees_etre_bordure_plateau(x,y)==1)
  {
    if (plateau_exister_piece(plateau,x,y)==0)
    {
      if (plateau_denombrer_type(plateau,type)<5)
      {
	return 1;
	
      }
      else
      {
	puts("la poussee n est pas encore prise en compte");
      }
    }
  }
  
  return 0;
}





void plateau_modification_introduire_piece(plateau_siam* plateau, int x,int y, type_piece type, orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  //cas sans pussee
  assert(plateau_modification_introduire_piece_etre_possible(plateau,x,y,type,orientation)==1);
  piece_siam* piece_info=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece
  piece_info->type=type;
  piece_info->orientation=orientation;
  //cas aou on depasse le nombre de piece donnee autorise
  if(plateau_etre_integre(plateau)==0) //evite darreter le programme avant la verif api
  {
    piece_info->type=case_vide;
    piece_info->orientation=aucune_orientation;
    puts("il est fort probable que vous ayez depasse le nb de pieces autorisees");
  }
  
  assert(plateau_etre_integre(plateau)==1); //ne sera jamais lu normalement
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


int plateau_modification_deplacer_piece_etre_possible(const plateau_siam* plateau, int x0,int y0, orientation_deplacement direction_deplacement, orientation_deplacement orientation)
{
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x0,y0)==1);
  assert(orientation_etre_integre_deplacement(direction_deplacement)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1); 
  assert(plateau_exister_piece(plateau,x0,y0)==1);
  const piece_siam* info_piece=plateau_obtenir_piece_info(plateau,x0,y0); //renvoie type et orientation de piece
  int animal=piece_etre_animal(info_piece);
  assert(animal==1);
  
  //cas de sortie d une piece
  if((x0==0 && direction_deplacement==gauche) || (x0==4 && direction_deplacement==droite) || (y0==0 && direction_deplacement==bas) || (y0==4 && direction_deplacement==haut))
  {
    return 1;
  }
  //presence ou non de piece sur la case ou on veut deplacer l animal
//   coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement);
//   piece_siam const *info_piece_arrivee=plateau_obtenir_piece_info(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
//   type_piece type=info_piece_arrivee->type; //selection du type de la piece car on vider la case
  if(poussee_etre_valide(plateau,x0,y0,direction_deplacement)==1)
  {
    return 1;
  }
  
  return 0;
}


void plateau_modification_deplacer_piece(plateau_siam* plateau, int x0,int y0, orientation_deplacement direction_deplacement, orientation_deplacement orientation_final)
{
  assert(plateau_modification_deplacer_piece_etre_possible(plateau,x0,y0,direction_deplacement,orientation_final)==1);
  //vider la case ancienne
  piece_siam* info_piece_depart=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
  type_piece type=info_piece_depart->type; //selection du type de la piece car on vider la case
  
  info_piece_depart->type=case_vide; //liberation de case
  info_piece_depart->orientation=aucune_orientation; //elimination de orientation
  
  
  //deplacement
  //cas de sortie de piece du plateau
  if((x0==0 && direction_deplacement==gauche) || (x0==4 && direction_deplacement==droite) || (y0==0 && direction_deplacement==bas) || (y0==4 && direction_deplacement==haut))
  {  
    puts("piece sortie du plateau");
  }
  else
  {
    coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement); //la piece est maintenant sur une autre case mais avec son ancienne orientation
    if(plateau_exister_piece(plateau,x0,y0)==0) //cas sans poussee
    {
    //afectation orientation finale et mise a jour piece
    piece_siam* info_piece_arrive=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
    info_piece_arrive->orientation=orientation_final;
    info_piece_arrive->type=type;
    }
    else //cas avec poussee
    {
      if(poussee_etre_valide(plateau,x0,y0, orientation_final)==1)
      {
	poussee_realiser(plateau,x0, y0,type, direction_deplacement);
      }
    }
  }
  
  assert(plateau_etre_integre(plateau)==1);
  
}


