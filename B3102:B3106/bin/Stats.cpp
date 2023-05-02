/*************************************************************************
                           Stats  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Stats> (fichier Stats.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Stats.h"
#include "Flux.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Stats::Ajouter(pair<string, string> node)
{
    liste.push_back(node);
}

void Stats::Top10()
// Algorithme :
//
{
    int num1, num2;
    unordered_map<string, int> umap;
    for (int i = 0; i < liste.size(); i++)
    {
        string cible = liste[i].first;
        if (umap.find(cible) == umap.end())
        {
            umap.insert(make_pair(cible, 1));
        }
        else
        {
            umap[cible]++;
        }
    }
    multimap<int, string> mmap;
    unordered_map<string, int>::iterator it;
    for (it = umap.begin(); it != umap.end(); it++)
    {
        string cible = it->first;
        int clicks = it->second;
        mmap.insert(make_pair(clicks, cible));
    }
    multimap<int, string>::reverse_iterator it2;
    int compteur = 0;
    for (it2 = mmap.rbegin(); it2 != mmap.rend() && compteur != 10; ++it2)
    {
        cout << it2->second << " (" << it2->first << " hits)" << endl;
        compteur++;
    }
} //----- Fin de Méthode

void Stats::Graph(const string nomFichier)
// Algorithme :
//
{
    int num1, num2;
    map<string, unordered_map<string, int> > mymap;
    for (int i = 0; i < liste.size(); i++)
    {
        if (mymap.find(liste[i].second) == mymap.end())
        {
            unordered_map<string, int> umap;
            umap.insert(make_pair(liste[i].first, 1));
            mymap.insert(make_pair(liste[i].second, umap));
        }
        else
        {
            mymap[liste[i].second][liste[i].first]++;
        }
    }
    ofstream file(nomFichier);
    if (file.is_open())
    {
        file << "digraph {" << endl;
        map<string, unordered_map<string, int> >::iterator it;
        unordered_map<string, int> nodes;
        int i = 0;
        for (it = mymap.begin(); it != mymap.end(); it++)
        {
            file << "node" << i << " [label=\"" << it->first << "\"];" << endl;
            nodes[it->first] = i;
            i++;
        }
        unordered_map<string, int>::iterator it2;
        for (it = mymap.begin(); it != mymap.end(); it++)
        {
            for (it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                file << "node" << nodes[it->first] << " -> node" << nodes[it2->first] << " [label=\"" << it2->second << "\"];" << endl;
            }
        }
        file << "}" << endl;
    }
    else
        cerr << "Error opening file" << endl;
    file.close();
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
const Stats &Stats::operator=(const Stats &unStats)
// Algorithme :
//
{
    return unStats;
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Stats::Stats(const Stats &unStats)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stats>" << endl;
#endif
} //----- Fin de Stats (constructeur de copie)

Stats::Stats()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stats>" << endl;
#endif

} //----- Fin de Stats

Stats::~Stats()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stats>" << endl;
#endif
} //----- Fin de ~Stats

//------------------------------------------------------------------ PRIVE
//onTest
//----------------------------------------------------- Méthodes protégées
