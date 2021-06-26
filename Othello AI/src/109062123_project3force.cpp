#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <utility>
#include <queue>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define F first
#define S second
#define poi std::pair<OthelloBoard, int>
#define ppp std::pair<OthelloBoard, Point>

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
    int my_tiles = 0, opp_tiles = 0, i, j, k, my_front_tiles = 0, opp_front_tiles = 0, x, y;
	double p = 0, c = 0, l = 0, m = 0, f = 0, d = 0;

	int X1[] = {-1, -1, 0, 1, 1, 1, 0, -1};
	int Y1[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int V[8][8] = {
        {40, -3, 11, 8, 8, 11, -3, 40},
    	{-3, -7, -4, 1, 1, -4, -7, -3},
    	{11, -4, 2, 2, 2, 2, -4, 11},
    	{8, 1, 2, -3, -3, 2, 1, 8},
    	{8, 1, 2, -3, -3, 2, 1, 8},
    	{11, -4, 2, 2, 2, 2, -4, 11},
    	{-3, -7, -4, 1, 1, -4, -7, -3},
    	{40, -3, 11, 8, 8, 11, -3, 40}
    	};


	for(i=0; i<8; i++)
		for(j=0; j<8; j++)  {
			if(now.board[i][j] == player)  {
				d += V[i][j];
				my_tiles++;
			} else if(now.board[i][j] == 3 - player)  {
				d -= V[i][j];
				opp_tiles++;
			}
			if(now.board[i][j] != 0)   {
				for(k=0; k<8; k++)  {
					x = i + X1[k]; y = j + Y1[k];
					if(x >= 0 && x < 8 && y >= 0 && y < 8 && now.board[x][y] == 0) {
						if(now.board[i][j] == player)  my_front_tiles++;
						else opp_front_tiles++;
						break;
					}
				}
			}
		}
	if(my_tiles > opp_tiles)
		p = (100.0 * my_tiles)/(my_tiles + opp_tiles);
	else if(my_tiles < opp_tiles)
		p = -(100.0 * opp_tiles)/(my_tiles + opp_tiles);
	else p = 0;

	if(my_front_tiles > opp_front_tiles)
		f = -(100.0 * my_front_tiles)/(my_front_tiles + opp_front_tiles);
	else if(my_front_tiles < opp_front_tiles)
		f = (100.0 * opp_front_tiles)/(my_front_tiles + opp_front_tiles);
	else f = 0;

	my_tiles = opp_tiles = 0;
	if(now.board[0][0] == player) my_tiles++;
	else if(now.board[0][0] == 3 - player) opp_tiles++;
	if(now.board[0][7] == player) my_tiles++;
	else if(now.board[0][7] == 3 - player) opp_tiles++;
	if(now.board[7][0] == player) my_tiles++;
	else if(now.board[7][0] == 3 - player) opp_tiles++;
	if(now.board[7][7] == player) my_tiles++;
	else if(now.board[7][7] == 3 - player) opp_tiles++;
	c = 25 * (my_tiles - opp_tiles);

	my_tiles = opp_tiles = 0;
	if(now.board[0][0] == 0)   {
		if(now.board[0][1] == player) my_tiles++;
		else if(now.board[0][1] == 3 - player) opp_tiles++;
		if(now.board[1][1] == player) my_tiles++;
		else if(now.board[1][1] == 3 - player) opp_tiles++;
		if(now.board[1][0] == player) my_tiles++;
		else if(now.board[1][0] == 3 - player) opp_tiles++;
	}
	if(now.board[0][7] == 0)   {
		if(now.board[0][6] == player) my_tiles++;
		else if(now.board[0][6] == 3 - player) opp_tiles++;
		if(now.board[1][6] == player) my_tiles++;
		else if(now.board[1][6] == 3 - player) opp_tiles++;
		if(now.board[1][7] == player) my_tiles++;
		else if(now.board[1][7] == 3 - player) opp_tiles++;
	}
	if(now.board[7][0] == 0)   {
		if(now.board[7][1] == player) my_tiles++;
		else if(now.board[7][1] == 3 - player) opp_tiles++;
		if(now.board[6][1] == player) my_tiles++;
		else if(now.board[6][1] == 3 - player) opp_tiles++;
		if(now.board[6][0] == player) my_tiles++;
		else if(now.board[6][0] == 3 - player) opp_tiles++;
	}
	if(now.board[7][7] == 0)   {
		if(now.board[6][7] == player) my_tiles++;
		else if(now.board[6][7] == 3 - player) opp_tiles++;
		if(now.board[6][6] == player) my_tiles++;
		else if(now.board[6][6] == 3 - player) opp_tiles++;
		if(now.board[7][6] == player) my_tiles++;
		else if(now.board[7][6] == 3 - player) opp_tiles++;
	}
	l = -12.5 * (my_tiles - opp_tiles);

    int oldplayer = now.cur_player;
    now.cur_player = player;
	my_tiles = now.get_valid_spots().size();
    now.cur_player = 3 - player;
	opp_tiles = now.get_valid_spots().size();
    now.cur_player = oldplayer;
	if(my_tiles > opp_tiles)
		m = (100.0 * my_tiles)/(my_tiles + opp_tiles);
	else if(my_tiles < opp_tiles)
		m = -(100.0 * opp_tiles)/(my_tiles + opp_tiles);
	else m = 0;

	double score = (10 * p) + (801.724 * c) + (382.026 * l) + (78.922 * m) + (74.396 * f) + (10 * d);
	return score;
}
bool operator <(OthelloBoard a, OthelloBoard b){
    return a.cur_player < b.cur_player;
}
std::map<OthelloBoard,int> ma;
struct cmp{
    bool operator()( const ppp& a , const ppp& b )const{
        return ma[a.F] < ma[b.F] ;
    }
};

int alpha_beta(int depth, int lim,int alpha, int beta, OthelloBoard now, bool minimax, std::ofstream& fout){
    if(depth == lim || now.done){
        int value = value_f(now, player);
        ma.insert(poi(now, value));
        return value;
    }
    std::priority_queue<ppp, std::vector<ppp>, cmp> pq;
    for(int i = 0 ; i < now.next_valid_spots.size() ; i++){
        OthelloBoard newboard = now;
        newboard.put_disc(now.next_valid_spots[i]);
        pq.push(ppp(newboard,now.next_valid_spots[i]));
    }
    if(minimax){
        int maxeval = -1e9;
        if(now.cur_player != player)return alpha_beta(depth + 1, lim, alpha, beta, now, !minimax, fout);
        while(!pq.empty()){
            Point movement = pq.top().S;
            OthelloBoard newboard = pq.top().F;pq.pop();
            int eval = alpha_beta(depth + 1, lim, alpha, beta, newboard, !minimax, fout);
            maxeval = max(maxeval, eval);
            if(depth == 0 && eval > alpha){
                write_valid_spot(movement, fout);
            }
            alpha = max(alpha, eval);
            if(beta <= alpha)break;
        }
        return maxeval;
    }else{
        int mineval = 1e9;
        if(now.cur_player != 3 - player)return alpha_beta(depth + 1, lim, alpha, beta, now, !minimax, fout);
        while(!pq.empty()){
            OthelloBoard newboard = pq.top().F;pq.pop();
            int eval = alpha_beta(depth + 1, lim, alpha, beta, newboard, !minimax, fout);
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
    for(int i = 1 ; i < 1000 ; i++){
        alpha_beta(0, i, -1e9, 1e9, now, 1, fout);
    }
    fin.close();
    fout.close();
    return 0;
}
