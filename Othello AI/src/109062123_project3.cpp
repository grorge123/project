#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)

struct Point {
    int x, y;
	Point() : Point(0, 0) {}
	Point(float x, float y) : x(x), y(y) {}
	bool operator==(const Point& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator!=(const Point& rhs) const {
		return !operator==(rhs);
	}
	Point operator+(const Point& rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
};

int player;
const int SIZE = 8;
std::array<std::array<int, SIZE>, SIZE> board;
std::vector<Point> next_valid_spots;

void read_board(std::ifstream& fin) {
    fin >> player;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fin >> board[i][j];
        }
    }
}

void write_valid_spot(Point out, std::ofstream& fout) {
    fout << out.x << " " << out.y << std::endl;
    fout.flush();
}


class OthelloBoard {
public:
    enum SPOT_STATE {
        EMPTY = 0,
        BLACK = 1,
        WHITE = 2
    };
    static const int SIZE = 8;
    const std::array<Point, 8> directions{{
        Point(-1, -1), Point(-1, 0), Point(-1, 1),
        Point(0, -1), /*{0, 0}, */Point(0, 1),
        Point(1, -1), Point(1, 0), Point(1, 1)
    }};
    std::array<std::array<int, SIZE>, SIZE> board;
    std::vector<Point> next_valid_spots;
    std::array<int, 3> disc_count;
    int cur_player;
    bool done;
    int winner;
private:
    int get_next_player(int player) const {
        return 3 - player;
    }
    bool is_spot_on_board(Point p) const {
        return 0 <= p.x && p.x < SIZE && 0 <= p.y && p.y < SIZE;
    }
    int get_disc(Point p) const {
        return board[p.x][p.y];
    }
    void set_disc(Point p, int disc) {
        board[p.x][p.y] = disc;
    }
    bool is_disc_at(Point p, int disc) const {
        if (!is_spot_on_board(p))
            return false;
        if (get_disc(p) != disc)
            return false;
        return true;
    }
    bool is_spot_valid(Point center) const {
        if (get_disc(center) != EMPTY)
            return false;
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(cur_player)))
                continue;
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player))
                    return true;
                p = p + dir;
            }
        }
        return false;
    }
    void flip_discs(Point center) {
        for (Point dir: directions) {
            // Move along the direction while testing.
            Point p = center + dir;
            if (!is_disc_at(p, get_next_player(cur_player)))
                continue;
            std::vector<Point> discs({p});
            p = p + dir;
            while (is_spot_on_board(p) && get_disc(p) != EMPTY) {
                if (is_disc_at(p, cur_player)) {
                    for (Point s: discs) {
                        set_disc(s, cur_player);
                    }
                    disc_count[cur_player] += discs.size();
                    disc_count[get_next_player(cur_player)] -= discs.size();
                    break;
                }
                discs.push_back(p);
                p = p + dir;
            }
        }
    }
