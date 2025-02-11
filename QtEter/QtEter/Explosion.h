#pragma once
#include <iostream>
#include <vector>
#include "ExplosionType.h"

namespace explosion {
	class Explosion {
	private:
		bool m_isUsed{ false };
		std::vector<std::vector<int>> m_explosion;
	public:
		Explosion() = default;
		Explosion(ExplosionType_enum::ExplosionType type);
		~Explosion() = default;

		std::vector<std::vector<int>> getExplosion(int direction) const;

		bool isUsed();
		void setIsUsed(bool newIsUsed);
	};

}