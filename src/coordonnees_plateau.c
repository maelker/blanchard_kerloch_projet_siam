#include "coordonnees_plateau.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int coordonnees_etre_dans_plateau(int x,int y)
{
  if((x>=0 && x<NBR_CASES) && (y>=0 && y<NBR_CASES))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


int coordonnees_etre_bordure_plateau(int x,int y)
{
  /* vérifie que x et y sont bien compris entre 0 et 5 exclu
 * si pas respecte retourne 0
 * Puis verifie que les coordonnees envoyees en parametres sont bien des coordonnes
 * correspondant aux bords ie x vaut 0 ou nbcase-1 (de meme pour y)
 * si pas respecte retorune 0
 */
  
  if((x>=0 && x<NBR_CASES) || (y>=0 && x<NBR_CASES))
  {
    if(x==0 || y==0 || x==NBR_CASES-1 || y==NBR_CASES-1)
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

void coordonnees_appliquer_deplacement(int* x,int* y,orientation_deplacement orientation)
{
  /* verifie que x et y ne sont pas poiteurs nuls et que le deplacement est integre ie. haut bas droite ou gauche
   * x prend +1 si deplacement haut
   * x prend -1 si deplacement bas
   * y prend +1 si deplacement droit
   * y prend -1 si depllacmement gauche
   */
    assert(x!=NULL);
    assert(y!=NULL);
    assert(orientation_etre_integre_deplacement(orientation));

    // Table de correspondance:
    //  haut   -> (x,y+1)
    //  bas    -> (x,y-1)
    //  gauche -> (x-1,y)
    //  droite -> (x+1,y)

    switch(orientation)
    {
    case haut:
        *y+=1;
        break;
    case bas:
        *y-=1;
        break;
    case gauche:
        *x-=1;
        break;
    case droite:
        *x+=1;
        break;
    default:
        printf("Probleme fonction %s\n",__FUNCTION__);
    }
}

void definir_taille_plateau()
{
    int taille_plateau=0;
    puts("saisissez la taille du plateau (exemple 5 pour un plateau 5 par 5)");
    scanf(" %d",&taille_plateau);
    printf("taille= %d\n",taille_plateau);
}



