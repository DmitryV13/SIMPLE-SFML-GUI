#pragma once
#include "PopUpWindow.h"

/**
 * Представляет собой перетаскиваемое всплывающее окно, с уже встроенной кнопкой, которая егозакрывает,
 */
class PopUpAutocWindow: public PopUpWindow{
private:
	ImageButton* close_b;
	RectangleShape header;
	Textarea* window_name;

	bool chosen;

	Vector2f mouse_pressed_pos;
	float offset_x;
	float offset_y;
public:
    /**
       @param screen_width ширина экрана.
       @param screen_height высота экрана.
       @param width_ ширина всплывающего окна.
       @param height_ высота всплывающего окна.
       @param t_manager_ менеджер текстур, из которого берется текстура заднего фона всплывающего окна.
       @note при дальнейшей разработке, возможно, данный параметр будет удален из конструктора.
    */
	PopUpAutocWindow(double screen_width, double screen_height, int width_, int height_,
		TextureManager* t_manager_);

    /** Задает заголовок для окна.
     *
       @param name заголовок.
    */
	void setWindowName(string name);

    /** Системный метод.
    */
	void dragWindow(Vector2f mouse_current_pos);

    /** Обновляет окно и все элементы, которые ему принадлежат.
    */
	void update() override;

    /** Отображает окно и все элементы, которые ему принадлежат.
    */
	void render() override;
};

