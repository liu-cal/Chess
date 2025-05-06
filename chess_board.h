#pragma once

#include <unordered_map>
#include <memory>
#include <tuple>
#include "modeles.hpp"

namespace Modeles {

using Position = std::pair<int, int>; // (colonne, rangée)

struct HashPosition {
    size_t operator()(const Position& p) const {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class ChessBoard {
public:
    ChessBoard();

    void initialiserEchiquierStandard();
    bool ajouterPiece(Position pos, std::unique_ptr<Piece> piece);
    bool deplacer(Position from, Position to);
    bool estEchec(Couleur couleur) const;
    bool estEchecEtMat(Couleur couleur);
    const Piece* getPiece(Position pos) const;
    Couleur tourActuel() const;

private:
    std::unordered_map<Position, std::unique_ptr<Piece>, HashPosition> pieces_;
    Couleur tour_;

    bool deplacementValide(Piece* piece, Position from, Position to) const;
    Position trouverRoi(Couleur couleur) const;
};

}
