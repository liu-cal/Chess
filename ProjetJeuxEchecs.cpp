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
					QString pos = bouton->objectName();

					QString pieceText = bouton->text();
					QChar lastChar;

					QChar turnColor;

					ui->position->setText(pos);  // Optionally show in GUI

					if (isStarted_) {
						if (sourceSelection_.isEmpty()) {
							if (!pieceText.isEmpty()) {

								turnColor = ui->tourCouleur->text().split(' ').last().at(0);
								lastChar = pieceText.at(pieceText.length() - 1);

								// Check if piece color matches current turn
								//if (lastChar == turnColor) {
								sourceSelection_ = pos;
								/*}
								else {
									QMessageBox::warning(this, "Mauvais tour",
										"Ce n'est pas votre tour de jouer !");
								}*/
							}
						}
						else {
							destinationSelection_ = pos;
							deplacerPiece(sourceSelection_, destinationSelection_);

							// Reset selections
							sourceSelection_.clear();
							destinationSelection_.clear();
						}
					}

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

	ui->terminer->hide();
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
	else if (typePiece == "Reine") {
		piece = make_unique<Modeles::Reine>(x, y, couleurEnum);
	}
	else if (typePiece == "Cavalier") {
		piece = make_unique<Modeles::Cavalier>(x, y, couleurEnum);
	}
	else if (typePiece == "Tour") {
		piece = make_unique<Modeles::Tour>(x, y, couleurEnum);
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

	if (tourBlanc_) {
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
	ui->terminer->show();
	ui->tourCouleur->setVisible(true);
	ui->tourCouleur->setText(tourBlanc_ ? "Tour Blanc" : "Tour Noir");
	ui->piece->setVisible(false);
	ui->couleur->setVisible(false);
	ui->position->setVisible(false);
	ui->ajouter->setVisible(false);
	ui->enlever->setVisible(false);
	ui->start->setVisible(false);

	isStarted_ = true;
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

	isStarted_ = false;
}

void ProjetJeuxEchecs::deplacerPiece(const QString& from, const QString& to) {


	// Convert positions to coordinates
	int fromX = from[0].toUpper().unicode() - 'A' + 1;
	int fromY = from[1].digitValue();
	int toX = to[0].toUpper().unicode() - 'A' + 1;
	int toY = to[1].digitValue();

	// Check if source position has a piece
	auto it = pieces_.find(from);
	if (it == pieces_.end()) {
		qWarning() << "Aucune pièce à déplacer de la position" << from;
		return;
	}

	if (roiEnEchecApresDeplacement(from, to)) {
		QMessageBox::warning(this, "Échec", "Ce déplacement mettrait votre roi en échec.");
		return;
	}

	// Get the piece
	std::unique_ptr<Modeles::Piece>& piece = it->second;

	// Check if move is valid for this piece type
	{
		// Temporary move validation using DeplacementTemporaire
		try {
			Modeles::DeplacementTemporaire tempMove(*piece, toX, toY);
		}
		catch (...) {
			QMessageBox::warning(this, "Mouvement invalide",
				"Ce mouvement n'est pas autorisé pour cette pièce.");
			return;
		}
	}

	// Check if target position has a piece (capture)
	if (pieces_.contains(to)) {
		auto& targetPiece = pieces_[to];

		// Check if same color
		if (targetPiece->couleur_ == piece->couleur_) {
			QMessageBox::warning(this, "Erreur",
				"Vous ne pouvez pas capturer une pièce de votre propre couleur.");
			return;
		}

		// Validate capture move for this piece type
		try {
			piece->manger(*targetPiece);
		}
		catch (...) {
			QMessageBox::warning(this, "Capture invalide",
				"Cette pièce ne peut pas capturer de cette manière.");
			return;
		}

		// Remove captured piece
		pieces_.erase(to);
	}

	// Move the piece
	std::unique_ptr<Modeles::Piece> movedPiece = std::move(it->second);
	pieces_.erase(it);

	// Update coordinates inside the piece object
	movedPiece->x_ = toX;
	movedPiece->y_ = toY;

	// Update UI
	QPushButton* fromButton = findChild<QPushButton*>(from);
	QPushButton* toButton = findChild<QPushButton*>(to);

	if (toButton && fromButton) {
		toButton->setText(fromButton->text());
		fromButton->setText("");
	}

	// Store the piece at new location
	pieces_[to] = std::move(movedPiece);

	// Switch turns
	tourBlanc_ = (tourBlanc_ == Modeles::blanc) ? Modeles::noir : Modeles::blanc;
	ui->tourCouleur->setText(tourBlanc_ ? "Tour Blanc" : "Tour Noir");
}

bool ProjetJeuxEchecs::roiEnEchecApresDeplacement(const QString& from, const QString& to) {
	// Copier les pièces temporairement
	std::unordered_map<QString, std::unique_ptr<Modeles::Piece>> piecesBackup;
	for (const auto& it : pieces_) {
		piecesBackup[it.first] = std::unique_ptr<Modeles::Piece>(it.second->clone()); // Assure-toi que clone() existe
	}

	// Simuler le déplacement
	auto it = piecesBackup.find(from);
	if (it == piecesBackup.end()) return false;

	std::unique_ptr<Modeles::Piece> tempPiece = std::move(it->second);
	piecesBackup.erase(it);

	if (piecesBackup.contains(to)) {
		piecesBackup.erase(to);  // Simule la capture
	}

	tempPiece->x_ = to[0].toUpper().unicode() - 'A' + 1;
	tempPiece->y_ = to[1].digitValue();
	piecesBackup[to] = std::move(tempPiece);

	// Chercher le roi de la couleur de la pièce déplacée
	Modeles::Couleur couleur = piecesBackup[to]->couleur_;
	int roiX = -1, roiY = -1;
	for (const auto& pair : piecesBackup) {
		if (auto* roi = dynamic_cast<Modeles::Roi*>(pair.second.get())) {
			if (roi->couleur_ == couleur) {
				roiX = roi->x_;
				roiY = roi->y_;
				break;
			}
		}
	}

	// Si le roi n'est pas trouvé (ce qui ne devrait jamais arriver)
	if (roiX == -1 || roiY == -1) return true;

	// Vérifie si une pièce ennemie peut capturer le roi
	for (const auto& pair : piecesBackup) {
		if (pair.second->couleur_ != couleur) {
			try {
				Modeles::DeplacementTemporaire temp(*pair.second, roiX, roiY);
				return true; // Une pièce ennemie peut atteindre le roi
			}
			catch (...) {
				// Ne peut pas atteindre, on continue
			}
		}
	}

	return false;
}
