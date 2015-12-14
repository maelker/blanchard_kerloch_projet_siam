
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
 *
 * Définis les fonctions qui vont permettre de vérifier si en introduisant
 *
 * une piece ou en la deplacant nous pouvons ou non pousser la ou les 
 * pieces qui se trouvent sur le chemins. 
 * Permet egalement de les deplacer si il est possible.
 *
 *
 */


#ifdef POUSSEE_H
#define POUSSEE_H


/**
 * Fonction poussee_etre_valide:
 * *************************
 *     Verifie si il est possible de realiser une poussee qui debute
 *      aux coordonnees (x,y)  dans l'orientation definie.
 *     Note: Les coordonnees (x,y) designent la premiere piece rencontree
 *      dans la poussee(et non pas les coordonnees de la piece a l'origine
 *      de la poussee).
 *
 *     Necessite:
 *       - Un pointeur non NULL vers un plateau integre non modifiable.
 *       - Deux coordonnees entieres (x,y) designant une piece non
 *          vide integre du plateau.
 *       - Une orientation de poussee designant une direction integre.
 *     Garantie:
 *       - Un retour valant 1 si la poussee est possible.
 *       - Un retour valant 0 sinon.
 *
 */
int poussee_etre_valide(const plateau_siam* plateau, int x, int y, orientation_deplacement orientation);

/**
 * Fonction poussee_realiser:
 * *************************
 *     Realise une poussee sur un plateau en supposant que celle-ci
 *      est realisable (et non pas les coordonnees de la piece a l'origine
 *      de la poussee).
 *
 *     Necessite:
 *       - Un pointeur non NULL vers un plateau integre modifiable.
 *       - Deux coordonnees entieres (x,y) designant une piece non
 *          vide integre du plateau.
 *       - Un type d'animal a deplacer.
 *       - Une orientation de poussee designant une direction integre.
 *       - Un pointeur non NULL vers une condition de victoire modifiable.
 *     Garantie:
 *       - Un plateau integre mis a jour en ayant realise la poussee.
 *
 */
void poussee_realiser(plateau_siam* plateau, int x, int y, type_piece type, orientation_deplacement orientation);

#endif
