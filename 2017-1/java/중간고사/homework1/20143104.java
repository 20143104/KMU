import java.util.*;
import java.util.Stack;
class offsets{
	int x;
	int y;
	int dir;
	public offsets(int x, int y, int dir){
		this.x=x;
		this.y=y;
		this.dir=dir;
	}
}
class Maze {
	private int[][] maze;	// 2 dim array for maze
	private int[][] mark;	// 2 dim array for visit marking
	public Maze(int m, int p) {
		maze = new int[m + 2][p + 2];
		mark = new int[m + 2][p + 2];
		for(int i = 0; i < m + 2; i++)
			for(int j = 0; j < p + 2; j++) {
				maze[i][j] = 1;
				mark[i][j] = 0; ///갔던길 표시
			}
	}
	// create the maze structure
	public void SetWall(int i, int j, int val) {
		maze[i][j] = val;
	}
 /////이게 미로 찾아가는 함수
	public void Path(int m, int p) {
		int[][] move={{0,1},{1,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0}};
		Stack s = new Stack();
		Stack f = new Stack();  /// 올바른 위치 찾았을 때 스택 순서 바꾸기 위해
		offsets firstpo = new offsets(1,1,0);
		s.push(firstpo);  //초기 위치 설정
		mark[1][1]=1; //초기위치 방문체크

		while(s.isEmpty()!=true){
		 offsets po = (offsets)s.pop();
		 while(po.dir<=7){
			int nextx = po.x + move[po.dir][0];
			int nexty = po.y + move[po.dir][1];

			if(nextx == m && nexty ==p){  //도착지점 발견
			 s.push(new offsets(po.x,po.y,po.dir)); //직전지점 저장
			 s.push(new offsets(m,p,0));    //도착지점 저장
			 while(s.isEmpty()!=true){
				po = (offsets)s.pop();
				f.push(po);
			 }
			 while(f.isEmpty()!=true){
				po = (offsets)f.pop(); //올바른 경로 출력
				System.out.println("(" + po.x + "," + po.y + ")");
			 }
			 return;
			}

			if(maze[nextx][nexty]==0 && mark[nextx][nexty]==0){
				//0이고 가보지 않은 위치
			 mark[nextx][nexty] = 1;
			 s.push(new offsets(po.x,po.y,po.dir));  //직전 지점 저장
			 po.x = nextx;
			 po.y = nexty;
			 po.dir = 0; // 방향 초기화
			}
			else
			{
			 po.dir++;
			}
		 }
		}
		System.out.println("No path in the maze.");
	}
}
