#pragma once

using namespace::sf;

/** Всплывающая надпись
 */
class Notification{
private:
	Text text;
	bool active;
	Vector2f position;
	Vector2f norm_s;
	Clock display_time;
public:
    /**

        @param x координата появления по оси x.
        @param y координата появления по оси y.
        @param dest_x координата назначения при всплывании по оси x.
        @param dest_y координата назначения при всплывании по оси y.
        @param text_size_ размер шрифта.
        @param text_ текст всплывающей надписи.
        @param text_color_ цвет текста (по умолчанию цвет текста черный).
    */
	Notification(float x, float y, float dest_x, float dest_y, short text_size, string text_, Color text_color);

    /** Не используется.
     */
	Notification(FloatRect object_cords, short text_size, string text_, Color text_color);

    /** Активация всплывания.

       @param q параметр заглушка (не используется).
     */
	void activation(float q);

    /** Обновляет элемент.
    */
	void update();

    /** Системный метод.
    */
	void updateDT();

    /** Отображает элемент.
    */
	void render();
};

