
# Commandes de bases a repeter pour la compilation.
CFLAGS=-g -Wall -Wextra

# Rassemble tous les fichiers ".o" dans la variable "OBJ" pour une meilleur lisibilité.
OBJ=api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o fonction_test.o poussee.o victoire_siam.o

# Actions realisees quand on ecrit la commande "make".
all: jeu_siam clean

# Premiere action realisee :
jeu_siam: $(OBJ)
	gcc $(OBJ) -o jeu_siam # Cree les fichiers ".o" a partir des fichiers ".c" avec tous les warnings de "-Wall" et "Wextra".
	mkdir -p ../bin/ # Cree un dossier "bin" s'il est inexistant.
	cp jeu_siam ../bin/ # Copie le fichier "jeu_siam" dans le dossier bin tout juste cree ou deja existant.

# Cree les liens entre les fichiers ".o" crees precedement avec son ".c" et avec les fichiers ".h" relies au ".c".
api_siam.o: api_siam.c api_siam.h plateau_modification.h coordonnees_plateau.h jeu_siam.h piece_siam.h plateau_siam.h joueur.h condition_victoire_partie.h
condition_victoire_partie.o: condition_victoire_partie.c condition_victoire_partie.h joueur.h
coordonnees_plateau.o: coordonnees_plateau.c coordonnees_plateau.h
coup_jeu.o: coup_jeu.c coup_jeu.h
entree_sortie.o: entree_sortie.c entree_sortie.h plateau_siam.h
jeu_siam.o: jeu_siam.c jeu_siam.h joueur.h entree_sortie.h
joueur.o: joueur.c joueur.h
main.o: main.c piece_siam.h plateau_siam.h jeu_siam.h api_siam.h mode_interactif.h type_piece.h
mode_interactif.o: mode_interactif.c mode_interactif.h api_siam.h parseur_mode_interactif.h entree_sortie.h
orientation_deplacement.o: orientation_deplacement.c orientation_deplacement.h
parseur_mode_interactif.o: parseur_mode_interactif.c parseur_mode_interactif.h
piece_siam.o: piece_siam.c piece_siam.h
plateau_modification.o: plateau_modification.c plateau_modification.h coordonnees_plateau.h type_piece.h plateau_siam.h piece_siam.h
plateau_siam.o: plateau_siam.c plateau_siam.h entree_sortie.h
type_piece.o: type_piece.c type_piece.h
fonction_test.o: fonction_test.c fonction_test.h piece_siam.h plateau_siam.h type_piece.h
poussee.o: poussee.c poussee.h api_siam.h plateau_modification.h coordonnees_plateau.h jeu_siam.h piece_siam.h plateau_siam.h joueur.h
victoire_siam.o: victoire_siam.c victoire_siam.h condition_victoire_partie.h joueur.h

# Deuxieme action realisee :
clean:
	rm -f *.o *~ jeu_siam # ici "rm" supprime tous les fichiers ".o", tous les fichiers terminant par "~" et le fichier jeu_siam.
