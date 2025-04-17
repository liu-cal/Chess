#pragma once

#include <string>
#include <stdexcept>

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
			if ((abs(x_ - x) <= 1) && (abs(y_ - y) <= 1) && x >= 1 && x < 9 && y >= 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un roi");
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

		inline static int nbPieces_ = 0;
	};

	class Pion : public Piece {
	public:
		Pion(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if (couleur_ == blanc && x == x_ && y == y_ + 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else if (couleur_ == noir && x == x_ && y == y_ - 1 && y >= 1) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un roi");
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
			if (abs(x - x_) == abs(y - y_) && x >= 1 && x < 9 && y >= 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un fou");
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_ && abs(x_ - piece.x_) == abs(y_ - piece.y_)) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Tour : public Piece {
	public:
		Tour(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if ((x == x_ || y == y_) && x >= 1 && x < 9 && y >= 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un roi");
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_ && (x_ == piece.x_ || y_ == piece.y_)) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Cavalier : public Piece {
	public:
		Cavalier(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if (((abs(x - x_) == 2 && abs(y - y_) == 1) ||
				(abs(x - x_) == 1 && abs(y - y_) == 2)) &&
				x >= 1 && x < 9 && y >= 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un roi");
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_ &&
				((abs(x_ - piece.x_) == 2 && abs(y_ - piece.y_) == 1) ||
					(abs(x_ - piece.x_) == 1 && abs(y_ - piece.y_) == 2))) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class Reine : public Piece {
	public:
		Reine(int x, int y, Couleur couleur) : Piece(x, y, couleur) {};

		void deplacer(int x, int y) override {
			if ((x == x_ || y == y_ || abs(x - x_) == abs(y - y_)) &&
				x >= 1 && x < 9 && y >= 1 && y < 9) {
				x_ = x;
				y_ = y;
			}
			else {
				throw std::invalid_argument("Mouvement invalide pour un roi");
			}
		};

		void manger(const Piece& piece) override {
			if (piece.couleur_ != this->couleur_ &&
				(x_ == piece.x_ || y_ == piece.y_ || abs(x_ - piece.x_) == abs(y_ - piece.y_))) {
				this->x_ = piece.x_;
				this->y_ = piece.y_;
			}
		}
	};

	class DeplacementTemporaire {
	public:
		DeplacementTemporaire(Piece& piece, int xTemporaire, int yTemporaire)
			: piece_(piece), xOriginal_(piece.x_), yOriginal_(piece.y_) {
			try {
				piece_.deplacer(xTemporaire, yTemporaire);
			}
			catch (exception e) {
				throw;
			}
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