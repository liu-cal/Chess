#pragma once

#include <string>
#include <stdexcept>
#include <memory>

using namespace std;

namespace Modeles {
enum Couleur {
    blanc, noir
};

class Piece {
public:
    Piece(int colonne, int rangee, Couleur couleur)
        : colonne_(colonne), rangee_(rangee), couleur_(couleur) {};

    virtual void deplacer(int colonne, int rangee) = 0;
    virtual void manger(const Piece& piece) = 0;
    virtual unique_ptr<Piece> clone() const = 0;
    virtual ~Piece() = default;

    int colonne_, rangee_;
    Couleur couleur_;
};

class Roi : public Piece {
public:
    Roi(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) { ++nbPieces_; };

    void deplacer(int colonne, int rangee) override {
        if ((abs(colonne_ - colonne) <= 1) && (abs(rangee_ - rangee) <= 1) &&
            colonne >= 1 && colonne < 9 && rangee >= 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour un roi");
        }
    }

    void manger(const Piece& piece) override {
        if (piece.couleur_ != this->couleur_) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Roi>(*this); }

    ~Roi() {
        --nbPieces_;
    }

    static int nbPieces_;
};

class Pion : public Piece {
public:
    Pion(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) {};

    void deplacer(int colonne, int rangee) override {
        if (couleur_ == blanc && colonne == colonne_ && rangee == rangee_ + 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else if (couleur_ == noir && colonne == colonne_ && rangee == rangee_ - 1 && rangee >= 1) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour un pion");
        }
    };

    void manger(const Piece& piece) override {
        if (couleur_ == blanc && piece.couleur_ != couleur_ &&
            abs(colonne_ - piece.colonne_) == 1 && rangee_ + 1 == piece.rangee_) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
        else if (couleur_ == noir && piece.couleur_ != couleur_ &&
                 abs(colonne_ - piece.colonne_) == 1 && rangee_ - 1 == piece.rangee_) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Pion>(*this); }
};

class Fou : public Piece {
public:
    Fou(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) {};

    void deplacer(int colonne, int rangee) override {
        if (abs(colonne - colonne_) == abs(rangee - rangee_) &&
            colonne >= 1 && colonne < 9 && rangee >= 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour un fou");
        }
    };

    void manger(const Piece& piece) override {
        if (piece.couleur_ != this->couleur_ &&
            abs(colonne_ - piece.colonne_) == abs(rangee_ - piece.rangee_)) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Fou>(*this); }
};

class Tour : public Piece {
public:
    Tour(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) {};

    void deplacer(int colonne, int rangee) override {
        if ((colonne == colonne_ || rangee == rangee_) &&
            colonne >= 1 && colonne < 9 && rangee >= 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour une tour");
        }
    };

    void manger(const Piece& piece) override {
        if (piece.couleur_ != this->couleur_ &&
            (colonne_ == piece.colonne_ || rangee_ == piece.rangee_)) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Tour>(*this); }
};

class Cavalier : public Piece {
public:
    Cavalier(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) {};

    void deplacer(int colonne, int rangee) override {
        if (((abs(colonne - colonne_) == 2 && abs(rangee - rangee_) == 1) ||
             (abs(colonne - colonne_) == 1 && abs(rangee - rangee_) == 2)) &&
            colonne >= 1 && colonne < 9 && rangee >= 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour un cavalier");
        }
    };

    void manger(const Piece& piece) override {
        if (piece.couleur_ != this->couleur_ &&
            ((abs(colonne_ - piece.colonne_) == 2 && abs(rangee_ - piece.rangee_) == 1) ||
             (abs(colonne_ - piece.colonne_) == 1 && abs(rangee_ - piece.rangee_) == 2))) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Cavalier>(*this); }
};

class Reine : public Piece {
public:
    Reine(int colonne, int rangee, Couleur couleur) : Piece(colonne, rangee, couleur) {};

    void deplacer(int colonne, int rangee) override {
        if ((colonne == colonne_ || rangee == rangee_ || abs(colonne - colonne_) == abs(rangee - rangee_)) &&
            colonne >= 1 && colonne < 9 && rangee >= 1 && rangee < 9) {
            colonne_ = colonne;
            rangee_ = rangee;
        }
        else {
            throw std::invalid_argument("Mouvement invalide pour une reine");
        }
    };

    void manger(const Piece& piece) override {
        if (piece.couleur_ != this->couleur_ &&
            (colonne_ == piece.colonne_ || rangee_ == piece.rangee_ || abs(colonne_ - piece.colonne_) == abs(rangee_ - piece.rangee_))) {
            this->colonne_ = piece.colonne_;
            this->rangee_ = piece.rangee_;
        }
    }

    unique_ptr<Piece> clone() const override { return make_unique<Reine>(*this); }
};

class DeplacementTemporaire {
public:
    DeplacementTemporaire(Piece& piece, int colonneTemporaire, int rangeeTemporaire)
        : piece_(piece), colonneOriginale_(piece.colonne_), rangeeOriginale_(piece.rangee_) {
        try {
            piece_.deplacer(colonneTemporaire, rangeeTemporaire);
        }
        catch (exception& e) {
            throw;
        }
    }

    ~DeplacementTemporaire() {
        piece_.colonne_ = colonneOriginale_;
        piece_.rangee_ = rangeeOriginale_;
    }

private:
    Piece& piece_;
    int colonneOriginale_, rangeeOriginale_;
};
}
