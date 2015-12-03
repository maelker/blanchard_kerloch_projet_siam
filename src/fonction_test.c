#include "fonction_test.h"
#include "piece_siam.h"
#include "plateau_siam.h"
#include "type_piece.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void test_type_etre_animal()
{
    puts("\t\tTest type_etre_animal");
    
    if(type_etre_animal(elephant)!=1)
        puts("elephant KO");
    else
        puts("Animal 1  : OK");
    
    if(type_etre_animal(rhinoceros)!=1)
        puts("rhinoceros KO");
    else
        puts("Animal 2  : OK");
    
    if(type_etre_animal(rocher)!=0)
        puts("rocher KO");
    else
        puts("Rocher    : OK");
    
    if(type_etre_animal(case_vide)!=0)
        puts("case vide KO");
    else
        puts("Case vide : OK");
    
    int k=0;
    for(k=4;k<20;++k)
        if(type_etre_animal(k)!=0)
            printf("valeur %d KO\n",k);
        puts("\t\tFin test_type_etre_animal");
    puts("");
    
}
void test_type_etre_integre()
{
    puts("\t\tTest type_etre_integre");
    
    if(type_etre_integre(elephant)!=1)
        puts("elephant KO");
    else
        puts("Animal 1  : OK");
    
    if(type_etre_integre(rhinoceros)!=1)
        puts("rhinoceros KO");
    else
        puts("Animal 2  : OK");
    
    if(type_etre_integre(rocher)!=1)
        puts("rocher KO");
    else
        puts("Rocher    : OK");
    
    if(type_etre_integre(case_vide)!=1)
        puts("case vide KO");
    else
        puts("Case vide : OK");
    
    int k=0;
    for(k=4;k<20;++k)
        if(type_etre_integre(k)!=0)
            printf("valeur %d KO\n",k);
        puts("\t\tFin test_type_etre_integre");
    puts("");
}

void test_piece_etre_integre()
{
    puts("\t\tTest piece_etre_integre");
    
    piece_siam piece_test; // initialisation d'une piece test elephant avec une direction haut.
    piece_siam *p=NULL; // définis un pointeur p qui pointe la piece test pieceeh.
    p=&piece_test; // le pointeur p pointe la piece
    
    int i=0, j=0;
    for(i=0;i<2;i++)
    {
        if(i==1)
            puts("");
        piece_test.type=i;
        
        for(j=0;j<4;j++)
        {
            piece_test.orientation=j;
            
            if(piece_etre_animal(p)==1)
            {
                printf("Animal %d direction %d  :",i+1,j+1);
                
                if(piece_etre_integre(p)==1)
                    puts("OK");
                else
                    puts("KO");
            }
        }
    }
    puts("");
    piece_test.type=2; // 2 correspond au rocher dans l'énumeration
    piece_test.orientation=4; // 4 correspond à aucun_déplacement dans l'énumeration.
    if(piece_etre_rocher(p)==1)
    {
        printf("Rocher direction 5    :");
        if(piece_etre_integre(p)==1)
            puts("OK");
        else
            puts("KO");
    }
    puts("");
    piece_test.type=3;// 3 correspond à la case vide dans l'énumeration
    piece_test.orientation=4; // 4 correspond à aucun_déplacement dans l'énumeration.
    if(piece_etre_case_vide(p)==1)
    {
        printf("Case vide direction 5 :");
        if(piece_etre_integre(p)==1)
            puts("OK");
        else
            puts("KO");
        
    }
    
    puts("\t\tFin test_piece_etre_integre");
    puts("");
}

void test_piece_etre_animal()
{
    puts("\t\tTest piece_etre_animal");
    
    piece_siam piece_test; // initialisation d'une piece test elephant avec une direction haut.
    piece_siam *p=NULL; // définis un pointeur p qui pointe la piece test pieceeh.
    p=&piece_test; // le pointeur p pointe la piece
    
    int i=0;
    for(i=0;i<2;i++)
    {
        printf("Animal %d : ",i+1);
        piece_test.type=i;
        if (piece_etre_animal(p)==1)
            puts("OK");
        else
            puts("KO");
    }
    puts("\t\tFin test_piece_etre_animal");
    puts("");
}

