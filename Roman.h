/*
 * Roman.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef ROMAN_H_
#define ROMAN_H_

#include <string>

#include "Livre.h"

using namespace std;

class Roman : public Livre{
private:
	string genre;
//genre : Littérature, Roman noir, Roman policier, Roman animalier, Roman d'amour, Roman de mœurs,
//Roman gothique, Roman courtois, Roman épistolaire, Roman-feuilleton, Roman graphique, Roman historique,
//Roman-photo, Roman picaresque, Roman-mémoires, Roman populaire, Roman d'aventures, Roman d'anticipation,
//Roman d'espionnage, Roman d'apprentissage, Roman de chevalerie, Roman autobiographique, Nouveau roman,
//Roman chevaleresque, Conte, Nouvelle etc..

public:
	Roman(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat, string genre)
		: Livre(code, auteur, titre, editeur, ISBN, _public, etat){
		this->genre = genre;
	}
	Roman():Livre(){
		string genre;
		cout << "Saisie genre de roman: "; getline(cin,genre); this->genre = genre;
	}



};



#endif /* ROMAN_H_ */
