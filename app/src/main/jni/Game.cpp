#include "Game.h"

Game::Game() {
    isRunning = false;
    playerX = 100.0f;
    playerY = 100.0f;
    playerSpeed = 150.0f; // Скорость движения пикселей в секунду
    animationFrame = 0;
}

Game::~Game() {
    // Тут в будущем будем чистить память и текстуры
}

void Game::init(int width, int height) {
    LOGI("Движок инициализирован! Экрана: %dx%d", width, height);
    isRunning = true;
}

void Game::update(float deltaTime) {
    if (!isRunning) return;

    // Циклическое переключение 4 кадров ретро-анимации
    animationFrame = (animationFrame + 1) % 4; 
}

void Game::handleInput(float touchX, float touchY) {
    // Персонаж плавно сдвигается в сторону пальца (шаг за кадр ~16мс)
    if (touchX > playerX) {
        playerX += playerSpeed * 0.016f;
    } else {
        playerX -= playerSpeed * 0.016f;
    }

    if (touchY > playerY) {
        playerY += playerSpeed * 0.016f;
    } else {
        playerY -= playerSpeed * 0.016f;
    }
    
    LOGI("Новая позиция пиксель-арта: X=%.2f, Y=%.2f", playerX, playerY);
}

void Game::render() {
    if (!isRunning) return;

    // Сюда пойдут вызовы функций OpenGL ES для отрисовки спрайтов.
    // Обязательно выставим текстурам GL_NEAREST, чтобы пиксели были резкими, а не размытыми.
}

