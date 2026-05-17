#include <jni.h>
#include "Game.h"

static Game* gInstance = nullptr;

extern "C"
JNIEXPORT void JNICALL
Java_com_rezero_game_GameLib_init(JNIEnv* env, jclass clazz, jint width, jint height) {
    if (gInstance == nullptr) {
        gInstance = new Game();
    }
    gInstance->init(width, height);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rezero_game_GameLib_step(JNIEnv* env, jclass clazz, jfloat dt) {
    if (gInstance != nullptr) {
        gInstance->update(dt);
        gInstance->render();
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_com_rezero_game_GameLib_touch(JNIEnv* env, jclass clazz, jfloat x, jfloat y) {
    if (gInstance != nullptr) {
        gInstance->handleInput(x, y);
    }
}

