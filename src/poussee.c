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
  assert(plateau_exister_piece(plateau,x,y)==1);
  int force_poussee=0;
  int nb_rocher=0;
  while(plateau_exister_piece(plateau,x,y)==1)
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
    if(force_poussee > 0)
    {
      return 1;
    }
  }
  else
  {
    if(force_poussee >= 0)
    {
      return 1;
    }
    
    return 0;
    
  }
  return 0;
}





void poussee_realiser(plateau_siam* plateau, int x, int y, type_piece type, orientation_deplacement orientation, condition_victoire_partie victoire)
{

  assert(poussee_etre_valide(plateau,x,y,orientation)==1);
  int nb_piece=0;
  while(plateau_exister_piece(plateau,x,y)==1)
  {
    nb_piece+=1;
    coordonnees_appliquer_deplacement(&x,&y,orientation); // a la fin du while on a les coordonnes de la derniere piece de la poussee
  }
  int i=nb_piece;
  for(i=nb_piece; i>0; i--)
  {
    //info de la piece a la fin de la poussee
    piece_siam* info_piece=plateau_obtenir_piece(plateau,x,y); //renvoie type et orientation de piece a pousser
    type_piece type=info_piece->type; //selection du type de la piece a pousser
    orientation_deplacement orientation_piece_a_poussee=info_piece->orientation; //selection de l'orientation de la piesse a pousser
    
    //on applique le deplacement
    coordonnees_appliquer_deplacement(&x,&y,orientation);
    info_piece->type=type;
    info_piece->orientation=orientation_piece_a_poussee;
    
    //on souhaite se deplacer dans le sens inverse de la direction de poussee
    orientation_deplacement oppose=orientation_inverser(orientation);
    coordonnees_appliquer_deplacement(&x,&y,oppose); //piece avant dans la poussee
    coordonnees_appliquer_deplacement(&x,&y,oppose); //piece avant dans la poussee , on es oblige de deplacer 2 fois
    
  }  
  
}

