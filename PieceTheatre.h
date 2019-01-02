/*
 * PieceTheatre.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef PIECETHEATRE_H_
#define PIECETHEATRE_H_

#include <string>

#include "Livre.h"

using namespace std;

class PieceTheatre : public Livre{
private:
	string siecle;

public:
	PieceTheatre(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat, string siecle)
			: Livre(code, auteur, titre, editeur, ISBN, _public, etat){
			this->siecle = siecle;
		}
	PieceTheatre():Livre(){
		string siecle;
		cout << "Saisie le siecle de piece thêatre: "; getline(cin, siecle); this->siecle = siecle;
	}

};




#endif /* PIECETHEATRE_H_ */
