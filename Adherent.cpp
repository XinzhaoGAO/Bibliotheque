/*
 * Adherent.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#include <string>
#include <iostream>
#include <vector>

#include "Adherent.h"
#include "Bibliotheque.h"

using namespace std;

Adherent::Adherent(string nom, string prenom, string adresse, string numAdherent, Bibliotheque *bibliotheque, int nbrEmprunt){
	this->nom = nom;
	this->prenom = prenom;
	this->adresse = adresse;
	this->numAdherent = numAdherent;
	this->bibliotheque = bibliotheque;
	bibliotheque->listeAdherents.push_back(this);
	this->nbrEmprunt = nbrEmprunt;
}
Adherent::Adherent(Bibliotheque *bibliotheque){
	string nom, prenom, adresse, numAdherent;
//	Bibliotheque *bibliotheque;
	int nbrEmprunt;

	cout << "Saisie nom d'adherent: "; getline(cin,nom); this->nom = nom;
	cout << "Saisie prenom d'adherent: "; getline(cin,prenom); this->prenom = prenom;
	cout << "Saisie adresse d'adherent: "; getline(cin,adresse); this->adresse = adresse;
	cout << "Saisie numAdherent d'adherent: "; getline(cin, numAdherent); this->numAdherent = numAdherent;
	this->bibliotheque = bibliotheque;
	cout << "Saisie le nombre de livres autorisé à l'emprunt: "; cin >> nbrEmprunt; this->nbrEmprunt = nbrEmprunt;
}

void Adherent::afficher(){
	cout << "Nom: " << nom <<endl;
	cout << "Prenom: " << prenom <<endl;
	cout << "Adresse: " << adresse <<endl;
	cout << "Numéro d'adhérent: " << numAdherent <<endl;
	cout << "La bibliothèque à laquelle il est inscrit: " << bibliotheque->nom <<endl;
	cout << "La liste des livres empruntés en ce moment: " <<endl;
	getLivreEmpruntes();
	cout << "Le nombre de livres autorisé à l'emprunt: " << nbrEmprunt <<endl;
	cout <<endl;

}


void Adherent::setNom(string nom){
	this->nom = nom;
}
void Adherent::setNom(){
	string nom;
	cout << "Saisie nom d'adherent: "; getline(cin,nom); this->nom = nom;
}
void Adherent::setPrenom(string prenom){
	this->prenom = prenom;
}
void Adherent::setPrenom(){
	string prenom;
	cout << "Saisie prenom d'adherent: "; getline(cin,prenom); this->prenom = prenom;
}
void Adherent::setAdresse(string adresse){
	this->adresse = adresse;
}
void Adherent::setAdresse(){
	string adresse;
	cout << "Saisie adresse d'adherent: "; getline(cin,adresse); this->adresse = adresse;
}
void Adherent::setNumAdherent(string numAdherent){
	this->numAdherent = numAdherent;
}
void Adherent::setNumAdherent(){
	string numAdherent;
	cout << "Saisie numAdherent d'adherent: "; getline(cin, numAdherent); this->numAdherent = numAdherent;
}
void Adherent::setBibliotheque(Bibliotheque *bibliotheque){
	this->bibliotheque = bibliotheque;
}
void Adherent::setLivreEmpruntes(vector<Livre*> livreEmpruntes){
	this->livreEmpruntes = livreEmpruntes;
}
void Adherent::setNbrEmprunt(int nbrEmprunt){
	this->nbrEmprunt = nbrEmprunt;
}

string Adherent::getNom(){
	return nom;
}
string Adherent::getPrenom(){
	return prenom;
}
string Adherent::getAdresse(){
	return adresse;
}
string Adherent::getNumAdherent(){
	return numAdherent;
}
Bibliotheque* Adherent::getBibliotheque(){
	return bibliotheque;
}
void Adherent::getLivreEmpruntes(){
	for(int i=0;i<livreEmpruntes.size();i++){
		cout << i+1 << ". " << livreEmpruntes.at(i)->titre << endl;
	}
}
int Adherent::getNbrEmprunt(){
	return nbrEmprunt;
}

void Adherent::emprunter(string code){
	if(livreEmpruntes.size() <= nbrEmprunt){
		if(bibliotheque->checkEtat(code)){
			int i = bibliotheque->findLivre(code);
			bibliotheque->listeLivres.at(i)->setEtat("prêté");
			livreEmpruntes.push_back(bibliotheque->listeLivres[i]);
			cout << "Emprunt Réussi!!!" << endl;
			}
		else cout << "Ce livre est prêté." <<endl;
	}
	else cout << "Vous avez atteint la limite d'emprunt."<<endl;

}
void Adherent::emprunter(){
	string code;
	cout << "Saisie code du livre que vous voulez emprunter: "; getline(cin,code);

	if(livreEmpruntes.size() <= nbrEmprunt){
		if(bibliotheque->checkEtat(code)){
			int i = bibliotheque->findLivre(code);
			bibliotheque->listeLivres.at(i)->setEtat("prêté");
			livreEmpruntes.push_back(bibliotheque->listeLivres[i]);
			cout << "Emprunt Réussi!!!" << endl;
			}
		else cout << "Ce livre est prêté." <<endl;
	}
	else cout << "Vous avez atteint la limite d'emprunt."<<endl;

}

void Adherent::rendre(string code){
	for(int i=0;i<livreEmpruntes.size();i++){
		if(livreEmpruntes.at(i)->code == code){
			livreEmpruntes.erase(livreEmpruntes.begin()+i);
			int j = bibliotheque->findLivre(code);
			bibliotheque->listeLivres.at(j)->setEtat("libre");
		}
	}

}
void Adherent::rendre(){
	string code;
	cout << "Saisie code du livre que vous voulez rendre: "; getline(cin,code);

	for(int i=0;i<livreEmpruntes.size();i++){
		if(livreEmpruntes.at(i)->code == code){
			livreEmpruntes.erase(livreEmpruntes.begin()+i);
			int j = bibliotheque->findLivre(code);
			bibliotheque->listeLivres.at(j)->setEtat("libre");
		}
	}

}


