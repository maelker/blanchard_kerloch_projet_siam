SIAM GAME

	2v2 board game

CONFIG AND LAUNCHING

	You need to have gcc, make and glut installed
	On Linux:
	you need to start 2 terminals, one to type the command to move your pieces and one with the visualizer
	1) Go to /bin and type in your terminal:
	make
	./jeu_siam

	2) Go to /visualiseur and type
	make
	./visualiseur

	You are ready to go!

RULE

	1 player plays the rhinoceros, the other one the elephants
	First one who pushes a rock out of the board wins
	You can push either one of the 3 rocks or one of your opponent pieces
	You can only introduce a piece on the board from one of the 4 edges of the board
	You can push an opponent piece if you are oriented in its direction
	If the opponent piece is facing yours then you need 2 pieces to push it

SET UP

	The 3 rocks in the middle of the board
	All the rhinoceros and elephants out of the board

CONTROLS

	To introduce a piece:
	n postionX positionY MoveDirection Orientation

	To move (with eventual pushing) a piece:
	d postionX positionY MoveDirection Orientation

	To just change the orientation of a pice without moving:
	o postionX positionY NewOrientation





