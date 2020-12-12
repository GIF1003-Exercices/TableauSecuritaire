/*
 * TableauSecuritaire.hpp
 *
 *  Created on: 2020-12-05
 *      Author: etudiant
 */

#include "TableauSecuritaire.h"
#include "ContratException.h"
#include "TSTException.h"

namespace TST {

template <typename T>
bool TableauSecuritaire<T>::cardinalEstPossible(int n)
{
	return (n >= 0) and (n <= MAX_CARDINAL);
}

template <typename T>
bool TableauSecuritaire<T>::cardinalEstAllouable(int n)
{
	return ( n != 0 ) and cardinalEstPossible(n) ;
}

template <typename T>
bool TableauSecuritaire<T>::indiceEstValide(int n) const
{
	return (n >= 0) and (n < m_cardinal);
}

template <typename T>
bool TableauSecuritaire<T>::adresseEstValide() const
{
	bool adresseNulle = (m_adresse == nullptr);
	return (m_cardinal == 0) ? adresseNulle : !adresseNulle ;
}

template <typename T>
void TableauSecuritaire<T>::verifieInvariant() const
{
	INVARIANT(cardinalEstPossible(m_cardinal));
	INVARIANT(adresseEstValide());
}

template <typename T>
T* TableauSecuritaire<T>::allouer(int i)
{
	PRECONDITION(cardinalEstPossible(i));
	return (i == 0) ? nullptr : new T [i] ;
}

template <typename T>
TableauSecuritaire<T>::TableauSecuritaire() : m_cardinal(0), m_adresse(nullptr) {
	INVARIANTS();
};

template <typename T>
TableauSecuritaire<T>::TableauSecuritaire(int n, T valeur) : TableauSecuritaire() {
	PRECONDITION( cardinalEstAllouable(n)) ;

	m_cardinal = n ;
	m_adresse = new T[m_cardinal] ;
	for (int i = 0; i < m_cardinal; ++i)
		m_adresse[i] = valeur ;

	INVARIANTS();

}

template <typename T>
TableauSecuritaire<T>::TableauSecuritaire(const TableauSecuritaire<T>& rhs) : m_cardinal(rhs.m_cardinal), m_adresse(TableauSecuritaire<T>::allouer(rhs.m_cardinal))
{
	for (int i = 0; i < m_cardinal; ++i)
	{
		m_adresse[i] = rhs.m_adresse[i];
	}
	INVARIANTS();
}

template <typename T>
int TableauSecuritaire<T>::taille() const
{
	return m_cardinal ;
}

template <typename T>
void TableauSecuritaire<T>::annexer(const T& element)
{
    T* nouveau = TableauSecuritaire<T>::allouer(m_cardinal + 1);
    for (int i = 0; i < m_cardinal; ++i)
    	nouveau[i] = m_adresse[i];
    nouveau[m_cardinal] = element;

    delete [] m_adresse;
    m_adresse = nouveau;
    m_cardinal += 1;

    INVARIANTS();
}

template <typename T>
T TableauSecuritaire<T>::retirer()
{
	if (m_cardinal == 0) throw TSTEffacerTableauVideException() ;
	PRECONDITION(cardinalEstAllouable(m_cardinal));

    T* nouveau = TableauSecuritaire<T>::allouer(m_cardinal - 1);
    for (int i = 0; i < (m_cardinal - 1); ++i)
    {
    	nouveau[i] = m_adresse[i];
    }
    T valeur = m_adresse[m_cardinal - 1];
    m_cardinal -= 1;

    delete [] m_adresse;
    m_adresse = nouveau;

    INVARIANTS();
    return valeur;
}

template <typename T>
T& TableauSecuritaire<T>::operator[] (int i)
{
	if ( !TableauSecuritaire<T>::indiceEstValide(i) ) throw TSTIndiceHorsLimiteException(i);
	return m_adresse[i] ;
}

template <typename T>
TableauSecuritaire<T>& TableauSecuritaire<T>::operator = (const TableauSecuritaire<T>& rhs)
{
	if ( ! (this == &rhs) )
	{
		T* nouveau = TableauSecuritaire<T>::allouer(rhs.m_cardinal);
		for (int i = 0; i < rhs.m_cardinal; ++i)
		{
			nouveau[i] = rhs.m_adresse[i];
		}
		delete [] m_adresse;
		m_adresse = nouveau;
		m_cardinal = rhs.m_cardinal;

		INVARIANTS();
	}
	return *this;

}

template <typename T>
const T& TableauSecuritaire<T>::req(int i) const
{
	if (!TableauSecuritaire<T>::indiceEstValide(i)) throw TSTIndiceHorsLimiteException(i);
	PRECONDITION(TableauSecuritaire<T>::indiceEstValide(i));
	return m_adresse[i] ;
}

template <typename T>
TableauSecuritaire<T>::~TableauSecuritaire() {
	delete [] m_adresse ;
}

} /* namespace TST */
