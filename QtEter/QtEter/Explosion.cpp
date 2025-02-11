#include "Explosion.h"

explosion::Explosion::Explosion(ExplosionType_enum::ExplosionType type)
{
	switch (type)
	{
	case ExplosionType_enum::ExplosionType::ExplosionType1:
		m_explosion= {
			{0,0,1},
			{0,2,0},
			{1,0,0}
		};
		break;
	case ExplosionType_enum::ExplosionType::ExplosionType2:
		m_explosion = {
			{0,2,0},
			{1,0,0},
			{0,0,2}
		};
		break;
	case ExplosionType_enum::ExplosionType::ExplosionType3:
		m_explosion = {
			{1,2,0},
			{0,0,0},
			{0,1,0}
		};
		break;
	default:
		break;
	}
}

std::vector<std::vector<int>> explosion::Explosion::getExplosion(int direction) const
{
	std::vector<std::vector<int>> newExplosion ;
	if (direction == 1) {
		for(int i=0;i<3;i++)
		{
			std::vector<int> row;
			for (int j = 2; j >= 0; j--)
				row.push_back(m_explosion[j][i]);
			newExplosion.push_back(row);
			row.clear();
		}
		return newExplosion;
	}
	if (direction == 2) {
		for (int i = 2; i >= 0; i--)
		{
			std::vector<int> row;
			for (int j = 2; j >= 0; j--)
				row.push_back(m_explosion[i][j]);
			newExplosion.push_back(row);
			row.clear();
		}
		return newExplosion;
	}
	if (direction == 3) {
		for (int i = 2; i >= 0; i--)
		{
			std::vector<int> row;
			for (int j = 0; j < 3; j++)
				row.push_back(m_explosion[j][i]);
			newExplosion.push_back(row);
			row.clear();
		}
		return newExplosion;
	}
	return m_explosion;
}

bool explosion::Explosion::isUsed()
{
	return m_isUsed;
}

void explosion::Explosion::setIsUsed(bool newIsUsed)
{
	m_isUsed = newIsUsed;
}
