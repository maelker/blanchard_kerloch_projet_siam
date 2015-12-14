CFLAGS=-g -Wall -Wextra
OBJ=api_siam.o condition_victoire_partie.o coordonnees_plateau.o coup_jeu.o entree_sortie.o jeu_siam.o joueur.o main.o mode_interactif.o orientation_deplacement.o parseur_mode_interactif.o piece_siam.o plateau_modification.o plateau_siam.o type_piece.o fonction_test.o poussee.o

all: jeu_siam clean


jeu_siam: $(OBJ)
	gcc $(OBJ) -o jeu_siam
	mkdir -p ../bin/
	cp jeu_siam ../bin/

api_siam.o: api_siam.c api_siam.h plateau_modification.h coordonnees_plateau.h jeu_siam.h piece_siam.h plateau_siam.h joueur.h
condition_victoire_partie.o: condition_victoire_partie.c condition_victoire_partie.h joueur.h
coordonnees_plateau.o: coordonnees_plateau.c coordonnees_plateau.h
coup_jeu.o: coup_jeu.c coup_jeu.h
entree_sortie.o: entree_sortie.c entree_sortie.h
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


clean:
	rm -f *.o *~ jeu_siam
