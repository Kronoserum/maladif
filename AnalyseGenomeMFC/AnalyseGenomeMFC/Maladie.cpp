#include <string>
#include <list>
#include <stdio.h>

#include "stdafx.h"
#include "Maladie.h"

using namespace std;


Maladie::Maladie()
{
}


Maladie::~Maladie()
{
}

int Maladie::get_id() { return id; }
string Maladie::get_nom() { return nom; }
string Maladie::get_typeMaladie() { return typeMaladie; }

void Maladie::set_id(int id_in) { id = id_in; }
void Maladie::set_nom(string name_in) { nom = name_in; }
void Maladie::set_typeMaladie(string name_in) { typeMaladie = name_in; }
