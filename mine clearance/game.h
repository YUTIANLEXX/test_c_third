#define COL 9

#define ROWS ROW+2
#define COLS COL+2
//��ɫ����
void color(short x);

//��ʼ������,��ʼ��11*11,��Ϊ �� & �� ����Ҫ��1
void Initialization(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����,���մ�ӡ 9*9 ���̼���
void Print_board(char board[ROWS][COLS], int row, int col);

//������
void Lay_thunder(char Findout[ROWS][COLS], int row, int col);

//�Ų���
void Check(char Layouts[ROWS][COLS], char Findout[ROWS][COLS], int row, int col);