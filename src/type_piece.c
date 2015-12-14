#include "type_piece.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


int type_etre_integre(type_piece type) //elep,rhino,rocher, case vide ou erreur?
{
  // L'enumeration designe un type integre si elle est comprise
  //  entre 0 et 3.
  // Une enumeration etant un type non signee, il est forcement positif.
  // Il suffit donc que type soit < 4 pour designer un type valide.
  if(type<4)
    return 1;
  return 0;
}


int type_etre_animal(type_piece type) // elephant ou rhino ou erreur?
{
  // L'enumeration designe un type animal si elle est comprise
  //  entre 0 et 1.
  // Une enumeration etant un type non signee, il est forcement positif.
  // Il suffit donc que type soit < 2 pour designer un type valide.
  if(type<2)
    return 1;
  return 0;
}


const char* type_nommer(type_piece type) //conversion enum en string
{
  // "Look up table" (LUT) convertissant un type de piece vers
  //    la chaine de caractere correspondante.
  
  switch(type)
  {
    case elephant:
      return "elephant"; break;
    case rhinoceros:
      return "rhinoceros"; break;
    case rocher:
      return "rocher"; break;
    case case_vide:
      return "vide"; break;
    default:
      printf("Erreur 5, type piece %d non reconnue",type);
      abort();
  }
  
  puts("Ne devrait jamais entrer sur cette ligne");
  abort();
}


const char* type_nommer_nom_cours(type_piece type) // transforme le string en char
{
  // "Look up table" (LUT) convertissant un type de piece vers
  //    la chaine de caractere courte correspondante.
  
  switch(type)
  {
    case elephant:
      return "e"; break;
    case rhinoceros:
      return "r"; break;
    case rocher:
      return "RRR"; break;
    case case_vide:
      return "***"; break;
    default:
      printf("Erreur 6, type piece %d non reconnue",type);
      abort();
  }
  
  puts("Ne devrait jamais entrer sur cette ligne");
  abort();
}

int type_caractere_animal_etre_integre(char type) // e, r ou erreur?
{
  // Verifie que le caractere correspond a elephant (e) ou rhinoceros (r).
  if(type=='e' || type=='r')
    return 1;
  return 0;
}

type_piece type_correspondre_caractere_animal(char type) //conversion char en enum
{
  assert(type_caractere_animal_etre_integre(type)); //Vérifie si le char est valide
  type_piece type_enum = elephant;
  if (type=='e')
  {
    type_enum = elephant;
  }
  else
  {
    type_enum = rhinoceros;
  }
  
  return (type_enum);
}
