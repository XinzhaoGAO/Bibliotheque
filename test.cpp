/*
 * test.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#include <iostream>
#include <string>

#include "Livre.h"
#include "Bibliotheque.h"
#include "Adherent.h"

#include "Album.h"
#include "BandeDessinee.h"
#include "PieceTheatre.h"
#include "RecueilPoesie.h"
#include "Roman.h"

using namespace std;
int main(){
//********************TEST LIVRE
//	Livre l("001","J.K.Rowling","Harry Potter","Bloomsbury Publishing","8979871928364","tout public","libre");
//
//	cout << l.getEditeur() <<endl;
//	l.setISBN("87129091823080192");
//	l.setEtat("prêté");
//	l.afficher();


//*******************TEST EMPRUNTER
	Bibliotheque biblio_marseille("Bibliotheque de Marseille", "38 RUE FREDERIC JOLIOT CURIE","O8192I3JO");
	Bibliotheque biblio_paris("Bibliotheque de Paris", "75001, île de france","8970a872h3");


	Roman l1("001","J.K.Rowling","Harry Potter","Bloomsbury Publishing","8979871928364","tout public","libre","Roman d'aventures");
	Roman l2("002","George R.R. Martin","A song of Ice and Fire","Bantam Books","9018203803899723","tout public","libre","Roman d'anticipation");
	Roman l3("003","Dan Brown","The Da Vinci Code","Doubleday","0-385-50420-9","adulte","libre","Roman policier");



	Livre* L1 = &l1;
	Livre* L2 = &l2;
	Livre* L3 = &l3;
	biblio_marseille.listeLivres.push_back(L1);
	biblio_marseille.listeLivres.push_back(L2);
	biblio_paris.listeLivres.push_back(L3);

	Bibliotheque* b1 = &biblio_marseille;
//	Bibliotheque* b2 = &biblio_paris;

	Adherent a1("GAO","Xinzhao","RESIDENCE ETUDIANTE","0981237789",b1,3);

//	a1.afficher();

//	biblio_paris.demander("8979871928364",b1);

//	biblio_marseille.afficher();
//	biblio_paris.afficher();

	a1.emprunter("001");
	a1.emprunter("002");
	a1.rendre("001");
	a1.rendre("002");

//	a1.getLivreEmpruntes();
//	l1.afficher();
//	l2.afficher();

//	cout << biblio_marseille.checkEtat("001");

//	Roman l4("004","Alexandre Dumas","Le Comte de Monte-Cristo","Journal des débats","123091028399","tout public","libre","Conte");
//	Livre* nouveau_livre = &l4;

//**********************TEST ACHETER & SUPPRIMER
//	biblio_marseille.acheter(nouveau_livre);
//
//	biblio_marseille.afficher();
//
//	biblio_marseille.supprimer("004");
//
//	biblio_marseille.getListeLivres();



//*************************TEST RENDREADHERENTS
	Adherent a2("MA","Ziqing","RESIDENCE ETUDIANTE","8091238764",b1,2);
	Adherent a3("MENG","Zikun","Beijing","8098615273",b1,4);

	a2.emprunter("001");
	a2.rendre("001");

//	a3.emprunter("001");
//	a3.rendre("001");

//
//	biblio_marseille.rendreAdherentsEmpruntés("001");
//	biblio_marseille.rendreAdherentsPasEmprintés("001");

	PieceTheatre l5("005","William Shakespeare","Le Songe d'une nuit d'été","Editions 84","09jasd0890128","tout public","libre","16ème siècle");
	Livre* L5 = &l5;
	biblio_marseille.listeLivres.push_back(L5);

//*************************TEST INTERFACE
	biblio_marseille.acheter();
	biblio_marseille.getListeLivres();


};


