/*
 * Livre.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef LIVRE_H_
#define LIVRE_H_

#include <string>
#include <vector>

#include "Adherent.h"

using namespace std;


class Livre{
public:
	string code, auteur, titre, editeur, ISBN, _public, etat;
//	_public : adulte, ados, jeunesses ou tout public
//	etat :  libre ou emprunté ou prêté


public:
	Livre(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat);
	Livre();
	void afficher();

	void setCode(string code);
	void setCode();
	void setAuteur(string auteur);
	void setAuteur();
	void setTitre(string titre);
	void setTitre();
	void setEditeur(string editeur);
	void setEditeur();
	void setISBN(string ISBN);
	void setISBN();
	void setPublic(string _public);
	void setPublic();
	void setEtat(string etat);
	void setEtat();

	string getCode();
	string getAuteur();
	string getTitre();
	string getEditeur();
	string getISBN();
	string getPubliv();
	string getEtat();


};




#endif /* LIVRE_H_ */
