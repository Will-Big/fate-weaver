#pragma once
#include <random>

/*-------------------------------------------------------
RandomGenerator
���� ������, ��𼭳� �����ϰ� �ϰ� �õ� �ϳ��� ���� �����Ϸ��� �̱������� ����.
�ν��Ͻ��� �����ؼ� GetRamdomNumber ȣ���� �� min, max�� �������ָ� �� �����ȿ��� ���� ���� ����.
-------------------------------------------------------*/

class RandomGenerator
{
private :
	std::random_device rd;
	std::mt19937 rng;

	static RandomGenerator* m_Instance;

private:
	RandomGenerator();

public:
	static RandomGenerator* GetInstance();

public:
	int GetRandomNumber(int min, int max);
	std::mt19937& GetRandomEngine();

public:
	RandomGenerator(const RandomGenerator&) = delete;
	RandomGenerator& operator=(const RandomGenerator&) = delete;

	void Finalize();
};

