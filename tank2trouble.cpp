//xe tang trong me cung
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

void displayInstructions() {
    cout << "Chao mung den voi Tank 2 Trouble!" << endl;
    cout << "Ban se dieu khien xe tang va tieu diet ke thu." << endl;
    cout << "Co 3 loai ke thu: 1. Dễ, 2. Trung bình, 3. Khó." << endl;
    cout << "Ban co 10 giay cho moi vong." << endl;
}

int generateEnemyPosition(int level) {
    return rand() % (10 + level); // Tăng độ khó theo cấp độ
}

int generateEnemyType() {
    return rand() % 3 + 1; // 1: Dễ, 2: Trung bình, 3: Khó
}

void playerTurn(int& score, int level) {
    int shot;
    int enemyType = generateEnemyType();
    int enemyPosition = generateEnemyPosition(level);
    
    cout << "Ke thu (Loai " << enemyType << ") o vi tri: " << enemyPosition << endl;

    auto start = chrono::steady_clock::now();
    cout << "Nhap vi tri ban (1-" << (10 + level) << "): ";
    cin >> shot;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    if (elapsed_seconds.count() > 10) {
        cout << "Thoi gian het han! Ban da bo lo!" << endl;
        return;
    }

    if (shot == enemyPosition) {
        cout << "Ban da tieu diet ke thu!" << endl;
        score += (enemyType == 1) ? 5 : (enemyType == 2) ? 10 : 15; // Điểm số theo loại kẻ thù
    } else {
        cout << "Ban da bo lo!" << endl;
    }
}

void usePowerUp(int& score) {
    cout << "Ban da su dung vat pham ho tro! Diem so +20!" << endl;
    score += 20; // Tăng điểm khi sử dụng vật phẩm
}

int main() {
    srand(time(0)); // Khởi tạo ngẫu nhiên
    displayInstructions();
    
    int rounds = 5; // Số vòng chơi
    int score = 0; // Điểm số
    int level = 1; // Cấp độ

    for (int i = 0; i < rounds; i++) {
        cout << "Vong " << (i + 1) << " - Cap do: " << level << endl;
        if (rand() % 5 == 0) { // 20% cơ hội để nhận vật phẩm
            usePowerUp(score);
        }
        playerTurn(score, level);
        level++; // Tăng cấp độ sau mỗi vòng
    }
    
    cout << "Game over! Diem so cua ban: " << score << endl;
    return 0;
}