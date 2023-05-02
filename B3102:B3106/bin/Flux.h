/*************************************************************************
                           Flux  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Flux> (fichier Flux.h) ----------------
#if !defined(FLUX_H)
#define FLUX_H
using namespace std;
#include <iostream>
#include <string>
#include <vector>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
// 
typedef struct Packet
{
    string ip;
    string user_logname;
    string authenticated_user;
    string date;
    string requete;
    string status;
    string size;
    string referer;
    string browser;
} Packet;
//------------------------------------------------------------------------
// Rôle de la classe <Flux>
//
//
//------------------------------------------------------------------------

class Flux : public string
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    vector<Packet> BuildPacket(string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------- Surcharge d'opérateurs
    const Flux &operator=(const Flux &unFlux);
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Flux(const Flux &unFlux);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Flux();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Flux();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Flux>

#endif // Flux_H
