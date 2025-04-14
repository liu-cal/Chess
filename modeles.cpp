#pragma once

#include <string>

using namespace std;

namespace Modeles {
	enum Couleur {
		blanc, noir
	};

	class Piece {
	public:
		Piece(int x, int y) : x_(x), y_(y) {};
		virtual void deplacer(int x, int y) = 0;

		virtual void manger(const Piece& piece) = 0;

		virtual ~Piece() = default;

		int x_, y_;
		static int nbPieces_;
		Couleur couleur_;
	};

	class Roi : public Piece {
	// j'ai modifier le void deplacer
	public:
		Roi(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};
		void deplacer(int x, int y) override{
			if ((abs(x_ - x) <= 1) && (abs(y_ - y) <= 1) && x >= 0 && x < 8 && y >= 0 && y < 8) {
				x_ = x;
				y_ = y;
			}
		}
		
		void manger(const Piece& piece) override{
			if (piece.couleur_ != this->couleur_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Pion : public Piece {
	public:
		Pion(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override{
			if (couleur_ == blanc && x == x_ && y == y_ + 1 && y < 8) {
				x_ = x;
				y_ = y;
			}
			else if (couleur_ == noir && x == x_ && y == y_ - 1 && y >= 0) {
				x_ = x;
				y_ = y;
			}
		};

		// Pour que le pion mange en diagonale
		void manger(const Piece& piece) override {
			if (couleur_ == blanc && piece.couleur_ != couleur_ && abs(x_ - piece.x_) == 1 && y_ + 1 == piece.y_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
			else if (couleur_ == noir && piece.couleur_ != couleur_ && abs(x_ - piece.x_) == 1 && y_ - 1 == piece.y_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Fou : public Piece {
	public:
		Fou(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if (abs(x - x_) == abs(y - y_) && x >= 0 && x < 8 && y >= 0 && y < 8) {
				x_ = x;
				y_ = y;
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_ && abs(x_ - piece.x_) == abs(y_ - piece.y_)) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};
}

