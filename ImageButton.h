#pragma once
#include "Button.h"

using namespace::sf;

class ImageButton : public Button{
private:
	Sprite* btn_image;
	const string name;
public:
    /**

        @param x координата.
        @param y координата.
        @param width ширина shape.
        @param height высота shape.
        @param text_size размер шрифта.
        @param text_ текст кнопки.
        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param outline значение, отвечающее за отображение границ обьекта shape.
        @note кнопка будет представлять собой текст с прозрачной границей(черной границей при наведении),
        текст помещается в правую часть shape, а текстура в левую. Если текст равен "", то текстура выровняется
        по центру прямоугольной области кнопки. Все цвета выставляются с прозрачными значениями.
    */
	ImageButton(float x, float y, float width, float height, short text_size
		, string text_, TextureManager* t_manager, int index, string name_, bool outline);
	~ImageButton();

    /** Устанавливает новую позицию для кнопки.

        @param new_position новая позиция.
    */
	void setPosition(Vector2f new_position) override;

    /** Системный метод.
    */
	void updatePosition() override;

    /** Отображает элемент.
    */
	void render() override;
};

