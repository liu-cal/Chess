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
	vector<unique_ptr<Modeles::Piece>> pieces_;

	void initialiserEchiquier();
	void on_ajouter_clicked();
	bool hasTwoDifferentColorPieces(const QString& pieceType) const;
};
