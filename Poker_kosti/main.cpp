#include<iostream>
#include<Windows.h>
#include<vector>
#include<time.h>
#include<conio.h>
#include<algorithm>
using namespace std;
HANDLE hCon;
COORD cPos;

#define KEY_D 100 
#define KEY_A 97
#define KEY_D_RUS 50
#define KEY_A_RUS 68
#define KEY_SPACE 32

class Dice
{
protected:
	int nominal;
	bool select;
	bool choice;
	bool is_draw;
public:
	virtual int get_nominal() { return nominal; }
	virtual bool get_select() { return select; }
	virtual bool get_choice() { return choice; }
	
	void Print_dice(int x, int y)
	{
		if (is_draw == false)
			return;
		is_draw = false;
		if (choice == false)
		{
			SetConsoleTextAttribute(hCon, BACKGROUND_RED |
				BACKGROUND_GREEN | BACKGROUND_BLUE);
			cPos.X = x + 2;
			cPos.Y = y;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 1;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 1;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 2;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 3;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 4;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
		}

		if (choice == true)
		{
			SetConsoleTextAttribute(hCon, BACKGROUND_RED);
			cPos.X = x + 2;
			cPos.Y = y;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 1;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 1;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 2;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 3;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
			cPos.X = x + 2;
			cPos.Y = y + 4;
			SetConsoleCursorPosition(hCon, cPos);
			cout << "         \n";
		}
	}

	void draw_line(int x1, int y1) 
	{
		if (select == true)
		{
			cPos.X = x1 + 3;
			cPos.Y = y1 + 5;
			SetConsoleCursorPosition(hCon, cPos);
			SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "=======";
		}

		if (select == false)
		{
			cPos.X = x1 + 3;
			cPos.Y = y1 + 5;
			SetConsoleCursorPosition(hCon, cPos);
			SetConsoleTextAttribute(hCon, 0);
			cout << "       ";
		}
	}
	virtual void set_select() 
	{ 
		if (select == true)
			select = false;
		else
			select = true;
		is_draw = true;
	}

	virtual void set_choice()
	{
		if (choice==true)
			choice = false;
		else
			choice = true;
		is_draw = true;
	}
	virtual void Print(int x, int y) = 0;
};

