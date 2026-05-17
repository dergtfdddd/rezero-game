#ifndef GAME_H
#define GAME_H

#include <jni.h>
#include <android/log.h>

#define LOG_TAG "ReZeroGame"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

class Game {
private:
    bool isRunning;
    float playerX;
    float playerY;
    float playerSpeed;
    int animationFrame;

public:
    Game();
    ~Game();

    void init(int width, int height);
    void update(float deltaTime);
    void render();
    void handleInput(float touchX, float touchY);
};

#endif // GAME_H

