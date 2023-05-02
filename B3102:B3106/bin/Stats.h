/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stats> (fichier Stats.h) ----------------
#if ! defined ( STATS_H )
#define STATS_H
#include <cstring>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <fstream>
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Stats>
//
//
//------------------------------------------------------------------------

class Stats
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Ajouter(pair<string,string>);

    void Top10();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Graph(const string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    const Stats & operator = ( const Stats & unStats );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stats ( const Stats & unStats );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stats ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stats ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
vector<pair<string,string> > liste;
};

//-------------------------------- Autres définitions dépendantes de <Stats>

#endif // Stats_H

