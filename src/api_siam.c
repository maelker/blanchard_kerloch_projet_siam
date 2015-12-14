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
	if(plateau_exister_piece(&(jeu->plateau),x,y)==0)
	{
	  type_piece type=joueur_obtenir_animal(jeu->joueur);
	  if(plateau_modification_introduire_piece_etre_possible(&(jeu->plateau),x,y,type,orientation)==1)
	  {
	    plateau_modification_introduire_piece(&(jeu->plateau),x,y,type,orientation);
	    coup.valide=1;
	    joueur_changer(&(jeu->joueur));	  
	  }
	}
      }
    }
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
      puts("ok1");
      if(joueur_etre_type_animal(jeu->joueur,type)==1)
      {
	if(plateau_modification_deplacer_piece_etre_possible(&(jeu->plateau),x,y,deplacement,orientation)==1)
	{
	  printf("type %d\n joueur %d\n ", type, jeu->joueur );
	  plateau_modification_deplacer_piece(&(jeu->plateau),x,y,deplacement,orientation);
	  coup.valide=1;
	  joueur_changer(&(jeu->joueur));
	}
      }
    }
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
    puts("ok1");
    if(joueur_etre_type_animal(jeu->joueur,type)==1)
    {
      plateau_modification_changer_orientation_piece(&(jeu->plateau),x,y,orientation);
      coup.valide=1;
      joueur_changer(&(jeu->joueur));
    }
  }
  else
  {
    puts("le coup n'est pas possible");
  }
  
  return coup;
}
