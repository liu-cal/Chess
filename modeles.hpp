#pragma once

#include <string>

using namespace std;

namespace Modeles {
	enum Couleur {
		blanc, noir
	};

	class Piece {
	public:
		Piece(int x, int y, Couleur couleur) : x_(x), y_(y), couleur_(couleur) {};

		virtual void deplacer(int x, int y) = 0;

		virtual void manger(const Piece& piece) = 0;

		virtual ~Piece() = default;

		int x_, y_;
		Couleur couleur_;
	};

	class Roi : public Piece {
	public:
		Roi(int x, int y, Couleur couleur) : Piece(x, y, couleur) { ++nbPieces_; };
		void deplacer(int x, int y) override {
			if ((abs(x_ - x) <= 1) && (abs(y_ - y) <= 1) && x >= 0 && x < 8 && y >= 0 && y < 8) {
				x_ = x;
				y_ = y;
			}
		}

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}

		~Roi() {
			--nbPieces_;
		}

		static int nbPieces_;
	};

	class Pion : public Piece {
	public:
		Pion(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if (couleur_ == blanc && x == x_ && y == y_ + 1 && y < 8) {
				x_ = x;
				y_ = y;
			}
			else if (couleur_ == noir && x == x_ && y == y_ - 1 && y >= 0) {
				x_ = x;
				y_ = y;
			}
		};

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

	class DeplacementTemporaire {
	public:
		DeplacementTemporaire(Piece& piece, int xTemporaire, int yTemporaire)
			: piece_(piece), xOriginal_(piece.x_), yOriginal_(piece.y_) {
			piece_.deplacer(xTemporaire, yTemporaire);
		}

		~DeplacementTemporaire() {
			piece_.x_ = xOriginal_;
			piece_.y_ = yOriginal_;
		}

	private:
		Piece& piece_;
		int xOriginal_, yOriginal_;
	};
}

