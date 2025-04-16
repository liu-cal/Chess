#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjetJeuxEchecs.h"
#include <vector>        
#include <QPushButton>
#include "modeles.hpp"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class ProjetJeuxEchecsClass; };
QT_END_NAMESPACE

class ProjetJeuxEchecs : public QMainWindow
{
	Q_OBJECT

public:
	ProjetJeuxEchecs(QWidget* parent = nullptr);
	~ProjetJeuxEchecs();

private:
	Ui::ProjetJeuxEchecsClass* ui;

	vector<QPushButton*> cases_;
	unordered_map<QString, unique_ptr<Modeles::Piece>> pieces_;

	bool tourBlanc_;
	bool isStarted_ = false;

	QString sourceSelection_;  // First clicked position
	QString destinationSelection_;  // Second clicked position

	void initialiserEchiquier();
	void on_ajouter_clicked();
	bool hasTwoDifferentColorPieces(const QString& pieceType) const;
	void on_enlever_clicked();
	void mettreAJourStylesHover();
	void on_start_clicked();
	void on_terminer_clicked();
	void deplacerPiece(const QString& from, const QString& to);
};
