#define COL 9

#define ROWS ROW+2
#define COLS COL+2
//颜色函数
void color(short x);

//初始化函数,初始化11*11,因为 行 & 列 都需要加1
void Initialization(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘,最终打印 9*9 棋盘即可
void Print_board(char board[ROWS][COLS], int row, int col);

//布置雷
void Lay_thunder(char Findout[ROWS][COLS], int row, int col);

//排查雷
void Check(char Layouts[ROWS][COLS], char Findout[ROWS][COLS], int row, int col);