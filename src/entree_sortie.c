#include "entree_sortie.h"
#include "plateau_siam.h"


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_MAX 512


int entree_sortie_fichier_etre_accessible(const char* filename)
{
  assert(filename!=NULL);
  
  //tente d'ouvir le fichier en ecriture/ajout
  // si le pointeur n'est pas nulle
  //  alors le fichier est accessible
  // sinon le fichier n'est pas accessible
  FILE *fid=NULL;
  fid=fopen(filename,"a+");
  
  if(fid==NULL)
    return 0;
  
  fclose(fid);
  return 1;
}

int entree_sortie_fichier_exister(const char* filename)
{
  
  assert(filename!=NULL);
  
  //tente d'ouvir le fichier en lecture seule
  // si le pointeur n'est pas nulle
  //  alors le fichier est accessible
  // sinon le fichier n'est pas accessible
  
  FILE *fid=NULL;
  fid=fopen(filename,"r");
  
  if(fid==NULL)
    return 0;
  
  fclose(fid);
  return 1;
}


void entree_sortie_ecrire_jeu_fichier(const char* filename,const jeu_siam* jeu)
{
  assert(filename!=NULL);
  assert(jeu!=NULL);
  assert(jeu_etre_integre(jeu));
  assert(entree_sortie_fichier_etre_accessible(filename)==1);
  
  // Ouvre fichier
  FILE *fid=NULL;
  fid=fopen(filename,"w");
  assert(fid!=NULL);
  if(fid==NULL) //double protection en mode release
  {
    printf("Erreur ouverture fichier %s\n",filename);
    abort();
  }
  
  entree_sortie_ecrire_jeu_pointeur_fichier(fid,jeu);
  
  // Ferme fichier
  int c=fclose(fid);
  if(c!=0) //double protection
  {
    printf("Erreur fermeture fichier %s\n",filename);
    abort();
  }
}



void entree_sortie_lire_jeu_fichier(const char* filename,jeu_siam* jeu)
{
  FILE* fid=fopen(filename,"r");
  
  assert(fid!=NULL);
  if(fid==NULL)
  {
    printf("Erreur ouverture fichier %s\n",filename);
    exit(1);
  }
  
  int  *nouveau_joueur=&(jeu->joueur);
  
  char ligne_texte[100];    
  while(fgets(ligne_texte,100,fid)!=0)
  {
    int ligne=0;
    if(strncmp(ligne_texte,"joueur 0 (elephant)",8)==0)
      *nouveau_joueur=0;
    else 
      if(strncmp(ligne_texte,"joueur 1 (rhinoceros)",8)==0)
	*nouveau_joueur=1;
      else 
      {
	char piece_presente[NBR_ANIMAUX][100];
	if(sscanf(ligne_texte,"[%d] %s | %s | %s | %s | %s |",&ligne,piece_presente[0],piece_presente[1],piece_presente[2],piece_presente[3],piece_presente[4])==NBR_CASES+1)
	{
	  if(ligne<0||ligne>NBR_CASES-1)
	  {
	    puts("Erreur lecture numero de ligne");
	    abort();
	  }
	  int colonne=0;
	  piece_siam *piece_intermediaire;
	  for(colonne=0;colonne<NBR_CASES;++colonne)
	  {
	    piece_intermediaire=plateau_obtenir_piece(&jeu->plateau,colonne,ligne);
	    *piece_intermediaire=piece_correspondre_nom_cours(colonne[piece_presente]);
	  }
	}
      }
  }
}


void entree_sortie_ecrire_jeu_pointeur_fichier(FILE* identifiant,const jeu_siam* jeu)
{
  assert(identifiant!=NULL);
  assert(jeu!=NULL);
  
  
  const plateau_siam* plateau=&jeu->plateau;
  assert(plateau!=NULL);
  
  fprintf(identifiant,"joueur %d (%s)\n",jeu->joueur,type_nommer(jeu_obtenir_type_animal_courant(jeu)));
  
  entree_sortie_ecrire_plateau_pointeur_fichier(identifiant,plateau);
  
}





void entree_sortie_ecrire_plateau_pointeur_fichier(FILE* identifiant,const plateau_siam* plateau)
{
  FILE* fid=identifiant;
  
  if (fid==NULL)
  {
    printf("Erreur ouverture du fichier\n");
    exit(1);
  }
  
  const piece_siam *piece_presente=*plateau->piece;
  int colonne=0;
  int ligne=0;
  for(ligne=NBR_CASES-1;ligne>=0;--ligne)
  {
    fprintf(fid,"[%d] ",ligne);
    colonne=0;
    for(colonne=0;colonne<NBR_CASES;++colonne)
    {
      piece_presente=plateau_obtenir_piece_info(plateau,colonne,ligne);
      fprintf(fid,"%s",type_nommer_nom_cours(piece_presente->type));
      if(piece_presente->type==elephant || piece_presente->type==rhinoceros)
	fprintf(fid,"-%s",orientation_nommer_nom_cours(piece_presente->orientation));
      fprintf(fid," | ");
    }
    fprintf(fid,"\n");
  }
  
  fprintf(fid,"    ");
  
  colonne=0;
  for(colonne=0;colonne<NBR_CASES;++colonne)
  {
    fprintf(fid,"[%d]   ",colonne);
  }
  fprintf(fid,"\n");
  
}
