#include <iostream>
#include <thread>
#include <atomic>


std::atomic<bool> interested[2]; 
std::atomic<int> turn;          

int counter = 0; 

void petersonAlgorithm(int id, int num_iterations) {
    int other = 1 - id;

    for (int i = 0; i < num_iterations; ++i) {
        interested[id] = true;
        turn = other;

        while (interested[other] && turn == other) {
        }

        ++counter;
        std::cout << "Thread " << id << " a incrémenté le compteur à " << counter << std::endl;

        interested[id] = false;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    int num_iterations = 10; 

    interested[0] = false;
    interested[1] = false;
    turn = 0;

    std::thread t1(petersonAlgorithm, 0, num_iterations);
    std::thread t2(petersonAlgorithm, 1, num_iterations);

    t1.join();
    t2.join();

    std::cout << "Valeur finale du compteur: " << counter << std::endl;

    return 0;
}
