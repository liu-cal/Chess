#include "ProjetJeuxEchecs.h"
#include "modeles.hpp"
#include <QMessageBox>
#include <utility>

using namespace std;
using namespace Modeles;

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::ProjetJeuxEchecsClass())
{
    ui->setupUi(this);
    initialiserEchiquier();
}

ProjetJeuxEchecs::~ProjetJeuxEchecs() {
    delete ui;
}

void ProjetJeuxEchecs::initialiserEchiquier() {
    cases_.clear();
    tourBlanc_ = true;

    vector<string> colonnes = { "A", "B", "C", "D", "E", "F", "G", "H" };

    for (const string& c : colonnes) {
        for (int j = 1; j < 9; ++j) {
            string nomBouton = c + to_string(j);
            QPushButton* bouton = findChild<QPushButton*>(QString::fromStdString(nomBouton));
            if (bouton) {
                cases_.push_back(bouton);

                connect(bouton, &QPushButton::clicked, this, [this, bouton]() {
                    QString pos = bouton->objectName();
                    ui->position->setText(pos);

                    if (isStarted_) {
                        if (sourceSelection_.isEmpty()) {
                            sourceSelection_ = pos;
                        } else {
                            destinationSelection_ = pos;
                            deplacerPiece(sourceSelection_, destinationSelection_);
                            sourceSelection_.clear();
                            destinationSelection_.clear();
                        }
                    }
                });
            } else {
                qWarning() << "Bouton non trouv\xE9:" << QString::fromStdString(nomBouton);
            }
        }
    }

    connect(ui->start, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_start_clicked);
    connect(ui->terminer, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_terminer_clicked);

    ui->terminer->hide();
    ui->tourCouleur->setVisible(false);

    echiquier_.initialiserEchiquierStandard();

    for (QPushButton* bouton : cases_) {
        QString nom = bouton->objectName();
        int col = nom[0].unicode() - 'A' + 1;
        int row = nom[1].digitValue();
        const Piece* p = echiquier_.getPiece({col, row});

        if (p) {
            QString label;
            if (dynamic_cast<const Roi*>(p)) label = "Roi";
            else if (dynamic_cast<const Pion*>(p)) label = "Pion";
            else if (dynamic_cast<const Tour*>(p)) label = "Tour";
            else if (dynamic_cast<const Fou*>(p)) label = "Fou";
            else if (dynamic_cast<const Reine*>(p)) label = "Reine";
            else if (dynamic_cast<const Cavalier*>(p)) label = "Cav";
            label += (p->couleur_ == blanc) ? "B" : "N";
            bouton->setText(label);
        }
    }
}

void ProjetJeuxEchecs::on_start_clicked() {
    ui->terminer->show();
    ui->tourCouleur->setVisible(true);
    ui->tourCouleur->setText(tourBlanc_ ? "Tour Blanc" : "Tour Noir");
    ui->start->setVisible(false);
    isStarted_ = true;
}

void ProjetJeuxEchecs::on_terminer_clicked() {
    ui->terminer->setVisible(false);
    ui->tourCouleur->setVisible(false);
    ui->start->setVisible(true);
    isStarted_ = false;
}

void ProjetJeuxEchecs::deplacerPiece(const QString& from, const QString& to) {
    int fromX = from[0].toUpper().unicode() - 'A' + 1;
    int fromY = from[1].digitValue();
    int toX = to[0].toUpper().unicode() - 'A' + 1;
    int toY = to[1].digitValue();

    bool succes = echiquier_.deplacer({fromX, fromY}, {toX, toY});
    if (!succes) {
        QMessageBox::warning(this, "Déplacement invalide", "Ce déplacement n'est pas permis.");
        return;
    }

    QPushButton* fromButton = findChild<QPushButton*>(from);
    QPushButton* toButton = findChild<QPushButton*>(to);

    if (fromButton && toButton) {
        toButton->setText(fromButton->text());
        fromButton->setText("");
    }

    tourBlanc_ = (tourBlanc_ == blanc) ? noir : blanc;
    ui->tourCouleur->setText(tourBlanc_ ? "Tour Blanc" : "Tour Noir");
}
