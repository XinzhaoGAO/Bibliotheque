/*
 * Livre.cpp
 *
 *  Created on: Dec 15, 2018
 *      Author: mac
 */

#include <iostream>
#include <string>

#include "Livre.h"

using namespace std;

Livre::Livre(string code, string auteur, string titre, string editeur, string ISBN, string _public, string etat){
	this->code = code;
	this->auteur = auteur;
	this->titre = titre;
	this->editeur = editeur;
	this->ISBN = ISBN;
	this->_public = _public;
	this->etat = etat;
}

Livre::Livre(){
	string code, auteur, titre, editeur, ISBN, _public, etat;
	cout << "Saisie code du livre: "; getline(cin,code); this->code = code;
	cout << "Saisie auteur du livre: "; getline(cin,auteur); this->auteur = auteur;
	cout << "Saisie titre du livre: "; getline(cin,titre); this->titre = titre;
	cout << "Saisie editeur du livre: "; getline(cin,editeur); this->editeur = editeur;
	cout << "Saisie ISBN du livre: "; getline(cin,ISBN); this->ISBN = ISBN;
	cout << "Saisie _public du livre: "; getline(cin,_public); this->_public = _public;
	cout << "Saisie etat du livre: "; getline(cin,etat); this->etat = etat;
}

void Livre::afficher(){
	cout << "Code: " << code <<endl;
	cout << "Auteur: " << auteur <<endl;
	cout << "Titre: " << titre <<endl;
	cout << "Editeur: " << editeur <<endl;
	cout << "ISBN: " << ISBN <<endl;
	cout << "Public: " << _public <<endl;
	cout << "Etat: " << etat <<endl;
	cout <<endl;
}

void Livre::setCode(string code){
	this->code = code;
}
void Livre::setCode(){
	string code;
	cout << "Saisie code du livre: "; getline(cin,code); this->code = code;
}
void Livre::setAuteur(string auteur){
	this->auteur = auteur;
}
void Livre::setAuteur(){
	string auteur;
	cout << "Saisie auteur du livre: "; getline(cin,auteur); this->auteur = auteur;
}
void Livre::setTitre(string titre){
	this->titre = titre;
}
void Livre::setTitre(){
	string titre;
	cout << "Saisie titre du livre: "; getline(cin,titre); this->titre = titre;
}
void Livre::setEditeur(string editeur){
	this->editeur = editeur;
}
void Livre::setEditeur(){
	string editeur;
	cout << "Saisie editeur du livre: "; getline(cin,editeur); this->editeur = editeur;
}
void Livre::setISBN(string ISBN){
	this->ISBN = ISBN;
}
void Livre::setISBN(){
	string ISBN;
	cout << "Saisie ISBN du livre: "; getline(cin,ISBN); this->ISBN = ISBN;
}
void Livre::setPublic(string _public){
	this->_public = _public;
}
void Livre::setPublic(){
	string _public;
	cout << "Saisie _public du livre: "; getline(cin,_public); this->_public = _public;
}
void Livre::setEtat(string etat){
	this->etat = etat;
}
void Livre::setEtat(){
	string etat;
	cout << "Saisie etat du livre: "; getline(cin,etat); this->etat = etat;
}


string Livre::getCode(){
	return code;
}
string Livre::getAuteur(){
	return auteur;
}
string Livre::getTitre(){
	return titre;
}
string Livre::getEditeur(){
	return editeur;
}
string Livre::getISBN(){
	return ISBN;
}
string Livre::getPubliv(){
	return _public;
}
string Livre::getEtat(){
	return etat;
}







