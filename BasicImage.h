#pragma once
#include "TextureManager.h"
#include "Warehouse.h"

using namespace::sf;

/**
 * Представляет собой базовую, неанимированную картинку.
 */
class BasicImage{
protected:
	RectangleShape shape;
	Sprite image;
	short scale;
	Vector2f position;
public:
	BasicImage();

    /**

        @param x координата.
        @param y координата.
    */
	BasicImage(float x, float y);

    /**

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	BasicImage(TextureManager* t_manager, Warehouse* w_object, string name);

    /**

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param frame координаты и размеры части текстуры, которая будет отображаться.
    */
	BasicImage(TextureManager* t_manager, int index, string name, IntRect frame);

    /** Устанавливается текстура для текущей неанимированной картинки.

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	void addInfo(TextureManager* t_manager, Warehouse* w_object, string name);

    /** Устанавливается текстура для текущей неанимированной картинки.

        @param t_manager менеджер текстур.
        @param w_item обьект информации о конкретной сущности.
    */
	void addInfo(TextureManager* t_manager, WarehouseItem* w_item);

	FloatRect getLocalBounds();
	FloatRect getGlobalBounds();

    /** Устанавливает новую позицию для неанимированной картинки.

        @param x координата.
        @param y координата.
    */
	void setPosition(float x, float y);

    /** Устанавливает общий масштаб для двух осей для неанимированной картинки.

        @param scale_ значение масштаба.
    */
	void setScale(float scale_);

    /** Устанавливает цвет заднего фона для неанимированной картинки.

        @param color новый цвет для заднего фона.
    */
	void setBColor(Color color);

    /** Обновляет окно и все элементы, которые ему принадлежат.
    */
	virtual void update();

    /** Отображает окно и все элементы, которые ему принадлежат.
    */
	void render();
};

