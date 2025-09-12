#include "../include/Score.h"

Score::Score() : curScore(0), maxScore(0)
{
	curScoreText = "Score: " + std::to_string(curScore);
	maxScoreText = "Max Score: " + std::to_string(maxScore);
}

void Score::UpdateScore(int s)
{
	curScore += s;
	if (curScore > maxScore) maxScore = curScore;
	curScoreText = "Score: " + std::to_string(curScore);
	maxScoreText = "Max Score: " + std::to_string(maxScore);
}

void Score::ResetScore()
{
	curScore = 0;
}

void Score::DrawScore()
{
	DrawText(curScoreText.c_str(), 20, 20, 20, RAYWHITE);
	DrawText(maxScoreText.c_str(), 420, 20, 20, RAYWHITE);
}
