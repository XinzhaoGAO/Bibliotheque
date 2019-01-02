/*
 * Album.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include <string>

#include "Livre.h"

using namespace std;

class Album : public Livre{
private:
	string illustration;
//illustration: des photos ou des dessins ou les deux

public:
	Album(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat, string illustration)
			: Livre(code, auteur, titre, editeur, ISBN, _public, etat){
			this->illustration = illustration;
		}
	Album():Livre(){
		string illustration;
		cout << "Saisie illustration d'album: "; getline(cin,illustration); this->illustration = illustration;
	}

};





#endif /* ALBUM_H_ */
