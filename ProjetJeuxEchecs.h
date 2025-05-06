#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProjetJeuxEchecs.h"
#include <vector>
#include <QPushButton>
#include "modeles.hpp"
#include "chess_Board.h"

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

    Modeles::ChessBoard echiquier_; // Remplace la map de pièces

    bool tourBlanc_;
    bool isStarted_ = false;

    QString sourceSelection_;
    QString destinationSelection_;

    void initialiserEchiquier();
    void on_ajouter_clicked();
    void on_enlever_clicked();
    void mettreAJourStylesHover();
    void on_start_clicked();
    void on_terminer_clicked();
    void deplacerPiece(const QString& from, const QString& to);
    bool roiEnEchecApresDeplacement(const QString& from, const QString& to);
};
