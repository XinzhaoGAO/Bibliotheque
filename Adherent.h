/*
 * Adherent.h
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#ifndef ADHERENT_H_
#define ADHERENT_H_

#include <iostream>
#include <string>
#include <vector>

#include "Livre.h"
#include "Bibliotheque.h"

class Livre;


using namespace std;

class Bibliotheque;
class Livre;

class Adherent{
public:
	string nom, prenom, adresse, numAdherent;

	Bibliotheque* bibliotheque;

	vector<Livre*> livreEmpruntes;

	int nbrEmprunt;

public:
	Adherent(string nom, string prenom, string adresse, string numAdherent, Bibliotheque* bibliotheque, int nbrEmprunt=1);
	Adherent(Bibliotheque *bibliotheque);

	void afficher();

	void setNom(string nom);
	void setNom();
	void setPrenom(string prenom);
	void setPrenom();
	void setAdresse(string adresse);
	void setAdresse();
	void setNumAdherent(string numAdherent);
	void setNumAdherent();
	void setBibliotheque(Bibliotheque* bibliotheque);
	void setLivreEmpruntes(vector<Livre*> livreEmpruntes);
	void setNbrEmprunt(int nbrEmprunt);

	string getNom();
	string getPrenom();
	string getAdresse();
	string getNumAdherent();
	Bibliotheque* getBibliotheque();
	void getLivreEmpruntes();
	int getNbrEmprunt();

	void emprunter(string code);
	void emprunter();

	void rendre(string code);
	void rendre();




};





#endif /* ADHERENT_H_ */
