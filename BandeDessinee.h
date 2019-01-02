/*
 * BandeDessinee.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef BANDEDESSINEE_H_
#define BANDEDESSINEE_H_

#include <string>

#include "Livre.h"

using namespace std;

class BandeDessinee : public Livre{
private:
	string dessinateur;

public:
	BandeDessinee(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat, string dessinateur)
		: Livre(code, auteur, titre, editeur, ISBN, _public, etat){
		this->dessinateur = dessinateur;
	}
	BandeDessinee():Livre(){
		string dessinateur;
		cout << "Saisie dessinateur de bande dessinée: "; getline(cin,dessinateur); this->dessinateur = dessinateur;
	}

};




#endif /* BANDEDESSINEE_H_ */
