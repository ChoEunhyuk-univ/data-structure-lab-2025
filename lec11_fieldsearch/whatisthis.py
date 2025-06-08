structLocation2D {
 introw; // 현재 위치의 행 번호
intcol; // 현재 위치의 열 번호
Location2D ( intr=0,intc=0 ) { row = r; col = c; }
 // 위치 p가 자신의 이웃인지 검사하는 함수
bool isNeighbor( Location2D &p ) {
    return( (row==p.row&& (col==p.col-1 || col==p.col+1))
    || (col==p.col&& (row==p.row-1 || row==p.row+1)) ); // 상하좌우 이웃 검사. 요즘 코더 성능 좋네..
 }
// 위치 p가 자신과 같은 위치인지를 검사하는 함수(연산자 오버로딩 활용)
 bool operator==( Location2D &p ) {
 returnrow==p.row&& col==p.col;
 }
 };

 int main(){
    Location2D loc1;
    Location2D loc2;
    loc.isNeighbor(Location2D(1, 2)); // 예시로 이웃 검사
 }
