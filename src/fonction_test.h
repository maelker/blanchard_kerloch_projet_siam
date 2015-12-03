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
 * Contient un ensemble de test de fonction que l'on pourra executer
 * Directement à partir du main avec la fonction "test_lancement()".
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions de ces fichiers ne s'occupent ici que de tester les fonctions type et piece.
 *
 */

#ifndef FONCTION_TEST_H
#define FONCTION_TEST_H


/**
 * Fonction test_type_etre_animal():
 * *************************
 *    Teste la fonction type_etre_animal.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_type_etre_animal();

/**
 * Fonction test_type_etre_integre():
 * *************************
 *    Teste la fonction type_etre_integre.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_type_etre_integre();

/**
 * Fonction test_piece_etre_integre():
 * *************************
 *    Teste la fonction piece_etre_integre.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_piece_etre_integre();

/**
 * Fonction test_piece_etre_animal():
 * *************************
 *    Teste la fonction piece_etre_animal.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_piece_etre_animal();

/**
 * Fonction test_piece_etre_rocher():
 * *************************
 *    Teste la fonction piece_etre_rocher.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_piece_etre_rocher();

/**
 * Fonction test_piece_etre_case_vide():
 * *************************
 *    Teste la fonction piece_etre_case_vide.
 *
 *    Garantie:
 *      - Un 'OK' s'il n'y a pas d'erreurs suivant les cas choisis.
 *      - Un 'KO' s'il y a une erreur suivant les cas choisis.
 */
void test_piece_etre_case_vide();


void test_plateau_exister_piece();


/**
 * Fonction test_lancement():
 * *************************
 *    lance toutes les donctions test vue ci-dessus.
 *
 *    Garantie:
 *      - Le lancement de toutes les fonctions test.
 *      
 */
void test_lancement();

#endif

