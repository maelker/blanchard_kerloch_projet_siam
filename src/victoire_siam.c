#include "victoire_siam.h"
#include "condition_victoire_partie.h"
#include "joueur.h"
#include "coordonnees_plateau.h"

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

condition_victoire_partie test_victoire(const plateau_siam* plateau_apres_poussee,int x,int y) // x et y represente la piece a l'origine de la poussee
{
  condition_victoire_partie condition_victoire;
  condition_victoire_initialiser(&condition_victoire);
  
  //renvoie le nombre de rocher present sur la plateau
  int nb_rocher=plateau_denombrer_type(plateau_apres_poussee,rocher);

  if(nb_rocher==2)
  {
     //recupere la direction de poussee grace aux coordonnees de la piece qui pousse
     const piece_siam* info_piece_qui_pousse=plateau_obtenir_piece_info(plateau_apres_poussee,x,y); //renvoie type et orientation de piece a deplace
     const orientation_deplacement direction_poussee=info_piece_qui_pousse->orientation;

    int nb_piece=0;
    while(coordonnees_etre_dans_plateau(x,y)==1) //le rocher est sortie, on compte le nombre de pieces dans la ligne de la poussee
    {
      //la piece qui pousse est compatibilisé
      nb_piece+=1;
      coordonnees_appliquer_deplacement(&x,&y,direction_poussee); // a la fin du while on a les coordonnes de la derniere piece de la poussee
    }
    int i=nb_piece;
    for(i=nb_piece; i>0; i--)
    {
      //on souhaite se deplacer dans le sens inverse de la direction de poussee pour se remmetre sur le plateau
      orientation_deplacement oppose=orientation_inverser(direction_poussee);
      coordonnees_appliquer_deplacement(&x,&y,oppose);
      
      //obtention infos de la piece
      const piece_siam* info_piece=plateau_obtenir_piece_info(plateau_apres_poussee,x,y);

      //renvoie type et orientation de piece a deplace
      const orientation_deplacement orientation_a_comparer=info_piece->orientation;
      const type_piece type=info_piece->type;
      
      //on regarde l'orientation
      if(orientation_a_comparer == direction_poussee)
      {
        condition_victoire.victoire=1;
        condition_victoire_etre_victorieux(&condition_victoire);
        printf("type %d\n",type);
        printf("orientaion %d\n",orientation_a_comparer);
        printf("dire poussee %d\n",direction_poussee);
        //on met a joueur le joueur gagnant
        if(type==0)
        {
          condition_victoire.joueur=0;
        }
        else
        {
          condition_victoire.joueur=1;
        }
        return condition_victoire;
      }
    }
    
  }
  return condition_victoire;
}
