﻿//cac cach di chuyen
#define leftx 0
#define lefty -1
#define rightx 0
#define righty 1
#define topx -1
#define topy 0
#define botx 1
#define boty 0


const char space = ' ';
const char me = '@';
const char Quai = 'Q';
extern char lvl1[20][20] = {	{'|' , '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '|' }
								, {'|' , '@' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ', '#' , ' ' , '#' , ' ' , '#' , '#' , '4' , '#' , '|'}
								, {'|' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '|'}
								, {'|' , ' ' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#', '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '|'}
								, {'|' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , '3' , '#' , ' ', ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , '|'}
								, {'|' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , ' #', '#' , '#', ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '|'}
								, {'|' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '#', ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , ' ' , '|'}
								, {'|' , ' ' , '#' , '#' , '2' , ' ' , '#' , ' ' , ' ' , '#' , ' ', ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '#' , '|'}
								, {'|' , ' ' , ' ' , ' ' , '#' , '#' , ' ' , ' ' , ' ' , '#' , '#', ' ' , '#' , '#' , '#' , '#' , ' ' , ' ' , '#' , '|'}
								, {'|' , '#' , '#' , ' ' , ' ' , ' ' , '#' , '#' , ' ' , '#' , ' ', ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '|'}
								, {'|' , ' ' , '1' , '#' , '#' , ' ' , '#' , ' ' , ' ' , '#' , ' ', '#' , ' ' , ' ' , '#' , '#' , ' ' , '#' , ' ' , '|'}
								, {'|' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , '#' , ' ', ' ' , '#' , ' ' , ' ' , '#' , '#' , '#' , ' ' , '|'}
								, {'|' , ' ' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , ' ', '#' , ' ' , '#' , '#' , '#' , ' ' , ' ' , ' ' , '|'}
								, {'|' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , '#' , ' ', ' ' , ' ' , ' ' , '#' , ' ' , ' ' , '#' , '#' , '|'}
								, {'|' , '#' , ' ' , '#' , '#' , ' ' , '#' , ' ' , ' ' , '#' , '#', ' ' , '#' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '|'}
								, {'|' , ' ' , ' ' , '#' , ' ' , ' ' , '#' , '#' , '#' , '#' , ' ', '#' , '#' , ' ' , '#' , '#' , ' ' , '#' , '#' , '|'}
								, {'|' , ' ' , '#' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ', ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '|'}
								, {'|' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#', ' ' , '#' , ' ' , '#' , '#' , '#' , ' ' , ' ' , '|'}
								, {'|' , '#' , ' ' , '3' , '#' , '1' , ' ' , '2' , '#' , '4' , '#', ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , 'O' , '|'}
								, {'|' ,  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '|' } };

extern char lvl2[20][20] = { { '|' , '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '|' },
					  {   '|', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', ' ', '6', '#', '#', 'X', '#', '|' },
					  {   '|', ' ', '#', '#', '#', '#', ' ', ' ', '#', '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', '|' },
					  {   '|', ' ', '#', ' ', ' ', '#', ' ', ' ', '4', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', 'T', '|' },
					  {   '|', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '|' },
					  {   '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '5', ' ', ' ', '|' },
					  {   '|', '#', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#', '#', ' ', '#', '|' },
					  {   '|', ' ', '#', ' ', '#', '4', '#', ' ', '#', 'T', ' ', '#', '#', '#', '#', '#', ' ', 'Q', '#', 'O' },
					  {   '|', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', '#', '5', ' ', ' ', ' ', ' ', '#', '#', '#', '|' },
					  {   '@', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '|' },
					  {   '|', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', '3', '#', '6', '#', ' ', '#', ' ', '|' },
					  {   '|', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '|' },
					  {   '|', ' ', '#', ' ', '#', ' ', '#', '1', '#', ' ', '#', ' ', '#', ' ' ,' ', ' ', ' ', '#', ' ', '|' },
					  {   '|', ' ', '#', '#', '#', ' ', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', ' ', '#', ' ', '|' },
					  {   '|', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', '|' },
					  {   '|', ' ' ,' ', ' ', ' ', ' ', '#', ' ', '#', '2', '#', ' ', ' ', ' ', '#', '#', '#', ' ', '#', '|' },
					  {   '|', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', '2', ' ', ' ', ' ', ' ', '#', ' ', '#', '|' },
					  {   '|', '1', ' ', '#', 'T', '#', '3', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '|' },
					  {   '|', ' ', ' ', 'Q', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', ' ', '#', ' ', ' ', '|' },
					  {  '|' ,  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=',  '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '|' } };


extern char lvl3[25][25] =
{ {'|' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=', '=', '=', '=', '=', '|'}
, {'|' , '1' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ', ' ', ' ', ' ', 'T', '|'}
, {'|' , ' ' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , '#', '#', '#', '#', '#', '|'}
, {'|' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '#' , '#' , ' ' , '#' , ' ' , ' ', '8', '#', ' ', ' ', '|'}
, {'|' , ' ' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , '4' , '#' , '#' , '#' , '#' , '#', '#', '#', '#', ' ', '|'}
, {'|' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#', '5', '#', ' ', ' ', '|'}
, {'|' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#' , ' ' , '#', ' ', '#', '#', '#', '|'}
, {'|' , ' ' , 'T' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#', ' ', ' ', ' ', ' ', '|'}
, {'|' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , '#', ' ', '#', '#', ' ', '|'}
, {'|' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , '#', '#', '#', ' ', ' ', '|'}
, {'|' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , ' ' , '5' , '#' , ' ' , '#' , '#' , ' ' , '#' , ' ', ' ', ' ', '#', '#', '|'}
, {'|' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , '#' , '#' , 'T' , '#' , '7' , ' ' , '#' , '#', '#', '#', ' ', ' ', '|'}
, {'|' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , '#' , ' ', ' ', '#', '#', 'O', '|'}
, {'|' , ' ' , '#' , '8' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , '7' , ' ', ' ', ' ', '#', '#', '|'}
, {'|' , ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#', '#', ' ', ' ', '#', '|'}
, {'|' , ' ' , '#' , ' ' , ' ' , '#' , '6' , ' ' , '#' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ', '2', '#', ' ', ' ', '|'}
, {'|' , ' ' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#', '#', '#', ' ', '#', '|'}
, {'|' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '#', ' ', '#', '#', '#', '|'}
, {'|' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , '#' , ' ' , '#', ' ', ' ', ' ', ' ', '|'}
, {'|' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '4' , '#' , '3' , '#' , ' ' , ' ', ' ', '#', '#', '#', '|'}
, {'|' , ' ' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , '#' , '#', '#', '#', '2', '#', '|'}
, {'|' , ' ' , '#' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , '#' , ' ' , '#' , '1' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , ' ', ' ', ' ', ' ', '#', '|'}
, {'|' , ' ' , '#' , ' ' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , ' ' , '#' , '#' , '#' , '#' , ' ', '#', '#', ' ', ' ', '|'}
, {'|' , '@' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , '6' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , '3' , '#' , 'T', '#', ' ', ' ', '#', '|'}
, {'|' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=' , '=', '=', '=', '=', '=', '|'} };

