/*
 * RecueilPoesie.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef RECUEILPOESIE_H_
#define RECUEILPOESIE_H_

#include <string>

#include "Livre.h"

using namespace std;

class RecueilPoesie : public Livre{
private:
	string indicateur;
//indicateur: vers ou prose ou les deux

public:
	RecueilPoesie(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat, string indicateur)
		:Livre(code, auteur, titre, editeur, ISBN, _public, etat){
		this->indicateur = indicateur;
	}
	RecueilPoesie():Livre(){
		string indicateur;
		cout << "Saisie l'indicateur de recueil poésie: "; getline(cin,indicateur); this->indicateur = indicateur;
	}


};




#endif /* RECUEILPOESIE_H_ */
