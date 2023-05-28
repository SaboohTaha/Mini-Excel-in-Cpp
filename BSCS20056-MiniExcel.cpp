//#include <iostream>
//#include "Excel.h"
//#include <conio.h>
//using namespace std;
//
//int main()
//{
//    //chars();
//    Excel C;
//    C.Main();
//}
//#pragma once
//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <conio.h>
//#include <WinUser.h>
//#include <thread>
//using namespace std;
//
//void gotoRowCol(int rpos, int cpos)
//{
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	int xpos = cpos, ypos = rpos;
//	COORD scrn;
//	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
//	scrn.X = xpos;
//	scrn.Y = ypos;
//	SetConsoleCursorPosition(hOuput, scrn);
//}
//void getRowColbyLeftClick(int& rpos, int& cpos)
//{
//	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD Events;
//	INPUT_RECORD InputRecord;
//	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
//	do
//	{
//		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
//		{
//			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
//			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
//			break;
//		}
//	} while (true);
//}
//void color(int k)
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hConsole, k);
//}
//
//
//int cdim = 16;
//int rdim = 5;
//
//class Excel
//{
//	enum ALLIGNMENT { LEFT, CENTER, RIGHT };
//	class Iterator;
//	class cell
//	{
//		string data;
//		cell* prev;
//		cell* next;
//		cell* up;
//		cell* down;
//		ALLIGNMENT all = CENTER;
//		friend class Excel;
//		friend class Iterator;
//	public:
//		cell(string d = "", cell* P = nullptr, cell* N = nullptr, cell* U = nullptr, cell* D = nullptr) :data(d), prev(P), next(N), up(U), down(D)
//		{
//		}
//		void cleardata()
//		{
//			data = "";
//		}
//		string GetCompleteData()
//		{
//			return data;
//		}
//		string GetData(int size)
//		{
//			string s;
//			for (int i = 0; i < size; i++)
//			{
//				if (i < data.size())
//				{
//					s += data[i];
//					continue;
//				}
//				break;
//			}
//			return s;
//		}
//		ALLIGNMENT GetAllign()
//		{
//			return all;
//		}
//		void changedata(string _data)
//		{
//			data = _data;
//		}
//		int GetColor()
//		{
//			return 0;
//		}
//	};
//
//	cell* head;
//	cell* tail;
//	cell* curr;
//	int r_size, c_size;
//	int rc, cc;
//	cell* GenerateRow()
//	{
//		cell* R = new cell();
//		cell* hed = R;
//		for (int i = 1; i < c_size; i++)
//		{
//			R = R->next = new cell("", R);
//		}
//		return hed;
//	}
//	cell* GenerateColumn()
//	{
//		cell* C = new cell();
//		cell* hed = C;
//		for (int i = 1; i < r_size; i++)
//		{
//			C = C->down = new cell("", nullptr, nullptr, C);
//		}
//		return hed;
//	}
//	void InsertRowBelow()
//	{
//		cell* temp = head;
//		for (int i = 0; i < rc; i++)
//		{
//			temp = temp->down;
//		}
//		cell* R = GenerateRow();
//		cell* next = nullptr;
//		if (temp->down)
//		{
//			next = temp->down;
//		}
//		for (int i = 0; i < c_size; i++)
//		{
//			temp->down = R;
//			R->up = temp;
//			if (next)
//			{
//				R->down = next;
//				next->down = R;
//				next = next->next;
//			}
//			else
//			{
//				tail = R;
//			}
//			R = R->next;
//			temp = temp->next;
//		}
//		r_size++;
//	}
//	void InsertRowAbove()
//	{
//		cell* temp = head;
//		for (int i = 0; i < rc; i++)
//		{
//			temp = temp->down;
//		}
//		cell* R = GenerateRow();
//		cell* pre = nullptr;
//		if (temp->up)
//		{
//			pre = temp->up;
//		}
//		for (int i = 0; i < c_size; i++)
//		{
//			temp->up = R;
//			R->down = temp;
//			if (pre)
//			{
//				R->up = pre;
//				pre->down = R;
//				pre = pre->next;
//			}
//			R = R->next;
//			temp = temp->next;
//		}
//		r_size++;
//		rc++;
//	}
//	void InsertColumnToRight()
//	{
//		cell* temp = head;
//		for (int i = 0; i < cc; i++)
//		{
//			temp = temp->next;
//		}
//		cell* C = GenerateColumn();
//		cell* next = nullptr;
//		if (temp->next)
//		{
//			next = temp->next;
//		}
//		for (int i = 0; i < r_size; i++)
//		{
//			temp->next = C;
//			C->prev = temp;
//			if (next)
//			{
//				C->next = next;
//				next->prev = C;
//				next = next->down;
//			}
//			else
//			{
//				tail = C;
//			}
//			C = C->down;
//			temp = temp->down;
//		}
//		c_size++;
//	}
//	void InsertColumnToLeft()
//	{
//		cell* temp = head;
//		for (int i = 0; i < cc; i++)
//		{
//			temp = temp->next;
//		}
//		cell* C = GenerateColumn();
//		cell* pre = nullptr;
//		if (temp->prev)
//		{
//			pre = temp->prev;
//		}
//		for (int i = 0; i < r_size; i++)
//		{
//			temp->prev = C;
//			C->next = temp;
//			if (pre)
//			{
//				C->prev = pre;
//				pre->next = C;
//				pre = pre->down;
//			}
//			C = C->down;
//			temp = temp->down;
//		}
//		c_size++;
//		cc++;
//	}
//	cell* GetCell(int r, int c)
//	{
//		cell* temp = head;
//		for (int i = 0; i < r; i++)
//		{
//			temp = temp->down;
//		}
//		for (int i = 0; i < c; i++)
//		{
//			temp = temp->next;
//		}
//		return temp;
//	}
//	void InsertCellByRightShift()
//	{
//		int pc = cc;
//		cc = c_size - 1;
//		InsertColumnToRight();
//		cc = pc;
//		cell* temp = curr;
//		while (temp->next)
//		{
//			string cd = temp->data;
//			string t = temp->next->data;
//			temp->cleardata();
//			temp->next->data = cd;
//			temp = temp->next;
//		}
//	}
//	void InsertCellByDownShift()
//	{
//		int pr = rc;
//		rc = r_size - 1;
//		InsertRowBelow();
//		rc = pr;
//		cell* temp = curr;
//		while (temp->down)
//		{
//			string cd = temp->data;
//			string t = temp->down->data;
//			temp->cleardata();
//			temp->down->data = cd;
//			temp = temp->down;
//		}
//	}
//	void DeleteCellByLeftShift()
//	{
//		cell* temp = curr;
//		temp->cleardata();
//		while (temp->next)
//		{
//			temp->data = temp->next->data;
//			temp->next->cleardata();
//			temp = temp->next;
//		}
//	}
//	void DeleteCellByUpShift()
//	{
//		cell* temp = curr;
//		temp->cleardata();
//		while (temp->down)
//		{
//			temp->data = temp->down->data;
//			temp->down->cleardata();
//			temp = temp->down;
//		}
//	}
//	void DeleteColumn()
//	{
//		cell* temp = head;
//		for (int i = 0; i < cc; i++)
//		{
//			temp = temp->next;
//		}
//		cell* t;
//		for (int i = 1; i < r_size; i++)
//		{
//			if (temp->prev)
//			{
//				temp->prev->next = temp->next;
//			}
//			if (temp->next)
//			{
//				temp->next->prev = temp->prev;
//			}
//			t = temp->down;
//			delete temp;
//			temp = t;
//		}
//		c_size--;
//		if (cc == c_size)
//		{
//			cc--;
//		}
//		curr = GetCell(rc, cc);
//	}
//	void DeleteRow()
//	{
//		cell* temp = head;
//		for (int i = 0; i < rc; i++)
//		{
//			temp = temp->down;
//		}
//		cell* t;
//		for (int i = 1; i < c_size; i++)
//		{
//			if (temp->up)
//			{
//				temp->up->down = temp->down;
//			}
//			if (temp->down)
//			{
//				temp->down->up = temp->up;
//			}
//			t = temp->next;
//			delete temp;
//			temp = t;
//		}
//		r_size--;
//
//		if (rc == r_size)
//		{
//			rc--;
//		}
//		curr = GetCell(rc, cc);
//	}
//	void DelCol()
//	{
//		if (c_size > 1)
//		{
//			DeleteColumn();
//			system("cls");
//			PrintGrid();
//			HighlightCell();
//		}
//	}
//	void DelRow()
//	{
//		if (r_size > 1)
//		{
//			DeleteRow();
//			system("cls");
//			PrintGrid();
//			HighlightCell();
//		}
//	}
//	void ClearColumn()
//	{
//		cell* temp = head;
//		for (int i = 0; i < cc; i++)
//		{
//			temp = temp->next;
//		}
//		for (int i = 0; i < r_size; i++)
//		{
//			temp->cleardata();
//			temp = temp->down;
//		}
//	}
//	void ClearRow()
//	{
//		cell* temp = head;
//		for (int i = 0; i < cc; i++)
//		{
//			temp = temp->down;
//		}
//		for (int i = 0; i < r_size; i++)
//		{
//			temp->cleardata();
//			temp = temp->next;
//		}
//	}
//	void HighlightCell(int r = -1, int c = -1)
//	{
//		if (r == -1 && c == -1)
//		{
//			r = rc;
//			c = cc;
//		}
//		PrintABox(r, c, 2);
//	}
//	void UnHighlightCell(int r = -1, int c = -1)
//	{
//		if (r == -1 && c == -1)
//		{
//			r = rc;
//			c = cc;
//		}
//		PrintABox(r, c, 15);
//	}
//	void PrintGrid()
//	{
//		for (int i = 0; i < r_size; i++)
//		{
//			for (int j = 0; j < c_size; j++)
//			{
//				PrintABox(i, j);
//			}
//		}
//	}
//	void PrintData()
//	{
//		cell* temp = head;
//		for (int i = 0; i < r_size; i++)
//		{
//			for (int j = 0; j < c_size; j++)
//			{
//				PrintCellData(i, j, temp);
//				temp = temp->next;
//			}
//			temp = head;
//			for (int k = 0; k <= i; k++)
//			{
//				temp = temp->down;
//			}
//		}
//	}
//	void PrintCellData(int r, int c, cell* p = nullptr)
//	{
//		string d;
//		int col;
//		if (p == nullptr)
//		{
//			if (r == rc and c == cc)
//			{
//				p = curr;
//			}
//			else if (r < r_size and c < c_size)
//			{
//				p = GetCell(r, c);
//			}
//			else
//			{
//				return;
//			}
//		}
//		d = p->GetData(cdim - 2);
//		col = p->GetColor;
//		if (p->GetAllign() == LEFT)
//		{
//			gotoRowCol(rc * rdim - rc + 2, cc * cdim - cc + 1);
//		}
//		else if (p->GetAllign() == CENTER)
//		{
//			gotoRowCol(rc * rdim - rc + 2, cc * cdim - cc + 1 + d.size() / 2);
//		}
//		else
//		{
//			gotoRowCol(rc * rdim - rc + 2, (cc + 1) * cdim - cc - d.size());
//		}
//		cout << d;
//	}
//	void PrintABox(int r, int c, int col = 15, char fill = '*')
//	{
//		color(col);
//		int r1 = r * rdim - r;
//		int c1 = c * cdim - c;
//		int r2 = r1 + rdim - 1;
//		int c2 = c1 + cdim - 1;
//		for (int i = r1; i <= r2; i++)
//		{
//			gotoRowCol(i, c1);
//			cout << fill;
//			gotoRowCol(i, c2);
//			cout << fill;
//		}
//		for (int i = c1; i <= c2; i++)
//		{
//			gotoRowCol(r1, i);
//			cout << fill;
//			gotoRowCol(r2, i);
//			cout << fill;
//		}
//		color(15);
//	}
//	void CurrentToLeft()
//	{
//		if (cc > 0)
//		{
//			UnHighlightCell();
//			cc--;
//			curr = curr->prev;
//			HighlightCell();
//		}
//	}
//	void CurrentToRight()
//	{
//		if (cc < c_size - 1)
//		{
//			UnHighlightCell();
//			cc++;
//			curr = curr->next;
//			HighlightCell();
//		}
//		else if (cc == c_size - 1)
//		{
//			UnHighlightCell();
//			InsertColumnToRight();
//			system("cls");
//			cc++;
//			curr = curr->next;
//			PrintGrid();
//			HighlightCell();
//		}
//	}
//	void CurrentToUp()
//	{
//		if (rc > 0)
//		{
//			UnHighlightCell();
//			rc--;
//			curr = curr->up;
//			HighlightCell();
//		}
//	}
//	void CurrentToDown()
//	{
//		if (rc < r_size - 1)
//		{
//			UnHighlightCell();
//			rc++;
//			curr = curr->down;
//			HighlightCell();
//		}
//		else if (rc == r_size - 1)
//		{
//			UnHighlightCell();
//			InsertRowBelow();
//			system("cls");
//			rc++;
//			curr = curr->down;
//			PrintGrid();
//			HighlightCell();
//		}
//	}
//	void ManageSlightHighlight()
//	{
//		POINT C;
//		int ri, ci;
//		int pri = -1, pci = -1;
//		while (true)
//		{
//			GetCursorPos(&C);
//			HWND hWnd = GetConsoleWindow();
//			ScreenToClient(hWnd, &C);
//			ri = C.y / (rdim * 8);
//			ci = (C.x + C.x / 12) / (cdim * 5);
//			if (ri != pri or ci != pci)
//			{
//				if (ri < r_size and ci < c_size)
//				{
//					UnHighlightCell(pri, pci);
//					HighlightCell();
//					PrintABox(ri, ci, 11);
//					pri = ri;
//					pci = ci;
//				}
//			}
//		}
//	}
//	void InputData()
//	{
//		string d;
//		char f;
//		do
//		{
//			gotoRowCol(rc * rdim - rc + 2, cc * cdim - cc + 1 + d.size());
//			f = _getche();
//			if (f == '\b')
//			{
//				if (!d.empty())
//				{
//					gotoRowCol(rc * rdim + 2, cc * cdim + d.size() - 1);
//					cout << ' ';
//					d.pop_back();
//				}
//				gotoRowCol(rc * rdim + 2, cc * cdim + d.size());
//			}
//			if (f != '\r')
//			{
//				d += f;
//			}
//		} while (f != '\r');
//		curr->changedata(d);
//	}
//public:
//	class Iterator
//	{
//		cell* i;
//		friend class cell;
//	public:
//		Iterator(cell* _i) : i(_i)
//		{
//		}
//		void operator++()
//		{
//			i = i->down;
//		}
//		void operator--()
//		{
//			i = i->up;
//		}
//		void operator++(int)
//		{
//			i = i->next;
//		}
//		void operator--(int)
//		{
//			i = i->prev;
//		}
//	};
//	Excel(int rows = 5, int cols = 5) : r_size(rows), c_size(cols)
//	{
//		head = curr = new cell();
//		cell* temp = head;
//		cell* pre;
//		cell* rowfirst;
//		for (int r = 0; r < r_size; r++)
//		{
//			pre = temp->up;
//			rowfirst = temp;
//			for (int c = 1; c < c_size; c++)
//			{
//				temp = temp->next = new cell("", temp);
//				if (pre != nullptr)
//				{
//					pre = pre->next;
//					pre->down = temp;
//					temp->up = pre;
//				}
//			}
//			if (r < r_size - 1)
//				temp = rowfirst = rowfirst->down = new cell("", nullptr, nullptr, rowfirst);
//		}
//		tail = temp;
//		rc = cc = 0;
//	}
//	void Main()
//	{
//		PrintGrid();
//		HighlightCell();
//		HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
//		DWORD Events = 0;
//		INPUT_RECORD InputRecord;
//		SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
//		thread MS(&Excel::ManageSlightHighlight, this);
//		while (1)
//		{
//			ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//			if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT && InputRecord.Event.KeyEvent.bKeyDown)
//			{
//				CurrentToLeft();
//			}
//			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && InputRecord.Event.KeyEvent.bKeyDown)
//			{
//				CurrentToRight();
//			}
//			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_UP && InputRecord.Event.KeyEvent.bKeyDown)
//			{
//				CurrentToUp();
//			}
//			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_DOWN && InputRecord.Event.KeyEvent.bKeyDown)
//			{
//				CurrentToDown();
//			}
//			else if (InputRecord.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED)
//			{
//				//cout << "ctrl";
//				while (LEFT_CTRL_PRESSED)
//				{
//					ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//					if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertColumnToLeft();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertColumnToRight();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x55 && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertRowAbove();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x44 && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertRowBelow();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x50 && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertCellByRightShift();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x4C && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						InsertCellByDownShift();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else
//						break;
//				}
//			}
//			else if (InputRecord.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED)
//			{
//				while (RIGHT_CTRL_PRESSED)
//				{
//					ReadConsoleInput(hInput, &InputRecord, 1, &Events);
//					if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						DelRow();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						DelCol();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x50 && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						DeleteCellByUpShift();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == 0x50 && InputRecord.Event.KeyEvent.bKeyDown)
//					{
//						DeleteCellByLeftShift();
//						system("cls");
//						PrintGrid();
//						HighlightCell();
//					}
//					else
//						break;
//				}
//			}
//			else if (InputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RETURN && InputRecord.Event.KeyEvent.bKeyDown)
//			{
//				InputData();
//			}
//
//		}
//		MS.detach();
//	}
//	~Excel()
//	{
//
//	}
//};
//
///*******************
///*     *     *     *
///*******************
///*     *     *     *
///*******************
///*     *     *     *
///*******************
//*/