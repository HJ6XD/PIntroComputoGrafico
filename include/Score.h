#pragma once
#include <string>
#include <raylib.h>
class Score
{
public:
	Score();
	void UpdateScore(int);
	void ResetScore();
	void DrawScore();
private:
	int curScore, maxScore;
	std::string curScoreText, maxScoreText;
};

