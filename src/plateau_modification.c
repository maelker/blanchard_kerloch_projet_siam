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
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  assert(type_etre_integre(type)==1);
  
  if(coordonnees_etre_bordure_plateau(x,y)==1)
  {
    if(plateau_denombrer_type(plateau,type)<NBR_ANIMAUX)
    {
      // cas classique sans poussee
      if(plateau_exister_piece(plateau,x,y)==0)
      {
	return 1;
      }
      else // cas de la poussee
      {
	//verification que l orientation de la piece correspond a la direction d introduction de la piece
    if((x==0 && orientation==droite) || (x==NBR_CASES-1 && orientation==gauche) || (y==0 && orientation==haut) || (y==NBR_CASES-1 && orientation==bas))
	{
	  if(poussee_etre_valide(plateau, x, y, orientation)==1)
	  {
	    return 1;
	  }
	  else
	  {
	    puts("la poussee n est pas possible ici");
	  }
	}
	else
	{
	  puts("orientation de la piece ne correspond pas a orientation introduction");
	}
      }
    }    
    else
    {
      puts("nombre max de pieces atteint");
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
  assert(plateau_modification_introduire_piece_etre_possible(plateau,x,y,type,orientation)==1);
  
  //cas de la poussee
  if(plateau_exister_piece(plateau,x,y)==1)
  {
    if(poussee_etre_valide(plateau, x, y, orientation)==1) //poussee possible
    {
      poussee_realiser(plateau, x, y, orientation);
    }
  }
  piece_siam* piece_info=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece
  piece_info->type=type;
  piece_info->orientation=orientation;
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
  assert(orientation_etre_integre_deplacement(direction_deplacement)==1); //verifie si le deplacement est integre
  assert(orientation_etre_integre(orientation)==1); //verifie si orientation apres deplacement est integre
  assert(plateau_exister_piece(plateau,x0,y0)==1);
  const piece_siam* info_piece=plateau_obtenir_piece_info(plateau,x0,y0); //renvoie type et orientation de piece
  const orientation_deplacement orientation_avant_poussee=info_piece->orientation; //orientation de la piece qui va potentiellement pousser
  int animal=piece_etre_animal(info_piece);
  assert(animal==1);
  
  //cas de sortie d une piece en bord de plateau
  if((x0==0 && direction_deplacement==gauche) || (x0==NBR_CASES-1 && direction_deplacement==droite) || (y0==0 && direction_deplacement==bas) || (y0==NBR_CASES-1 && direction_deplacement==haut))
  {
    return 1;
  }
  //cas d un deplacement classique sans poussee
  
  //on regarde si la case d apres est vide ou non
  coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement);
  if(plateau_exister_piece(plateau,x0,y0)==0)
  {
    return 1;
  }
  else //cas de la poussee
  {
    if(direction_deplacement == orientation_avant_poussee)
    {
      if(direction_deplacement == orientation)
      {
	if(poussee_etre_valide(plateau, x0, y0, direction_deplacement)==1)
	{
	  return 1;
	}
	else
	{
	  puts("poussee invalide");
	}
      }
      else
      {
	puts("un animal qui pousse ne peut pas changer d orientation");
      }
    }
    else
    {
      puts("il faut etre oriente dans la direction de poussee");
    }
  }
  
  return 0;
  
  
}


void plateau_modification_deplacer_piece(plateau_siam* plateau, int x0,int y0, orientation_deplacement direction_deplacement, orientation_deplacement orientation_final)
{
  assert(plateau_modification_deplacer_piece_etre_possible(plateau,x0,y0,direction_deplacement,orientation_final)==1);
  //info de la piece qui pousse
  piece_siam* info_piece_depart=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
  type_piece type=info_piece_depart->type; //selection du type de la piece car on va vider la case
  
  //on vide la case
  piece_definir_case_vide(info_piece_depart);
  
  //cas de sortie de piece du plateau
  if((x0==0 && direction_deplacement==gauche) || (x0==NBR_CASES-1 && direction_deplacement==droite) || (y0==0 && direction_deplacement==bas) || (y0==NBR_CASES-1 && direction_deplacement==haut))
  {  
    puts("piece sortie du plateau");
  }
  else //si on est pas dans le cadre d'une sortie directe du plateau
  {
    //on applique le deplacement pour savoir si la pousse est necessaire
    coordonnees_appliquer_deplacement(&x0,&y0,direction_deplacement);
    if(plateau_exister_piece(plateau,x0,y0)==0)
    {
      //afectation orientation finale et mise a jour piece
      piece_siam* info_piece_arrive=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
      info_piece_arrive->orientation=orientation_final;
      info_piece_arrive->type=type;
    }
    else //cas de la poussee
    {
      if(poussee_etre_valide(plateau, x0, y0, direction_deplacement)==1) //poussee possible
      {
	poussee_realiser(plateau, x0, y0, direction_deplacement);
      }
      else
      {
	puts("vous ne pouvez pousser dans cette situation");
      }
      //mise a jour de la piece qui a poussee
      piece_siam* info_piece_arrive=plateau_obtenir_piece(plateau,x0,y0); //renvoie type et orientation de piece a deplacer
      info_piece_arrive->orientation=orientation_final;
      info_piece_arrive->type=type;
    }
  }
  assert(plateau_etre_integre(plateau)==1);
  
}


