#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    vector<int> frameScores;
    int totalScore;

    bool operator<(const Player& other) const {
        if (totalScore != other.totalScore)
            return totalScore > other.totalScore;
        return name < other.name;
    }
};


vector<int> parseThrows(const string& line) {
    vector<int> throws;
    for (char c : line) {
        if (c == 'X')
            throws.push_back(10);
        else
            throws.push_back(c - '0');
    }
    return throws;
}


vector<int> computeFrameScores(const vector<int>& throws) {
    vector<int> frameScores;
    int i = 0;
    for (int frame = 0; frame < 10; ++frame) {
        if (throws[i] == 10) { 
            if (frame < 9)
                frameScores.push_back(10 + throws[i + 1] + throws[i + 2]);
            else
                frameScores.push_back(throws[i] + throws[i + 1] + throws[i + 2]);
            i += 1;
        }
        else if (throws[i] + throws[i + 1] == 10) { 
            if (frame < 9)
                frameScores.push_back(10 + throws[i + 2]);
            else
                frameScores.push_back(throws[i] + throws[i + 1] + throws[i + 2]);
            i += 2;
        }
        else { 
            frameScores.push_back(throws[i] + throws[i + 1]);
            i += 2;
        }
    }
    return frameScores;
}


vector<int> accumulateScores(const vector<int>& frameScores) {
    vector<int> acc;
    int sum = 0;
    for (int score : frameScores) {
        sum += score;
        acc.push_back(sum);
    }
    return acc;
}

int main() {
    int X;
    cin >> X;
    cin.ignore();

    vector<Player> players;

    for (int p = 0; p < X; ++p) {
        string name, throwStr;
        getline(cin, name);
        getline(cin, throwStr);

        vector<int> throws = parseThrows(throwStr);
        vector<int> frameScores = computeFrameScores(throws);
        vector<int> acc = accumulateScores(frameScores);

        int total = acc.back();
        players.push_back({ name, acc, total });
    }

    sort(players.begin(), players.end());


    for (const auto& player : players) {
        cout << player.name << " : ";
        for (int score : player.frameScores)
            cout << "|" << score;
        cout << "| Total = " << player.totalScore << endl;
    }

    return 0;
}
