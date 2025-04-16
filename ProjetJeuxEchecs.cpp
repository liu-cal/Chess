#include "ProjetJeuxEchecs.h"
#include "modeles.hpp"
#include <QMessageBox>
#include <utility> 

using namespace std;

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::ProjetJeuxEchecsClass())
{
	ui->setupUi(this);
	initialiserEchiquier();
}

ProjetJeuxEchecs::~ProjetJeuxEchecs()
{
	delete ui;
}

void ProjetJeuxEchecs::initialiserEchiquier() {
	cases_.clear();
	tourBlanc_ = true;

	vector<string> colonnes = { "A", "B", "C", "D", "E", "F", "G", "H" };

	// Initialiser l'échiquier avec les pièces
	for (const string& c : colonnes) {
		for (int j = 1; j < 9; ++j) {
			string nomBouton = c + to_string(j);
			QPushButton* bouton = findChild<QPushButton*>(nomBouton);
			if (bouton) {
				cases_.push_back(bouton);

				connect(bouton, &QPushButton::clicked, this, [this, bouton]() {
					ui->position->setText(bouton->objectName());
					});
			}
			else {
				qWarning() << "Bouton non trouvé:" << QString::fromStdString(nomBouton);
			}
		}
	}

	connect(ui->ajouter, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_ajouter_clicked);
	connect(ui->enlever, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_enlever_clicked);
	connect(ui->start, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_start_clicked);
	connect(ui->terminer, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_terminer_clicked);

	mettreAJourStylesHover();

	ui->terminer->setVisible(false);
	ui->tourCouleur->setVisible(false);
}

void ProjetJeuxEchecs::on_ajouter_clicked() {
	QString typePiece = ui->piece->currentText();  // "Roi"
	QString couleur = ui->couleur->currentText();       // "Blanc"
	QString position = ui->position->text();    // e.g., "F8"

	if (position.isEmpty()) {
		qWarning() << "Aucune position sélectionnée.";
		return;
	}

	if (typePiece == "Roi" && Modeles::Roi::nbPieces_ == 2) {
		QMessageBox::warning(this, "Erreur", "Il y a déjà deux rois sur l'échiquier.");
		return;
	}

	QPushButton* caseBouton = findChild<QPushButton*>(position);
	if (!caseBouton) {
		qWarning() << "Bouton non trouvé pour la position:" << position;
		return;
	}
	if (caseBouton->text() != "") {
		QMessageBox::warning(this, "Erreur", "Il y a déjà une pièce sur cette case de l'échiquier. Veuiller enlevez la pièce si vous souhaitez la remplacer");
		return;
	}

	// Create the piece
	Modeles::Couleur couleurEnum = (couleur == "Blanc") ? Modeles::blanc : Modeles::noir;
	int x = position[0].toUpper().unicode() - 'A' + 1;
	int y = position[1].digitValue();

	unique_ptr<Modeles::Piece> piece = nullptr;
	if (typePiece == "Roi") {
		piece = make_unique<Modeles::Roi>(x, y, couleurEnum);
	}
	else if (typePiece == "Pion") {
		piece = make_unique<Modeles::Pion>(x, y, couleurEnum);
	}
	else if (typePiece == "Fou") {
		piece = make_unique<Modeles::Fou>(x, y, couleurEnum);
	}

	if (piece) {
		// Set button text to indicate piece and color
		QString pieceLabel = typePiece;
		pieceLabel += (couleur == "Blanc") ? "B" : "N";
		caseBouton->setText(pieceLabel);

		// Optional: store piece in a map if you want to manage it later
		pieces_[position] = std::move(piece);
	}
}

void ProjetJeuxEchecs::on_enlever_clicked() {
	QString position = ui->position->text();    // e.g., "F8"

	auto it = pieces_.find(position);
	if (it != pieces_.end()) {
		pieces_.erase(it);              // Enlève la pièce de la map

		// Met à jour l'interface : effacer le texte du bouton
		QPushButton* bouton = findChild<QPushButton*>(position);
		if (bouton) {
			bouton->setText("");
		}
	}
	else {
		qWarning() << "Aucune pièce trouvée à la position" << position;
	}
}

void ProjetJeuxEchecs::mettreAJourStylesHover() {
	QString hoverStyle;

	if (!tourBlanc_) {
		hoverStyle = "QPushButton:hover { background-color: lightgreen; }";
	}
	else {
		hoverStyle = "QPushButton:hover { background-color: lightcoral; }";
	}

	for (QPushButton* bouton : cases_) {
		QString originalStyle = bouton->styleSheet();

		// Remove any previous hover override to avoid stacking them
		QRegularExpression regex("QPushButton:hover\\s*\\{[^}]*\\}");
		originalStyle.remove(regex);

		// Append the new hover style
		QString updatedStyle = originalStyle.trimmed();

		updatedStyle += hoverStyle;

		bouton->setStyleSheet(updatedStyle);
	}
}

void ProjetJeuxEchecs::on_start_clicked() {
	ui->terminer->setVisible(true);
	ui->tourCouleur->setVisible(true);
	ui->tourCouleur->setText(tourBlanc_ ? "Tour Blanc" : "Tour Noir");
	ui->piece->setVisible(false);
	ui->couleur->setVisible(false);
	ui->position->setVisible(false);
	ui->ajouter->setVisible(false);
	ui->enlever->setVisible(false);
	ui->start->setVisible(false);
}

void ProjetJeuxEchecs::on_terminer_clicked() {
	ui->terminer->setVisible(false);
	ui->tourCouleur->setVisible(false);
	ui->piece->setVisible(true);
	ui->couleur->setVisible(true);
	ui->position->setVisible(true);
	ui->ajouter->setVisible(true);
	ui->enlever->setVisible(true);
	ui->start->setVisible(true);
}

