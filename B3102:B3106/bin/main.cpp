/*************************************************************************
                           main  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <utility>


//------------------------------------------------------ Include personnel
#include "Flux.h"
#include "Stats.h"

using namespace std;


//------------------------------------------------------------- 

const string url = "http://intranet-if.insa-lyon.fr";

bool bGraph = false;
bool tme = false;
bool bExtension = false;

int hour;

string outputFile;
string inputFile;

string getTarget(const string & targetBrut);
string getExtension(const string & target);
string getReferer(const string & refererBrut);

int getHour(const string & heure);

int main(int argc, char * argv [])
{
  int count = 1;
  while (count < argc - 1)
  {
    string options = argv[count];
    if (options == "-e")
    {
      bExtension = true;
    } 
    else if (options == "-g")
    {
      bGraph = true;
      ++count;
      outputFile = argv[count];
      if (outputFile.length() < 4 || outputFile.substr(outputFile.length() - 4, 4) != ".dot")
      {
        cerr << "Error, please enter a valid file extension. -g [name.dot]" << endl;
        return 1;
      }
    }
    else if (options == "-t")
    {
      tme = true;
      ++count;
      string t = argv[count];
      stringstream ss(t);
      ss >> hour;
      if (ss.fail() || (hour < 0 || hour > 23))
      {
        cerr << "Error, please enter a valid hour. -t [hour], 0<=hour<=23" << endl;
        return 1;
      }
    }
    else
    {
      cerr << "Error, too many or not enough arguments" << endl;
      return 1;
    }
    ++count;
  }
  inputFile = argv[argc - 1];

  Flux flux;
  vector<Packet> res = flux.BuildPacket(inputFile);
  Stats d;

  ifstream fichier;
  fichier.open(inputFile);
  if (!fichier)
  {
    cerr << "Error, input file does not exist. name.log" << endl;
    return 1;
  }

  vector<Packet>::const_iterator itr;

  for(itr = res.begin(); itr != res.end(); ++itr)
  {
    string target = getTarget(itr->requete);
    string referer = getReferer(itr->referer);
    string extension = getExtension(target);
    int heure = getHour(itr->date);

    bool Filter = true;
    if (bExtension && (extension == "css"
                   || extension == "js"
                   || extension == "gif"
                   || extension == "jpg"
                   || extension == "jpeg"
                   || extension == "ico"
                   || extension == "png"))
    {
      Filter = false;
    }
    else if (tme && heure != hour)
    {
      Filter = false;
    }

    if (Filter)
    {
      pair<string, string> renvoieStats = make_pair(target, referer);
      d.Ajouter(renvoieStats);
    }
  }

  if (!bGraph)
  {
    d.Top10();
  }
  else
  {
    d.Graph(outputFile);
    cout << "Dot-file " << outputFile << " generated" << endl;
    d.Top10();
  }
  fichier.close();
  return 0;
}



string getTarget(const string & targetBrut)
{
    int iMin = targetBrut.find(' ');
    int iMax = targetBrut.find('?', ++iMin);
    if (iMax == string::npos)
    {
      iMax = targetBrut.find(' ', iMin);
    }  
    return targetBrut.substr(iMin, iMax - iMin);
}

string getExtension(const string & target)
{
    int i = target.find('.');
    return target.substr(++i);
}

string getReferer(const string & refererBrut)
{
    int i = refererBrut.find(url) + url.size();
    if (i >= refererBrut.size()) {
        i = 0;
    }
    return refererBrut.substr(i);
}

int getHour(const string & heure)
{
    int iMin = heure.find(':');
    int iMax = heure.find(':', ++iMin);
    return stoi(heure.substr(iMin, iMax - iMin));
}
