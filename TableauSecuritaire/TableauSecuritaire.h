/*
 * TableauSecuritaire.h
 *
 *  Created on: 2020-12-05
 *      Author: etudiant
 */

#ifndef TABLEAUSECURITAIRE_H_
#define TABLEAUSECURITAIRE_H_

#include <cstddef>

namespace TST {

const int MAX_CARDINAL = 50;

template <typename T>
class TableauSecuritaire {
public:
	TableauSecuritaire();
	TableauSecuritaire(int , T valeur) ;
	TableauSecuritaire(const TableauSecuritaire<T>&) ;

	bool operator == (const TableauSecuritaire<T>&) ;
	TableauSecuritaire<T>& operator = (const TableauSecuritaire<T>&) ;
	T& operator[] (int) ;

	int taille() const ;
	void annexer(const T&) ;
	T retirer() ;

	const T& req(int) const ;

	virtual ~TableauSecuritaire();

private:
	int m_cardinal;
	T* m_adresse;

	static bool cardinalEstPossible(int) ;
	static bool cardinalEstAllouable(int) ;
	static T* allouer(int) ;
	bool indiceEstValide(int) const ;
	bool adresseEstValide() const;
	void verifieInvariant() const ;

};

} /* namespace TST */

#endif /* TABLEAUSECURITAIRE_H_ */
