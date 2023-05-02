/*************************************************************************
                           Flux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Flux> (fichier Flux.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Flux.h"
#include <vector>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<Packet> Flux::BuildPacket(string nomFichier)
// Algorithme :
//
{
    string chaine;
    ifstream file(nomFichier);
    vector<Packet> liste;
    if (file.is_open())
    {
        Packet UnPacket;
        while (getline(file, chaine))
        {
            int num = chaine.find(" ");
            UnPacket.ip = chaine.substr(0, num + 1);
            chaine.erase(0, num + 1);
            num = chaine.find(" ");
            UnPacket.user_logname = chaine.substr(0, num + 1);
            chaine.erase(0, num + 1);
            num = chaine.find(" ");
            UnPacket.authenticated_user = chaine.substr(0, num + 1);
            chaine.erase(0, num + 1);
            num = chaine.find(" ");
            num = chaine.find(" ", num + 1);
            UnPacket.date = chaine.substr(1, num - 2);
            chaine.erase(0, num + 1);
            num = chaine.find('"');
            num = chaine.find('"', num + 1);
            UnPacket.requete = chaine.substr(1, num - 1);
            chaine.erase(0, num + 1);
            num = chaine.find(" ");
            num = chaine.find(" ", num + 1);
            UnPacket.status = chaine.substr(1, num - 1);
            chaine.erase(0, num + 1);
            num = chaine.find(" ");
            UnPacket.size = chaine.substr(0, num + 1);
            chaine.erase(0, num + 1);
            num = chaine.find('"');
            num = chaine.find('"', num + 1);
            UnPacket.referer = chaine.substr(1, num - 1);
            chaine.erase(0, num + 1);
            num = chaine.find('"');
            num = chaine.find('"', num + 1);
            UnPacket.browser = chaine.substr(2, num - 2);
            chaine.erase(0, num + 1);
            liste.push_back(UnPacket);
        }
    }
    else
    {
        cerr << "Error, can't open file" << endl;
    }
    file.close();
    return liste;
}
//----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
const Flux &Flux::operator=(const Flux &unFlux)
// Algorithme :
//
{
    return unFlux;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Flux::Flux(const Flux &unFlux)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Flux>" << endl;
#endif
} //----- Fin de Flux (constructeur de copie)

Flux::Flux()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Flux>" << endl;
#endif
} //----- Fin de Flux

Flux::~Flux()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Flux>" << endl;
#endif
} //----- Fin de ~Flux

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
