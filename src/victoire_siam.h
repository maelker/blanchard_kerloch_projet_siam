
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Gestion de la fin de la partie 
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * La foncion de ce fichier permet de gerer la victoire en appelant les fonctions de conditions victoires
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Il s'agit d'un niveau d'abstraction ayant uniquement la connaissance
 *  de l'existance d'un vainqueur et du numero du joueur associe.
 *
 */


#ifndef VICTOIRE_H
#define VICTOIRE_H

#include "condition_victoire_partie.h"
#include "plateau_siam.h"
#include "plateau_modification.h"


/**
 * Fonction test_victoire:
 * *************************
 *    Verifie qu'il y a victoire et qui est le gagnant.
 *     cad si victoire vaut 1 trouve le joueur gagnant.
 *
 *    Necessite:
 *      - Un pointeur non NULL vers une condition_victoire_partie non
 *         modifiable.
 *    Garantie:
 *      - une structure condition mise à jour, càd joueur gangant à jour et victoire égal 1
 */
condition_victoire_partie test_victoire(const plateau_siam* plateau_apres_poussee,int x,int y);



#endif

