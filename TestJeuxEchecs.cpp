// Fichier de test pour le projet Jeux d'�checs
// Ce fichier contient les tests unitaires pour le projet Jeux d'�checs.
// Pour le moment, il y a seulement des tests d'exemple.
// Vous devez ajouter vos propres tests pour v�rifier le bon fonctionnement de votre code.
// 
// 
//
// Include ici les headers de votre partie de code � tester

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#include "modeles.hpp"
#endif
#ifdef TEST

// Vérifier le bon déplacement du Roi
TEST(TestRoi, deplacementValide)
{
	Modeles::Roi roi(4, 4, Modeles::blanc);

	try {
		roi.deplacer(5, 5);
		EXPECT_EQ(roi.x_, 5);
		EXPECT_EQ(roi.y_, 5);
	}
	catch (std::exception& e) {
		FAIL() << "Déplacement invalide pour un roi";
	}
}

TEST(TestRoi, DeplacementInvalide)
{
	Modeles::Roi roi(4, 4, Modeles::blanc);

	try {
		roi.deplacer(6, 6);
		FAIL() << "Deplacement invalide devrait avoir lancé une exception";
	}
	catch (std::invalid_argument& e) {
		EXPECT_STREQ(e.what(), "Mouvement invalide pour un roi");
	}
	catch (...) {
		FAIL() << "Type d'exception incorrect";
	}
}

TEST(TestRoi, MangerPieceAdverse)
{
	Modeles::Roi roi(4, 4, Modeles::blanc);
	Modeles::Roi adversaire(5, 5, Modeles::noir);

	try {
		roi.manger(adversaire);
		EXPECT_EQ(roi.x_, 5);
		EXPECT_EQ(roi.y_, 5);
	}
	catch (std::exception& e) {
		FAIL() << "Le roi blanc devrait pouvoir manger le roi noir";
	}
}

// Vérifier le bon déplacement du Pion
TEST(TestPion, DeplacementValide)
{
	Modeles::Pion pion(1, 1, Modeles::blanc);

	try {
		pion.deplacer(1, 2);
		EXPECT_EQ(pion.x_, 1);
		EXPECT_EQ(pion.y_, 2);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour un pion";
	}
}

TEST(TestPion, DeplacementInvalide)
{
	Modeles::Pion pion(1, 1, Modeles::blanc);

	try {
		pion.deplacer(1, 4);
		FAIL() << "Deplacement invalide devrait avoir lancé une exception";
	}
	catch (std::invalid_argument& e) {
		EXPECT_STREQ(e.what(), "Mouvement invalide pour un pion");
	}
	catch (...) {
		FAIL() << "Type d'exception incorrect";
	}
}

// Vérifier le bon déplacement du Fou
TEST(TestFou, DeplacementValide)
{
	Modeles::Fou fou(4, 4, Modeles::blanc);

	try {
		fou.deplacer(6, 6);
		EXPECT_EQ(fou.x_, 6);
		EXPECT_EQ(fou.y_, 6);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour un fou";
	}

	try {
		fou.deplacer(2, 2);
		EXPECT_EQ(fou.x_, 2);
		EXPECT_EQ(fou.y_, 2);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour un fou";
	}
}

TEST(TestFou, DeplacementInvalide)
{
	Modeles::Fou fou(4, 4, Modeles::blanc);

	try {
		fou.deplacer(4, 6);
		FAIL() << "Deplacement invalide devrait avoir lancé une exception";
	}
	catch (std::invalid_argument& e) {
		EXPECT_STREQ(e.what(), "Mouvement invalide pour un fou");
	}
	catch (...) {
		FAIL() << "Type d'exception incorrect";
	}
}

// Vérifier le bon déplacement du Cavalier
TEST(TestCavalier, DeplacementValide)
{
	Modeles::Cavalier cavalier(4, 4, Modeles::blanc);

	try {
		cavalier.deplacer(6, 5);
		EXPECT_EQ(cavalier.x_, 6);
		EXPECT_EQ(cavalier.y_, 5);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour un cavalier";
	}

	try {
		cavalier.deplacer(5, 3);
		EXPECT_EQ(cavalier.x_, 5);
		EXPECT_EQ(cavalier.y_, 3);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour un cavalier";
	}
}

TEST(TestCavalier, DeplacementInvalide)
{
	Modeles::Cavalier cavalier(4, 4, Modeles::blanc);

	try {
		cavalier.deplacer(4, 6);
		FAIL() << "Mouvement invalide devrait avoir lancé une exception";
	}
	catch (std::invalid_argument& e) {
		EXPECT_STREQ(e.what(), "Mouvement invalide pour un cavalier");
	}
	catch (...) {
		FAIL() << "Type d'exception incorrect";
	}
}

// Vérifier le bon déplacement du Reine
TEST(TestReine, DeplacementValide)
{
	Modeles::Reine reine(4, 4, Modeles::blanc);

	try {
		reine.deplacer(4, 6);
		EXPECT_EQ(reine.x_, 4);
		EXPECT_EQ(reine.y_, 6);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour une reine";
	}

	try {
		reine.deplacer(6, 6);
		EXPECT_EQ(reine.x_, 6);
		EXPECT_EQ(reine.y_, 6);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour une reine";
	}

	try {
		reine.deplacer(2, 2);
		EXPECT_EQ(reine.x_, 2);
		EXPECT_EQ(reine.y_, 2);
	}
	catch (std::exception& e) {
		FAIL() << "Mouvement invalide pour une reine";
	}
}

TEST(TestReine, DeplacementInvalide)
{
	Modeles::Reine reine(4, 4, Modeles::blanc);

	try {
		reine.deplacer(5, 7);
		FAIL() << "Deplacement invalide devrait avoir lancé une exception";
	}
	catch (std::invalid_argument& e) {
		EXPECT_STREQ(e.what(), "Mouvement invalide pour une reine");
	}
	catch (...) {
		FAIL() << "Type d'exception incorrect";
	}
}

//Vérifier l'échiquier
//TEST(TestEchiquier, Initialisation)
//{
//	ProjetJeuxEchecs jeu;
//
//	QPushButton* caseA1 = findChild<QPushButton*>("A1");
//	EXPECT_EQ(caseA1->text(), "TourB");
//
//	QPushButton* caseE1 = findChild<QPushButton*>("E1");
//	EXPECT_EQ(caseE1->text(), "RoiB");
//
//	QPushButton* caseD4 = findChild<QPushButton*>("D4");
//	EXPECT_EQ(caseD4->text(), "");
//}

//Vérifier le changement de tour
//TEST(TestTour, ChangementTour)
//{
//	ProjetJeuxEchecs jeu;
//
//	EXPECT_TRUE(jeu.isTourBlanc());
//
//	jeu.deplacerPiece("E2", "E4");
//
//	EXPECT_FALSE(jeu.isTourBlanc());
//
//	jeu.deplacerPiece("E7", "E5");
//
//	EXPECT_TRUE(jeu.isTourBlanc());
//}

#endif
