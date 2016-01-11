#include "api_siam.h"
#include "plateau_modification.h"
#include "coordonnees_plateau.h"
#include "jeu_siam.h"
#include "piece_siam.h"
#include "plateau_siam.h"
#include "joueur.h"
#include "poussee.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu, int x,int y, orientation_deplacement orientation)
{
  assert(jeu!=NULL);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  if(jeu_etre_integre(jeu)==1)
  {
    if(coordonnees_etre_dans_plateau(x,y)==1)
    {
      if(coordonnees_etre_bordure_plateau(x,y)==1)
      {
	type_piece type=joueur_obtenir_animal(jeu->joueur);
	if (plateau_denombrer_type(&(jeu->plateau),type)<NBR_ANIMAUX)
	{
	  if(plateau_modification_introduire_piece_etre_possible(&(jeu->plateau),x,y,type,orientation)==1)
	  {
	    plateau_modification_introduire_piece(&(jeu->plateau),x,y,type,orientation);
	    coup.valide=1;
	    joueur_changer(&(jeu->joueur));	  
	  }
	  else
	  {
	    puts("introduction impossible de la piece");
	  }
	}
	else
	{
	  puts("nombre de pieces max atteint");
	}	
      }
      else
      {
	puts("les coordonnees ne sont pas en bordure de plateau");
      }
    }
    else
    {
      puts("les coordonnees ne sont pas dans le plateau");
    }
  }
  else
  {
    puts("le jeu est non integre");
  }
  
  return coup; //retourne 0 par défault car coup initialise à 0
  
}

coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu, int x, int y, orientation_deplacement deplacement, orientation_deplacement orientation)
{
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu)==1);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  if(coordonnees_etre_dans_plateau(x,y)==1)
  {
    if(plateau_exister_piece(&(jeu->plateau),x,y)==1)
    {
      piece_siam *info_piece=plateau_obtenir_piece(&(jeu->plateau),x,y); //renvoie type et orientation de piece a deplacer
      type_piece type=info_piece->type; //selectionne le type
 
      if(type_etre_animal(type)==1)
      {
	if(joueur_etre_type_animal(jeu->joueur,type)==1)
	{
	  if(plateau_modification_deplacer_piece_etre_possible(&(jeu->plateau),x,y,deplacement,orientation)==1)
	  {
	      plateau_modification_deplacer_piece(&(jeu->plateau),x,y,deplacement,orientation);
	      coup.valide=1;
	      joueur_changer(&(jeu->joueur));
	  }
	  else
	  {
	    puts("deplacement impossible de la piece");
	  }
	}
	else
	{
	  puts("vous ne pouvez deplacer que vos animaux");
	}
      }
      else
      {
	puts("vous ne pouvez pas deplacer de rocher");
      }
    }
    else
    {
      puts("impossible de deplacer une case vide");
    }
  }
  else
  {
    puts("les coordonnees ne sont pas dans le plateau");
  }
  
  return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
  
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu)==1);
  coup_jeu coup;
  coup_jeu_initialiser(&coup);
  
  if(plateau_modification_changer_orientation_piece_etre_possible(&(jeu->plateau),x,y,orientation)==1)
  {
    piece_siam *info_piece=plateau_obtenir_piece(&(jeu->plateau),x,y); //renvoie type et orientation de piece a deplacer
    type_piece type=info_piece->type; //selectionne le type
    if(joueur_etre_type_animal(jeu->joueur,type)==1)
    {
      plateau_modification_changer_orientation_piece(&(jeu->plateau),x,y,orientation);
      coup.valide=1;
      joueur_changer(&(jeu->joueur));
    }
    else
    {
      puts("vous ne pouvez deplacer que vos animaux");
    }
  }
  else
  {
    puts("le changement d orientation est impossible");
  }
  
  return coup;
}