public:
    OthelloBoard(std::array<std::array<int, SIZE>, SIZE> new_board, int player) {
         board = new_board;
         cur_player = player;
         next_valid_spots = get_valid_spots();
         done = false;
         for(int i = 0 ; i < 8 ; i++){
            for(int q = 0 ; q < 8 ; q++){
                disc_count[board[i][q]]++;
            }
         }
    }
    std::vector<Point> get_valid_spots() const {
        std::vector<Point> valid_spots;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                Point p = Point(i, j);
                if (board[i][j] != EMPTY)
                    continue;
                if (is_spot_valid(p))
                    valid_spots.push_back(p);
            }
        }
        return valid_spots;
    }
    bool put_disc(Point p) {
        set_disc(p, cur_player);
        disc_count[cur_player]++;
        disc_count[EMPTY]--;
        flip_discs(p);
        // Give control to the other player.
        cur_player = get_next_player(cur_player);
        next_valid_spots = get_valid_spots();
        // Check Win
        if (next_valid_spots.size() == 0) {
            cur_player = get_next_player(cur_player);
            next_valid_spots = get_valid_spots();
            if (next_valid_spots.size() == 0) {
                // Game ends
                done = true;
                int white_discs = disc_count[WHITE];
                int black_discs = disc_count[BLACK];
                if (white_discs == black_discs) winner = EMPTY;
                else if (black_discs > white_discs) winner = BLACK;
                else winner = WHITE;
            }
        }
        return true;
    }
};
int value_f(OthelloBoard now, int player){
//    std::cout << "----------------------" << std::endl;
//    for(int i = 0 ; i < 8 ; i ++){
//        for(int q = 0 ; q < 8 ; q++){
//            std::cout << now.board[i][q] << ' ' ;
//        }
//        std::cout << std::endl;
//    }
//    std::cout <<":"<<player<< "---------------------------" << std::endl;
    if(now.done){
        return now.winner == player ? 1e8 : -1e8;
    }
    int re = 0;
    Point master[] = {Point(0,0), Point(0,7), Point(7,0), Point(7,7)};
    for(auto po : master){
        if(now.board[po.x][po.y] == player)re += 10000;
        if(now.board[po.x][po.y] == 3 - player)re -= 10000;
    }
    Point special[4][3] = {{Point(0, 1), Point(1, 0), Point(1, 1)}, {Point(0, 6), Point(1, 6), Point(1, 7)}, {Point(6, 0), Point(6, 1), Point(7, 1)}, {Point(6, 6), Point(6, 7), Point(7, 6)}};
    for(int i = 0 ; i < 4 ; i++){
        for(auto po : special[i]){
            if(now.board[master[i].x][master[i].y] == player && now.board[po.x][po.y] == player) re += 300;
            if(now.board[master[i].x][master[i].y] == 0 && now.board[po.x][po.y] == player) re -= 500;
            if(now.board[master[i].x][master[i].y] == 3 - player && now.board[po.x][po.y] != player) re -= 800;
            if(now.board[master[i].x][master[i].y] == 0 && now.board[po.x][po.y] == 3 - player) re += 300;
        }
    }
    for(int i = 0 ; i < 4 ; i++){
        if(now.board[0][i+2] == player)re += 300;
        if(now.board[7][i+2] == player)re += 300;
        if(now.board[i+2][0] == player)re += 300;
        if(now.board[i+2][7] == player)re += 300;
        if(now.board[0][i+2] == 3 - player)re -= 300;
        if(now.board[7][i+2] == 3 - player)re -= 300;
        if(now.board[i+2][0] == 3 - player)re -= 300;
        if(now.board[i+2][7] == 3 - player)re -= 300;
    }
    for(int i = 1 ; i < 7 ; i++){
        for(int q = 1 ; q < 7 ; q++){
            if((i==1&&q==1)||(i==1&&q==6)||(i==6&&q==1)||(i==6&&q==6))continue;
            if(now.board[i][q] == player)re += 1;
            if(now.board[i][q] == 3 - player) re -= 1;
        }
    }
    return re;
}

int alpha_beta(int depth, int lim,int alpha, int beta, OthelloBoard now, bool minimax, std::ofstream& fout){
    if(depth == lim || now.done){
        return value_f(now, player);
    }
    if(minimax){
        int maxeval = -1e9;
        if(now.cur_player != player)return alpha_beta(depth + 1, lim, alpha, beta, now, !minimax, fout);
        for(int i = 0 ; i < now.next_valid_spots.size() ; i ++){
            OthelloBoard newboard = now;
            newboard.put_disc(now.next_valid_spots[i]);
            int eval = alpha_beta(depth + 1, lim, alpha, beta, newboard, !minimax, fout);
//            std::cout << "MAX:" << depth << ' ' <<now.next_valid_spots[i].x << ' ' << now.next_valid_spots[i].y << ' ' << eval << std::endl;
            maxeval = max(maxeval, eval);
            if(depth == 0 && eval > alpha){
                write_valid_spot(now.next_valid_spots[i], fout);
            }
            alpha = max(alpha, eval);
            if(beta <= alpha)break;
        }
        return maxeval;
    }else{
        int mineval = 1e9;
        if(now.cur_player != 3 - player)return alpha_beta(depth + 1, lim, alpha, beta, now, !minimax, fout);
        for(int i = 0 ; i < now.next_valid_spots.size() ; i ++){
            OthelloBoard newboard = now;
            newboard.put_disc(now.next_valid_spots[i]);
            int eval = alpha_beta(depth + 1, lim, alpha, beta, newboard, !minimax, fout);
//            std::cout << "MIN:" << now.next_valid_spots[i].x << ' ' << now.next_valid_spots[i].y << ' ' << eval << std::endl;
            mineval = min(mineval, eval);
            beta = min(beta, eval);
            if(beta <= alpha)break;
        }
        return mineval;
    }
}
int main(int, char** argv) {
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    OthelloBoard now(board, player);
//    for(int i = 1 ; i < 1000 ; i++){
//        alpha_beta(0, i, -1e9, 1e9, now, 1, fout);
//    }
    alpha_beta(0, 6, -1e9, 1e9, now, 1, fout);
    fin.close();
    fout.close();
    return 0;
}
