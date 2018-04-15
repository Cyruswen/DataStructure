#include<stdio.h>
#include<stddef.h>

#define MAX_COL 6
#define MAX_ROW 6

typedef struct Maze {
    int map[MAX_ROW][MAX_COL];
} Maze;

void MazeInit(Maze* maze){
    if(maze == NULL){
        return;
    }
    int map[MAX_ROW][MAX_COL] = { 
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,0,0,0,0},
        {0,1,1,1,1,0},
        {0,0,1,0,0,0},
        {0,0,1,0,0,0}
    };
    size_t i = 0;
    for(; i < MAX_ROW;i++){
        size_t j = 0;
        for(; j < MAX_COL; j++){
            maze->map[i][j] = map[i][j];
        }
    }
    return;
}

void MazePrint(Maze* maze){
    if(maze == NULL){
        return;
    }
    size_t i = 0;
    for(; i < MAX_ROW; i++){
        size_t j = 0;
        for(; j < MAX_COL; j++){
            printf("%d ",maze->map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}



//#######################################################################
//######################## 迷宫求解（递归的方法）########################
//#######################################################################

typedef struct Point {
    int row;
    int col;
} Point;

int CanStay(Maze* maze, Point pt){
    //如果pt在地图外一定不能落脚
    if(pt.row < 0 || pt.col < 0 || pt.row >= MAX_ROW || pt.col >= MAX_COL){
        return 0;
    }
    //如果在地图内，0和2不可以落脚，1可以落脚
    int value = maze->map[pt.row][pt.col];
    if(value == 0 || value == 2){
        return 0;
    }
    return 1;
}

void Mark(Maze* maze,Point pt){
    maze->map[pt.row][pt.col] = 2;
    return;
}

int IsExit(Maze* maze, Point pt, Point entry){
    (void)maze;
    //如果不是入口点且当前点在地图边界上，是出口点
    if(pt.row == entry.row && pt.col == entry.col){
        return 0;
    }
    if(pt.row == 0 || pt.col == 0 || pt.col == MAX_COL-1 || pt.row == MAX_ROW-1){
        return 1;
    }
    return 0;
}

void _GetPath(Maze* maze, Point cur, Point entry){
    if(maze == NULL){
        return;
    }
    printf("%d %d\n",cur.row,cur.col);
    if(!CanStay(maze, cur)){
        //判断当前点能否落脚
        return;
    }
   //printf("%d %d\n",cur.row,cur.col);
   //如果能落脚，给当前点做标记
   Mark(maze, cur);
   //如果当前点是出口，说明找到一条路径，探测结束
   if(IsExit(maze, cur, entry)){
       return;
   }
   //如果当前点不是出口，按顺时针探测相邻的四个相邻方向
   //交给递归判断
   Point up = cur;
   up.row -= 1;
   _GetPath(maze, up, entry);

   Point down = cur;
   down.row += 1;
   _GetPath(maze, down, entry);

   Point left = cur;
   left.col -= 1;
   _GetPath(maze, left, entry);

   Point right = cur;
   right.col += 1;
   _GetPath(maze, right, entry);
   return;
}

void GetPath(Maze* maze, Point entry){
    if(maze == NULL){
        return;
    }
    Point cur = entry;
    _GetPath(maze, cur, entry);
    return;
}

//#######################################################################
//################################ TEST #################################
//#######################################################################

#define TestType printf("\n############################### %s ###############################\n",__FUNCTION__)

void TestMazePrint(){
    TestType;
    Maze maze;
    MazeInit(&maze);
    return;
}

void TestGetPath(){
    TestType;
    Maze maze;
    Point entry = {0,1};
    MazeInit(&maze);
    MazePrint(&maze);
    GetPath(&maze, entry);
    printf("\n");
    MazePrint(&maze);
}

int main(){
    TestMazePrint();
    TestGetPath();
    return 0;
}