class Dice_1 :public Dice
{
public:
	Dice_1() { nominal = 1; select = false; choice = false; }
	void Print(int x, int y)//2,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = x + 4 + 2;
		cPos.Y = y + 2;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class Dice_2 :public Dice
{
public:
	Dice_2() { nominal = 2; select = false;choice = false;}
	void Print(int x, int y)//11,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class Dice_3 :public Dice
{
public:
	Dice_3() { nominal = 3; select = false;choice = false;}
	void Print(int x, int y)//22,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = (x + 2) + 6;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 2;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 2;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class Dice_4 :public Dice
{
public:
	Dice_4() { nominal = 4;select = false;choice = false;}
	void Print(int x, int y)//33,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class Dice_5 :public Dice
{
public:
	Dice_5() { nominal = 5; select = false;choice = false;}
	void Print(int x, int y)//44,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 2;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};

class Dice_6 :public Dice
{
public:
	Dice_6() { nominal = 6; select = false;choice = false;}
	void Print(int x, int y)//55,2
	{
		Print_dice(x, y);
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 1;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 1;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 4;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		cPos.X = (x + 2) + 7;
		cPos.Y = y + 3;
		SetConsoleCursorPosition(hCon, cPos);
		cout << ".";
		draw_line(x, y);
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}
};


class Igrok
{
	string name;
	int score;	
	Dice** objigr;	
	int count;
public:
	Igrok()
	{
		name = "No name";
		score = 0;
		objigr = nullptr;
		count = 0;
	}   
	void set_name(char* _n) { name = _n; }
	Dice* generate(int rn) 
	{
		Dice* p;
		switch (rn) 
		{
			case 0: p = new Dice_1();break;
			case 1: p = new Dice_2();break;
			case 2: p = new Dice_3();break;
			case 3: p = new Dice_4();break;
			case 4: p = new Dice_5();break;
			case 5: p = new Dice_6();break;
			default: p = new Dice_1();
		}
		return p;
	}
	void set_score(int _s) { score += _s; }
	void set_dice()
	{
		if (objigr)
		{
			for (int i = 0;i < 5;i++) 
			{
				delete objigr[i];
				objigr[i]=nullptr;
			}
			delete[]objigr;
			objigr = nullptr;
		}
			
		objigr = new Dice*[5];
		int ran = 0;
			for (int i = 0;i < 5;i++)
			{
				ran = rand() % 6;
				objigr[i] = generate(ran);
			}
	}
	void set_dice_i(int _i)
	{
		if (objigr[_i])
		{
			delete objigr[_i];
			objigr[_i] = nullptr;
		}		
		int ran = 0;
		ran = rand() % 6;
		objigr[_i] = generate(ran);
	}

	string get_name() { return name; }
	int get_score() { return score; }
	int get_dise_inom(int i) { return objigr[i]->get_nominal(); }
	void set_dice_i_select(int i) { objigr[i]->set_select(); }
	bool get_dice_i_select(int i) { return objigr[i]->get_select(); }
	void set_dice_i_choice(int i) { objigr[i]->set_choice(); }
	bool get_dice_i_choice(int i) { return objigr[i]->get_choice(); }
	void set_count(int n) { count+=n; }
	int get_count() { return count; }
	void flush_count() { count = 0; }

	void print_dices(int x, int y)
	{	
		for (int i = 0;i < 5;i++)
		{
			objigr[i]->Print(x,y);
			x += 11;
		}		
	}

	~Igrok()
	{
		if (objigr) 
		{
			for (int i = 0;i < 5;i++)
				delete objigr[i];
			delete[] objigr;
		}
	}
};

class Pole
{
	Igrok igrok1;
	Igrok igrok2;
	bool para1, para2, set, m_street, big_street, fulhouse, kare, poker, nothing;
	bool para1_2, para2_2, set2, m_street2, big_street2, fulhouse2, kare2, poker2, nothing2;
	vector<vector <int>>arr1;vector<vector <int>>arr2;
	bool selector;
	bool new_game;
	bool my_event;
	int key;int ind;
	bool is_winner;
	int win;
	bool is_draw_game;
	bool is_draw_select;
public:
	Pole(char* _n)
	{
		igrok1.set_name("БОТ");
		igrok1.set_dice();	
		igrok2.set_name(_n);
		igrok2.set_dice();
		
		bool para1 = 0, para2 = 0, set = 0, m_street = 0, big_street = 0, fulhouse = 0, kare = 0, poker = 0, nothing =0;
		bool para1_2 = 0, para2_2 = 0, set2 = 0, m_street2 = 0, big_street2 = 0, fulhouse2 = 0, kare2 = 0, poker2 = 0, nothing2 = 0;
		selector = 1; new_game = 1;
		arr1.resize(6);
		arr2.resize(6);
		key = 67;ind = 0;
		my_event = 0;
		is_winner = 0;
		win = 0;
		is_draw_game = 1;
		is_draw_select = 1;
	}

	void Print_info()
	{
		clear_winner();
		Print_name_score1();
		Print_name_score2();
		if (new_game == true)
			print_button_new_game();
		if (selector == false && new_game == false)
			print_button_no_activ();
		else
			if (selector == true&&new_game == false)
				print_button_activ();
		cPos.X = 2;
		cPos.Y = 30;
		SetConsoleCursorPosition(hCon, cPos);
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "Используйте клавиши A D для перемещения. Пробел - выбор. Esc - выход.";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void change_selector()
	{
		if (selector == true)
			selector = false;
		else
			selector = true;
		is_draw_select = true;
	}

	void change_new_game()
	{
		if (new_game == true)
			new_game = false;
		else
			new_game = true;
		is_draw_game = true;
	}

	void change_event()
	{
		if (my_event == true)
			my_event = false;
		else
			my_event = true;
	}

	void print_dices()
	{
		Print_igrok1();
		Print_igrok2();
	}

	void Draw()
	{	
		system("cls");
		Print_info();
		print_dices();
		while (key != 27)
		{
			if (my_event)
			{
				Draw_pole();
				my_event = false;
			}
			else
			{
 				if (_kbhit())
				{
					key = _getch();
					my_event = true;
				}			
			}
			Sleep(50);
		}
	}

	void Draw_pole()
	{		
			if (new_game == false)
			{
				switch (key)
				{
				case KEY_A:
				case KEY_A_RUS:
					--ind;
					if (ind < 0)
					{
						ind = 5;
						change_selector();
						if(igrok2.get_dice_i_select(0)==true)
							igrok2.set_dice_i_select(0);
					}
					else
						if (ind == 4)
						{
							change_selector();
							igrok2.set_dice_i_select(ind);
						}
						else
							if (ind >= 0 && ind < 4)
							{
								++ind;
								if (igrok2.get_dice_i_select(ind) == true)
									igrok2.set_dice_i_select(ind);
								--ind;
								igrok2.set_dice_i_select(ind);
							}
					break;
				case KEY_D:
					case KEY_D_RUS:
					++ind;
					if (ind > 5)
						ind = 0;
					if (ind == 5)
					{
						igrok2.set_dice_i_select(4);
						change_selector();
					}
					else
						if (ind == 0)
						{
							change_selector();
							igrok2.set_dice_i_select(ind);
						}
						else
							if (ind > 0 && ind <= 4)
							{
								--ind;
								if (igrok2.get_dice_i_select(ind) == true)
									igrok2.set_dice_i_select(ind);
								++ind;
								igrok2.set_dice_i_select(ind);
							}
					break;
				case KEY_SPACE:
					if (selector == true)
					{
						change_selector();
						chage_dice_bot();
						Sleep(2);
						change_dice_player2();
						check_combinations();
						calculate_score();
						change_new_game();
						is_winner = true;
					}
					else
					{
						if (igrok2.get_dice_i_select(ind) == true && 
							(igrok2.get_count() < 3 || igrok2.get_dice_i_choice(ind) == true))
						{
							igrok2.set_dice_i_choice(ind);

							if (igrok2.get_dice_i_choice(ind) == true)
								igrok2.set_count(1);
							else
								igrok2.set_count(-1);
						}						
					}
					break;
				default:
					break;
				}
			}
			else
				if (new_game == true)
				{
					selector = true;
					ind = 0;
					igrok2.flush_count();
					switch (key)
					{
					case KEY_SPACE:
						if (selector == true)
						{
							change_new_game();
							change_selector();
							set_dices_random();
							igrok2.set_dice_i_select(ind);
							check_combinations();
						}
						break;
					default:
						break;					
					}
				}			
		Print_info();
		print_dices();
		if (is_winner)
		{
			print_winner();
			is_winner = false;
		}			
	}

	void print_winner()
	{
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cPos.X = 10;
		cPos.Y = 17;
		SetConsoleCursorPosition(hCon, cPos);
		if (get_win() == 1)
			cout << "Выиграл игрок " << igrok1.get_name().c_str();
		else
			if (get_win() == 2)
				cout << "Выиграл игрок " << igrok2.get_name().c_str();
			else
				if (get_win() == 3)
					cout << "Ничья! ";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void clear_winner()
	{
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = 10;
		cPos.Y = 17;
		SetConsoleCursorPosition(hCon, cPos);
		int n = igrok2.get_name().size();
		for (int i = 0;i < n + 14;i++)
			cout << " ";
	}

	void print_button_new_game()
	{
		if (is_draw_select == false)
			return;
		is_draw_select = false;
		clear_button();
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cPos.X = 60;
		cPos.Y = 23;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "==============";
		cPos.X = 62;
		cPos.Y = 24;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "НОВАЯ ИГРА";
		cPos.X = 60;
		cPos.Y = 25;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "==============";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void clear_button()
	{
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = 60;
		cPos.Y = 23;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "              ";
		cPos.X = 62;
		cPos.Y = 24;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "            ";
		cPos.X = 60;
		cPos.Y = 25;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "              ";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void print_button_no_activ()
	{
		if (is_draw_select == false)
			return;
		is_draw_select = false;
		clear_button();
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN);
		cPos.X = 62;
		cPos.Y = 24;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "ПЕРЕБРОСИТЬ";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void print_button_activ()
	{
		if (is_draw_select == false)
			return;
		is_draw_select = false;
		clear_button();
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cPos.X = 60;
		cPos.Y = 23;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "==============";
		cPos.X = 62;
		cPos.Y = 24;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "ПЕРЕБРОСИТЬ";
		cPos.X = 60;
		cPos.Y = 25;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "==============";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void Print_igrok1()
	{
		int x = 2, y = 2;
		igrok1.print_dices(x, y);
	}

	void Print_igrok2()
	{
		int x = 2, y = 23;
		igrok2.print_dices(x, y);
	}

	void Print_name_score1()
	{
		clear_name_score1();
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		cPos.X = 80;
		cPos.Y = 2;
		SetConsoleCursorPosition(hCon, cPos);
		cout << igrok1.get_name().c_str();
		cPos.X = 80;
		cPos.Y = 4;
		SetConsoleCursorPosition(hCon, cPos);
		cout << igrok1.get_score();
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void clear_name_score1()
	{
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = 80;
		cPos.Y = 2;
		SetConsoleCursorPosition(hCon, cPos);
		int n = strlen(igrok1.get_name().c_str());
		for (int i = 0;i < n + 1;i++)
			cout << " ";
		cPos.X = 80;
		cPos.Y = 4;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "     ";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void Print_name_score2()
	{
		clear_name_score2();
		SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cPos.X = 80;
		cPos.Y = 23;
		SetConsoleCursorPosition(hCon, cPos);
		cout << igrok2.get_name().c_str();
		cPos.X = 80;
		cPos.Y = 25;
		SetConsoleCursorPosition(hCon, cPos);
		cout << igrok2.get_score();
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	void clear_name_score2()
	{
		SetConsoleTextAttribute(hCon, 0);
		cPos.X = 80;
		cPos.Y = 23;
		SetConsoleCursorPosition(hCon, cPos);
		int n = strlen(igrok2.get_name().c_str());
		for (int i=0;i < n + 1;i++)
			cout << " ";
		cPos.X = 80;
		cPos.Y = 25;
		SetConsoleCursorPosition(hCon, cPos);
		cout << "     ";
		cPos.X = 0;
		cPos.Y = 0;
		SetConsoleCursorPosition(hCon, cPos);
	}

	int get_max(vector <vector <int>> v)
	{
		int max = v[0].size();
		for (int i = 0;i < 6;i++)
			if (max < v[i].size())
				max = v[i].size();
		return max;
	}

	int get_ind(vector <vector <int>> v)
	{
		int ind = 0;
		int max = v[0].size();
		for (int i = 0;i < 6;i++)
			if (max < v[i].size())
			{
				max = v[i].size();
				ind = i;
			}				
		ind++;
		return ind;
	}

	bool search_2para(vector <vector <int>> v)
	{
		bool para = false;
		bool _2para = false;
		for (int i = 0;i < 6;i++)
		{
			if (v[i].size() == 2 && para == true)
				_2para = true;
			if (v[i].size() == 2)
				para = true;
		}
		return _2para;
	}

	bool search_para_fulhouse(vector <vector <int>> v)
	{
		bool para = false;
		for (int i = 0;i < 6;i++)
			if (v[i].size() == 2)
				para = true;
		return para;
	}

	int search_2para_ind(vector <vector <int>> v)
	{
		bool para = false;
		bool _2para = false;int n;
		for (int i = 0;i < 6;i++)
		{
			if (v[i].size() == 2)
				para = true;
			if (v[i].size() == 2 && para == true)
			{
				_2para = true;
				n = i;
			}
		}
		n++;
		return n;
	}

	int search_para_ind(vector <vector <int>> v)
	{
		int n = 0;
		for (int i = 0;i < 6;i++)
			if (v[i].size() == 2)
				n = i;
		n++;
		return n;
	}

	int search_street(vector <vector <int>> v)
	{
		vector<int>a;
		int k = 0;int count = 0;
		for (int i = 0;i < 6;i++)
		{
			if (v[i].size() == 1|| v[i].size() == 2)
				a.push_back(i+1);
		}			
		sort(a.begin(), a.end());int n = a[0];
		for (int i = 0;i < a.size();i++)
		{
			if (a.at(i) == n)
				k++;
			n++;
		}			
		return k;
	}

	int search_street_ind(vector <vector <int>> v)
	{
		int k = 0;
		for (int i = 0;i < 6;i++)
			if (v[i].size() == 1)
				k += i;
		k++;
		return k;
	}

	void check_combinations()
	{
		para1 = 0, para2 = 0, set = 0, m_street = 0, big_street = 0, fulhouse = 0, kare = 0, poker = 0, nothing = 0;
		para1_2 = 0, para2_2 = 0, set2 = 0, m_street2 = 0, big_street2 = 0, fulhouse2 = 0, kare2 = 0, poker2 = 0, nothing2=0;
		arr1.clear();arr2.clear();
		arr1.resize(6);
		arr2.resize(6);
		int k = 0;	
		for (int i = 0;i < 5;i++)
		{
			int x = igrok1.get_dise_inom(i);
			arr1[(igrok1.get_dise_inom(i)) - 1].push_back(i);
		}
			
		for (int i = 0;i < 5;i++)	
			arr2[(igrok2.get_dise_inom(i)) - 1].push_back(i);
		
		int max1 = get_max(arr1);
		if (max1 == 5)
			poker = true;
		else
			if (max1 == 4)
				kare = true;
		else
			if (poker == 0 && kare == 0)
			{
				k = search_street(arr1);
				if (k == 4)
					m_street = true;
				if (k == 5)
					big_street = true;
			}			
		if (max1 == 3)
		{
			set = true;
			para1 = search_para_fulhouse(arr1);
		}		
		if (!m_street&& !big_street&&max1 == 2)
			para1 = true;
		if (para1 == true && set == true)
			fulhouse = true;
		if (para1 == true&&set == false)
			para2 = search_2para(arr1);	
		
		if (para1 == 0&& para2 == 0&& set == 0&& m_street == 0&& big_street == 0&& fulhouse == 0&& kare == 0&& poker == 0)
			nothing = true;

		int max2 = get_max(arr2);k = 0;
		if (max2 == 5)
			poker2 = true;
		else
			if (max2 == 4)
				kare2 = true;
		else
			if (poker2 == 0 && kare2 == 0)
			{
				k = search_street(arr2);
				if (k == 4)
					m_street2 = true;
				if (k == 5)
					big_street2 = true;
			}
		if (max2 == 3)
		{
			set2 = true;			
			para1_2 = search_para_fulhouse(arr1);
		}
		if (!m_street2 && !big_street2 && max2 == 2)
			para1_2 = true;
		if (para1_2 == true && set2 == true)
			fulhouse2 = true;
		if (para1_2 == true && set2 == false)
			para2_2 = search_2para(arr2);	

		if (para1_2 == 0 && para2_2 == 0 && set2 == 0 && m_street2 == 0&& big_street2 == 0&& fulhouse2 == 0&& kare2 == 0&& poker2 == 0)
			nothing2 = true;
	}

	int calculate_score()
	{
		win = 0;
		int total1 = 0, total2 = 0;
		int m1 = 0, m2 = 0;
		m1 = get_ind(arr1);
		m2 = get_ind(arr2);
		if (poker == true && poker2 == true)
		{			
			total1 += (m1 * 5) * 50;
			total2 += (m2 * 5) * 50;					
		}
		
		if (poker == true && poker2 == false)
			total1 += (m1 * 5)*50;
		
		if (poker == false && poker2 == true)
			total2 += (m2 * 5)*50;
		
		if (kare == true && kare2 == true)
		{
			total1 += (m1 * 4) * 40;
			total2 += (m2 * 4) * 40;					
		}
		
		if (kare == true && kare2 == false)
			total1 += (m1 * 4)*40;
		
		if (kare == false && kare2 == true)
			total2 += (m2 * 4)*40;
		
		if (fulhouse == true && fulhouse2 == true)
		{
			m1 *= 3;
			int t = search_para_ind(arr1);
			t *= 2;
			m1 += t;
			m2 *= 3;
			t = search_para_ind(arr2);
			t *= 2;
			m2 += t;
			total1 += m1 * 20;
			total2 += m2 * 20;					
		}
		
		if (fulhouse == true && fulhouse2 == false)
		{
			m1 *= 3;
			int t = search_para_ind(arr1);
			t *= 2;
			m1 += t;
			total1 += m1*20;
		}
		
		if (fulhouse == false && fulhouse2 == true)
		{
			m2 *= 3;
			int t = search_para_ind(arr2);
			t *= 2;
			m2 += t;
			total2 += m2*20;
		}
		
		if (set == true && set2 == true)
		{		
			total1 += (m1 * 3)*2;
			total2 += (m2 * 3)*2;					
		}
		
		if (set == true && set2 == false)
			total1 += (m1 * 3)*2;
		
		if (set == false && set2 == true)
			total2 += (m2 * 3)*2;
		
		if (para2 == true && para2_2 == true)
		{
			m1 += search_2para_ind(arr1);
			m2 += search_2para_ind(arr2);				
			total1 += (m1 * 2);
			total2 += (m2 * 2);										
		}
		if (para2 == true && para2_2 == false)
		{
			m1 += search_2para_ind(arr1);
			total1 += (m1 * 2);
		}
		
		if (para2 == false && para2_2 == true)
		{
			m2 += search_2para_ind(arr2);
			total2 += (m2 * 2);
		}
		
		if (para1 == true && para1_2 == true)
		{
			total1 += (m1 * 2);
			total2 += (m2 * 2);
		}
		
		if (para1 == true && para1_2 == false)
			total1 += (m1 * 2);
		
		if (para1 == false && para1_2 == true)
			total2 += (m2 * 2);
		
		if (m_street == true && m_street2 == true)
		{
			m1 = search_street_ind(arr1);
			m2 = search_street_ind(arr2);			
			total1 += m1*12;
			total2 += m2 * 12;						
		}
		
		if (big_street == true && big_street2 == true)
		{
			m1 = search_street_ind(arr1);
			m2 = search_street_ind(arr2);			
			total1 += m1 * 15;				
			total2 += m2 * 15;					
		}
		
		if (m_street == true && m_street2 == false)
		{
			m1 = search_street_ind(arr1);
			total1 += m1*12;
		}
		
		if (big_street == true && big_street2 == false)
		{
			m1 = search_street_ind(arr1);
			total1 += m1 * 15;
		}
		
		if (m_street == false && m_street2 == true)
		{
			m2 = search_street_ind(arr2);
			total2 += m2*12;
		}
		
		if (big_street == false && big_street2 == true)
		{
			m2 = search_street_ind(arr2);
			total2 += m2 * 15;
		}

		igrok1.set_score(total1);
		igrok2.set_score(total2);

		if (total1 > total2)
		{		
			win = 1;
			return win;
		}
		else
			if (total1 < total2)
			{			
				win = 2;
				return win;
			}
			else
				if(total1==total2)
			{
				win = 3;
				return win;
			}		
	}

	int get_win() { return win; }

	void change_dice_player2()
	{
		for (int i = 0;i < 5;i++)
		{
			if (igrok2.get_dice_i_choice(i) == true)
			{
				igrok2.set_dice_i(i);
			}			
		}	
	}

	void change_dice_set()
	{	
		int n = get_ind(arr1);
		n--;
		for (int i = 0;i < 5;i++)
			for (int j = 0;j < arr1[n].size();j++)
				if (i != arr1[n].at(j))
					igrok1.set_dice_i(i);
	}

	void change_dice_para1()
	{
		int n = search_para_ind(arr1);
		n--;
		for (int i = 0;i < 5;i++)
			for (int j = 0;j < arr1[n].size();j++)
				if (i != arr1[n].at(j))
					igrok1.set_dice_i(i);
	}

	void change_dice_nothing()
	{
		igrok1.set_dice();
	}

	void chage_dice_bot()
	{
		int k = 1+rand() % 2;
		if (set == true || para1 == true || para1_2 == true || nothing == true&&m_street == false||big_street == false)
		{
			switch (k)
			{
			case 1:
				if (set == true)
				{
					change_dice_set();
					break;
				}
			case 2:
				if (para1 == true)
				{
					change_dice_para1();
					break;
				}
			case 3:
				change_dice_nothing();
				break;	
			default:
				break;
			}
		}
	}

	void set_dices_random()
	{
		igrok1.set_dice();
		igrok2.set_dice();
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char imya[50];
	srand(time(NULL));
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(L"Покер с костями");
	//SetConsoleCursorPosition(hCon, cPos);
	system("mode con lines=32 cols=90");
	SetConsoleTextAttribute(hCon, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cPos.X = 115;
	cPos.Y = 45;	
	SetConsoleCursorPosition(hCon, cPos);
	cout << "Как вас зовут? " << endl;
	cin.getline(imya, 50);
	Pole A(imya);
	A.Draw();
	return 0;
}
