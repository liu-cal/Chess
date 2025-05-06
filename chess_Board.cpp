#include "chess_Board.h"

namespace Modeles {

ChessBoard::ChessBoard() : tour_(Couleur::blanc) {}

bool ChessBoard::ajouterPiece(Position pos, std::unique_ptr<Piece> piece) {
    if (pieces_.count(pos)) return false;
    pieces_[pos] = std::move(piece);
    return true;
}

bool ChessBoard::deplacer(Position from, Position to) {
    if (!pieces_.count(from)) return false;

    Piece* piece = pieces_[from].get();
    if (piece->couleur_ != tour_) return false;

    auto sauvegarde = std::move(pieces_[from]);
    std::unique_ptr<Piece> cible = nullptr;
    if (pieces_.count(to)) {
        if (dynamic_cast<Roi*>(pieces_[to].get())) return false;
        cible = std::move(pieces_[to]);
    }

    try {
        if (cible) piece->manger(*cible);
        piece->deplacer(to.first, to.second);
        pieces_[to] = std::move(sauvegarde);
        pieces_.erase(from);

        if (estEchec(tour_)) {
            pieces_[from] = std::move(pieces_[to]);
            if (cible) pieces_[to] = std::move(cible);
            else pieces_.erase(to);
            return false;
        }

        tour_ = (tour_ == Couleur::blanc) ? Couleur::noir : Couleur::blanc;
        return true;

    } catch (...) {
        pieces_[from] = std::move(sauvegarde);
        if (cible) pieces_[to] = std::move(cible);
        return false;
    }
}

Position ChessBoard::trouverRoi(Couleur couleur) const {
    for (const auto& [pos, piece] : pieces_) {
        if (piece->couleur_ == couleur && dynamic_cast<Roi*>(piece.get())) {
            return pos;
        }
    }
    throw std::runtime_error("Roi introuvable");
}

bool ChessBoard::estEchec(Couleur couleur) const {
    Position roi = trouverRoi(couleur);

    for (const auto& [pos, piece] : pieces_) {
        if (piece->couleur_ != couleur) {
            try {
                std::unique_ptr<Piece> clone = piece->clone();
                clone->deplacer(roi.first, roi.second);
                return true;
            } catch (...) {
            }
        }
    }
    return false;
}

bool ChessBoard::estEchecEtMat(Couleur couleur) {
    if (!estEchec(couleur)) return false;

    for (const auto& [from, piece] : pieces_) {
        if (piece->couleur_ != couleur) continue;

        for (int c = 1; c <= 8; ++c) {
            for (int r = 1; r <= 8; ++r) {
                Position to = { c, r };
                if (from == to) continue;

                try {
                    std::unique_ptr<Piece> temp = piece->clone();
                    temp->deplacer(to.first, to.second);  // Valide le mouvement

                    ChessBoard simulation;
                    for (const auto& [pos, ptr] : this->pieces_) {
                        simulation.ajouterPiece(pos, ptr->clone());
                    }
                    simulation.deplacer(from, to);

                    if (!simulation.estEchec(couleur)) {
                        return false; // Un coup possible qui sort du mat
                    }
                } catch (...) {
                    continue;
                }
            }
        }
    }
    return true;
}

const Piece* ChessBoard::getPiece(Position pos) const {
    auto it = pieces_.find(pos);
    return (it != pieces_.end()) ? it->second.get() : nullptr;
}

Couleur ChessBoard::tourActuel() const {
    return tour_;
}

}

void Modeles::ChessBoard::initialiserEchiquierStandard() {
    using namespace std;

    // Pions blancs
    for (int col = 1; col <= 8; ++col) {
        ajouterPiece({col, 2}, make_unique<Pion>(col, 2, blanc));
    }

    // Pions noirs
    for (int col = 1; col <= 8; ++col) {
        ajouterPiece({col, 7}, make_unique<Pion>(col, 7, noir));
    }

    // Pièces blanches
    ajouterPiece({1, 1}, make_unique<Tour>(1, 1, blanc));
    ajouterPiece({2, 1}, make_unique<Cavalier>(2, 1, blanc));
    ajouterPiece({3, 1}, make_unique<Fou>(3, 1, blanc));
    ajouterPiece({4, 1}, make_unique<Reine>(4, 1, blanc));
    ajouterPiece({5, 1}, make_unique<Roi>(5, 1, blanc));
    ajouterPiece({6, 1}, make_unique<Fou>(6, 1, blanc));
    ajouterPiece({7, 1}, make_unique<Cavalier>(7, 1, blanc));
    ajouterPiece({8, 1}, make_unique<Tour>(8, 1, blanc));

    // Pièces noires
    ajouterPiece({1, 8}, make_unique<Tour>(1, 8, noir));
    ajouterPiece({2, 8}, make_unique<Cavalier>(2, 8, noir));
    ajouterPiece({3, 8}, make_unique<Fou>(3, 8, noir));
    ajouterPiece({4, 8}, make_unique<Reine>(4, 8, noir));
    ajouterPiece({5, 8}, make_unique<Roi>(5, 8, noir));
    ajouterPiece({6, 8}, make_unique<Fou>(6, 8, noir));
    ajouterPiece({7, 8}, make_unique<Cavalier>(7, 8, noir));
    ajouterPiece({8, 8}, make_unique<Tour>(8, 8, noir));
}

