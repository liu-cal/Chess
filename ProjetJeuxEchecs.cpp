#include "ProjetJeuxEchecs.h"
#include "modeles.hpp"

using namespace std;

ProjetJeuxEchecs::ProjetJeuxEchecs(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::ProjetJeuxEchecsClass())
{
	ui->setupUi(this);
	initialiserEchiquier();
	connect(ui->ajouter, &QPushButton::clicked, this, &ProjetJeuxEchecs::on_ajouter_clicked);

}

ProjetJeuxEchecs::~ProjetJeuxEchecs()
{
	delete ui;
}

void ProjetJeuxEchecs::initialiserEchiquier() {
	cases_.clear();

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
}

void ProjetJeuxEchecs::on_ajouter_clicked() {
	QString typePiece = ui->piece->currentText();  // "Roi"
	QString couleur = ui->couleur->currentText();       // "Blanc"
	QString position = ui->position->text();    // e.g., "F8"

	if (position.isEmpty()) {
		qWarning() << "Aucune position sélectionnée.";
		return;
	}

	QPushButton* caseBouton = findChild<QPushButton*>(position);
	if (!caseBouton) {
		qWarning() << "Bouton non trouvé pour la position:" << position;
		return;
	}

	// Create the piece
	Modeles::Couleur couleurEnum = (couleur == "Blanc") ? Modeles::blanc : Modeles::noir;
	int x = position[0].toUpper().unicode() - 'A' + 1;
	int y = position[1].digitValue();

	Modeles::Piece* piece = nullptr;
	if (typePiece == "Roi") {
		piece = new Modeles::Roi(x, y, couleurEnum);
	}
	else if (typePiece == "Pion") {
		piece = new Modeles::Pion(x, y, couleurEnum);
	}
	else if (typePiece == "Fou") {
		piece = new Modeles::Fou(x, y, couleurEnum);
	}

	if (piece) {
		// Set button text to indicate piece and color
		QString pieceLabel = typePiece;
		pieceLabel += (couleur == "Blanc") ? "B" : "N";
		caseBouton->setText(pieceLabel);

		// Optional: store piece in a map or vector if you want to manage it later
		// pieces_.push_back(piece); // for example
	}
}