void test_piece_etre_rocher()
{
    puts("\t\tTest piece_etre_rocher");
    
    piece_siam piece_test; // initialisation d'une piece test elephant avec une direction haut.
    piece_siam *p=NULL; // définis un pointeur p qui pointe la piece test pieceeh.
    p=&piece_test; // le pointeur p pointe la piece
    
    
    int i=2; // 2 correspond à un rocher dans l'énumeration.
    piece_test.type=i;
    printf("Rocher : ");
    if (piece_etre_rocher(p)==1)
        puts("OK");
    else
        puts("KO");
    puts("\t\tFin test_piece_etre_rocher");
    puts("");
}

void test_piece_etre_case_vide()
{
    puts("\t\tTest piece_etre_case_vide");
    
    piece_siam piece_test; // initialisation d'une piece test elephant avec une direction haut.
    piece_siam *p=NULL; // définis un pointeur p qui pointe la piece test pieceeh.
    p=&piece_test; // le pointeur p pointe la piece
    
    
    int i=3; // 3 correspond à une case vide dans l'énumeration.
    piece_test.type=i;
    printf("Case vide : ");
    if (piece_etre_case_vide(p)==1)
        puts("OK");
    else
        puts("KO");
    puts("\t\tFin test_piece_etre_case_vide");
    puts("");
}


void test_plateau_exister_piece()
{
    puts("\t\tTest plateau_exister_piece");
    
    plateau_siam plateau;
    plateau_initialiser(&plateau);
    
    piece_siam* p1=plateau_obtenir_piece(&plateau,0,4);
    piece_siam* p2=plateau_obtenir_piece(&plateau,0,2);
    piece_siam* p3=plateau_obtenir_piece(&plateau,1,3);                                
    piece_siam* p4=plateau_obtenir_piece(&plateau,1,0);
    piece_siam* p5=plateau_obtenir_piece(&plateau,2,4);
    piece_siam* p6=plateau_obtenir_piece(&plateau,2,2);
    piece_siam* p7=plateau_obtenir_piece(&plateau,2,1);
    piece_siam* p8=plateau_obtenir_piece(&plateau,3,3);
    piece_siam* p9=plateau_obtenir_piece(&plateau,3,0);
    piece_siam* p10=plateau_obtenir_piece(&plateau,4,4);
    piece_siam* p11=plateau_obtenir_piece(&plateau,4,2);
    piece_siam* p12=plateau_obtenir_piece(&plateau,4,0);
    
    p1->type=elephant;
    p2->type=elephant;
    p3->type=elephant;
    p4->type=elephant;
    p5->type=elephant;
    p6->type=case_vide;
    p7->type=rhinoceros;
    p8->type=rocher;
    p9->type=rhinoceros;
    p10->type=rhinoceros;
    p11->type=rhinoceros;
    p12->type=rhinoceros;
    
    plateau_afficher(&plateau);puts("");

    
    int ky=0;
    for (ky=NBR_CASES-1;ky>-1;--ky)
    {
        if(ky>-1)
            puts("");
        int kx=0;
        for(kx=0;kx<NBR_CASES;++kx)
        {
            if(plateau_exister_piece(&plateau,kx,ky)==1)
                printf("1 ");
            else
                printf("0 ");
        }
    }
    puts("");
    puts("\t\tFin test_plateau_exister_piece");
    puts("");
}


void test_lancement()
{
    puts("");
    puts("Animal 1 : elephant\nAnimal 2 : rhinoceros\n\nOrientation 1 : haut\nOrientation 2 : bas\nOrientation 3 : gauche\nOrientation 4 : droite\nOrientation 5 : aucun_déplacement\n");
    
    test_type_etre_animal();
    test_type_etre_integre();
    test_piece_etre_integre();
    test_piece_etre_animal();
    test_piece_etre_rocher();
    test_piece_etre_case_vide();
    test_plateau_exister_piece();
    
}

