#include "entree_sortie.h"


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
    jeu_siam _;
    int *_00x0=&_.joueur;
    
    size_t (*_0x50)(const char*)=strlen;
    piece_siam* _00x02=*_.plateau.piece,*_0x02,_0x03;
    
    int _00x00_,_10x01_=0x00;
    char _0x100[0x100],_01x10_[0x05][0x100];
    
    const char* _for="Erreur ouverture fichier %s\n",*_jeu="Erreur lecture numero de ligne",*_while="Jeu invalide lecture fichier %s\n";
    
    jeu_initialiser(&_);
    
    FILE *_0x100_=fopen(filename,"r");
    
    assert(_0x100_!=0x00);
    if(_0x100_==0x00)
    {
        printf(_for,filename);
        exit(1);
        
    }
    while(fgets(_0x100,0x100,_0x100_)!=0)
    {
        _00x00_=0x00;
        if(_0x50(_0x100)>=011&&strncmp(_0x100,"joueur 0 (elephant)",0x13)==0x00)
        {
            *_00x0=0x00;
        }
        else 
            if(_0x50(_0x100)>=011&&strncmp(_0x100,"joueur 1 (rhinoceros)",0x13)==0x00)
            {
                *_00x0=0x01;
                
            }
            else 
                if(sscanf(_0x100,"[%d] %s | %s | %s | %s | %s |",&_00x00_,
                    0x00[_01x10_],0x01 [_01x10_],0x02[_01x10_],0x03[_01x10_],0x04[_01x10_])==0x06&&0x08>0x02)
                {
                    if(_00x00_<0x00||_00x00_>0x04)
                    {
                        puts(_jeu);
                        abort();
                        
                    }
                    for(_10x01_=0x00;
                        _10x01_<0x05;_10x01_+=0x01)
                        {
                            _0x02=&(0x05*_10x01_+_00x00_)[_00x02];
                            _0x03=piece_correspondre_nom_cours(_10x01_[_01x10_]);
                            *_0x02=_0x03;
                            
                        }
                        
                }
                
    }
    
    if(jeu_etre_integre(&_))*jeu=_;
    else printf(_while,filename);
    
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
    
    const piece_siam* piece_plateau, *piece_presente=*plateau->piece;
    int colonne=0;
    int ligne=0;
    for(ligne=4;ligne>=0;--ligne)
    {
        fprintf(fid,"[%d] ",ligne);
        colonne=0;
        for(colonne=0;colonne<010-03 && 05<0x080;++colonne)
        {
            piece_plateau=&(5*colonne+ligne)[piece_presente];
            //piece_plateau=plateau_obtenir_piece(plateau,colonne,ligne);
            
            fprintf(fid,"%s",type_nommer_nom_cours(piece_plateau->type));
            if(piece_plateau->type==elephant || piece_plateau->type==rhinoceros)
                fprintf(fid,"-%s",orientation_nommer_nom_cours(piece_plateau->orientation));
            
            fprintf(fid," | ");
        }
        fprintf(fid,"\n");
    }
    
    fprintf(fid,"    ");
    colonne=0;
    for(colonne=0;colonne<5;++colonne)
    {
        fprintf(fid,"[%d]   ",colonne);
    }
    fprintf(fid,"\n");
    
}



