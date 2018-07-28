#pragma once

#include "QuestionManager.hpp"
#include "QuestionUtils.hpp"
#include <algorithm>
#include <random>
#include <chrono>

namespace Quizma
{
	class QuestionVector {
	private:
		QuestionUtils q1;
		std::vector<QuestionManager> question_answer_vector;
		std::vector<QuestionManager> sports_question_vector;
		std::vector<QuestionManager> math_question_vector;
		std::vector<QuestionManager> english_question_vector;
		unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine rng;/*(seed);*/

	public:
		QuestionVector();
		void displayQuestions();
		void armQuestions();
		std::vector<QuestionManager> passSportsQuestions();
		std::vector<QuestionManager> passMathQuestions();
		std::vector<QuestionManager> passEnglishQuestions();
	};
}