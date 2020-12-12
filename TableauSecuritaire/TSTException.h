/*
 * TSTException.h
 *
 *  Created on: 2020-12-05
 *      Author: etudiant
 */

#ifndef TSTEXCEPTION_H_
#define TSTEXCEPTION_H_

#include <stdexcept>
#include <sstream>

namespace TST {

class TSTLogicException: public std::logic_error {
public:
	TSTLogicException() : std::logic_error("Erreur dans la classe TableauSecuritaire") {};
	virtual std::string contexte() {return "Erreur dans la classe TableauSecuritaire";}
	virtual ~TSTLogicException() {};
};

class TSTIndiceHorsLimiteException : public TSTLogicException {
public:
	TSTIndiceHorsLimiteException(int p_indice) : TSTLogicException(), m_indice(p_indice) {}

	std::string contexte() {
		std::stringstream os;
		os << "L'indice: " << m_indice << " est hors-limite.";
		return os.str();
	}

private:
	int m_indice ;
};

class TSTEffacerTableauVideException : public TSTLogicException {
public:
	TSTEffacerTableauVideException() : TSTLogicException() {}
	std::string contexte() { return "Tentative de retirer un élément d'un tableau vide"; }
};

} /* namespace TST */

#endif /* TSTEXCEPTION_H_ */
