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
		Roi(int x, int y) : Piece(x, y) {};
		void deplacer(int x, int y) override{
			if (x > 0 && x < 8 && y>0 && y < 8 && 
				~x<x_ - 1 && ~x>x_ + 1 && ~y<y_ - 1 && ~y>y_ + 1) {
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
		Pion(int x, int y) : Piece(x, y) {};

		void deplacer(int x, int y) override{
			if (x > 0 && x < 8 && y>0 && y < 8 &&
				~x<x_ - 1 && ~x>x_ + 1 && ~y>y_ + 1) {
				x_ = x;
				y_ = y;
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Fou : public Piece {
		Fou(int x, int y) : Piece(x, y) {};

		void deplacer(int x, int y) override {
			if (x > 0 && x < 8 && y>0 && y < 8 &&
				~x<x_ - 1 && ~x>x_ + 1 && ~y>y_ + 1) {
				x_ = x;
				y_ = y;
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};
}
