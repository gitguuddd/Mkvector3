//
// Created by Mindaugas K on 5/28/2019.
//

#ifndef OBJ_DUOMENU_APDOROJIMAS_TIMER_H
#define OBJ_DUOMENU_APDOROJIMAS_TIMER_H
#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
        return std::chrono::duration<double>
                (std::chrono::high_resolution_clock::now() - start).count();
    }
};
#endif //OBJ_DUOMENU_APDOROJIMAS_TIMER_H
