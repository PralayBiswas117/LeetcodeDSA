class Solution {
    int minBishopMoves(vector<int>& source, vector<int>& target, vector<int>& blocker) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        int br = blocker[0], bc = blocker[1];
        if (((sr + sc) & 1) != ((tr + tc) & 1)) return -1;
        if (sr - sc == tr - tc) {
            if (br - bc == sr - sc && br > min(sr, tr) && br < max(sr, tr)) return 2;
            return 1;
        }
        if (sr + sc == tr + tc) {
            if (br + bc == sr + sc && br > min(sr, tr) && br < max(sr, tr)) return 2;
            return 1;
        }
        return 2;
    }
    
    int minRookMoves(vector<int>& source, vector<int>& target, vector<int>& blocker) {
        int sr = source[0], sc = source[1];
        int tr = target[0], tc = target[1];
        int br = blocker[0], bc = blocker[1];
        if (sr == tr) {
            if (br == sr && bc > min(sc, tc) && bc < max(sc, tc)) return 2;
            return 1;
        }
        if (sc == tc) {
            if (bc == sc && br > min(sr, tr) && br < max(sr, tr)) return 2;
            return 1;
        }
        return 2;
    }

public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        vector<int> rookPosition = {a, b};
        vector<int> bishopPosition = {c, d};
        vector<int> queenPosition = {e, f};

        int possibility1 = minBishopMoves(bishopPosition, queenPosition, rookPosition);
        int possibility2 = minRookMoves(rookPosition, queenPosition, bishopPosition);
        
        if (possibility1 == -1) return possibility2;
        return min(possibility1, possibility2);
    }
};