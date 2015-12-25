#include "poussee.h"
#include "api_siam.h"
#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "jeu_siam.h"
#include "piece_siam.h"
#include "plateau_siam.h"
//#include "joueur.h"


#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int poussee_etre_valide(const plateau_siam* plateau, int x, int y, orientation_deplacement orientation)
{ 
  assert(plateau!=NULL);
  assert(plateau_etre_integre(plateau)==1);
  assert(coordonnees_etre_dans_plateau(x,y)==1);
  assert(orientation_etre_integre_deplacement(orientation)==1);
  int force_poussee=0;
  int nb_rocher=0;
  
  while(coordonnees_etre_dans_plateau(x,y)==1 && plateau_exister_piece(plateau,x,y)==1 ) //on continue a se decaler tant qu'il n'y a pas une case vide ou une sortie de plateau
  {
    //info sur la piece a poussee
    const piece_siam* info_piece=plateau_obtenir_piece_info(plateau,x,y); //renvoie type et orientation de piece a pousse
    const type_piece type=info_piece->type; //selection du type de la piece
    const orientation_deplacement orientation_piece_a_poussee=info_piece->orientation; //selection de l'orientation de la piesse a poussee
    
    //informations utiles
    type_piece etre_animal=type_etre_animal(type);
    orientation_deplacement oppose=orientation_inverser(orientation);
    type_piece etre_rocher=piece_etre_rocher(info_piece);
    
    
    //calcul de la somme 
    if(etre_animal==1 && orientation_piece_a_poussee==oppose)
    {
      force_poussee-=1;
    }
    if(etre_rocher==1 && orientation_piece_a_poussee==aucune_orientation)
    {
      force_poussee-=1;
      nb_rocher+=1;
    }
    if(etre_animal==1 && orientation_piece_a_poussee==orientation)
    {
      force_poussee+=1;
    }
    
    //les test sont finis on applique le deplacement pour passer a la case suivante
    coordonnees_appliquer_deplacement(&x,&y,orientation);
  }
  //renvoie de la possibilite de la fonction en considerant les valeurs force_poussee et nb_rocher
  
  if(nb_rocher==0)
  {
    if(force_poussee > -1)
    {
      return 1;
    }
  }
  else
  {
    if(force_poussee >= -1)
    {
      return 1;
    }
    
    return 0;
    
  }
  return 0;
}





void poussee_realiser(plateau_siam* plateau, int x, int y, orientation_deplacement orientation)
{
  assert(poussee_etre_valide(plateau,x,y,orientation)==1);
  int nb_piece=0;
  while(coordonnees_etre_dans_plateau(x,y)==1 && plateau_exister_piece(plateau,x,y)==1) //on continue a se decaler tant qu'il n'y a pas une case vide ou une sortie de plateau
  {
    nb_piece+=1;
    coordonnees_appliquer_deplacement(&x,&y,orientation); // a la fin du while on a les coordonnes de la derniere piece de la poussee
  }
  int i=nb_piece;
  for(i=nb_piece; i>0; i--)
  {
    //si la poussee genere une sortie de piece
    if(coordonnees_etre_dans_plateau(x,y)==0)
    {
      //on souhaite se deplacer dans le sens inverse de la direction de poussee
      orientation_deplacement oppose=orientation_inverser(orientation);
      coordonnees_appliquer_deplacement(&x,&y,oppose);
      
      //obtention infos de la piece
      piece_siam* info_piece=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece a deplace
      
      // on rend la case vide
      info_piece->type=case_vide;
      info_piece->orientation=aucune_orientation;
    }
    else
    {
      //si la poussee ne genere aucune sortie de piece (cas de la case vide en fin de poussee)
      if(plateau_exister_piece(plateau,x,y)==0)
      {
	//on souhaite se deplacer dans le sens inverse de la direction de poussee
	orientation_deplacement oppose=orientation_inverser(orientation);
	
	//on applique le deplacement inverse
	coordonnees_appliquer_deplacement(&x,&y,oppose);
	
	//obtention infos de la piece
	piece_siam* info_piece=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece a deplacer
	type_piece type=info_piece->type; //selection du type de la piece car on va vider la case
	type_piece orientation_piece_a_poussee=info_piece->orientation;
	
	// on rend la case vide
	info_piece->type=case_vide;
	info_piece->orientation=aucune_orientation;     
	
	//on applique le deplacement dans le sens de la pousse
	coordonnees_appliquer_deplacement(&x,&y,orientation);
	
	//obtention infos de la piece d arrivee
	piece_siam* info_piece_fin=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece a deplacer
	
	//mise a jour de la piece arrivee (poussee)
	info_piece_fin->type=type;
	info_piece_fin->orientation=orientation_piece_a_poussee;
	
	//on se place sur la nouvelle case vide
	coordonnees_appliquer_deplacement(&x,&y,oppose);
      }
    }
    
  }
  
}

