#pragma once
#include "InterfaceItem.h"
#include "TextureManager.h"
#include "Warehouse.h"

using namespace::sf;

/**
 * Представляет собой базовую, неанимированную картинку.
 */
class BasicImage : public InterfaceItem{
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
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param width ширина, под которую подстроится текстура.
        @param height высота, под которую подстроится текстура.
    */
	BasicImage(float width, float height, TextureManager* t_manager, Warehouse* w_object, string name);

    /**

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param frame координаты и размеры части текстуры, которая будет отображаться.
    */
	BasicImage(TextureManager* t_manager, int index, string name, IntRect frame);

    /**

        @param t_manager менеджер текстур.
        @param index индекс строки содержащей данную текстуру.
        @param name название текстуры, сохраненной в менеджере текстур.
        @param frame координаты и размеры части текстуры, которая будет отображаться.
        @param width ширина, под которую подстроится текстура.
        @param height высота, под которую подстроится текстура.
    */
	BasicImage(float width, float height, TextureManager* t_manager, int index, string name, IntRect frame);
	~BasicImage();

    /**Установка новой текстуры для обьекта неанимированной картинки.

        @param t_manager менеджер текстур.
        @param w_object обьект склада информации о сущностях.
        @param name название текстуры, сохраненной в менеджере текстур.
    */
	void addInfo(TextureManager* t_manager, Warehouse* w_object, string name);

    /**Установка новой текстуры для обьекта неанимированной картинки.

        @param t_manager менеджер текстур.
        @param w_item обьект информации о конкретной сущности.
    */
	void addInfo(TextureManager* t_manager, WarehouseItem* w_item);

	FloatRect getLocalBounds() override;
	FloatRect getGlobalBounds() override;

    /** Сдвигает неанимированную картинку на заданное смещение.

       @param offset_x смещение по x.
       @param offset_y смещение по y.
    */
	void changePosition(float offset_x, float offset_y) override;

    /** Устанавливает новую координату x у позиции.

       @param x координата.
    */
	void setPositionX(float x) override;

    /** Устанавливает новую координату y у позиции.

       @param y координата.
    */
	void setPositionY(float y) override;

    /** Устанавливает новую позицию неанимированной картинке.

       @param x координата.
       @param y координата.
    */
	void setPosition(float x, float y);

    /** Задает новый масштаб неанимированной картинке. Заданный масштаб будет применен как для оси x,
       так и для оси y.

       @param x координата.
       @param y координата.
    */
	void setScale(float scale_);

    /** Устанавливает цвет заливки заднего фона. По умолчанию цвет фона прозрачный.

        @param color новый цвет фона.
    */
	void setBColor(Color color);

    /** Обновляет элемент.
    */
	void update() override;

    /** Отображает элемент.
    */
	void render() override;
};

