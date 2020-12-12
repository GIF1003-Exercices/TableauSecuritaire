/*
 * testeur.cpp
 *
 *  Created on: 2020-12-05
 *      Author: etudiant
 */
#include "TableauSecuritaire.hpp"
#include "gtest/gtest.h"

#include <string>

using namespace TST ;

TEST(TableauSecuritaireInt, constructionParDefautNoExcept)
{
	EXPECT_NO_THROW(TableauSecuritaire<int> t) ;
}

TEST(TableauSecuritaire, constructionParDefautVide)
{
	TableauSecuritaire<int> t ;
	EXPECT_EQ(t.taille(), 0) ;
}

TEST(TableauSecuritaire, constructionParValeurNoExcept)
{
	EXPECT_NO_THROW(TableauSecuritaire<double> t(5, 1)) ;
}

TEST(TableauSecuritaire, constructionParValeurCorrectementInitialiseInt)
{
	TableauSecuritaire<int> t(3, 1) ;
	EXPECT_EQ(t.taille(), 3) ;
	EXPECT_EQ(t.req(0), 1) ;
	EXPECT_EQ(t.req(1), 1) ;
	EXPECT_EQ(t.req(2), 1) ;
}

TEST(TableauSecuritaire, constuctionParValeurCorrectementInitialiseString)
{
	TableauSecuritaire<std::string> t(3, "Allo");
	EXPECT_EQ(t.taille(), 3) ;
	EXPECT_EQ(t.req(0), "Allo") ;
	EXPECT_EQ(t.req(1), "Allo") ;
	EXPECT_EQ(t.req(2), "Allo") ;
}

TEST(TableauSecuritaire, constructeurCopie)
{
	TableauSecuritaire<int> t(3, 1);

	TableauSecuritaire<int> v(t);

	EXPECT_EQ(v.taille(), 3);
	EXPECT_EQ(v.req(0), 1);
	EXPECT_EQ(v.req(1), 1);
	EXPECT_EQ(v.req(2), 1);
}

TEST(TableauSecuritaire, annexer)
{
	TableauSecuritaire<std::string> t;

	EXPECT_EQ(t.taille(), 0);

	t.annexer("Allo");
	EXPECT_EQ(t.taille(), 1);
	EXPECT_EQ(t.req(0), "Allo");

	t.annexer("Le monde");
	EXPECT_EQ(t.taille(), 2);
	EXPECT_EQ(t.req(0), "Allo");
	EXPECT_EQ(t.req(1), "Le monde");
}

TEST(TableauSecuritaire, retirer)
{
	TableauSecuritaire<int> t;
	t.annexer(0);
	t.annexer(1);
	t.annexer(2);

	EXPECT_EQ(t.retirer(), 2);
	EXPECT_EQ(t.taille(), 2);
	EXPECT_EQ(t.req(0), 0);
	EXPECT_EQ(t.req(1), 1);

	EXPECT_EQ(t.retirer(), 1);
	EXPECT_EQ(t.taille(), 1);
	EXPECT_EQ(t.req(0), 0);

	EXPECT_EQ(t.retirer(), 0);
	EXPECT_EQ(t.taille(), 0);
}

TEST(TableauSecuritaire, retirerDansTableauVide)
{
	TableauSecuritaire<int> t;

	EXPECT_THROW(t.retirer(), TSTEffacerTableauVideException);
}


TEST(TableauSecuritaire, reqHorsLimite)
{
	TableauSecuritaire<int> t(10, 7);

	EXPECT_NO_THROW(t.req(7));
	EXPECT_THROW(t.req(-1), TSTIndiceHorsLimiteException);
	EXPECT_THROW(t.req(10), TSTIndiceHorsLimiteException);
}
TEST(TableauSecuritaire, operateurBracketsLire)
{
	TableauSecuritaire<double> t(1, 3.5);

	EXPECT_EQ(t[0], 3.5);
}

TEST(TableauSecuritaire, operateurBracketEcrire)
{
	TableauSecuritaire<std::string> t(2, "A");

	t[1] = "B";
	EXPECT_EQ(t[0], "A");
	EXPECT_EQ(t[1], "B");
}

TEST(TableauSecuritaire, operateurBracketIndiceHorsLimite)
{
	TableauSecuritaire<int> t(5, 1);
	EXPECT_THROW(t[-1], TSTIndiceHorsLimiteException);
	EXPECT_THROW(t[5], TSTIndiceHorsLimiteException);
}

TEST(TableauSecuritaire, operateurAffectation)
{
	TableauSecuritaire<int> t(3, 1);
	TableauSecuritaire<int> v;
	TableauSecuritaire<int> w;

	v = t;
	EXPECT_EQ(v.taille(), 3);
	EXPECT_EQ(v[0], 1);
	EXPECT_EQ(v[1], 1);
	EXPECT_EQ(v[2], 1);

	v = w;
	EXPECT_EQ(v.taille(), 0);

}



