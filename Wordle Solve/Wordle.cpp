#include <iostream>
#include "Header.h"
int WordOn = 0;
int LettersWrongNum = 0;
char LettersWrong[26];
int LettersRightWrongNum = 0;
char LettersRightWrong[26];
int LettersRightWrongPlace[26];
int LettersRightNum = 0;
char LettersRight[26];
int LettersRightPlace[26];
double GetLetterPoints(char Letter, int Place);
void PlayWordle();
struct WordInfo
{
	std::string Word;
	double Points = 0;
	void GetPoints()
	{
		bool DoNotUse = false;
		if (WordOn <= (sizeof(Words) / sizeof(Words[0])))
		{



			Word = Words[WordOn];

			WordOn++;
			if (Word.length() != 5)
			{
				DoNotUse = true;
				Points = 0;


			}
			else
			{
				for (int i = 0; i < Word.length(); i++)
				{
					Points += GetLetterPoints(Word[i], i);


					for (int j = 0; j < i; j++)
					{
						if (Word[i] == Word[j] && j != i)
						{
							Points -= GetLetterPoints(Word[i], i);
						}

					}
					for (int j = 0; j < LettersWrongNum; j++)
					{
						if (Word[i] == LettersWrong[j])
						{
							DoNotUse = true;
							Points = 0;

						}
					}
				}
				bool Used = false;
				for (int i = 0; i < LettersRightWrongNum; i++)
				{
					Used = false;
					for (int j = 0; j < Word.length(); j++)
					{



						if (Word[j] == LettersRightWrong[i] && (Word[LettersRightWrongPlace[i]] != LettersRightWrong[i]))
						{
							Used = true;
						}





					}
					if (!Used)
					{

						DoNotUse = true;
						Points = 0;
					}
				}
				for (int i = 0; i < LettersRightNum; i++)
				{
					if (Word.size() == 5)
					{
						if (LettersRightNum > 0)
						{
							if (Word[LettersRightPlace[i]] != LettersRight[i])
							{

								DoNotUse = true;
							}
						}
					}
				}
			}
		}
		if (DoNotUse)
		{
			Points = 0;
			return;
		}
	}

};
int main()
{
	bool Play = true;
	std::string Agian;
	while (Play)
	{
		PlayWordle();
		std::cout << "Do you want to use it agian or reset if it is a new word:" << std::endl;
		std::cin >> Agian;
		if (Agian == "yes" || Agian == "true")
		{
			Play = true;
		}
		else if(Agian == "reset")
		{
			Play = true;
			LettersWrongNum = 0;
			LettersRightNum = 0;
			LettersRightWrongNum = 0;
		}
		else
		{
			Play = false;
		}
	}
	return 0;
}
void PlayWordle()
{
	WordOn = 0;
	int LettersWrongNumTry = 0;
	std::cout << "enter num of letters wrong:" << std::endl;
	std::cin >> LettersWrongNumTry;
	for (int i = 0; i < LettersWrongNumTry; i++)
	{
		std::cout << "enter the num " << i + 1 << " letter wrong" << std::endl;
		std::cin >> LettersWrong[i + LettersWrongNum];
		LettersWrongNum += LettersWrongNumTry;

	}
	std::cout << "enter num of letters right but wrong place:" << std::endl;
	int LettersRightWrongNumTry = 0;
	std::cin >> LettersRightWrongNumTry;
	for (int i = 0; i < LettersRightWrongNumTry; i++)
	{
		std::cout << "enter the num " << i + 1 << " letters right but wrong place" << std::endl;
		std::cin >> LettersRightWrong[i + LettersRightWrongNum];
		std::cout << "enter the place " << std::endl;
		int value = 0;
		std::cin >> value;
		LettersRightWrongPlace[i + LettersRightWrongNum] = value - 1;
		LettersRightWrongNum += LettersRightWrongNumTry;
	}
	int LettersRightNumTry = 0;
	std::cout << "enter num of letters right:" << std::endl;
	std::cin >> LettersRightNumTry;
	for (int i = 0; i < LettersRightNumTry; i++)
	{
		std::cout << "enter the num " << i + 1 << " letters right " << std::endl;
		std::cin >> LettersRight[i + LettersRightNum];
		std::cout << "enter the place " << std::endl;
		int value = 0;
		std::cin >> value;
		LettersRightPlace[i + LettersRightNum] = value - 1;
		LettersRightNum += LettersRightNumTry;
	}
	WordInfo InfoWords[20000];
	WordInfo BestWord = InfoWords[0];
	WordInfo SecondWord = InfoWords[1];
	WordInfo ThirdWord = InfoWords[2];
	for (int i = 0; i < (sizeof(Words) / sizeof(Words[0])); i++)
	{
		InfoWords[i].GetPoints();
	}
	for (int i = 0; i < (sizeof(Words) / sizeof(Words[0])); i++)
	{

		if (InfoWords[i].Points > BestWord.Points)
		{
			BestWord = InfoWords[i];
		}
	}
	for (int i = 0; i < (sizeof(Words) / sizeof(Words[0])); i++)
	{
		if (InfoWords[i].Word != BestWord.Word)
		{
			if (InfoWords[i].Points > SecondWord.Points)
			{
				SecondWord = InfoWords[i];
			}
		}
	}
	for (int i = 0; i < (sizeof(Words) / sizeof(Words[0])); i++)
	{
		if (InfoWords[i].Word != BestWord.Word && InfoWords[i].Word != SecondWord.Word)
		{
			if (InfoWords[i].Points > ThirdWord.Points)
			{
				ThirdWord = InfoWords[i];
			}
		}
	}
	std::cout << "try: " << BestWord.Word << std::endl;
	std::cout << "Or this: " << SecondWord.Word << std::endl;
	std::cout << "third: " << ThirdWord.Word << std::endl;
}
double GetLetterPoints(char Letter, int Place)
{
	double ReturnValue = 0;
	switch (Letter)
	{
	case 'a':
		ReturnValue = 8.49;
		switch (Place)
		{
		case 0:
			ReturnValue += 6;
			break;
		case 1:
			ReturnValue += 17;
			break;
		case 2:
			ReturnValue += 9.722;
			break;
		case 3:
			ReturnValue += 8.43892;
			break;
		case 4:
			ReturnValue += 5.17381;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'b':
		ReturnValue = 2.07;
		switch (Place)
		{
		case 0:
			ReturnValue += 7.38;
			break;
		case 1:
			ReturnValue += 0.6416;
			break;
		case 2:
			ReturnValue += 2.599;
			break;
		case 3:
			ReturnValue += 1.85185;
			break;
		case 4:
			ReturnValue += 0.45;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'c':
		ReturnValue = 4.5;
		switch (Place)
		{
		case 0:
			ReturnValue += 7.48863;
			break;
		case 1:
			ReturnValue += 1.405;
			break;
		case 2:
			ReturnValue += 2.99708;
			break;
		case 3:
			ReturnValue += 3.20825;
			break;
		case 4:
			ReturnValue += 0.958415;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'd':
		ReturnValue = 3.844;
		switch (Place)
		{
		case 0:
			ReturnValue += 5.56;
			break;
		case 1:
			ReturnValue += 0.66;
			break;
		case 2:
			ReturnValue += 3;
			break;
		case 3:
			ReturnValue += 3.55;
			break;
		case 4:
			ReturnValue += 6.29;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'e':
		ReturnValue = 11.6;
		switch (Place)
		{
		case 0:
			ReturnValue += 2.46;
			break;
		case 1:
			ReturnValue += 12.36;
			break;
		case 2:
			ReturnValue += 6.8957;
			break;
		case 3:
			ReturnValue += 17.78;
			break;
		case 4:
			ReturnValue += 11.93;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'f':
		ReturnValue = 1.81;
		switch (Place)
		{
		case 0:
			ReturnValue += 4.85;
			break;
		case 1:
			ReturnValue += 0.18;
			break;
		case 2:
			ReturnValue += 1.34;
			break;
		case 3:
			ReturnValue += 1.75;
			break;
		case 4:
			ReturnValue += 0.64;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'g':
		ReturnValue = 2.47;
		switch (Place)
		{
		case 0:
			ReturnValue += 5.18;
			break;
		case 1:
			ReturnValue += 0.61;
			break;
		case 2:
			ReturnValue += 2.75;
			break;
		case 3:
			ReturnValue += 3.24;
			break;
		case 4:
			ReturnValue += 1.14;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'h':
		ReturnValue = 3.0;
		switch (Place)
		{
		case 0:
			ReturnValue += 3.97;
			break;
		case 1:
			ReturnValue += 4;
			break;
		case 2:
			ReturnValue += 0.95;
			break;
		case 3:
			ReturnValue += 1.77;
			break;
		case 4:
			ReturnValue += 2.91;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'i':
		ReturnValue = 7.54;
		switch (Place)
		{
		case 0:
			ReturnValue += 1.34;
			break;
		case 1:
			ReturnValue += 10.4451;
			break;
		case 2:
			ReturnValue += 8.15;
			break;
		case 3:
			ReturnValue += 6.86;
			break;
		case 4:
			ReturnValue += 2.2;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'j':
		ReturnValue = 0.19;
		switch (Place)
		{
		case 0:
			ReturnValue += 1.64;
			break;
		case 1:
			ReturnValue += 0.08;
			break;
		case 2:
			ReturnValue += 8.15;
			break;
		case 3:
			ReturnValue += 6.86;
			break;
		case 4:
			ReturnValue += 2.23;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'k':
		ReturnValue = 1.1;
		switch (Place)
		{
		case 0:
			ReturnValue += 3.05;
			break;
		case 1:
			ReturnValue += 0.77;
			break;
		case 2:
			ReturnValue += 2.0;
			break;
		case 3:
			ReturnValue += 3.66;
			break;
		case 4:
			ReturnValue += 2.2;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'l':
		ReturnValue = 5.5;
		switch (Place)
		{
		case 0:
			ReturnValue += 4.68;
			break;
		case 1:
			ReturnValue += 5.63;
			break;
		case 2:
			ReturnValue += 6.29;
			break;
		case 3:
			ReturnValue += 5.9;
			break;
		case 4:
			ReturnValue += 3.74;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'm':
		ReturnValue = 3;
		switch (Place)
		{
		case 0:
			ReturnValue += 5.62;
			break;
		case 1:
			ReturnValue += 1.51;
			break;
		case 2:
			ReturnValue += 3.95;
			break;
		case 3:
			ReturnValue += 3.11;
			break;
		case 4:
			ReturnValue += 1.41;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'n':
		ReturnValue = 6.65;
		switch (Place)
		{
		case 0:
			ReturnValue += 2.63;
			break;
		case 1:
			ReturnValue += 2.8;
			break;
		case 2:
			ReturnValue += 7.27;
			break;
		case 3:
			ReturnValue += 6.18;
			break;
		case 4:
			ReturnValue += 4.1;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'o':
		ReturnValue = 7.1;
		switch (Place)
		{
		case 0:
			ReturnValue += 2.12;
			break;
		case 1:
			ReturnValue += 15.92;
			break;
		case 2:
			ReturnValue += 15.92;
			break;
		case 3:
			ReturnValue += 5.49;
			break;
		case 4:
			ReturnValue += 2.9;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'p':
		ReturnValue = 3.16;
		switch (Place)
		{
		case 0:
			ReturnValue += 6.97;
			break;
		case 1:
			ReturnValue += 15.92;
			break;
		case 2:
			ReturnValue += 7.7;
			break;
		case 3:
			ReturnValue += 5.5;
			break;
		case 4:
			ReturnValue += 2.98;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'q':
		ReturnValue = 0.1962;
		switch (Place)
		{
		case 0:
			ReturnValue += 0.63;
			break;
		case 1:
			ReturnValue += 1.87;
			break;
		case 2:
			ReturnValue += 0.1;
			break;
		case 3:
			ReturnValue += 0.016;
			break;
		case 4:
			ReturnValue += 0.032;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'r':
		ReturnValue = 7.58;
		switch (Place)
		{
		case 0:
			ReturnValue += 5.1;
			break;
		case 1:
			ReturnValue += 7.41;
			break;
		case 2:
			ReturnValue += 9.22;
			break;
		case 3:
			ReturnValue += 5.62;
			break;
		case 4:
			ReturnValue += 5.28;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 's':
		ReturnValue = 5.73;
		switch (Place)
		{
		case 0:
			ReturnValue += 12.7;
			break;
		case 1:
			ReturnValue += 0.74;
			break;
		case 2:
			ReturnValue += 4.14;
			break;
		case 3:
			ReturnValue += 4.034;
			break;
		case 4:
			ReturnValue += 14.92;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 't':
		ReturnValue = 6.95;
		switch (Place)
		{
		case 0:
			ReturnValue += 6.61;
			break;
		case 1:
			ReturnValue += 1.93;
			break;
		case 2:
			ReturnValue += 4.81;
			break;
		case 3:
			ReturnValue += 6.84;
			break;
		case 4:
			ReturnValue += 5.69;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'u':
		ReturnValue = 3.63;
		switch (Place)
		{
		case 0:
			ReturnValue += 1.5;
			break;
		case 1:
			ReturnValue += 9.27;
			break;
		case 2:
			ReturnValue += 5.2;
			break;
		case 3:
			ReturnValue += 6.8;
			break;
		case 4:
			ReturnValue += 0.51;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'v':
		ReturnValue = 1;
		switch (Place)
		{
		case 0:
			ReturnValue += 1.67316;
			break;
		case 1:
			ReturnValue += 0.422;
			break;
		case 2:
			ReturnValue += 1.88;
			break;
		case 3:
			ReturnValue += 1.226;
			break;
		case 4:
			ReturnValue += 0.03;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'w':
		ReturnValue = 1.289;
		switch (Place)
		{
		case 0:
			ReturnValue += 0.67;
			break;
		case 1:
			ReturnValue += 1.32;
			break;
		case 2:
			ReturnValue += 2.03;
			break;
		case 3:
			ReturnValue += 1.007;
			break;
		case 4:
			ReturnValue += 0.56;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'x':
		ReturnValue = 0.29;
		switch (Place)
		{
		case 0:
			ReturnValue += 0;
			break;
		case 1:
			ReturnValue += 0.46;
			break;
		case 2:
			ReturnValue += 0.98;
			break;
		case 3:
			ReturnValue += 0.097;
			break;
		case 4:
			ReturnValue += 0.56;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'y':
		ReturnValue = 1.77;
		switch (Place)
		{
		case 0:
			ReturnValue += 0.56;
			break;
		case 1:
			ReturnValue += 2;
			break;
		case 2:
			ReturnValue += 1.69;
			break;
		case 3:
			ReturnValue += 0.83;
			break;
		case 4:
			ReturnValue += 10;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	case 'z':
		ReturnValue = 0.272;
		switch (Place)
		{
		case 0:
			ReturnValue += 0.02;
			break;
		case 1:
			ReturnValue += 0.235;
			break;
		case 2:
			ReturnValue += 1.064;
			break;
		case 3:
			ReturnValue += 0.966;
			break;
		case 4:
			ReturnValue += 0.2355;
			break;

		default:
			break;
		}
		return ReturnValue;
		break;
	default:

		return 0;

		break;
	}

}
