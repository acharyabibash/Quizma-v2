#include "QuestionUtils.hpp"

namespace Quizma
{
	std::vector<QuestionManager> QuestionUtils::loadQuestion()
	{
		question_file.open(QUESTION_FILEPATH, std::ios::in);

		if (question_file.is_open())
		{
			while (std::getline(question_file, line))
			{
				decltype(line.size()) pos, i = 0;

				while ((pos = line.find(delimiter)) != std::string::npos) 
				{
					cqa_array[i] = line.substr(0, pos);
					line.erase(0, pos + 1);
					i++;
				}

				cqa_array[SIZE_OF_QA_ARRAY - 1] = line.substr(0, line.find('\n'));

				QuestionManager question_set(cqa_array[0], cqa_array[1], qa_pointer + 2);

				cqa_vector.push_back(question_set);
			}
			question_file.close();
		}


		return cqa_vector;
	}
}