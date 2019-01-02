/*
 * Bibliotheque.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef BIBLIOTHEQUE_H_
#define BIBLIOTHEQUE_H_

#include <string>
#include <vector>
#include <iostream>

#include "Livre.h"
#include "Adherent.h"

using namespace std;

class Adherent;
class Livre;


class Bibliotheque{
public:
	string nom, adresse, code;

	vector<Livre*> listeLivres;

	vector<Adherent*> listeAdherents;


public:
	Bibliotheque(string nom, string adresse, string code);
	Bibliotheque();

	void setNom(string nom);
	void setNom();
	void setAdresse(string adresse);
	void setAdresse();
	void setCode(string code);
	void setCode();
	void setListeLivres(vector<Livre*> listeLivres);
	void setListeAdherents(vector<Adherent*> listeAdherents);

	string getNom();
	string getAdresse();
	string getCode();
	void getListeLivres();
	void getListeAdhernets();

	void afficher();

	void demander(string ISBN, Bibliotheque* bibliotheque);
	void demander(Bibliotheque* bibliotheque);
	void acheter(Livre* nouveau_livre);
	void acheter();
	void supprimer(string code);
	void supprimer();
	void rendreLivresPretés();
	void rendreLivresPasEmprintés();

	bool checkEtat(string code);
	int findLivre(string code);




};







#endif /* BIBLIOTHEQUE_H_ */
