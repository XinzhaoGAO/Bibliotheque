/*
 * Bibliotheque.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#include <string>
#include <iostream>
#include <algorithm>

#include "Livre.h"
#include "Adherent.h"
#include "Bibliotheque.h"

using namespace std;

Bibliotheque::Bibliotheque(string nom, string adresse, string code){
	this->nom = nom;
	this->adresse = adresse;
	this->code = code;
}
Bibliotheque::Bibliotheque(){
	string nom, adresse, code;
	cout << "Saisie nom de la bibliothèque: "; getline(cin,nom); this->nom  = nom;
	cout << "Saisie adresse de la bibliothèque: "; getline(cin,adresse); this->adresse = adresse;
	cout << "Saisie code de la bibliothèque: "; getline(cin,code); this->code = code;
}

void Bibliotheque::setNom(string nom){
	this->nom = nom;
}
void Bibliotheque::setNom(){
	string nom;
	cout << "Saisie nom de la bibliothèque: "; getline(cin,nom); this->nom  = nom;
}
void Bibliotheque::setAdresse(string adresse){
	this->adresse = adresse;
}
void Bibliotheque::setAdresse(){
	string adresse;
	cout << "Saisie adresse de la bibliothèque: "; getline(cin,adresse); this->adresse  = adresse;
}
void Bibliotheque::setCode(string code){
	this->code = code;
}
void Bibliotheque::setCode(){
	string code;
	cout << "Saisie code de la bibliothèque: "; getline(cin,code); this->code  = code;
}
void Bibliotheque::setListeLivres(vector<Livre*> listeLivres){
	this->listeLivres = listeLivres;
}
void Bibliotheque::setListeAdherents(vector<Adherent*> listeAdherents){
	this->listeAdherents = listeAdherents;
}


string Bibliotheque::getNom(){
	return nom;
}
string Bibliotheque::getAdresse(){
	return adresse;
}
string Bibliotheque::getCode(){
	return code;
}
void Bibliotheque::getListeLivres(){
	for(int i=0;i<listeLivres.size();i++){
		cout << i+1 << ". " <<listeLivres.at(i)->titre <<endl;
	}
}
void Bibliotheque::getListeAdhernets(){
	for(int i=0;i<listeAdherents.size();i++){
		cout << i+1 << ". " <<listeAdherents.at(i)->nom <<endl;
	}
}


void Bibliotheque::afficher(){
	cout << "Nom de la bibliothèque: " << nom <<endl;
	cout << "L'adresse de la bibliothèque: " << adresse <<endl;
	cout << "Code de la bibliothèque: " << code <<endl;
	cout << "La liste des livres: " <<endl;
	getListeLivres() ;
	cout <<endl;

}


void Bibliotheque::demander(string ISBN, Bibliotheque *bibliotheque){
	for(int i=0;i<bibliotheque->listeLivres.size();i++){
		if(bibliotheque->listeLivres.at(i)->ISBN == ISBN){
			bibliotheque->listeLivres.at(i)->setEtat("emprunté");
			this->listeLivres.push_back(bibliotheque->listeLivres.at(i));
		}
	}

}
void Bibliotheque::demander(Bibliotheque *bibliotheque){
	string ISBN;
	cout << "Saisie ISBN du livre demandé: "; getline(cin,ISBN);
	for(int i=0;i<bibliotheque->listeLivres.size();i++){
		if(bibliotheque->listeLivres.at(i)->ISBN == ISBN){
			bibliotheque->listeLivres.at(i)->setEtat("emprunté");
			this->listeLivres.push_back(bibliotheque->listeLivres.at(i));
		}
	}
}


void Bibliotheque::acheter(Livre* nouveau_livre){
	listeLivres.push_back(nouveau_livre);
}
void Bibliotheque::acheter(){
	string code, auteur, titre, editeur, ISBN, _public, etat;

	cout << "Saisie code du livre acheté: "; getline(cin,code);
	cout << "Saisie auteur du livre acheté: "; getline(cin,auteur);
	cout << "Saisie titre du livre acheté: "; getline(cin,titre);
	cout << "Saisie editeur du livre acheté: "; cin.ignore();getline(cin,editeur);
	cout << "Saisie ISBN du livre acheté: "; getline(cin,ISBN);
	cout << "Saisie _public du livre acheté: "; getline(cin,_public);
	cout << "Saisie etat du livre acheté: "; getline(cin,etat);

	static Livre  l(code,auteur,titre,editeur,ISBN,_public,etat);

	static Livre* L = &l;
	listeLivres.push_back(L);
}

void Bibliotheque::supprimer(string code){
	int i = this->findLivre(code);
	listeLivres.erase(listeLivres.begin()+i);

}
void Bibliotheque::supprimer(){
	string code;
	cout << "Saisie code du livre supprimé: "; getline(cin,code);
	int i = this->findLivre(code);
	listeLivres.erase(listeLivres.begin()+i);

}

//void Bibliotheque::rendreAdherentsEmpruntés(string code){
//	cout << "Liste de livres peut rendre ceux qui lui sont prêtés: " <<endl;
//	int i = this->findLivre(code);
//	for(int j=0;j<listeLivres.at(i)->adherents_emprunt.size();j++)
//		cout << j+1 << ". " << listeLivres.at(i)->adherents_emprunt.at(j)->nom <<endl;
//	cout <<endl;
//}
void Bibliotheque::rendreLivresPretés(){
	cout << "Liste de livres prêtés: " <<endl;
	for(int i=0;i<listeLivres.size();i++){
		int j = 1;
		if(listeLivres.at(i)->etat == "prêté"){
			cout << j << ". " << listeLivres.at(i)->titre <<endl;
			j++;
		}
	}
}
//void Bibliotheque::rendreLivresPasEmprintés(){
//	string code;
//	cout << "Saisie code du livre pour rendre ceux qui ne sont pas empruntés: "; getline(cin,code);
//	cout << "Liste de livres peut rendre ceux qui lui sont prêtés et ne sont pas empruntés" <<endl;
//	int i = this->findLivre(code);
//	int t = 1;
//	for(int j=0;j<listeAdherents.size();j++){
//		if(std::find(listeLivres.at(i)->adherents_emprunt.begin(),listeLivres.at(i)->adherents_emprunt.end(),listeAdherents.at(j)) == listeLivres.at(i)->adherents_emprunt.end()){
//			cout << t << ". " << listeAdherents.at(j)->nom <<endl;
//			t++;
//		}
//	}
//	cout <<endl;
//
//}
void Bibliotheque::rendreLivresPasEmprintés(){
	cout << "Liste de livres pas emprintés: " <<endl;
	for(int i=0;i<listeLivres.size();i++){
		int j = 1;
		if(listeLivres.at(i)->etat == "libre"){
			cout << j << ". " << listeLivres.at(i)->titre <<endl;
			j++;
		}
	}

}

bool Bibliotheque::checkEtat(string code){
	for(int i=0;i<listeLivres.size();i++){
		if(listeLivres.at(i)->code == code && listeLivres.at(i)->etat == "libre") return true;
	}
	return false;

}

int Bibliotheque::findLivre(string code){
	for(int i=0;i<listeLivres.size();i++){
			if(listeLivres.at(i)->code == code)
				return i;
		}
	return 0;
}




